const jwt = require('jsonwebtoken');
require('dotenv').config();

var middleware = function(req, res, next){
    var token = req.header('token');
    
    jwt.verify(token, process.env.SECRET, function(err, decoded) {    
    if (err) {    
        res.status(401).send({message:'Please login'});
    }
    req.mytoken = decoded;
    });
    next();
};

module.exports = middleware;