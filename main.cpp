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

    std::cout << "new num of rows: " << m.Rows() << "\n";

    linalg::matrix init0{{1,1,1}, {1,1,1}, {1,1,1}};
    linalg::matrix init1{{2,2,2},{2,2,2},{2,2,2}};
    linalg::matrix init2{{7, 8, 9999}, {1,2,3}, {3,2,1}, {1, 1, 1}};
    linalg::matrix init3{{1, 2, 3}, {1, 1, 1}, {5, 7, 4}};
    std::cout << "num of rows: " << init2.Rows() << "\t" << "num of columns: " << init2.Columns() << "\n";
    std::cout << "num of rows: " << init3.Rows() << "\t" << "num of columns: " << init3.Columns() << "\n";

    (init2 * init3).print();
    init0 += init1;
    init0.print();
    init3.print();
    std::cout << init3.det() << std::endl;

    init3.gaus_forward();
    init3.print();

    return 0;
}