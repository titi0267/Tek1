const express = require("express");
const env = require('../../../.env');
const app = express();
var mysql = require('mysql');

app.use(express.static("private"));

var con = mysql.createConnection({
    MYSQL_HOST,
    MYSQL_USER,
    MYSQL_ROOT_PASSWORD,
    MYSQL_DATABASE
});

module.exports = (app) => app.post("/register", (req, res) => {
    const email = req.body.email;
    const name = req.body.name;
    const firstname = req.body.firstname;
    const password = req.body.password;
    con.query("INSERT INTO user (email, name, firstname,  password) VALUES", (email, name, firstname, password), function(err, result) {
        if (err) {
            console.log('acccount already exists');
        } else {
            console.log('Token of the newly registered user');
        }
    });
});

app.post("/login", (req, res) => {
    const email = req.body.email;
    const password = req.body.password;
});

module.exports = app;