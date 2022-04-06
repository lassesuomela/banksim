const db = require("../config/db");

const logs = {
    get: function(callback){
        return db.query("SELECT * FROM logs ORDER BY log_ID DESC", callback);
    },
    getByCardNumberFixed: function(card_number, callback){
        return db.query("SELECT * FROM logs WHERE account_ID = (SELECT card.account_ID FROM card WHERE card_number = ?) ORDER BY log_ID DESC LIMIT 5", [card_number], callback);
    },
    getByCardNumber: function(card_number, min, max, callback){
        return db.query("SELECT * FROM logs WHERE account_ID = (SELECT card.account_ID FROM card WHERE card_number = ?) AND log_ID > ? AND log_ID < ? ORDER BY log_ID DESC LIMIT 5", [card_number, min, max], callback);
    },
    add: function(req, event, callback){
        return db.query("INSERT INTO logs (date, event, amount, account_ID) VALUES(current_timestamp(), ?,?, (SELECT card.account_ID FROM card WHERE card_number = ?))",
        [event, req.body.amount, req.body.card_number], callback);
    },
    delete: function(req, callback){
        return db.query("DELETE FROM logs WHERE account_ID = (SELECT card.account_ID FROM card WHERE card_number = ?) AND log_ID = ?",
        [req.body.card_number, req.body.log_ID], callback);
    }

}

module.exports = logs;
