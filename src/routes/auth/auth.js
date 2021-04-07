const express = require("express");
const auth = express.Router();

auth.post("/register", (req, res) => {;
    const request = "INSERT INTO user (email, name, firstname,  password) VALUES (?, ?, ?, ?)";

    const body = [req.body.email, req.body.name, req.body.firstname, req.body.password];

    con.query(request, body,(err, result) => {
        if (err) {
            res.send(err);
        }
        res.send(result);
    });
});

auth.post("/login", (req, res) => {
    const email = req.body.email;
    const password = req.body.password;
});

module.exports = auth;