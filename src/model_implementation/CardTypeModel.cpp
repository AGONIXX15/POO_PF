#include "../../include/models/CardTypeModel.hpp"
#include <string>
#include <iostream>

std::string CardTypeModel::GetType(){
    return this->type;
}

float CardTypeModel::GetCreditLimit(){
    if(this->is_credit){
        return this->credit_limit;
    }
    else{
        std::cout << "Card is not a credit card" << std::endl;
        return -1;
    }
}

float CardTypeModel::GetInterestRate(){
    if(this->is_credit){
        return this->interest_rate;
    }
    else{
        std::cout << "Card is not a credit card" << std::endl;
        return -1;
    }
}

void CardTypeModel::SetType(bool is_credit, bool is_debit){
    if(is_credit && is_debit){
        std::cout << "Card cannot be both credit and debit" << std::endl;
    }
    else if(!is_credit && !is_debit){
        std::cout << "Card must be either credit or debit" << std::endl;
    }
    else{
        this->is_credit = is_credit;
        this->is_debit = is_debit;
        if(is_credit){
            this->type = "credit";
        }
        else{
            this->type = "debit";
        }
    }
}

void CardTypeModel::SetCreditLimit(float credit_limit){
    if (!this->is_credit){
        std::cout << "Card is not a credit card" << std::endl;
        return;
    }
    this->credit_limit = credit_limit;
}

void CardTypeModel::SetInterestRate(float interest_rate){
    if (!this->is_credit){
        std::cout << "Card is not a credit card" << std::endl;
        return;
    }
    this->interest_rate = interest_rate;
}

void CardTypeModel::PayDoubts(float amount){
    if (!this->is_credit){
        std::cout << "Card is not a credit card" << std::endl;
        return;
    }
    if(this->interest_rate < amount){
        this->interest_rate -= amount ;
    }
    else{
        this->interest_rate = 0;
        this->credit_limit = 1000.56;
    }
}
