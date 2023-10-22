#include <iostream>
#include "Matrix.h"


int main(){
    matrix obj(6, 2);
    std::cout << obj.Rows() << std::endl;
    std::cout << obj.Columns() << std::endl;

    if (obj.empty()){
        std::cout << "Matrix is empty";
    }

    obj.reshape(3,4);
    std::cout << obj.Rows() << std::endl;
    std::cout << obj.Columns() << std::endl;

    obj.reshape(3,5);

    return 0;
}