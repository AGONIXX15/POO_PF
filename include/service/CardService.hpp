#pragma once
#include "../models/CardModel.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


class CardService {
    public:
        std::string filename;
        CardService(CardModel card);
        bool Find(int number);
        void Add(CardModel card);
        void Remove(int number);
        void Update(int number);
        void Read();
};
