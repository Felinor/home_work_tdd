#pragma once

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>

class Solver {
public:
    std::vector<double> solve_1(double a, double b, double c);
    std::vector<double> solve_2(double a, double b, double c);
    std::vector<double> solve_3(double a, double b, double c);
    std::vector<double> solve_4(double a, double b, double c);
    std::vector<double> solve_5(double a, double b, double c);
    // Метод для решения квадратного уравнения ax^2 + bx + c = 0
    std::vector<double> solve(double a, double b, double c);
};
