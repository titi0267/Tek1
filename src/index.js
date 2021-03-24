const express = require("express") ;
const env = require('../.env')
const app = express();

app.get("/", (req, res) => {
    res.send("Hello World !");
}) ;

app.get("/name/:id", (req, res) => {
    let msg = {
        msg: `Hello ${req.params.id} !`
    };
    res.send(JSON.stringify(msg));
});

app.get("/date", (req, res) => {
    var date = new Date();
    res.send(`${date.getFullYear()}-${((date.getMonth() + 1) > 9) ? (date.getMonth() + 1) : ('0' + (date.getMonth() + 1))}-${date.getDate()}`);
});

app.listen(PORT, () => {
console.log(`Example app listening at http://localhost:${PORT}`) ;
});
