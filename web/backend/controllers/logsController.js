const logs = require("../models/logsModel");
const card = require("../models/cardModel")

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

    if(!req.params.card_number || !req.params.page){
        return res.json({status:"error",message:"Please fill all fields."});
    }

    card.getByUserID(req.userId, function(err,dbResult){

        let hasAccessToCard = false;

        for(let i = 0; i < dbResult.length; i++){

            if(dbResult[i].card_number === req.params.card_number){
                hasAccessToCard = true;
            }
        }
        
        if(!hasAccessToCard){
            return res.json({status:"error",message:"User doesn't have access to this card"});
        }

        // how many logs per page we want to show in the exe
        let perPageCount = 10; 
        let maxLogCount = 0;
        let currentPage = 0;
        let maxPage = 0;

        logs.getMaxLogsNum(req.params.card_number, function(err,dbResult){
            if(err){
                return res.json(err);
            }

            if(dbResult.length > 0){
                maxLogCount = dbResult[0].maxCount;

                // round the max page num up because there doesn't need to be exactly 10 logs per page
                maxPage = Math.ceil(maxLogCount/perPageCount); 

                if(req.params.page <= 0 || req.params.page > maxPage){
                    return res.json({status:"error",message:"Page number out of scope"});
                }

                currentPage = (req.params.page - 1) * perPageCount;
                
                logs.getByCardNumber(req.params.card_number, currentPage, function(err,dbResult){
                    if(err){
                        return res.json(err);
                    }
    
                    if(dbResult.length > 0){
                        res.json({status:"success", maxPageAmount: maxPage, data:dbResult});
                    }else{
                        res.json({status:"error",message:"No logs found for that card number"});
                    }
                })

            }else{
                return res.json({status:"error",message:"0 logs found for that card number"});
            }
        })
    })
}

const getByCardNumberFixed = (req, res) => {

    card.getByUserID(req.userId, function(err,dbResult){

        let hasAccessToCard = false;

        for(let i = 0; i < dbResult.length; i++){

            if(dbResult[i].card_number === req.params.card_number){
                hasAccessToCard = true;
            }
        }

        if(!hasAccessToCard){
            return res.json({status:"error",message:"User doesn't have access to this card"});
        }

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
            res.json({status:"error",message:"Please fill all fields."});
        }
    })
}

const add = (req, res) => {

    card.getByUserID(req.userId, function(err,dbResult){

        let hasAccessToCard = false;

        for(let i = 0; i < dbResult.length; i++){

            if(dbResult[i].card_number === req.body.card_number){
                hasAccessToCard = true;
            }
        }

        if(!hasAccessToCard){
            return res.json({status:"error",message:"User doesn't have access to this card"});
        }

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
    })
}

const deleteLogs = (req, res) => {

    card.getByUserID(req.userId, function(err,dbResult){

        let hasAccessToCard = false;

        for(let i = 0; i < dbResult.length; i++){

            if(dbResult[i].card_number === req.params.card_number){
                hasAccessToCard = true;
            }
        }

        if(!hasAccessToCard){
            return res.json({status:"error",message:"User doesn't have access to this card"});
        }
        
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
            res.json({status:"error",message:"Please fill all fields."});
        }
    })
}

module.exports = {
    getAll,
    getByCardNumber,
    getByCardNumberFixed,
    add,
    deleteLogs
}
