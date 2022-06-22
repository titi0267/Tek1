const express = require("express");
const auth = express.Router();
var mysql = require('mysql');
const con = require('../../config/db.js');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
require('dotenv').config();

auth.post("/register", (req, res) => {
    const request = "INSERT INTO user (email, name, firstname,  password) VALUES (?, ?, ?, ?)";

    bcrypt.hash(req.body.password, 10, (error, hash) => {
        if (error) throw err;
        let body = [req.body.email, req.body.name, req.body.firstname, hash];
        const select_email = 'SELECT email FROM user WHERE email =?'

        con.query(select_email, [req.body.email], (mailerror, emailresult) => {
            if (emailresult[0] === undefined) {
                con.query(request, body,(err, result) => {
                    if (err) {
                        res.send(err);
                    };
                    let token = jwt.sign({body}, process.env.SECRET);
                    let printtoken = {
                        token: `${token}`
                    };
                    res.json(printtoken);
                });
            } else {
                let msg = {
                    msg: `account already exists`
                };
                res.json(msg);
                return;
            }
        });

    });
});

auth.post("/login", (req, res) => {
    const body = [req.body.email, req.body.password];
    const request = "SELECT * FROM user WHERE email=?";

    con.query(request, [req.body.email], (err, result) => {
        if (err) throw err;
        if (result[0] === undefined) {
            let msg = {
                msg: `Invalid Credentials`
            };
            res.json(msg);
            return;
        } else {
            bcrypt.compare(req.body.password, result[0].password, (err, same) => {
                if (err) throw err;
                if (same === false) {
                    let msg = {
                        msg: `Invalid Credentials`
                    };
                    res.json(msg);
                } else {
                    let token = jwt.sign({body}, process.env.SECRET);
                    let printtoken = {
                        token: `${token}`
                    };
                    res.json(printtoken);
                }
            });
        }
    });
});

module.exports = auth;