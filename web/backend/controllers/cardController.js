const card = require("../models/cardModel");
const bcrypt = require("bcrypt");
const emailvalidator = require("email-validator");
const { json } = require("express/lib/response");

const getAll = (req, res) => {
    card.get(function(err,dbResult){
        if(err){
            res.json(err);
        }else{
            res.json(dbResult);
        }
    });
}

const getByCardNumber = (req, res) => {
    if(req.params.card_number){
        card.getByNumber(req.params.card_number, function(err,dbResult){
            if(err){
                res.json(err);
            }
            if(dbResult.length > 0){
                res.json(dbResult);
            }else{
                res.json({status:"error",message:"Card not found"})
            }
        });
    }
}

const updateCardStatus = (req, res) => {
    if(req.body.active && req.body.card_number){
        card.updateActiveStatus(req, function(err, dbResult){
            if(err){
                res.json(err);
            }
            
            if(dbResult.affectedRows > 0){
                res.json({status:"Successfully modified card's status"});
            }else{
                res.json({status:"error",message:"Card not found"})
            }
            
        });
    }else{
        res.json({status:"error",message:"Please fill all fields"});
    }
}

const addCard = (req, res) => {
    if(req.body.pin && req.body.card_number && req.body.account_ID && req.body.user_ID && req.body.card_type){
        card.add(req, function(err, result){
            if(err){
                res.json(err);
            }else{
                res.json({status:"Successfully added new card"});
            }
        });
    }else{
        res.json({message:"Please fill all fields"});
    }
}

const authenticate = (req, res) => {
    if(req.body.card_number && req.body.pin){
        card.getByNumber(req.body.card_number, function(err, result){
            if(err){
                return res.send(err);
            }

            if(result.length > 0){
                bcrypt.compare(req.body.pin, result[0].pin.toString(), (err, match)=>{
                    if(err){
                        res.json(err);
                    }
                    if(match){
                        console.log("Successfully authenticated!");
                        res.json({status:"success",message:"Successfully authenticated!"});
                    }else{
                        console.log("Invalid pin code or card number!");
                        res.json({status:"error",message:"Invalid pin code or card number!"});
                    }
                });
            }else{
                res.json({status:"error",message:"Card was not found"});
            }
            
        });
    }else{
        res.json({status:"error",message:"Please fill all fields"})
    }
    
}

const deleteCard = (req, res) => {
    if(req.body.card_number){
        card.delete(req, function(err,result) {

            if(err){
                return res.json(err);
            }

            console.log(result);

            if(result.affectedRows > 0){
                res.json({status:"success",message:"Card deleted"});
            }else{
                res.json({status:"error",message:"Card not found"})
            }
        })
    }else{
        res.json({status:"error",message:"Please fill all fields"})
    }
    
}

module.exports = {
    getAll,
    getByCardNumber,
    updateCardStatus,
    addCard,
    authenticate,
    deleteCard
}
