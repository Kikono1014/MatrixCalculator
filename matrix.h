#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "./inputFunctions.h"

using std::vector;
using std::string;

namespace MatrixCalculator {
    // Generate a random number in [min, max] diapason 
    int  random      (const int& min, const int& max);

    void printMatrix (const vector<vector<double>>&  matrix);

    // Create empty(zero) matrix
    vector<vector<double>> createZeroMatrix (
            const unsigned int& height, 
            const unsigned int& width
        );

    // Generate a matrix with random elements
    vector<vector<double>> createRandomMatrix (
            const unsigned int& height, 
            const unsigned int& width, 
            const int& minElementSize = -10,
            const int& maxElementSize = 10
        );

    // User's matrix
    vector<vector<double>> inputMatrix ();
    void inputMatrixSizes (
            unsigned int& height,
            unsigned int& width
        );
    void inputMatrixElements (
            vector<vector<double>>& matrix,
            const unsigned int& height,
            const unsigned int& width
        );

    // Check if matrices are the same size
    bool checkMatricesSameSize (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );

    // Operations with matrices
    // matrix1 + matrix2 
    vector<vector<double>> addMatrices (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );
    // matrix1 - matrix2
    vector<vector<double>> subtractMatrices (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );

    // matrix * n
    vector<vector<double>> multiplyMatrixByNumber (
            const vector<vector<double>>& matrix,
            const double& number
        );

    // matrix1 * matrix2
    vector<vector<double>> multiplyMatrices (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );


    vector<vector<double>> makeStairsMatrix (
            const vector<vector<double>>& matrix
        );

    bool checkIsMatrixSquare (
            const vector<vector<double>>& matrix
        );

    // |matrix|
    double calculateMatrixDeterminant (
            const vector<vector<double>>& matrix
        );

    // Mij
    double calculateMinor (
            const vector<vector<double>>& matrix,
            const int& y,
            const int& x
        );
    
    // Aij
    double calculateAlgebraicComplement (
            const vector<vector<double>>& matrix,
            const int& y,
            const int& x
        );

    vector<vector<double>> transposeMatrix (
            const vector<vector<double>>& matrix
        );
    
    // matrix ^ -1
    vector<vector<double>> inverseMatrix (
            const vector<vector<double>>& matrix
        );

    bool checkIfItIsNotZeroRow (vector<double> row);

    // r(matrix)
    int matrixRank (
            const vector<vector<double>>& matrix
        );
    
}

#endif
