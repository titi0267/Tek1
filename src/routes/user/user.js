const express = require("express");
const env = require('../../../.env');
const app = express();

app.get("/user", (req, res) => {

});

app.get("/user/todos", (req, res) => {

});

app.get("/user/:email", (req, res) => {
    let msg = {
        msg: `Hello ${req.params.email} !`
    };
    res.send(JSON.stringify(msg));
});

app.put("user/:id", (req, res) => {

});

app.delete