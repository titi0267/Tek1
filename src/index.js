const express = require("express") ;
const env = require('dotenv').config()
const app = express();
const bodyParser = require('body-parser');
var mysql = require('mysql');
const authRouter = require('./routes/auth/auth.js');

console.log(process.env)

var con = mysql.createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: process.env.MYSQL_DATABASE
});

con.connect(function(err) {
    if (err) {
        throw (err);
    }
    //console.log("[mysql error]",err);
    console.log('Connected');
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.listen(process.env.PORT, () => {
    console.log(`Example app listening at http://localhost:${process.env.PORT}`) ;
});

app.use('/', authRouter);
