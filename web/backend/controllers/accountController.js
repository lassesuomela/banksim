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
    account.getByUserId(req.userId,function(err, dbResult){
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
    if(emailvalidator(req.body.email)){
        let uid = 0;
        user.getByEmail(req.body.email,function(err, dbResult){
            if(err){
                return res.json(err);
            }
            if(dbResult.length > 0){
                uid = dbResult[0].user_ID;
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