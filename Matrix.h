#ifndef UNTITLED4_MATRIX_H
#define UNTITLED4_MATRIX_H
#pragma once

#include <initializer_list>

namespace linalg {
    class matrix {
    public:
        //constructors:
        matrix(int m_rows, int m_columns);
        matrix();
        matrix(int m_rows);
        matrix(matrix const &obj);//copy constructor
        matrix(matrix& other)noexcept; //move constructor
        //initializer_list
        matrix(std::initializer_list<double> list);
        matrix(std::initializer_list<std::initializer_list<double>> list);

        //methods:
        int Rows();
        int Columns();
        void print();
        bool empty();
        void reshape(int new_rows, int new_columns);
        double norm();

        //operators:
       // int operator()(int i, int j);
        void operator=(matrix const &obj);
        double& operator()(int row, int column);
        void operator=(std::initializer_list<std::initializer_list<double>> list);

    private:
        double *ptr;
        int rows;
        int columns;
    };


}

linalg::matrix concatenate(linalg::matrix m1, linalg::matrix m2);
#endif //UNTITLED4_MATRIX_H
