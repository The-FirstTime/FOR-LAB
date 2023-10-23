#ifndef UNTITLED4_MATRIX_H
#define UNTITLED4_MATRIX_H
#pragma once

namespace linalg {
    class matrix {
    public:
        matrix(int m_rows, int m_columns);
        matrix();
        matrix(int m_rows);
        matrix(matrix const &obj);

        int Rows();

        int Columns();

        bool empty();

        void reshape(int new_rows, int new_columns);


    private:
        double *ptr;
        int rows;
        int columns;
    };
}
#endif //UNTITLED4_MATRIX_H
