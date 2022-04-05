const logs = require("../models/logsModel");

const getAll = (req, res) => {
    logs.get(function(err,dbResult){
        if(err){
            res.json(err);
        }else{
            res.json(dbResult);
        }
    });
}

const getByAccountId = (req, res) => {
    if(req.body.accountId){
        logs.getById(req.body.accountId, function(err,dbResult){
            if(err){
                res.json(err);
            }else{
                res.json(dbResult);
            }
        });
    }
}

const add = (req, res) => {
    if(req.body.event && req.body.amount && req.body.account_ID){
        logs.add(req, function(err, dbResult){
            if(err){
                console.log(err);
                res.json({status:"error",message:"Error on creating logs."});
            }else{
                res.json({status:"success",message:"Log created."});
            }
        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

const deleteLogs = (req, res) => {
    if(req.body.account_ID && req.body.log_ID){
        logs.delete(req, function(err, dbResult){
            if(err){
                res.json({status:"error",message:"Error on deleting logs."});
            }else{
                res.json({status:"success",message:"Log deleted."});
            }
        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

module.exports = {
    getAll,
    getByAccountId,
    add,
    deleteLogs
}
