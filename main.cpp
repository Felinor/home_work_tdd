#include <iostream>
#include <cassert>
#include "solver.h"

void test_no_roots() {
    Solver solver;
    auto roots = solver.solve(1, 0, 1);
    assert(roots.empty());
    std::cout << "Test 1: no roots - passed.\n";
}

void test_two_roots() {
    Solver solver;
    auto roots = solver.solve(1, 0, -1);
    assert(roots.size() == 2);
    assert((roots[0] == 1.0 && roots[1] == -1.0) || (roots[0] == -1.0 && roots[1] == 1.0));
    std::cout << "Test 2: two roots - passed.\n";
}

void test_double_root() {
    Solver solver;
    double epsilon = std::numeric_limits<double>::epsilon();
    double a = 1;
    double b = 2 + epsilon;
    double c = 1;

    auto roots = solver.solve(a, b, c);

    assert(roots.size() == 2);

    // Проверяем, что корни близки к -1
    assert(roots[0]-1 <= epsilon && roots[1]-1 <= epsilon);

    std::cout << "Test 3: double root - passed.\n";
}

void test_a_is_zero() {
    Solver solver;
    try {
        solver.solve(0, 2, 1);
        assert(false);  // Ожидаем, что должно быть выброшено исключение
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
    std::cout << "Test 4: a is zero - passed.\n";
}

void test_invalid_coefficients() {
    Solver solver;

    double nan = std::numeric_limits<double>::quiet_NaN();
    double inf = std::numeric_limits<double>::infinity();

    try {
        solver.solve(nan, 1, 1);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        solver.solve(1, nan, 1);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        solver.solve(1, 1, nan);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        solver.solve(inf, 1, 1);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        solver.solve(1, inf, 1);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    try {
        solver.solve(1, 1, inf);
        assert(false);
    } catch (const std::invalid_argument&) {
        assert(true);
    }

    std::cout << "Test 5: invalid coefficients - passed.\n";
}

int main(int argc, char *argv[])
{
    test_no_roots();
    test_two_roots();
    test_double_root();
    test_a_is_zero();
    test_invalid_coefficients();

    std::cout << "All tests have been passed. You're amazing!\n";

    return 0;
}
