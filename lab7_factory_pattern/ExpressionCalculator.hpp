#pragma once

#include <iostream>
#include <cstring>
#include "CompositeClasses/Op.hpp"
#include "CompositeClasses/base.hpp"
#include "CompositeClasses/Div.hpp"
#include "CompositeClasses/Mult.hpp"
#include "CompositeClasses/Pow.hpp"
#include "CompositeClasses/Rand.hpp"
#include "CompositeClasses/Sub.hpp"
#include "CompositeClasses/Add.hpp"


class ExpressionCalculator
{
    private:
        bool checkifdigit(std::string str){
            for (char a : str){
                if (!isdigit(a)){
                    return false;
                }
            }
            return true;
        }

        Base* result = nullptr;
    public: 
        Base* parse(char** argv, int length)
        {
            result = checkifdigit(argv[1]) ? new Op((std::stoi(argv[1]))): nullptr;
            if(!result){return nullptr;}
            char* c;

            for (int i = 2; i < length-1; i++)
            {
                c = argv[i];
                if (strcmp(c,"+") == 0)
                {
                    if(checkifdigit(argv[i+1])){
                        result = new Add(result, new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    return nullptr;
                }
                else if (strcmp(c, "-") == 0)
                {
                    if(checkifdigit(argv[i+1])){
                        result = new Sub(result, new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    return nullptr;
                }
                else if (strcmp(c, "**") == 0)
                {
                    if(checkifdigit(argv[i+1])){
                        result = new Pow(result, new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    return nullptr;
                }
                else if (strcmp(c, "/") == 0)
                {
                    if(checkifdigit(argv[i+1])){
                        result = new Div(result, new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    return nullptr;
                }
                else if (strcmp(c, "*") == 0)
                {
                    if(checkifdigit(argv[i+1])){
                        result = new Mult(result, new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    return nullptr;
                }
                else
                {
                    return nullptr;
                }
            }
            return result;
        }

};