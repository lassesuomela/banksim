const user = require("../models/userModel");
const bcrypt = require("bcrypt");
const emailvalidator = require("email-validator");
const { json } = require("express/lib/response");
const jwt = require("../config/jwtAuth");

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
    if(emailvalidator.validate(req.body.email) && req.body.password){
        user.getByEmail(req.body.email, function(err, dbResult){
            if(err){
                console.log(err);
                res.json(err);
            }else{
                if(dbResult.length > 0){
                    bcrypt.compare(req.body.password, dbResult[0].password.toString(), (err, match)=>{
                        if(err){
                            res.json(err);
                        }
                        if(match){
                            const token = jwt.generateToken(dbResult[0].user_ID);
                            console.log("Created token: ",token);
                            res.status(200).json({status:"success",message:"Successfully logged in.",token:token});
                        }else{
                            console.log("Invalid email or password!");
                            res.json({status:"error",message:"Invalid email or password."});
                        }
                    });
                }else{ 
                    console.log("No user found with this email");
                    res.json({status:"error",message:"No user found with this email."});
                }
            };
        });
    }else{
        res.json({status:"error",message:"Please enter email and password."});
    }
}

const userRegister = (req, res) => {
    if(emailvalidator.validate(req.body.email) && req.body.password && req.body.address && req.body.fname && req.body.lname && req.body.phone){
        user.add(req, function(err, result){
            if(err){
                if(err.errno === 1062){
                    res.json({status:"error",message:"Email already exists."});
                }
            }else{
                console.log("Successfully registered.");
                res.redirect("/login");
            }
        });
    }else{
        res.json({message:"Please fill all fields."});
    }
}

module.exports = {
    getAll,
    userLogin,
    userRegister,
    getById
}
