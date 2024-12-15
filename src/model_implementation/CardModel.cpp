#include "../../include/models/CardModel.hpp"  
#include <string>
#include <iostream>

CardModel::CardModel(int number, int cvv, float balance, CardTypeModel type){
    this->number = number;
    this->cvv = cvv;
    this->balance = balance;
    this->type = type;
}


std::string CardModel::GetBrand(){
    return this->brand;
}

int CardModel::GetNumber(){
    return this->number;
}

int CardModel::GetCvv(){
    return this->cvv;
}

float CardModel::GetBalance(){
    return this->balance;
}

CardTypeModel CardModel::GetType(){
    return this->type;
}

void CardModel::Transfer(float amount){
    if(this->type.GetType() == "debit"){
        if(this->balance < amount){
            std::cout << "Insufficient funds" << std::endl;
        }
        else{
            this->balance -= amount;
        }
    }
    else{
        if(!this->type.GetCreditLimit()){
            std::cout << "Credit limit exceeded" << std::endl;
        }
        else if(this->type.GetCreditLimit() < amount){
            std::cout << "Insufficient funds" << std::endl;
        }
        else{
            this->type.SetCreditLimit(this->type.GetCreditLimit() - amount);
            this->type.SetInterestRate(this->type.GetInterestRate() + amount * 0.1);
        }
    }
}

void CardModel::SaveFunds(float amount, bool is_credit){
    if(is_credit){
        this->type.PayDoubts(amount);
    }
    else{
        this->balance += amount;
    }
}

void CardModel::WithdrawFunds(float amount, bool is_credit){
    if(is_credit){
        if(this->type.GetCreditLimit() < amount){
            std::cout << "Insufficient funds" << std::endl;
        }
        else{
            this->type.SetCreditLimit(this->type.GetCreditLimit() - amount);
            this->type.SetInterestRate(this->type.GetInterestRate() + amount * 0.1);
        }
    }
    else{
        if(this->balance < amount){
            std::cout << "Insufficient funds" << std::endl;
        }
        else{
            this->balance -= amount;
        }
    }
}

std::string CardModel::ToString(){
    if(this->type.GetType() == "credit"){
        return this->brand + "," + std::to_string(this->number) + "," + std::to_string(this->cvv) + "," + std::to_string(this->balance) + "," + this->type.GetType() + "," + std::to_string(this->type.GetCreditLimit()) + "," + std::to_string(this->type.GetInterestRate()) + "\n";
    }
    else{
        return this->brand + "," + std::to_string(this->number) + "," + std::to_string(this->cvv) + "," + std::to_string(this->balance) + "," + this->type.GetType() + "\n";
    }
}