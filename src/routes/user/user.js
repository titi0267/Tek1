const express = require("express");
const app = express.Router();
const con = require('../../config/db.js');
const bcrypt = require('bcrypt');
var mysql = require('mysql');


app.get("/", (req, res) => {
    const request = "SELECT * FROM user"

    con.query(request, (err, result) => {
        if (err)
            res.send(err);
        res.send(result);
    });
});

app.get("/todo", (req, res) => {
    console.log();
    const search = "SELECT id FROM user WHERE email =?"
    const request = "SELECT * FROM todo WHERE user_id=?"

    con.query(search, [req.mytoken.body[0]], (err, search_result) => {
        if (err)
            res.send(err);
        con.query(request, [search_result[0].id], (error, result) => {
            console.log(result);
            if (error)
                res.send(error);
            res.send(result);
        });
    });
});

app.get("/:id", (req, res) => {
    let request;
    if (isNaN(req.params.id) === false)
        request = "SELECT * FROM user WHERE id =?";
    else
        request = "SELECT * FROM user WHERE email =?"
    con.query(request, [req.params.id], (err, result) => {
        if (err)
            res.send(err);
        res.send(result);
        console.log(result);
    });
});

app.put("/:id", (req, res) => {
    const request = "UPDATE user SET email=?, name=?, firstname=?, password=? WHERE id=?";
    
    bcrypt.hash(req.body.password, 10, (error, hash) => {
        if (error) throw err;
        let body = [req.body.email, req.body.name, req.body.firstname, hash, req.params.id];

        con.query(request, body,(err, result) => {
            if (err) {
                res.send(err);
            };
            let respond = {
                email: `${req.body.email}`,
                name: `${req.body.name}`,
                firstname: `${req.body.firstname}`,
                password: `${hash}`
            };
            res.json(respond)
        });
    });
});

app.delete("/:id", (req, res) => {
    const remove = 'DELETE FROM user WHERE id = ?'

    con.query(remove, [req.params.id], (err, result) => {
        if (err) throw err;
        let msg = {
            msg: `succesfully deleted record number : ${req.params.id}`
        }
        res.json(msg);
    });
});

module.exports = app;