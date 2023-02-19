#include <iostream>
#include "Calculator.hpp"
using namespace std;


int main(int argc, char* argv[]){
    Calculator calc;
    int a = 3;
    cout << "coucou, on additionne : " << calc.addition(a, 5) << endl;
    return 0;
};