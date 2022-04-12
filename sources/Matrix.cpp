



#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
# include "Matrix.hpp"


// using zich::Matrix;
using namespace zich;
using namespace std;
   
   

    Matrix :: Matrix(const vector<double> &vec, int row , int col) : row(row) , col(col)
    {
        if(vec.size()!= row*col)
        {
            throw ("the vector size need to be matched to the size of multiplying row  and column");
           
        }
        if(row<0 || col<0)
        {
            throw ("your input for row and column should be greater than 0");
        }
        this->row = row;
        this->col = col;
        unsigned int vec_index=0;
        for(unsigned int i=0 ; i<row ; i++)
        {
            for(unsigned int j=0 ; j<col ; j++)
            {
                this->matrix[i][j]=vec[vec_index];
                vec_index++;
            }
        }

    };

    Matrix::Matrix(Matrix& other){
            this->row = other.row;
            this->col=other.col;
            for(unsigned int i=0 ; i<other.row ; i++)
        {
            for(unsigned int j=0 ; j<other.col ; j++)
            {
                this->matrix[i][j]=other.matrix[i][j];
            }
        }
        }
    
    Matrix :: Matrix():row(0) , col(0)
    {
       
    }

    Matrix :: ~Matrix(){}

    bool Matrix::check(const Matrix& mtx)const
    {
        if((this->col != mtx.col) || (this->row != mtx.row))
        {
            return false;
        }
        return true;

    }

    // bool Matrix::check(Matrix& mtx1 , Matrix& mtx2)
    // {
    //     if((mtx1.col!=mtx2.col) || (mtx1.row!=mtx2.row))
    //     {
    //         return false;
    //     }
    //     return true;

    // }

    Matrix& Matrix::operator+()
    {
        return (*this);
    }
  
    Matrix& Matrix::operator+(const Matrix &mtx1 )
    {
        if(check(mtx1)!=true) 
        {
            throw invalid_argument("you can apply this function only on Matrices with the same  size series of nXm");
        }
        Matrix  &temp_matrix= *this ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                temp_matrix.matrix[i][j] = this->matrix[i][j] + mtx1.matrix[i][j];
            
            }
             
        }
        return temp_matrix ;

    }

    Matrix& Matrix::operator+=(const Matrix &mtx1)
    {
        
        if(check(mtx1)!=true) 
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ;j++)
            {
                this->matrix[i][j]+=mtx1.matrix[i][j];
            }
        }
        
        return (*this) ;
    }

    Matrix& Matrix::operator++(const int)
    {
        Matrix  &tamp_matrix = *this ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]++;
            }
        }

        return tamp_matrix ;

    }

    Matrix& Matrix::operator++()
    {
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]++;
            }
        }
        return (*this);
    }

    Matrix& Matrix::operator-()
    {
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]--;
            }
        }
        return (*this);

    }

    Matrix& Matrix::operator-(const Matrix &mtx1)
    {
        if(check(mtx1)!=true) 
        {
            throw invalid_argument("you can apply this function only on Matrices with the same  size series of nXm");
        }
        Matrix &temp_matrix=*this;
        for(unsigned int i=0 ; i<mtx1.row ; i++)
        {
            for(unsigned int j=0 ; j<mtx1.col ; j++)
            {
                temp_matrix.matrix[i][j]= this->matrix[i][j] - mtx1.matrix[i][j];
            
            }
             
        }
        return temp_matrix;

        
    }

    Matrix& Matrix::operator-=(const Matrix &mtx1 )
    {
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]-=mtx1.matrix[i][j];
            }
        }

        return (*this);
    }

    Matrix& Matrix::operator--(const int)
    {
        Matrix &tamp_matrix = *this ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]--;
            }
        }

        return tamp_matrix ;
    }

    Matrix& Matrix::operator--()
    {
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]--;
            }
        }
        return (*this);
    }
    
    bool Matrix::operator>(const Matrix &mtx1)
    {
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm ");
        }
        int this_sum_matrix=0;
        int mtx1_sum=0;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this_sum_matrix+=this->matrix[i][j];
                mtx1_sum+=this->matrix[i][j];
            }
        }
        if(this_sum_matrix>mtx1_sum)
        {
            return true ;
        }
        return false;

    }
    // bool Matrix::operator>(const Matrix &mtx1, const Matrix &mtx2)
    // {
    //     if(check(mtx1 ,mtx2)!)
    //     {
    //         throw("you can apply this function only on Matrices with the same  size series of nXm")
    //     }
    //     int mtx1_sum =0 ;
    //     int mtx2_sum =0 ;
    //     for(int i=0 ; i<mtx1.row ; i++)
    //     {
    //         for(int j=0 ; j<mtx1.col ; j++)
    //         {
    //             mtx1_sum+=mtx1.matrix[i][j];
    //             mtx2_sum+=mtx2.matrix[i][j];
    //         }
    //     }
    //     if(mtx1_sum > mtx2_sum)
    //     {
    //         return true;
    //     }
    //     return false ;
    // }

    bool Matrix::operator>=(const Matrix &mtx1)
    {
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        int this_sum_matrix =0 ;
        int mtx1_sum =0 ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this_sum_matrix+=this->matrix[i][j];
                mtx1_sum+=mtx1.matrix[i][j];
            }
        }
        if((this_sum_matrix > mtx1_sum||(this_sum_matrix == mtx1_sum)))
        {
            return true;
        }
        return false ;
    }

    bool Matrix::operator<(const Matrix &mtx1)
    {
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        int this_sum_matrix =0 ;
        int mtx1_sum =0 ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this_sum_matrix+=this->matrix[i][j];
                mtx1_sum+=mtx1.matrix[i][j];
                
            }
        }
        if(this_sum_matrix < mtx1_sum )
        {
            return true;
        }
        return false ;
    }

    bool Matrix::operator<=(const Matrix &mtx1)
    {
        
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        int this_sum_matrix =0 ;
        int mtx1_sum =0 ;
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this_sum_matrix += this->matrix[i][j];
                mtx1_sum+=mtx1.matrix[i][j];
            }
        }
        if((this_sum_matrix < mtx1_sum ||(this_sum_matrix == mtx1_sum)))
        {
            return true;
        }
        return false ;
    }
    
    // bool Matrix::operator==(const Matrix &mtx1 , const Matrix &mtx2)
    // {
    //     if(check(mtx1 , mtx2)!=true)
    //     {
    //         throw("you can apply this function only on Matrices with the same  size series of nXm");
    //     }
    //     for(unsigned int i=0 ; i< mtx1.row ; i++)
    //     {
    //         for(unsigned int j=0 ; j<mtx1.col ; j++)
    //         {
    //             if(mtx2.matrix[i][j] ==mtx1.matrix[i][j])
    //             {
    //                 continue;
    //             }else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return true ;

    // }

    bool Matrix::operator==(const Matrix &mtx1 )const{
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                if(this->matrix[i][j] ==mtx1.matrix[i][j])
                {
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true ;
    }

    bool Matrix::operator!=(const Matrix &mtx1)
    {
        if(check(mtx1)!=true)
        {
            throw("you can apply this function only on Matrices with the same  size series of nXm");
        }
        for(unsigned int i=0 ; i<this->row ; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)

            {
                if(this->matrix[i][j]==mtx1.matrix[i][j])
                {
                    continue;
                }else{
                    return true;
                }
            }
        }
        return false ;
    }



    Matrix operator*(int scalar, zich::Matrix mtx)
    {
        // Matrix temp_matrix = *this ;
        
        for(unsigned int i=0 ; i<mtx.row ; i++)
        {
            for(unsigned int j=0 ; j<mtx.col ; j++)
            {
                mtx.matrix[i][j]*=scalar ;
            }
        }
        return mtx;
        // vector<double> temp((size_t)( mat.row*mat.col));
        // for (size_t i = 0; i < (mat.row*mat.col); ++i)
        // {
        //     temp[i] = mat.matrix[i] * num;
        // }
        // return Matrix(temp, mat.row, mat.col);
    }

    Matrix& Matrix::operator*(double num) 
    {
        for(unsigned int i=0 ; i<this->row; i++)
        {
            for(unsigned int j=0 ; j<this->col ; j++)
            {
                this->matrix[i][j]*=num ;
            }
        }
        return *this;
        // vector<double> temp((size_t)(col*row));
        // for (size_t i = 0; i < col*row; ++i)
        // {
        //     temp[i] = matrix[i] * num;
        // }
        // return Matrix(temp, row, col);
    }


    
    // Matrix Matrix::operator*(double num) const
    // {
    //     Matrix temp_matrix = *this ;
    //     return temp_matrix;
    // }

    Matrix Matrix::operator*(const Matrix &mtx1 )
    {
         if(check(mtx1)!=true)
        {
            throw(" you can apply this function only on Matrices with the same  size series of nXm ");           
        }
        Matrix &temp_matrix = *this ;
        for(unsigned int i=0 ; i<temp_matrix.row ; i++)
        {
            for(unsigned int j=0 ; j<temp_matrix.col ; j++)
            {
                temp_matrix.matrix[i][j] =this->matrix[i][j]+mtx1.matrix[j][i]  ;
            }
        }
        return temp_matrix; 
    }

    Matrix& Matrix::operator*=( double scalar  )
    {
        Matrix &temp_matrix = *this ;
        for(unsigned int i=0 ; i<temp_matrix.row ; i++)
        {
            for(unsigned int j=0 ; j<temp_matrix.col ; j++)
            {
                temp_matrix.matrix[i][j]*=scalar ;
            }
        }
                

        return temp_matrix ;
    }
    
    Matrix& Matrix::operator*=( const Matrix &mtx1  )
    {
        if(check(mtx1)!=true)
        {
            throw(" you can apply this function only on Matrices with the same  size series of nXm ");           
        }
        Matrix &temp_matrix = *this ;
        for(unsigned int i=0 ; i<temp_matrix.row ; i++)
        {
            for(unsigned int j=0 ; j<temp_matrix.col ; j++)
            {
                temp_matrix.matrix[i][j] =this->matrix[i][j]+mtx1.matrix[j][i]  ;
            }
        }
        return temp_matrix; 
    }



    
    // ostream &operator<<(std::ostream &os, const Matrix &mtx1)
    ostream &operator<<(std::ostream &os , const Matrix &mtx1)
    {
        int help=0;
        for(unsigned int i=0 ; i<mtx1.row ; i++)
        {
            os << " [ " ;
            for(unsigned int j=0 ; j<mtx1.col ; j++)
            {
                help = mtx1.matrix[i][j];
                os << help  ;
                
            }
            os << " ] " << endl ;
        }

        return os ;
    }

    // istream &operator>>(std::istream &is, Matrix &mtx)
    istream &operator>>(std::istream &is ,  Matrix &mtx1)
    {
        return is ;
    }




    


