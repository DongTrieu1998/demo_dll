#ifndef CALCULATOR_LIB_H
#define CALCULATOR_LIB_H

#include "calculator_lib_global.h"

class CALCULATOR_LIB_EXPORT Calculator_lib
{
public:
    Calculator_lib();

    double add(double num1,double num2);
    double subtract(double num1,double num2);
    double multiply(double num1,double num2);
    double divide(double num1,double num2);
};

#endif // CALCULATOR_LIB_H
