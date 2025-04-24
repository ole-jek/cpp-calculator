#include <iostream>
#include <cmath>
#include <string>
#include "calculator.h"

using namespace std;

bool ReadNumber (Number& result){
    cin>>result;
    if (cin.fail()) {
        return false;
    } 
    return true;
}

bool RunCalculatorCycle(){
    Number number = 0;
    string operation;
    Number memory_num = 0;
    Number new_number = 0;
    int count = 0;
    if (!ReadNumber(number)){
        cerr<<"Error: Numeric operand expected";
        return false;
    } else {
        while (operation != "q") {
            cin>>operation;
            if (operation == "+"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                }
                number += new_number;
            } else if (operation == "="){
                cout<<number<<endl;
            } else if (operation == "-"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } 
                number -= new_number;
            } else if (operation == "*"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } 
                number *= new_number;
            } else if (operation == "/"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                } 
                number /= new_number;
            } else if (operation == "**"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                }
                number = pow(number, new_number);
            } else if (operation == "c"){
                number = 0;
                count = 0;
            } else if (operation == ":"){
                if (!ReadNumber(new_number)){
                    cerr<<"Error: Numeric operand expected";
                    return false;
                }
                number = new_number;
            } else if (operation == "s"){
                memory_num = number;
                ++count;
            } else if (operation == "l"){
                if (count == 0) {
                    cerr<<"Error: Memory is empty";
                    return false; 
                }
                number = memory_num;
            } else if (operation != "q") {
                cerr<<"Error: Unknown token "<<operation;
                return false;
            }
        } 
        return true;
    }
}
