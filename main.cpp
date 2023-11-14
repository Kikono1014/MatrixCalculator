#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <random>

#include "./inputFunctions.h"
#include "./matrix.h"

using namespace MatrixCalculator;

using std::unordered_map;
using std::vector;
using std::string;

std::unordered_map<string, vector<vector<double>>> savedMatrices {};

void savingMatrix (const vector<vector<double>>& matrix);
string         inputMatrixName     ();
string         getOneMatrixName    ();
vector<string> getTwoMatricesNames ();
vector<vector<double>> getMatrixByName   (string matrixName);
vector<vector<double>> inputRandomMatrix ();


void savingMatrix (const vector<vector<double>>& matrix)
{
    std::cout << std::endl;

    string answer { "n" };

    std::cout << "Would you like to save this matrix? (Y/n) ";
    std::cin >> answer;

    if (answer == "Y") {
        std::cout << "Input matrix name: ";
        std::cin >> answer;
        
        savedMatrices[answer] = matrix;
        std::cout << "The matrix has been saved" << std::endl;
    }

    std::cout << std::endl;
}

string inputMatrixName ()
{
    string matrixName {};
    std::cin >> matrixName;
    std::cout << "Your matrix:" << std::endl;
    try {
        printMatrix(getMatrixByName(matrixName));
        return matrixName;
    }
    catch (const std::exception& e) {
        std::cout << "!!!!!!!!!!!!!!EROR!!!!!!!!!!!!!!" << std::endl;
        std::cout << "Can't find this matrix" << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        return "ERoRe";
    }
}

string getOneMatrixName ()
{
    std::cout << "Input matrix name:" << std::endl;
    string matrixName { inputMatrixName() };
    std::cout << std::endl;
    return matrixName;
}

vector<string> getTwoMatricesNames ()
{
    std::cout << "Input matrices names:" << std::endl;
    std::cout << "First: " << std::endl;
    string matrixName1 { inputMatrixName() };
    std::cout << std::endl;
    std::cout << "Second: " << std::endl;
    string matrixName2 { inputMatrixName() };
    return { matrixName1, matrixName2 };
}

vector<vector<double>> getMatrixByName (string matrixName)
{
    if (matrixName != "ERoRe") {
        return savedMatrices.at(matrixName);
    }
    else {
        return vector<vector<double>> {};
    }
}

vector<vector<double>> inputRandomMatrix ()
{
    double height     { 0 };
    double width      { 0 };
    double minElement { 0 };
    double maxElement { 0 };
    std::cout << "Input matrix height and width." << std::endl;
    std::cout << "Height: ";
    getCorrectIntegerInput(height);
    std::cout << "Width: ";
    getCorrectIntegerInput(width );
    std::cout << "Input diapason of numbers" << std::endl;
    std::cout << "Min: ";
    getCorrectInput(minElement);
    std::cout << "Max: ";
    getCorrectInput(maxElement);

    return createRandomMatrix(height, width, minElement, maxElement);
}


int main ()
{
    bool isRun { 1 };

    while (isRun) {
        double chosenOption { -1 };
        std::cout << "Choose option (0 - for help): ";
        getCorrectIntegerDiapasonInput(chosenOption, 0, 15);

        std::cout << std::endl;
        
        vector<vector<double>> resultMatrix {};
        
        if (chosenOption == 0) {
            std::cout << "Choose options:"                      << std::endl;
            std::cout << "1  - Print matrix"                    << std::endl;
            std::cout << "2  - Create random matrix"            << std::endl;
            std::cout << "3  - Input matrix"                    << std::endl;
            std::cout << "4  - Add matrices"                    << std::endl;
            std::cout << "5  - Subtract matrices"               << std::endl;
            std::cout << "6  - Multiply matrix by number"       << std::endl;
            std::cout << "7  - Multiply matrices"               << std::endl;
            std::cout << "8  - Transform matrix to stairs form" << std::endl;
            std::cout << "9  - Calculate matrix determinant"    << std::endl;
            std::cout << "10 - Calculate minor"                 << std::endl;
            std::cout << "11 - Calculate algebraic complement"  << std::endl;
            std::cout << "12 - Transpose matrix"                << std::endl;
            std::cout << "13 - Inverse matrix"                  << std::endl;
            std::cout << "14 - Matrix rank"                     << std::endl;
            std::cout << "15 - Exit"                            << std::endl;
        }

        if (chosenOption == 1) {
            string matrixName { getOneMatrixName() };
        }
    
        if (chosenOption == 2) {
            resultMatrix = inputRandomMatrix();
        }
        if (chosenOption == 3) {
            resultMatrix = inputMatrix();
        }
        if (chosenOption == 4) {
            vector<string> names { getTwoMatricesNames() };

            resultMatrix = 
                addMatrices(   
                    getMatrixByName(names[0]),
                    getMatrixByName(names[1])
                );
        }
        if (chosenOption == 5) {
            vector<string> names { getTwoMatricesNames() };

            resultMatrix = 
                subtractMatrices(   
                    getMatrixByName(names[0]),
                    getMatrixByName(names[1])
                );
        }
        if (chosenOption == 6) {
            string matrixName { getOneMatrixName() };
            double number {};
            getCorrectInput(number);

            resultMatrix = 
                multiplyMatrixByNumber(   
                    getMatrixByName(matrixName),
                    number
                );
        }
        if (chosenOption == 7) {
            vector<string> names { getTwoMatricesNames() };

            resultMatrix = 
                multiplyMatrices(   
                    getMatrixByName(names[0]),
                    getMatrixByName(names[1])
                );
        }
        if (chosenOption == 8) {
            string matrixName { getOneMatrixName() };

            
            resultMatrix = 
                makeStairsMatrix (   
                    getMatrixByName(matrixName)
                );

        }
        if (chosenOption == 9) {
            string matrixName { getOneMatrixName() };

            std::cout << calculateMatrixDeterminant(
                    getMatrixByName(matrixName)
                ) << 
            std::endl;

        }
        if (chosenOption == 10) {
            string matrixName { getOneMatrixName() };
            double input { 0 };
            std::cout << "Input coordinates:" << std::endl;
            std::cout << "Y: ";
            getCorrectIntegerInput(input);
            int y { (int)input };
            std::cout << "X: ";
            getCorrectIntegerInput(input);
            int x { (int)input };

            std::cout << calculateMinor(
                    getMatrixByName(matrixName),
                    y, x
                ) << 
            std::endl;

        }
        if (chosenOption == 11) {
            string matrixName { getOneMatrixName() };
            double input { 0 };
            std::cout << "Input coordinates:" << std::endl;
            std::cout << "Y: ";
            getCorrectIntegerInput(input);
            int y { (int)input };
            std::cout << "X: ";
            getCorrectIntegerInput(input);
            int x { (int)input };

            std::cout << calculateAlgebraicComplement(
                    getMatrixByName(matrixName),
                    y, x
                ) << 
            std::endl;
        }
        if (chosenOption == 12) {
            string matrixName { getOneMatrixName() };

            resultMatrix =
                transposeMatrix(
                    getMatrixByName(matrixName)
                );
        }
        if (chosenOption == 13) {
            string matrixName { getOneMatrixName() };

            resultMatrix =
                inverseMatrix(
                    getMatrixByName(matrixName)
                );
        }
        if (chosenOption == 14) {
            string matrixName { getOneMatrixName() };

            std::cout << matrixRank(
                    getMatrixByName(matrixName)
                ) <<
            std::endl;
        }
        if (chosenOption == 15) {
            isRun = 0;
        }

        if (
            (chosenOption > 1 and chosenOption < 9) or
            chosenOption == 12 or
            chosenOption == 13
        ) {
            if (!resultMatrix.empty()) {
                std::cout << std::endl;
                std::cout << "Result matrix:" << std::endl;
                printMatrix(resultMatrix);

                savingMatrix(resultMatrix);
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
