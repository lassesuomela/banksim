const jwt = require("jsonwebtoken");
require("dotenv").config();

function generateToken(user) {
    return jwt.sign({userid: user}, process.env.SECRET_TOKEN.toString(), { expiresIn: '1800s' });
}

function authToken(req, res, next) {
    const authHeader = req.headers['authorization'];
    const token = authHeader && authHeader.split(' ')[1];
    if (token == null) return res.sendStatus(401)

    jwt.verify(token, process.env.SECRET_TOKEN, (err, user) => {
        if (err){
            console.log(err);
            return res.sendStatus(403);
        }
        req.user = user
        next()
    })
}

module.exports = {
    generateToken,
    authToken
}