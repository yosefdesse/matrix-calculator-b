
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ostream>
#include <istream>
#include <vector>

using namespace std;


namespace zich
{
    class Matrix
    {
        private:


        public:
            // unsigned int row;
            // unsigned int col;
            int row;
            int col;
            vector<vector<double>> matrix; 
            Matrix();   
            Matrix(Matrix& other);   
            Matrix(const vector<double> &vec, int row , int col);
            ~Matrix();
            bool check(const Matrix& mtx)const;
            // bool check(Matrix& mtx1 , Matrix& mtx2);

            Matrix& operator+();
            Matrix& operator+(const Matrix &mtx1 );
            Matrix& operator-();           
            Matrix& operator+=(const Matrix &mtx1);
            Matrix& operator-(const Matrix &mtx1 );
            Matrix& operator-=(const Matrix &mtx1);
            Matrix& operator++();         
            Matrix& operator--();
            Matrix& operator--(const int i);
            Matrix& operator++(const int i);




            bool operator>(const Matrix &mtx1) ;
            bool operator>=(const Matrix &mtx1) ;
            bool operator<(const Matrix &mtx1) ;
            bool operator<=(const Matrix &mtx1);
            bool operator==(const Matrix &mtx1)const;
            // friend bool operator==(const Matrix &mtx1 , const Matrix &mtx2);
            bool operator!=(const Matrix &mtx1);
         

            friend std::ostream &operator<<(std::ostream &os , const Matrix &mtx1);
            // friend std::ostream &operator<<(std::ostream &os, const Matrix &mtx1);
            friend std::istream &operator>>(std::istream &is , Matrix &mtx1);
            // friend std::istream &operator>>(std::istream &is, Matrix &mtx);
           


            // friend Matrix operator*(int scalar , Matrix mtx  );
            friend Matrix operator*(int scalar, zich::Matrix mtx);
            Matrix operator*(const Matrix &mtx1 );
            Matrix& operator*(double num) ;
            Matrix& operator*=( double scalar );
            Matrix& operator*=(const Matrix &mtx1 );

    };
}