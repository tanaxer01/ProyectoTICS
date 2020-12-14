#!/usr/bin/env node
const express      = require('express')
    , bodyParser   = require('body-parser')
    , cookieParser = require('cookie-parser')
    , session      = require('express-session')
    , cors         = require('cors')
    , corsOptions  = { origin: "localhost:3000" }
    , app          = express();


// |>REQUERIMIENTOS DE LA APP
app.set('views', './views');

app.set('view engine', 'pug');
// |--> Configurando CORS para que podamos intercambiar info sin problemas 
app.use(cors(corsOptions));
// |--> Configurando las librerias que ocuparemos para manejar las sessiones y cookies
app.use(bodyParser.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(session({ key: 'userINFO', secret: "qazedcrfvtgb", resave: false, saveUninitialized: false, cookie: { expires: 600000 }}));
// |--> Definiendo rutas necesarias para el render de las views
app.use(express.static(__dirname + '/views'))


//DIRECCION DE LAS DISTINTAS RUTAS
app.use(require('./controllers'));


app.listen(3000, () => console.log('Server running in port 3000'));
