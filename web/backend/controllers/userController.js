const user = require("../models/userModel");
const bcrypt = require("bcrypt");
const { json } = require("express/lib/response");

const getAll = (req, res) => {
    user.get(function(err,dbResult){
        if(err){
            res.json(err);
        }else{
            res.json(dbResult);
        }
    });
}

const getById = (req, res) => {
    if(req.params.id){
        user.getById(req.params.id, function(err,dbResult){
            if(err){
                res.json(err);
            }else{
                res.json(dbResult);
            }
        });
    }
}

const userLogin = (req, res) => {
    if(req.body.email && req.body.password){
        user.getByEmail(req.body.email, function(err, dbResult){
            if(err){
                res.json(err);
            }else{
                if(dbResult.length > 0){
                    bcrypt.compare(req.body.password, dbResult[0].password.toString(), (err, match)=>{
                        if(err){
                            res.json(err);
                        }
                        if(match){
                            console.log("Successfully logged in!");
                            res.json({message:"Successfully logged in!"});
                        }else{
                            res.json({message:"Invalid email or password!"});
                            console.log("Invalid email or password!");
                        }
                    });
                }else{ 
                    console.log("No user found with this email");
                    res.json({message: "No user found with this email"});
                }
            };
        });
    }else{
        res.json({message:"Please enter email and password."});
    }
}

const userRegister = (req, res) => {
    if(req.body.email && req.body.password && req.body.address && req.body.fname && req.body.lname && req.body.phone){
        user.add(req, function(err, result){
            if(err){
                res.json(err);
            }else{
                res.json({status:"success",affectedRows: result.affectedRows});
            }
        });
    }else{
        res.json({message:"Please fill all fields"});
    }
}

module.exports = {
    getAll,
    userLogin,
    userRegister,
    getById
}