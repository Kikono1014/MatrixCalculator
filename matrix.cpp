#include "./matrix.h"

using std::vector;
using std::string;

int MatrixCalculator::random (const int& min, const int& max) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int random = mersenne() % (max - (min - 1)) + min;
    if (random > max or random < min) {
        std::cout << std::endl;
        std::cout << "!!!!!!!!!!!!!!EROR!!!!!!!!!!!!!!" << std::endl;
        std::cout << random << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    }
    return random;
}


void MatrixCalculator::printMatrix (const vector<vector<double>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            std::cout << matrix[i][j] << "\t\t";
        }   
        std::cout << std::endl;
    }
}


vector<vector<double>> MatrixCalculator::createZeroMatrix (
        const unsigned int& height,
        const unsigned int& width
    )
{
    vector<vector<double>> matrix {};
    vector<double> tempRow {};
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tempRow.push_back(0);
        }
        matrix.push_back(tempRow);
        tempRow.clear();
    }
    return matrix;
}

vector<vector<double>> MatrixCalculator::createRandomMatrix (
        const unsigned int& height,
        const unsigned int& width, 
        const int& minElementSize, 
        const int& maxElementSize
    )
{
    vector<vector<double>> matrix { createZeroMatrix(height, width) };
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = random(minElementSize, maxElementSize);
        }
    }
    return matrix;
}

void MatrixCalculator::inputMatrixSizes (
        unsigned int& height,
        unsigned int& width
    )
{
    double inputHeight {};
    double inputWidth  {};

    std::cout << "Enter the height and width of your matrix." << std::endl;
    std::cout << "Height: ";
    getCorrectIntegerInput(inputHeight);
    std::cout << "Width: ";
    getCorrectIntegerInput(inputWidth); 
    height = (unsigned int)inputHeight;
    width  = (unsigned int)inputWidth;
}

void MatrixCalculator::inputMatrixElements (
        vector<vector<double>>& matrix,
        const unsigned int& height,
        const unsigned int& width
    )
{
    std::cout << std::endl;
    std::cout << "Input the matrix arguments. Row by row. Splitted by single space." << std::endl;
    for (int i = 0; i < height; ++i) {
        vector<double> elementsInRow {};
        for (int j = 0; j < width; ++j) {
            elementsInRow.push_back(0);
        }
        getCorrectInputs(elementsInRow);
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = elementsInRow[j];
        }
    }
}

vector<vector<double>> MatrixCalculator::inputMatrix ()
{
    unsigned int height {};
    unsigned int width  {};

    inputMatrixSizes (height, width);

    std::cout << std::endl;
    std::cout << "Matrix size is: " << std::endl;
    std::cout << height << "x" << width << std::endl;

    vector<vector<double>> matrix { createZeroMatrix(height, width) };
    inputMatrixElements(matrix, height, width);
    
    return matrix;
}

bool MatrixCalculator::checkMatricesSameSize (
        const vector<vector<double>>& matrix1,
        const vector<vector<double>>& matrix2
    )
{
    return (matrix1.size() == matrix2.size()) and 
           (matrix1[0].size() == matrix2[0].size());
}



vector<vector<double>> MatrixCalculator::addMatrices (
        const vector<vector<double>>& matrix1,
        const vector<vector<double>>& matrix2
    )
{
    vector<vector<double>> resultMatrix { matrix1 };
    if (checkMatricesSameSize(matrix1, matrix2)) {
        for (int i = 0; i < matrix1.size(); ++i) {
            for (int j = 0; j < matrix1[0].size(); ++j) {
                resultMatrix[i][j] = resultMatrix[i][j] + matrix2[i][j];
            }
        }
        return resultMatrix;
    }
    std::cout << "Matrices are different size. Can't make addition" << std::endl;
    return vector<vector<double>> {};
}


vector<vector<double>> MatrixCalculator::subtractMatrices (
        const vector<vector<double>>& matrix1,
        const vector<vector<double>>& matrix2
    )
{
    vector<vector<double>> resultMatrix { matrix1 };
    if (checkMatricesSameSize(matrix1, matrix2)) {
        for (int i = 0; i < matrix1.size(); ++i) {
            for (int j = 0; j < matrix1[0].size(); ++j) {
                resultMatrix[i][j] = resultMatrix[i][j] - matrix2[i][j];
            }
        }
        return resultMatrix;
    }
    std::cout << "Matrices are different size. Can't make subtraction" << std::endl;
    return vector<vector<double>> {};
}


vector<vector<double>> MatrixCalculator::multiplyMatrixByNumber (
        const vector<vector<double>> &matrix,
        const double &number
    )
{
    vector<vector<double>> resultMatrix { matrix };
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            resultMatrix[i][j] = resultMatrix[i][j] * number;
        }
    }
    return resultMatrix;
}


vector<vector<double>> MatrixCalculator::multiplyMatrices (
        const vector<vector<double>>& matrix1,
        const vector<vector<double>>& matrix2
    )
{
    if (matrix1[0].size() == matrix2.size()) {
        vector<vector<double>> resultMatrix {
            createZeroMatrix(matrix1.size(), matrix2[0].size())
        };
        for (int i = 0; i < matrix1.size(); ++i) {
            for (int j = 0; j < matrix2[0].size(); ++j) {
                for (int el = 0; el < matrix1[0].size(); ++el) {
                    resultMatrix[i][j] = resultMatrix[i][j] +
                        matrix1[i][el] * matrix2[el][j];
                }
            }
        }
        return resultMatrix;
    }
    std::cout << "Matrices can't be multiplied. Incorrect sizes." << std::endl;
    return vector<vector<double>> {};
}

vector<vector<double>> MatrixCalculator::makeStairsMatrix (
        const vector<vector<double>>& matrix
    )
{
    vector<vector<double>> resultMatrix { matrix };
    
    for (int i = 0; i < resultMatrix[0].size(); ++i) {
        // TODO
        // if (resultMatrix[i][i] == 0) {
        //     std::cout << "-----------------------" << std::endl;
        //     std::cout << "haven't developed yet"   << std::endl;
        //     std::cout << "-----------------------" << std::endl;
        //     return vector<vector<double>> {};
        // }
        for (int j = i + 1; j < resultMatrix.size(); ++j) {
            double x { - (resultMatrix[j][i] / resultMatrix[i][i]) };
            for (int k = i; k < resultMatrix[0].size(); ++k) {
                resultMatrix[j][k] = resultMatrix[j][k] + resultMatrix[i][k] * x;
            }
        }
    }
    return resultMatrix;
}

bool MatrixCalculator::checkIsMatrixSquare (
        const vector<vector<double>>& matrix
    )
{
    return (matrix.size() == matrix[0].size());
}

double MatrixCalculator::calculateMatrixDeterminant (
        const vector<vector<double>>& matrix
    )
{
    if (checkIsMatrixSquare(matrix)) {
        vector<vector<double>> tMatrix { 
            makeStairsMatrix(matrix)
        };
        double determinant { 1 };
        for (int i = 0; i < tMatrix.size(); ++i) {
            if (tMatrix[i][i] == 0) {
                return 0;
            }
            else {
                determinant *= tMatrix[i][i];
            }
        }
        return determinant;
    }
    std::cout << "Determinant can't be calculated. Matrix isn't square." << std::endl;
    return -1;
}

double MatrixCalculator::calculateMinor (
        const vector<vector<double>>& matrix,
        const int& y,
        const int& x
    )
{
    if (checkIsMatrixSquare(matrix)) {
        if (
            x <= matrix[0].size() and x > 0 and
            y <= matrix.size()    and y > 0
        ) {  
            vector<vector<double>> minor {
                createZeroMatrix(matrix.size() - 1, matrix[0].size() - 1)
            };
            int mi { 0 };
            int mj { 0 };

            for (int i = 0; i < matrix.size(); ++i) {
                if (i != y - 1) {
                    for (int j = 0; j < matrix[0].size(); ++j) {
                        if (j != x - 1) {
                            minor[mi][mj] = matrix[i][j];
                            mj++;
                        }
                    }
                    mj = 0;
                    mi++; 
                }
            }
            return calculateMatrixDeterminant(minor);
        }
        else {
            std::cout << "Wrong coordinates." << std::endl;
        }
    }
    else {
        std::cout << "Matrix isn't square." << std::endl;
    }

    return -1;
}

double MatrixCalculator::calculateAlgebraicComplement (
        const vector<vector<double>>& matrix,
        const int& y,
        const int& x
    )
{
    if ((x + y) % 2 == 0) {
        return calculateMinor(matrix, y, x);
    }
    if ((x + y) % 2 != 0) {
        return -1 * calculateMinor(matrix, y, x);
    }
    return -1;
}


vector<vector<double>> MatrixCalculator::transposeMatrix (
        const vector<vector<double>>& matrix
    )
{
    vector<vector<double>> tMatrix {
        createZeroMatrix(matrix[0].size(), matrix.size())
    };
    
    for (int i = 0; i < matrix[0].size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            tMatrix[i][j] = matrix[j][i];
        }
    }
    return tMatrix;
}

vector<vector<double>> MatrixCalculator::inverseMatrix (
        const vector<vector<double>>& matrix
    )
{
    if (checkIsMatrixSquare(matrix)) {
        vector<vector<double>> tMatrix {
            transposeMatrix(matrix)
        };

        vector<vector<double>> resMatrix {
            createZeroMatrix(matrix.size(), matrix[0].size())
        };

        for (int i = 0; i < tMatrix[0].size(); ++i) {
            for (int j = 0; j < tMatrix.size(); ++j) {
                resMatrix[i][j] = calculateAlgebraicComplement(tMatrix, j + 1 , i + 1);
            }
        }
        resMatrix = multiplyMatrixByNumber(
            resMatrix,
            1 / calculateMatrixDeterminant(resMatrix)
        );
        return resMatrix;
        
    }
    else {
        std::cout << "Matrix isn't square." << std::endl;
    }
    return vector<vector<double>> {};
}

bool MatrixCalculator::checkIfItIsNotZeroRow (vector<double> row)
{
    int sum { 0 };
    for (double number : row) {
        if (fabs(number) < MAXFLOAT) {
            sum += number;
        }
    }
    
    return sum != 0 ;
}

int MatrixCalculator::matrixRank (
        const vector<vector<double>>& matrix
    )
{
    vector<vector<double>> tMatrix { makeStairsMatrix(matrix) };
    int rank { 0 };
    for (int i = 0; i < tMatrix.size(); ++i) {
        if (checkIfItIsNotZeroRow(tMatrix[i])) {
            rank++;
        }
    }
    return rank;
}