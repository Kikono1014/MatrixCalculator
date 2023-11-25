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
    int  random      (const int& min, const int& max);

    void printMatrix (const vector<vector<double>>&  matrix);

    vector<vector<double>> createZeroMatrix (
            const unsigned int& height, 
            const unsigned int& width
        );


    vector<vector<double>> createRandomMatrix (
            const unsigned int& height, 
            const unsigned int& width, 
            const int& minElementSize = -10,
            const int& maxElementSize = 10
        );

    vector<vector<double>> inputMatrix ();
    void inputMatrixSizes (
            unsigned int& height,
            unsigned int& width
        );
    void inputMatrixElements (
            vector<vector<double>>& matrix
        );

    bool checkMatricesSameSize (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );

    vector<vector<double>> addMatrices (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );

    vector<vector<double>> subtractMatrices (
            const vector<vector<double>>& matrix1,
            const vector<vector<double>>& matrix2
        );

    vector<vector<double>> multiplyMatrixByNumber (
            const vector<vector<double>>& matrix,
            const double& number
        );

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

    double calculateMatrixDeterminant (
            const vector<vector<double>>& matrix
        );

    double calculateMinor (
            const vector<vector<double>>& matrix,
            const int& y,
            const int& x
        );
    
    double calculateAlgebraicComplement (
            const vector<vector<double>>& matrix,
            const int& y,
            const int& x
        );

    vector<vector<double>> transposeMatrix (
            const vector<vector<double>>& matrix
        );
    
    vector<vector<double>> inverseMatrix (
            const vector<vector<double>>& matrix
        );

    bool checkIfItIsNotZeroRow (vector<double> row);

    int matrixRank (
            const vector<vector<double>>& matrix
        );
    
}

#endif
