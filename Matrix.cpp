//
// Created by Арсений  Ростовщиков on 21.10.2023.
//

#include "Matrix.h"

int Matrix::rows(){
    return m_rows;
};

int Matrix::columns(){
    return m_columns;
};

bool Matrix::empty(){
    return m_rows * m_columns == 0;
};

void reshape(int new_rows, int new_columns){

};