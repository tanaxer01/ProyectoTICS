const express  	    = require('express')
    , router   	    = express.Router()
    , database 	    = require('../db')
    , path     	    = require('path')
    , auth     	    = require('../middlewares/auth')
    , guardabosques = require('../middlewares/guardabosques')
    , validAlert    = require('../middlewares/validAlert')
    , checkConfig   = require('../middlewares/checkConfig')


//MIDDLEWARES APLICADOS A TODO
router.use((req, res, next) => {
	// BORRAR LA COOKIE SI EL USUARIO NO ESTA LOGEADO
	if( req.cookies.userINFO && !req.session.user){
		console.log("cleaning out");
		res.clearCookie("userINFO") 
	};


	// CONFIGURAR EL HEADER PARA NO TENER PROBLEMAS CON EL CORS
	res.header('Access-Control-Allow-Origin', '*');
	res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');

	next();
});

// HOME STF -----------------------------------------------------------------------------------------------------------
router.get('/home',auth,checkConfig, async (req,res) => {
	const datos = await database.query(`
		select 
			clientes.nombre, configuraciones.temperatura, configuraciones.humedad, configuraciones.viento 
		from 
			clientes, configuraciones 
		where 
			clientes.rut = $1 and 
			clientes.rut = configuraciones.empresa and 
			configuraciones.ocupante = 0`, [ req.session.empleador ]);

	res.status(200).render("home.pug",{ empleador:     datos.rows[0].nombre, 
					    temperatura:   datos.rows[0].temperatura, 
					    humedad:       datos.rows[0].humedad, 
					    viento:        datos.rows[0].viento,
					    guardabosques:  req.session.guardabosques}) 
});

router.get('/', (req,res) => res.status(200).redirect("/home"));

router.get('/alertas', auth, async (req, res) => {
	let matches = await database.query("select timestamp, length, sector from registros where temperatura::int + humedad::int + viento::int = 3 order by timestamp desc limit 15");
	

	console.log(matches.rows)
	res.status(200).json({ alertas: matches.rows })
});


// MAP STF  -----------------------------------------------------------------------------------------------------------
router.get('/map',auth, (req, res) => res.status(200).sendFile(path.join(__dirname, '../views/map.html')));

router.get('/registros',auth, async (req, res) => {

	const torres = await database.query("select x,y from nodos where torre = true and rutcliente = $1", [ req.session.empleador ]);
	const registers = await database.query(`select
registros.sector, registros.length, max(temperatura::int+viento::int+humedad::int)                                                
from
registros,
(select max(timestamp), sector, length from registros group by sector, length) as t1
where 
registros.timestamp = t1.max and registros.sector = t1.sector and registros.length = t1.length
group by registros.sector, registros.length;`, []);

	res.status(200).json({ coordenadas: torres.rows, registros: registers.rows });
});

// LOGIN & OUT STF  --------------------------------------------------------------------------------------------------- 
router.get('/login', (req,res) => res.status(200).sendFile(path.join(__dirname, '../views/login.html')));

router.post('/login', async (req,res) => {
	const user = req.body.username, pass = req.body.password
	    , query = await database.query(
		    "select usuarios.id, clientes.rut as empleador, usuarios.guardabosques from usuarios, clientes  where clientes.rut = usuarios.empleador and usuarios.id = $1 and usuarios.password = $2 ", [user, pass])

	if(query.rows.length){
		req.session.user          = query.rows[0].id;
		req.session.empleador     = query.rows[0].empleador;
		req.session.guardabosques = query.rows[0].guardabosques;
		console.log("logged",req.session);

		res.status(200).redirect("/home");
	}else{
		res.status(404).end();
	}
});

router.get('/logout', (req,res) => {
	if (req.session.user && req.cookies.userINFO){
		res.clearCookie('userINFO');
	}else{
		console.log("ou shiet");
	}
	
	res.redirect('/login');
});

// CONFIG RELATED STF ------------------------------------------------------------------------------------------------------------

router.post('/config',auth, checkConfig, async (req, res) => {
	console.log("Update made on ",req.session.empleador,"with",req.body)

	if( req.body.length == 0 ){
		const result = await database.query(`
			update 
				configuraciones 
			set 
				temperatura = $1, humedad = $2 , viento = $3  
			where 
				empresa = $4 and 
				ocupante = 0`,
			[ parseFloat(req.body.nodos[0].temperatura)
			, parseFloat(req.body.nodos[0].humedad)
			, parseFloat(req.body.nodos[0].viento)
			, req.session.empleador] )
	}

	res.status(200).send("s");
});

// STATS STF ---------------------------------------------------------------------------------------------------------------------
router.get('/plots', auth, (req, res) => res.status(200).sendFile(path.join(__dirname, '../views/plot.html')))

router.get('/info', auth, async (req, res) => {
	console.log("Query for plots from ", req.session.user, " - ", req.session.empleador);

	const meses = await database.query(`
		select 
			extract(month from timestamp) as mes, count(*)
		from
			registros
		where
			temperatura::int + humedad::int + viento::int = 3
		group by
			mes
		order by
			mes asc`, []);
	res.status(200).json(meses.rows)
})

// Input Alert -------------------------------------------------------------------------------------------------------------------
router.get('/guardabosques', auth, guardabosques, (req,res) => res.status(200).sendFile(path.join(__dirname,'../views/guardabosques.html')));

router.post('/guardabosques', auth, guardabosques, validAlert, async (req,res) => {
	const result = await database.query(`
		insert into 
			registros (timestamp, length, sector, cliente, temperatura, humedad, viento) 
		values 
			(current_timestamp, 0, $1, $2, true, true, true)`, [req.body.sector, req.session.empleador]);

	console.log(result)
	res.status(200).send(true);
})

// P
router.post('/data', auth, async (req, res) => {
	let alertas = []
	req.body.registros.map( async (elemento) => {


		temp = parseFloat(elemento.temperatura)
		hum  = parseFloat(elemento.humedad)
		viento = parseFloat(elemento.viento)


		if(temp + hum + viento == 1){ alertas.append(elemento) }
		const result = await database.query("insert into registros(length, sector, temperatura, humedad, viento) values ($1,$2,$3,$4,$5)",[elemento.id, elemento.sector, temp, hum , viento]);
	});

	res.status(200).json({ alerta: 1, nodos: alertas})
});



module.exports = router;
