const emailvalidator = require("email-validator");
const { json } = require("express/lib/response");
const account = require("../models/accountModel");
const user = require("../models/userModel");

const getAll = (req, res) => {
    account.get(function(err, dbResult){
        if(err){
            return res.json(err);
        }else{
            return res.json(dbResult);
        }
    });
}

const getById = (req, res) => {
    account.getById(req.params.id,function(err, dbResult){
        if(err){
            return res.json(err);
        }else{
            return res.json(dbResult);
        }
    });
}

const getOwnedAccounts = (req, res) => {
    account.getByUserId(req,function(err, dbResult){
        if(err){
            return res.json(err);
        }else{
            return res.json(dbResult);
        }
    });
}

const addAccount = (req, res) => {
    if(req.userId){
        account.add(req.userId,function(err, dbResult){
            if(err){
                console.log(err);
                return res.json(err);
            }else{
                if(dbResult.affectedRows > 0){
                    return res.json({status:"success",message:"New account added succesfully!"});
                }else{
                    return res.json({status:"error"});
                }
            }
        });
    }
}

const addUserToAccount = (req, res) => {
    if(emailvalidator.validate(req.body.email)){
        user.getByEmail(req.body.email,function(err, dbResult){
            if(err){
                return res.json(err);
            }
            if(dbResult.length > 0){
                account.addUser(dbResult[0].user_ID,req.body.account,function(err, dbResult){
                    if(err){
                        return res.json(err);
                    }else{
                        return res.json({status:"success",message:req.body.email+" now has access to account "+req.body.account+"."});
                    }
                });
            }else{
                return res.json({status:"error",message:"Requested email not found."});
            }
        });
        
    }
}

module.exports = {
    getAll,
    getById,
    getOwnedAccounts,
    addAccount,
    addUserToAccount,

}
