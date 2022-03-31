const db = require("../config/db");
const bcrypt = require("bcrypt");

const account = {
    get: function(callback){
        return db.query("SELECT * FROM account", callback);
    },
    getById: function(id, callback){
        return db.query("SELECT * FROM account WHERE account_ID = ?", [id], callback);
    },
    getByUserId: function(id, callback){
        return db.query("SELECT account.* FROM account JOIN user_account ON user_account.account_ID = account.account_ID JOIN user on user.user_ID = user_account.user_ID WHERE user.user_ID = ?", [id], callback);

    },
    getByCardId: function(id, callback){
        return db.query("SELECT * FROM account JOIN card on card.account_ID = account.account_ID WHERE account_ID = ?", [id], callback);

    },
    add: function(userId, callback){
        db.query("INSERT INTO account(date_opened) VALUES(current_timestamp())");
        return db.query("INSERT INTO user_account(user_ID, account_ID) VALUES(?, (SELECT account_ID FROM account ORDER BY account_ID DESC LIMIT 1))",[userId], callback);
    },
    addUser: function(userId, accountId, callback){
        return db.query("INSERT INTO user_account(user_ID, account_ID) VALUES(?, )", [userId]);
    }
}

module.exports = account;
