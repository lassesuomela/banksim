var express = require('express');
var router = express.Router();
const db = require("../config/db");
const cardController = require("../controllers/cardController");

router.get('/',cardController.getAll)

router.get('/:card_number',cardController.getByCardNumber);

router.put("/updateCard",cardController.updateCardStatus);

router.post("/addCard",cardController.addCard);

router.post("/auth", cardController.authenticate)

router.delete("/deleteCard", cardController.deleteCard)

module.exports = router;
