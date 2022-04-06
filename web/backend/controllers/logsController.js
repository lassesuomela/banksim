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

const getByCardNumber = (req, res) => {
    if(req.params.card_number, req.params.min, req.params.max){
        logs.getByCardNumber(req.params.card_number, req.params.min, req.params.max, function(err,dbResult){
            if(err){
                res.json(err);
            }

            if(dbResult.length > 0){
                res.json(dbResult);
            }else{
                res.json({status:"error",message:"No logs found for that card number"});
            }

        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

const getByCardNumberFixed = (req, res) => {
    if(req.params.card_number){
        logs.getByCardNumberFixed(req.params.card_number, function(err,dbResult){
            if(err){
                res.json(err);
            }

            if(dbResult.length > 0){
                res.json(dbResult);
            }else{
                res.json({status:"error",message:"No logs found for that card number"});
            }

        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

const add = (req, res) => {
    if(req.body.amount && req.body.card_number){
        let event = null;

        if(req.body.amount < 0){
            event = "Otto";
        }else{
            event = "Talletus";
        }

        logs.add(req, event, function(err, dbResult){
            if(err){
                console.log(err);
                return res.json({status:"error",message:"Error on creating logs."});
            }

            if(dbResult.affectedRows > 0){
                res.json({status:"success",message:"Log created."});
            }else{
                res.json({status:"error",message:"Log was not created."});
            }
        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

const deleteLogs = (req, res) => {
    if(req.body.card_number && req.body.log_ID){
        logs.delete(req, function(err, dbResult){
            if(err){
                return res.json({status:"error",message:"Error on deleting logs."});
            }

            if(dbResult.affectedRows > 0){
                res.json({status:"success",message:"Log deleted."});
            }else{
                res.json({status:"error",message:"Log not deleted."});
            }
        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

module.exports = {
    getAll,
    getByCardNumber,
    getByCardNumberFixed,
    add,
    deleteLogs
}
