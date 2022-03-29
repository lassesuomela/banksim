var express = require('express');
var router = express.Router();
const db = require("../config/db");
const userController = require("../controllers/userController");
const jwtAuth = require("../config/jwtAuth");

router.get('/',jwtAuth.verifyToken,userController.getAll)

router.get('/:id',jwtAuth.verifyToken,userController.getById);

router.get("/test",jwtAuth.verifyToken,userController.test);

router.post("/login",userController.userLogin);

router.post("/register",userController.userRegister);

module.exports = router;
