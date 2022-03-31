var express = require('express');
var router = express.Router();
const db = require("../config/db");
const cardController = require("../controllers/cardController");
const jwtAuth = require("../config/jwtAuth");

router.get('/getAllCards', jwtAuth.verifyToken, cardController.getAll)

router.get('/getByCardNumber/:card_number', jwtAuth.verifyToken, cardController.getByCardNumber);

router.get('/usersCards', jwtAuth.verifyToken, cardController.getByCardsByUserID);

router.put("/updateCard", jwtAuth.verifyToken, cardController.updateCardStatus);

router.post("/addCard", jwtAuth.verifyToken, cardController.addCard);

router.post("/auth", jwtAuth.verifyToken, cardController.authenticate)

router.delete("/deleteCard", jwtAuth.verifyToken, cardController.deleteCard)

module.exports = router;
