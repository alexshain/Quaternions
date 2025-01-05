#include <iostream>

#include "Quaternion.h"

void testMultipleQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion q3 = quater1 * quater2;
    quater1.outputToConsole();
    quater2.outputToConsole();
    q3.outputToConsole();
}

void testMultipleQuaterAndComplex(){
    std::cout << "quater * complex" << std::endl;
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    std::complex<int> quater2(1, 2);
    Quaternion q3 = quater2 * quater1;
    quater1.outputToConsole();
    std::cout << quater2.real() << "+" << quater2.imag() << "i" << std::endl;
    q3.outputToConsole();
}

void testMultipleQuaterAndScalar(){
    std::cout << "quater * scalar" << std::endl;
    Quaternion quater1 = Quaternion{6, -7, -8, 9};
    int scalar1 = 10;
    Quaternion q3 = quater1 * scalar1;
    quater1.outputToConsole();
    std::cout << scalar1 << std::endl;
    q3.outputToConsole();

    std::cout << std::endl;

    std::cout << "scalar * quater" << std::endl;
    Quaternion quater3 = Quaternion{6, -7, -8, 9};
    int scalar2 = 10;
    Quaternion q5 = scalar2 * quater3;
    quater3.outputToConsole();
    std::cout << scalar2 << std::endl;
    q5.outputToConsole();
}

void testUnarMinus() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    quater1.outputToConsole();
    Quaternion quater2 = -quater1;
    quater2.outputToConsole();
}

void testMinusQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    
    Quaternion q3 = quater2 - quater1;
    quater1.outputToConsole();
    quater2.outputToConsole();
    q3.outputToConsole();
}

void testMinusQuaterAndComplex(){
    /*std::cout << "quater - complex" << std::endl;
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    std::complex<int> quater2(1, 2);
    Quaternion q3 = quater1 - quater2;
    quater1.outputToConsole();
    std::cout << quater2.real() << "+" << quater2.imag() << "i" << std::endl;
    q3.outputToConsole();

    std::cout << std::endl;*/

    std::cout << "complex - quater" << std::endl;
    Quaternion quater3 = Quaternion{5, -6, -7, 8};
    std::complex<int> quater4(9, 10);
    quater3.outputToConsole();
    Quaternion q5 = quater4 - quater3;
    std::cout << quater4.real() << "+" << quater4.imag() << "i" << std::endl;
    q5.outputToConsole();
}

void testMinusQuaterAndScalar(){
    /*std::cout << "quater - scalar" << std::endl;
    Quaternion quater1 = Quaternion{6, -7, -8, 9};
    int scalar1 = 10;
    Quaternion q3 = quater1 - scalar1;
    quater1.outputToConsole();
    std::cout << scalar1 << std::endl;
    q3.outputToConsole();

    std::cout << std::endl;*/

    std::cout << "scalar - quater" << std::endl;
    Quaternion quater3 = Quaternion{6, -7, -8, 9};
    int scalar2 = 10;
    Quaternion q5 = scalar2 - quater3;
    quater3.outputToConsole();
    std::cout << scalar2 << std::endl;
    q5.outputToConsole();
}

void testDevideOperator() {
    Quaternion quater1 = Quaternion<double>(1.0, -2.0, -3.0, 4.0);
    quater1.outputToConsole();
    Quaternion q2 = quater1/2;
    q2.outputToConsole();
}

int main() {
    testMultipleQuaterAndComplex();
    return 0;
}