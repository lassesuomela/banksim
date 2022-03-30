const card = require("../models/cardModel");
const bcrypt = require("bcrypt");
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

        // activating card, resetting tries
        if(req.body.active == 1){
            card.updateTries(0, req.body.card_number, (err, dbResult) =>{

                if(err){
                    console.log(err);
                    return res.json({status:"error",message:"Error on resetting card's tries"})
                }

                if(dbResult.affectedRows > 0){
                    console.log("Unlocking card, resetting tries");
                }else{
                    console.log("Error on resetting tries");
                }
            })
        }

        card.updateActiveStatus(req.body.active, req.body.card_number, function(err, dbResult){

            if(err){
                return res.json(err);
            }
            
            if(dbResult.affectedRows > 0){
                res.json({status:"success",message:"Successfully modified card's status"});
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
                res.json({status:"success", message:"Successfully added new card"});
            }
        });
    }else{
        res.json({message:"Please fill all fields"});
    }
}

const authenticate = (req, res) => {
    if(req.body.card_number && req.body.pin){
        card.getByNumber(req.body.card_number, function(err, dbResult){
            if(err){
                return res.send(err);
            }

            if(dbResult.length > 0){

                if(dbResult[0].active === 0){
                    return res.json({status:"error",message:"Card is locked!"});
                }

                bcrypt.compare(req.body.pin, dbResult[0].pin.toString(), (err, match)=>{
                    if(err){
                        return res.json(err);
                    }
                    if(match){
                        console.log("Successfully authenticated!");
                        return res.json({status:"success",message:"Successfully authenticated!"});
                    }else{
                        console.log("Invalid pin code or card number!");

                        if(dbResult[0].tries >= 2 && dbResult[0].active === 1){
                            card.updateActiveStatus(0, req.body.card_number, (err, dbResult) =>{
                                if(err){
                                    console.log(err);
                                }
    
                                if(dbResult){
                                    console.log(dbResult);
                                }

                                res.json({status:"error",message:"Card deactivated!"});
                            })
                        }else{
                            card.updateTries(dbResult[0].tries + 1, req.body.card_number, (err, dbResult)=>{
                                if(err){
                                    console.log(err);
                                }
    
                                if(dbResult.affectedRows > 0){
                                    console.log("Incremented tries");
                                }else{
                                    console.log("Error on incrimenting tries");
                                }
    
                                res.json({status:"error",message:"Invalid pin code!"});
                            })
                        }
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
