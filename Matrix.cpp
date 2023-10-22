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