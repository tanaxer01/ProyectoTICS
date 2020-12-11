const db    = require('../models');
const path 	= require('path')

module.exports = (app) => {
	app.use( (req,res,next) => {
		res.header('Access-Control-Allow-Origin', '*');
		res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');

		next();
	});


	app.get('/home', (req, res) => {
		res.status(200).sendFile(path.join(__dirname,'../views/index.html'));
	});

	app.get('/login', (req,res) => {
		res.status(200).sendFile(path.join(__dirname,'../views/login.html'));
	});

	app.post('/logUser', async (req,res) => {
		const response = await db.query("select * from Usuarios where id = $1 and password = $2",[req.params('user'), req.params('password')]);
		console.log(response)
		res.status(200).json({ message: response });
	});

	app.get('/map', (req,res) => {
		res.status(200).sendFile(path.join(__dirname,'../views/map.html'));
	});
//	app.post('/changeCongig', (req,res) => {
//	
//	})

	app.get('/empresa/:rut', async (req,res) => {
		console.log("query a empresa ", req.params.rut);
		const torres    = await db.query(`select x,y from nodos where id = '0' and rutcliente = $1`,[ '1234567890' ]);
		const registers = await db.query(`
		select 
			sector, length(idnodo), max(total) 
		from
			(select sector, idnodo, (temperatura::int + humedad::int + viento::int) as total from registros) as t1 group by sector, length(idnodo) order by sector, length
		`, []);
		res.status(200).json({ coordenadas: torres.rows, registros: registers.rows });
	
	});

}

