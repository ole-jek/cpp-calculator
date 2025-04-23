// В этом файле только функция main и #include-директивы.
#include "calculator.h"
#include <iostream>
int main() {
    bool calc_success = RunCalculatorCycle();
    if(calc_success){
        std::cout<<"All good"<<std::endl;
    } else {
        std::cout<<"Something's wrong. I can feel it"<<std::endl;
    }
}