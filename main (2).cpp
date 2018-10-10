// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: doing overloading operator on two dimensional array by using pointer
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
void createMatrix1 (int row, int col, int num[], matrix& mat);

// Student #1
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    matrix mat1, mat2, mat3,mat4;
    cout<<"enter your mat1"<<endl;
    cin>>mat1;
    cout<<"enter your mat2"<<endl;
    cin>>mat2;
    cout<<"enter your mat3"<<endl;
    cin>>mat3;
    cout << mat1 ;
    cout<<"             ************    "<<endl;
    cout << mat2 ;
    cout<<"             ************    "<<endl;
    cout << mat3 ;
    cout<<"             ************    "<<endl;
    cout << (mat2+mat3) ;
    cout<<"             ************    "<<endl;
    cout<<(mat2+5);
     cout<<"             ************    "<<endl;
    cout << (mat3 + mat3) ;
    cout<<"             ************    "<<endl;
    cout<<(mat1*mat2);
    cout<<"             ************    "<<endl;
    cout<<transpose(mat1);
    cout<<"             ************    "<<endl;
    ++mat1;
    cout << mat1;
    cout<<"             ************    "<<endl;

    mat2+= mat3 += mat3;
    cout << mat2;

    cout<<"             ************    "<<endl;
    cout << mat2;
    cout<<"             ************    "<<endl;
    cout << mat3;
    cout<<"             ************    "<<endl;
    cout <<  (mat3 == mat2) <<endl ;
    cout<<"             ************    "<<endl;
    cout << ( mat1 != mat2 )<<endl ;
    cout<<"             ************    "<<endl;
    cout << isSymetric(mat1)<<endl ;
    cout<<"             ************    "<<endl;
    cout << isIdentity(mat1 )<<endl;
    cout<<"             ************    "<<endl;
    delete[] mat1.data;
    delete[] mat2.data;
    delete[] mat3.data;
    delete[] mat4.data;
    return 0;

}
void createMatrix (int row, int col, int num[], matrix& mat) //passing an array into pointer
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];
    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
void createMatrix1 (int row, int col, int num[], matrix& mat) // New Matrix for the function of Transpose
{
    mat.row = col;  // The New Matrix rows equal the columns of the input matrix
    mat.col = row;   // The New Matrix columns equal the rows  of the input matrix
    mat.data = new int* [col];

    for (int i = 0; i < col; i++)
        mat.data[i] = new int [row];

    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            mat.data[i][j] = num[i * row + j];
}

ostream& operator<<(ostream& os, matrix mat1) // print matrix
{
    int counter=0;
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            if(mat1.data[i][j]==-1999999){
                counter++;
            }
        }
    }
    if(counter==mat1.row*mat1.col){
        cout<<"not vaild "<<endl;
    }
    else{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            cout<< mat1.data[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    }
}
istream& operator>>(istream& is,matrix &mat1) // input matrix
{
    cout<<"number of rows of mat :";
    cin >> mat1.row;
    cout<<"number of col of mat :";
    cin >> mat1.col;
    mat1.data = new int* [mat1.row];

    for (int i = 0; i < mat1.row; i++)
        mat1.data[i] = new int [mat1.col];


    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            cout<<"enter you number of "<<i<<j<<":";
            cin >> mat1.data[i][j];
        }
    }
}
void operator++(matrix& mat1) // This function will increase the data of the matrix by 1
{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            mat1.data[i][j]++;
        }
    }

}
void operator--(matrix& mat1) // This function will decrease the data of the matrix by 1
{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            mat1.data[i][j]--;
        }
    }
}
matrix operator+= (matrix& mat1, int scalar) // This function will increase the data of the matrix by number and return the output in the same matrix
{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat1;

}
matrix operator-= (matrix& mat1, int scalar) // This function will decrease the data of the matrix by number and return the output in the same matrix
{
    for (int i = 0; i < mat1.row ; i++)
    {
        for(int j = 0; j < mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat1;
}

matrix operator+= (matrix& mat1, matrix mat2) // This function will add two matrices
{
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<" not valid"<<endl;
    }
    else
    {
        for (int i = 0; i < mat1.row ; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }

        }
        return mat1;
    }
}
matrix operator-= (matrix& mat1, matrix mat2) // This function will subtract two matrices
{
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<" not valid"<<endl;
    }
    else
    {
        for (int i = 0; i < mat1.row ; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                mat1.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return mat1;
    }

}
matrix operator+(matrix mat1, matrix mat2) // This function will add two matrices and return the output in new matrix
{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,num,mat3);

    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
         for (int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }
    else
    {
        for (int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++ )
            {
                mat3.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }

        return mat3;
    }
}

matrix operator-(matrix mat1, matrix mat2)  // This function will subtract two matrices and return the output in new matrix

{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,num,mat3);
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        for (int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }

    else
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {

                mat3.data [i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return mat3;
    }
}


matrix operator+(matrix mat1, int scalar) // This function will increase the data of the matrix by number and return the output in the new matrix
{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,num,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {

            mat3.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat3;
}
matrix operator-(matrix mat1, int scalar) // This function will decrease the data of the matrix by number and return the output in the new matrix
{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,num,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {

            mat3.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat3;
}
matrix operator*(matrix mat1, matrix mat2) //// This function will multiply two matrices and return the output in the new matrix

{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat2.col];
    createMatrix(mat1.row,mat2.col,num,mat3);
    if(mat1.col!=mat2.row)
    {
        for (int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++ )
            {
             mat3.data[i][j]=-1999999;
            }
        }
    }
     else
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {
                mat3.data[i][j]=0;
                for(int k=0; k<mat1.col; k++)
                {
                    mat3.data[i][j]+=(mat1.data[i][k])*(mat2.data[k][j]);
                }
            }
        }
        return mat3;
    }

}

matrix operator*(matrix mat1, int scalar) //// This function will multiply matrix with a constant number and return the output in the new matrix

{
    matrix mat3;
    int* num;
    num= new int[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,num,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {

            mat3.data[i][j]=mat1.data[i][j]*scalar;
        }

        return mat3;
    }
}

matrix transpose(matrix mat) //this function makes the coloums of a function the rows and the rows become the col
{
    matrix mat3;
    int* num;
    num= new int[mat.row*mat.col];
    createMatrix1(mat.row,mat.col,num,mat3);
    cout<<mat3.row<<":"<<mat3.col<<endl;
    for(int i = 0 ; i<mat.col; i++)
    {
        for(int j=0; j<mat.row; j++)
        {

            mat3.data[i][j]=0;
            mat3.data[i][j]=mat.data[j][i];
        }
    }
    return mat3;

}
bool   operator== (matrix mat1, matrix mat2) //this fun return true if the row of matrix1  equal the row of matrix2 and  col of matrix1 equal col of matrix2
{
    if ( ( mat1.row == mat2.row ) && ( mat1.col == mat2.col ) )
    {
        for ( int i = 0 ; i < mat1.row ; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                if ( mat1.data[i][j] != mat2.data[i][j] )
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return false ;
}
bool   operator!= (matrix mat1, matrix mat2) //this fun return true if the row of matrix1 not equal the row of matrix2 and  col of matrix1 not equal col of matrix2

{
    if ( ( mat1.row == mat2.row ) && ( mat1.col == mat2.col ) )
    {
        for ( int i = 0 ; i < mat1.row ; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {

                if ( mat1.data[i][j] == mat2.data[i][j])
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return true ;
}
bool   isSquare   (matrix mat) //return true if row of matrix equal col of this matrix
{
    if ( mat.row == mat.col )
    {
        return true ;
    }
    else
        return false ;
}

bool   isSymetric (matrix mat) //return true if the content of each col of matrix around the main dimensional is identical.
{
    if ( mat.row == mat.col )
    {
        for ( int i = 0 ; i < mat.row ; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if ( mat.data[i][j] != mat.data[j][i] )
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    else
        return false ;
}

bool   isIdentity (matrix mat)//return true if the content of each col equal.
{
    if ( mat.row == mat.col )
    {
        for ( int i = 0 ; i < mat.row ; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if ( i == j )
                {
                    if ( mat.data[i][j] != 1)
                    {
                        return false;
                    }
                }
                else //if ( i != j )
                {
                    if ( mat.data[i][j] != 0 )
                    {
                        return false ;
                    }
                }
            }
        }
        return true ;
    }
    else
        return false ;
}
