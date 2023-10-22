#ifndef UNTITLED4_MATRIX_H
#define UNTITLED4_MATRIX_H
#pragma once


class matrix{
public:
    matrix(int m_rows, int m_columns);
    int Rows();
    int Columns();
    bool empty();
    void reshape(int new_rows, int new_columns);

private:
    double *ptr;
    int rows;
    int columns;
};
#endif //UNTITLED4_MATRIX_H
