const db = require("../config/db");
const bcrypt = require("bcrypt");

const saltRounds = 10;
const card = {
    get: function(callback){
        return db.query("SELECT * FROM card", callback);
    },
    getByNumber: function(card_number, callback){
        return db.query("SELECT * FROM card WHERE card_number = ?", [card_number], callback);
    },
    updateActiveStatus: function(req, callback){
        return db.query("UPDATE card SET active = ? WHERE card_number = ?", [req.body.active, req.body.card_number], callback);
    },
    add: function(req, callback){
        bcrypt.hash(req.body.pin, saltRounds, function(err, hash){
            return db.query("INSERT INTO card (pin, card_number, account_ID, user_ID, card_type) VALUES(?,?,?,?,?)",
            [hash, req.body.card_number, req.body.account_ID, req.body.user_ID, req.body.card_type], callback);
        });
    },
    delete: function(req, callback){
        return db.query("DELETE FROM card WHERE card_number = ?", [req.body.card_number], callback);
    }

}

module.exports = card;
