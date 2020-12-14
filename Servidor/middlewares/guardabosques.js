
module.exports = (req, res, next) => {
	if(req.session.guardabosques){
		next()
	}else{
		res.status(401).redirect("/home");
	}
}
