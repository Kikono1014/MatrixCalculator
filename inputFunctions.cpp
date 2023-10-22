#include "./inputFunctions.h"

void clearCin ()
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getCorrectDiapasonInput (
        double& input,
        const double& min,
        const double& max
    )
{
    while (1) {
        getCorrectInput(input);
        if (input < min or input > max) {
            std::cout << "Wrong id. Must be from " << min << " to " << max << std::endl;
            std::cout << std::endl;
            clearCin();
        }
        else {
            break;
        }
    }
}

void getCorrectIntegerDiapasonInput (
        double& input,
        const double& min,
        const double& max
    )
{
    while (1) {
        getCorrectIntegerInput(input);
        if (input < min or input > max) {
            std::cout << "Wrong id. Must be from " << min << " to " << max << std::endl;
            std::cout << std::endl;
            clearCin();
        }
        else {
            break;
        }
    }
}


void getCorrectInput (double& input)
{
    while (1) {
        std::cin >> input;
        
        // catch char input
        if (std::cin.fail()) {
            std::cout << "Wrong input. Input can't be a symbol." << std::endl;
            std::cout << std::endl;
            clearCin();
        }
        else {
            break;
        }
    }
}


void getCorrectIntegerInput (double& input)
{
    while (1) {
        std::cin >> input;
        
        // catch char input
        if (std::cin.fail()) {
            std::cout << "Wrong input. Input can't be a symbol." << std::endl;
            std::cout << std::endl;
            clearCin();
        }
        else {
            if (input != (int)input) {
                std::cout << "Wrong input. Input can't be a float number." << std::endl;
                std::cout << std::endl;
                clearCin();
            }
            else {
                break;
            }
        }
    }
}

void getCorrectInputs (std::vector<double>& inputs)
{
    for (double& input : inputs) {
        getCorrectInput(input);
    }
}

void getCorrectIntegerInputs (std::vector<double>& inputs)
{
    for (double& input : inputs) {
        getCorrectIntegerInput(input);
    }
}