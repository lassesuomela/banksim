var express = require('express');
var router = express.Router();
const db = require("../config/db");
const accountController = require("../controllers/accountController");
const jwtAuth = require("../config/jwtAuth");

router.get("/",jwtAuth.verifyToken,accountController.getOwnedAccounts);

router.get("/:id",jwtAuth.verifyToken,accountController.getById);

router.post("/adduser",jwtAuth.verifyToken,accountController.addUserToAccount);

router.post("/",jwtAuth.verifyToken,accountController.addAccount);

router.delete("/", jwtAuth.verifyToken, accountController.deleteAccount);

module.exports = router;
