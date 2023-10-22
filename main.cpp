#include <iostream>
#include "Matrix.h"


int main(){
    matrix obj(6, 2);
    std::cout << obj.Rows() << std::endl;
    std::cout << obj.Columns() << std::endl;
    
    return 0;
}