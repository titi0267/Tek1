const express = require("express") ;
const env = require('dotenv').config()
const app = express();
const bodyParser = require('body-parser');
const con = require('./config/db.js');
const authRouter = require('./routes/auth/auth.js');
const userRouter = require('./routes/user/user.js');

con.connect(function(err) {
    if (err) {
        throw (err);
    }
    console.log('Connected');
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.listen(process.env.PORT, () => {
    console.log(`Example app listening at http://localhost:${process.env.PORT}`);
});

app.use('/', authRouter);
app.use('/user', userRouter);
