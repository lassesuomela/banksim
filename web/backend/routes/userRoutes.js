var express = require('express');
var router = express.Router();
const db = require("../config/db");
const userController = require("../controllers/userController");

router.get('/',userController.getAll)

router.get('/:id',userController.getById);

router.post("/login",userController.userLogin);

router.post("/register",userController.userRegister);

module.exports = router;
