#include "ImageGenerator.hpp"
#include "Calculator.hpp"
using namespace std;

previous_main(){
    Calculator calc;
    int a = 3;
    cout << "coucou, on additionne : " << calc.addition(a, 5) << endl;
    return 0;
};

int main(int argc, char* argv[]){
    ImageGenerator imgen; 
    imgen.parse_params(argc, argv);
    imgen.generate_image();

    return 0;
}