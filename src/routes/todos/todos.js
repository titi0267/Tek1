const express = require("express");
const app = express.Router();
var mysql = require('mysql');
const con = require('../../config/db.js');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
require('dotenv').config();

app.get("/", (req, res) => {
    const request = "SELECT * FROM todo"

    con.query(request, (err, result) => {
        if (err)
            res.send(err);
        res.send(result);
    });
});

app.get("/:id", (req, res) => {
    const request = 'SELECT * FROM todo WHERE id=?';

    con.query(request, [req.params.id], (err, result) => {
        if (err)
            res.send(err);
        res.send(result);
    });
});

app.post("/", (req, res) => {
    const request = "INSERT INTO todo (title, description, due_time,  user_id, status) VALUES (?, ?, ?, ?, ?)";
    const body = [req.body.title, req.body.description, req.body.due_time, req.body.user_id, req.body.status];

    con.query(request, body, (error, result) => {
        if (error) throw error;
        let respond = {
            title: `${req.body.title}`,
            description: `${req.body.description}`,
            due_time: `${req.body.due_time}`,
            user_id: `${req.body.user_id}`,
            status: `${req.body.status}`
        }
        res.json(respond);
    });
});

app.put("/:id", (req, res) => {
    const request = "UPDATE todo SET title=?, description=?, due_time=?,  user_id=?, status=?";
    const body = [req.body.title, req.body.description, req.body.due_time, req.body.user_id, req.body.status];

    con.query(request, body, (error, result) => {
        if (error) throw error;
        let respond = {
            title: `${req.body.title}`,
            description: `${req.body.description}`,
            due_time: `${req.body.due_time}`,
            user_id: `${req.body.user_id}`,
            status: `${req.body.status}`
        }
        res.json(respond);
    });
});

app.delete("/:id", (req, res) => {
    const remove = 'DELETE FROM todo WHERE id = ?'

    con.query(remove, [req.params.id], (err, result) => {
        if (err) throw err;
        let msg = {
            msg: `succesfully deleted record number : ${req.params.id}`
        }
        res.json(msg);
    });
});

module.exports = app;