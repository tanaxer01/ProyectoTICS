const database = require('../db');

module.exports = async (req,res,next) => {
	console.log(req.session.empleador)
	const config = await database.query("select * from configuraciones where ocupante = '0' and empresa = $1",[req.session.empleador]);

	if( config.rows.length ){
		console.log(config);
		next()
	}else{
		const create = await database.query("insert into configuraciones values ('0', '0000', $1, 30,30,30)",[req.session.empleador]);
		console.log(create,"ñoo");
		next()
	}

}
