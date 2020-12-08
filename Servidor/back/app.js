const express 	 = require('express');
const bodtParser = require('body-parser');
const cors 		 = require('cors');


const port = 3000;

const app = express();

// cors
var corsOptions = { origin: "localhost:3000" };
app.use(cors(corsOptions));

app.use(express.static(__dirname+'/views'));

//DATABASE
const db = require('./models');

db.query("SELECT * FROM nodos", []);


// ENDPOINTS
app.get('/', (req, res) => res.status(200).json({ message: "Hola mundo" }) );

require("./routes/routes")(app);
	//"Main"



	//if cookie -> MAPA

	//else login/register

	//"CONFIGS"
	//if cookie -> config
//k



app.listen(port, () => console.log(`Servidor iniciando en el puerto ${port}`) );



// FALTA -----------------------------------------------
// Config con DB
// Configurar Rutas
// Configurar middlewares y controladores (same as arriba)

// Generar todo lo grafico
// ** Dejar lo del mapa pulento
// portar lo que hizo el mexcel aca.
