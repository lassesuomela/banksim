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
    getByUserID: function(user_ID, callback){
        return db.query("SELECT * FROM card WHERE user_ID = ?", [user_ID], callback);
    },
    updateActiveStatus: function(active, card_number, callback){
        return db.query("UPDATE card SET active = ? WHERE card_number = ?", [active, card_number], callback);
    },
    connectToAccount: function(accountId, userId, card_type, callback){
        return db.query("UPDATE card SET account_ID = ?, user_ID = ?, card_type = ? WHERE user_ID IS NULL AND account_ID IS NULL ORDER BY card_ID ASC LIMIT 1", [accountId, userId, card_type], callback);
    },
    add: function(req, callback){
        bcrypt.hash(req.body.pin, saltRounds, function(err, hash){
            return db.query("INSERT INTO card (pin, card_number) VALUES(?,?)",
            [hash, req.body.card_number], callback);
        });
    },
    delete: function(req, callback){
        return db.query("DELETE FROM card WHERE card_number = ?", [req.body.card_number], callback);
    },
    updateTries: function(tries, card_number, callback){
        return db.query("UPDATE card SET tries = ? WHERE card_number = ?", [tries, card_number], callback);
    }

}

module.exports = card;
