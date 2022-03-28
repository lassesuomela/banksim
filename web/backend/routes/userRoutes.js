var express = require('express');
var router = express.Router();
const db = require("../config/db");
const userController = require("../controllers/userController");
const jwtAuth = require("../config/jwtAuth");

router.get('/',jwtAuth.authToken,userController.getAll)

router.get('/:id',jwtAuth.authToken,userController.getById);

router.post("/login",userController.userLogin);

router.post("/register",userController.userRegister);

module.exports = router;
