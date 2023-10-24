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

linalg::matrix::matrix(linalg::matrix& other) noexcept {
    ptr = other.ptr;
    rows = other.rows;
    columns = other.columns;
    other.ptr = nullptr;
    other.rows = 0;
    other.columns = 0;
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
    for(auto x: list){
        columns = x.size();
    }
    ptr = new double [columns * rows];
    int i = 0, j = 0;
    for (auto row: list){
        if (row.size() != columns){
            throw std::invalid_argument("Invalid initializer list");
        }
        for(auto col: row){
            ptr[i*columns + j] = col;
            j++;
            j %= columns;
        }
        i++;
    }
}

void linalg::matrix::print() {
    int max = 0, n = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (ptr[i*columns + j] > max) {
                max = ptr[i*columns + j];
            }
        }
    }
    for(;max>1; n++){
        max/=10;
    }
    std::cout << "Matrix: " << std::endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            std::cout.width(n+2);
            std::cout << ptr[i*columns + j];
        }
        std::cout << std::endl;
    }
}

/**int linalg::matrix::operator() (int i, int j){
    return ptr[i*columns + j];
}**/

double& linalg::matrix::operator()(int row, int column) {
    return ptr[row * columns + column];
}


void linalg::matrix::operator=(linalg::matrix const &obj){
    if (rows == obj.rows && columns == obj.columns){
        for(int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                ptr[i*columns + j] = obj.ptr[i*columns + j];
            }
        }
    }
    else throw std::invalid_argument("Wrong size");
}

linalg::matrix linalg::operator+(const matrix& x, const matrix& y){
    if(x.rows!=y.rows||x.columns!=y.columns){
        throw std::runtime_error("Matrices cannot be added.\n");
    }
    linalg::matrix res(x.rows, x.columns);
    for(int i=0; i < x.rows * x.columns; i++) {
        res.ptr[i] = x.ptr[i] + y.ptr[i];
    }
    return res;
}

linalg::matrix linalg::operator-(const matrix& x, const matrix& y){
    if(x.rows!=y.rows||x.columns!=y.columns){
        throw std::runtime_error("Matrices cannot be added.\n");
    }
    linalg::matrix res(x.rows, x.columns);
    for(int i=0; i < x.rows * x.columns; i++) {
        res.ptr[i] = x.ptr[i] - y.ptr[i];
    }
    return res;
}

linalg::matrix linalg::operator*(const matrix& x, const matrix& y){
    if(x.columns != y.rows){
        throw std::runtime_error("Matrices cannot be multyplied.\n");
    }
    linalg::matrix res(x.rows, y.columns);
    for(int i=0; i < x.rows; i++) {
        for(int j = 0; j < y.columns; j++){
            for(int r = 0; r < x.columns; r++){
                res(i,j) += x.ptr[i * x.columns+r] * y.ptr[r*y.columns + j];
            }
        }
    }
    return res;
}

linalg::matrix& linalg::matrix::operator+=(const matrix& x){
    *this=*this + x;
    return *this;
}

linalg::matrix& linalg::matrix::operator-=(const matrix& x){
    *this=*this - x;
    return *this;
}

linalg::matrix& linalg::matrix::operator*=(const matrix& x){
    *this=(*this)*x;
    return *this;
}

linalg::matrix& linalg::matrix::operator*=(double a){
    *this=(*this)*a;
    return *this;
}

linalg::matrix linalg::matrix::operator*(double a){
    matrix res(*this);
    for(int i=0; i < this->rows * this->columns; i++)
        res.ptr[i] *= a;
    return res;
}

linalg::matrix linalg::operator*(double a, const matrix& x){
    linalg::matrix res(x);
    for(int i=0; i< x.rows * x.columns; i++)
        res.ptr[i] *= a;
    return res;
}

bool linalg::operator==(const matrix& x, const matrix& y) noexcept{
    if(x.rows!=y.rows||x.columns!=y.columns){
        return false;
    }
    for(int i=0; i < x.rows * x.columns; i++){
        if(x.ptr[i] != y.ptr[i]) return false;
    }
    return true;
}


bool linalg::operator!=(const linalg::matrix& x, const linalg::matrix& y) noexcept{
    return !(x==y);
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
void linalg::matrix::swap_rows(int row_index) {
    for (int i = row_index + 1; i < rows; i++) {
        if (ptr[i*columns + row_index] != 0) {
            for(int j = 0; j < columns; j++) {
                std::swap(ptr[row_index*columns + j], ptr[i*columns + j]);
            }
        }
    }
}

double linalg::matrix::norm() {
    double result = 0.0;
    for (int i = 0; i < rows * columns; i++) {
        result += pow(std::abs(ptr[i]), 2);
    }
    result = sqrt(result);
    return result;
}

double linalg::matrix::trace() {
    double trace = 0.0;
    int min_dim = std::min(rows, columns);
    for (int i = 0; i < min_dim; i++) {
        trace += ptr[i * columns + i];
    }
    return trace;
}

double linalg::matrix::det() {
    if (rows != columns) {
        throw std::invalid_argument ("Wrong matrix size");
    }
    int n = rows;

    // Приведем матрицу к треугольному виду
    linalg::matrix m = (rows, columns);
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            m.ptr[i*columns + j] = ptr[i*columns + j];
        }
    }
    m.gaus_forward();
    // Вычислим определитель как произведение диагональных элементов
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        det *= m.ptr[i * n + i];
    }

    return det;
}


void linalg::matrix::gaus_forward() {/*
    int n = std::min(rows, columns);
    for (int i = 0; i < rows; i++) {
        if(i > n) {
            if (ptr[i * columns + n] == 0) {
                // Если на главной диагонали встречается ноль, меняем строки местами
                swap_rows(i);
            }
        }
        if (ptr[i * columns + i] == 0) {
            // Если на главной диагонали встречается ноль, меняем строки местами
            swap_rows(i);
        }

        if (i > n){ i = n;}
        for (int j = i + 1; j < n; j++) {
            double factor = ptr[j*columns + i] / ptr[i*columns + i];

            for (int k = i; k < columns; k++) {
                ptr[j*columns + k] -= ptr[i*columns + k] * factor;
            }
        }
    }
    */

    int n = rows;

    for (int col = 0; col < n - 1; col++) {
        for (int row = col + 1; row < n; row++) {
            double factor = ptr[row * n + col] / ptr[col * n + col];

            for (int k = col; k < n; k++) {
                ptr[row * n + k] -= ptr[col * n + k] * factor;
            }
        }
    }


}


void linalg::matrix::gaus_back() {
    int n = columns;
    for (int i = rows - 1; i > 0; i--) {
        if (i > n){i = n;}
        for (int j = i - 1; j >= 0; j--) {
            while (ptr[i*columns + n] == 0){
                i--;
                if (i<0){break;}
            }
            double factor = ptr[j*columns + i] / ptr[i*columns + i];

            for (int k = columns - 1; k >= 0; k--) {
                ptr[j*columns + k] -= ptr[i*columns + k] * factor;
            }
        }
    }
}


linalg::matrix concatenate(linalg::matrix m1, linalg::matrix m2){
    linalg::matrix result (m1.Rows(), m1.Columns() + m2.Columns());
    for (int i = 0; i < m1.Rows(); i++){
        for (int j = 0; j < m1.Columns(); j++){
            result(i,j) = m1(i, j);
        }
        for (int j = 0; j < m2.Columns(); j++){
            double temp = m2(i, j);
            result(i, j+m1.Columns()) = temp;
        }
    }
    return result;
}


linalg::matrix transpose(linalg::matrix m){
    linalg::matrix result(m.Columns(), m.Rows());
    for (int i = 0; i < result.Rows(); i++){
        for (int j = 0; j < result.Columns(); j++){
            result(i, j) = m(j, i);
        }
    }
    return result;
}




/*linalg::matrix invert(linalg::matrix matr) {
    // Implementation of matrix inversion using Gauss-Jordan elimination
    int rows = matr.Rows();
    int columns = matr.Columns();

    if (rows != columns) {
        throw std::runtime_error("Matrix is not square");
    }

    linalg::matrix a = matr;
    linalg::matrix result(rows, rows);
    result.setIdentity();

    for (int i = 0; i < rows; ++i) {
        int pivot_row = i;
        double pivot_element = a(i, i);

        // Find pivot element with maximum absolute value
        for (int j = i + 1; j < rows; ++j) {
            if (std::abs(a(j, i)) > std::abs(pivot_element)) {
                pivot_row = j;
                pivot_element = a(j, i);
            }
        }

        // Swap rows to bring pivot element to diagonal
        if (pivot_row != i) {
            for (int j = i; j < columns; ++j) {
                std::swap(a(i, j), a(pivot_row, j));
                std::swap(b(i, j), b(pivot_row, j));
            }
        }

        // Scale pivot row to have a pivot element of 1
        double scale_factor = 1.0 / pivot_element;
        for (int j = i; j < columns; ++j) {
            a(i, j) *= scale_factor;
            b(i, j) *= scale_factor;
        }

        // Eliminate other rows
        for (int j = 0; j < rows; ++j) {
            if (j != i) {
                double factor = a(j, i);
                for (int k = i; k < columns; ++k) {
                    a(j, k) -= factor * a(i, k);
                    b(j, k) -= factor * b(i, k);
                }
            }
        }
    }

    return b;
}
*/