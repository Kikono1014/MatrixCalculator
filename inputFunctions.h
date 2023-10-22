#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <cmath>


void clearCin ();
void getCorrectDiapasonInput (
        double& input,
        const double& min,
        const double& max
    );

void getCorrectIntegerDiapasonInput (
        double& input,
        const double& min,
        const double& max
    );

void getCorrectInput         (double& input);
void getCorrectIntegerInput  (double& input);
void getCorrectInputs        (std::vector<double>& inputs);
void getCorrectIntegerInputs (std::vector<double>& inputs);
#endif
