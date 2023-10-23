#include <iostream>
#include "Matrix.h"


int main(){
    //defolt constructor
    linalg::matrix obj(6, 2);
    //test some methods
    std::cout << obj.Rows() << std::endl;
    std::cout << obj.Columns() << std::endl;

    if (obj.empty()){
        std::cout << "Matrix is empty";
    }

    obj.reshape(3,4);
    std::cout << obj.Rows() << std::endl;
    std::cout << obj.Columns() << std::endl;

    //constructor without arguments
    linalg::matrix object;

    if (object.empty()){
        std::cout << "Matrix is empty" << std::endl;
    }

    //constructor with single argument
    linalg::matrix m(5);
    std::cout << "number of rows: " << m.Rows() << std::endl;

    //catching exeption
    try{m.reshape(1, 5);} catch (const std::invalid_argument& ex) {
        std::cerr << "Wrong new size" << "\n";
        return 1;
    };

    std::cout << "new num of rows: " << m.Rows();
    
    return 0;
}