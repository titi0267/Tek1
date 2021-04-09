const express = require("express");
const app = express.Router();
const con = require('../../config/db.js');

app.get("/", (req, res) => {
    const request = "SELECT * FROM user"

    con.query(request, (err, result) => {
        if (err)
            res.send(err);
        res.send(result);
    });
});

app.get("/todos", (req, res) => {
    const request = "SELECT * FROM todo"

    con.query(request, (err, res) => {
        if (err)
            res.send(err);
        res.send(res);
    });

});

app.get("/:email", (req, res) => {
    let msg = {
        msg: `Hello ${req.params.email} !`
    };
    res.send(JSON.stringify(msg));
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