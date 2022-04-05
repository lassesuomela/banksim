const db = require("../config/db");

const logs = {
    get: function(callback){
        return db.query("SELECT * FROM logs", callback);
    },
    getById: function(id, callback){
        return db.query("SELECT * FROM logs WHERE account_ID = ?", [id], callback);
    },
    add: function(req, callback){

        return db.query("INSERT INTO logs (date, event, amount, account_ID) VALUES(current_timestamp(), ?,?,?)",
        [req.body.event, req.body.amount, req.body.account_ID], callback);
    },
    delete: function(req, callback){
        return db.query("DELETE FROM logs WHERE account_ID = ? AND log_ID = ?",
        [req.body.account_ID, req.body.log_ID], callback);
    }

}

module.exports = logs;
