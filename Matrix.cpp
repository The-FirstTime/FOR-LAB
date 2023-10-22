#include "Matrix.h"
#include <iostream>




matrix::matrix(int m_rows, int m_columns){
    rows = m_rows;
    columns = m_columns;
    ptr = new double [m_rows * m_columns];
}

int matrix::Rows(){
    return(matrix::rows);
}

int matrix::Columns(){
    return(matrix::columns);
}

bool matrix::empty(){
    return (rows * columns == 0);
}

void matrix::reshape(int new_rows, int new_columns){
    if (new_rows * new_columns != rows * columns){
        throw std::invalid_argument ("Wrong new size");
    }
    else {
        rows = new_rows;
        columns = new_columns;
    }
}