#include <iostream>
#include <cmath>
#include <string>
#include "calculator.h"

using Number = double;
using namespace std;

bool ReadNumber (Number& result){
    cin>>result;
    if (cin.fail()) {
        return false;
    } else {
        return true;
    }
}

bool RunCalculatorCycle(){
    Number number;
    string operation;
    Number memory_num;
    Number new_number;
    int count = 0;
    if (!ReadNumber(number)){
        cerr<<"Error: Numeric operand expected";
        return false;
    } else {
        while (operation != "q") {
            cin>>operation;
            if (operation == "+"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number += new_number;
                }
            } else if (operation == "="){
                cout<<number<<endl;
            } else if (operation == "-"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number -= new_number;
                }
            } else if (operation == "*"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number *= new_number;
                }
            } else if (operation == "/"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number /= new_number;
                }
            } else if (operation == "**"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number = pow(number, new_number);
                }
            } else if (operation == "c"){
                number = 0;
                count = 0;
            } else if (operation == ":"){
                if (!(cin>>new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } else {
                number = new_number;
                }
            } else if (operation == "s"){
                memory_num = number;
                ++count;
            } else if (operation == "l"){
                if (count != 0) {
                    number = memory_num; 
                } else {
                    cerr<<"Error: Memory is empty";
                    return false;
                }
            } else if (operation != "q") {
                cerr<<"Error: Unknown token "<<operation;
                return false;
            }
        } 
        return true;
    }
}
