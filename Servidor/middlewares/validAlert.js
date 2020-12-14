const database = require("../db");

module.exports =  async (req,res,next) => {
	const existe = await database.query("select * from sectores where sector = $1",[req.body.sector]);
	console.log(existe);

	if(existe.rows.length ){ 
		console.log("valid Alert entered")
		next()
	}else{
		console.log("AAAAAAAAAAA");
		res.status(404).end()
	}
}
