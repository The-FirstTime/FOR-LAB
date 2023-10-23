#include "Matrix.h"
#include <iostream>




linalg::matrix::matrix(int m_rows, int m_columns){
    rows = m_rows;
    columns = m_columns;
    ptr = new double [m_rows * m_columns];
}

linalg::matrix::matrix(){
    rows = 0;
    columns = 0;
    ptr = new double [rows * columns];
}

linalg::matrix::matrix(int m_rows){
    rows = m_rows;
    columns = 1;
    ptr = new double [rows * columns];

}

linalg::matrix::matrix(const matrix &obj) {
    rows = obj.rows;
    columns = obj.columns;
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            ptr[i*j + j] = obj.ptr[i*j + j];
        }
    }
}

linalg::matrix::matrix(std::initializer_list<double> list){
    columns = list.size();
    rows = 1;
    ptr = new double [columns * rows];
    int i = 0;
    for (auto elem: list){
        ptr[i] = elem;
        i++;
    }
}

linalg::matrix::matrix(std::initializer_list<std::initializer_list<double>> list){
    rows = list.size();
    columns = list.begin()->size();
    ptr = new double [columns * rows];
    int i = 0, j = 0;
    for (auto row: list){
        if (row.size() != columns){
            throw std::invalid_argument("Invalid initializer list");
        }
        for(auto elem: row){
            ptr[i*j + j] = elem;
            j++;
            j %= columns;
        }
        i++;
    }
}


int linalg::matrix::Rows(){
    return(matrix::rows);
}

int linalg::matrix::Columns(){
    return(matrix::columns);
}

bool linalg::matrix::empty(){
    return (rows == 0 || columns == 0);
}

void linalg::matrix::reshape(int new_rows, int new_columns){
    if (new_rows * new_columns != rows * columns){
        throw std::invalid_argument ("Wrong new size");
    }
    else {
        rows = new_rows;
        columns = new_columns;
    }
}