#include "solver.h"

std::vector<double> Solver::solve_1(double a, double b, double c) {
    // Уравнение имеет вид x^2 + 1 = 0, дискриминант < 0, значит корней нет.
    return {};
}

std::vector<double> Solver::solve_2(double a, double b, double c) {
    // Уравнение имеет вид x^2 - 1 = 0, два корня: 1 и -1.
    return {1.0, -1.0};
}

std::vector<double> Solver::solve_3(double a, double b, double c) {
    // Уравнение имеет вид x^2 + 2x + 1 = 0, один корень кратности 2: -1.
    return {-1.0, -1.0};
}

std::vector<double> Solver::solve_4(double a, double b, double c) {
    // Проверка, что 'a' не равно 0
    if (std::fabs(a) < std::numeric_limits<double>::epsilon()) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero.");
    }

    // Возвращаем пустой вектор для простоты, так как реализация пока не важна
    return {};
}

std::vector<double> Solver::solve_5(double a, double b, double c) {
    // Проверка, что 'a' не равно 0
    if (std::fabs(a) < std::numeric_limits<double>::epsilon()) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero.");
    }

    // Вычисляем дискриминант
    double discriminant = b * b - 4 * a * c;

    if (std::fabs(discriminant) < std::numeric_limits<double>::epsilon()) {
        double x = -b / (2 * a);
        return {x, x};  // Один корень кратности 2
    } else {
        double sqrtD = std::sqrt(discriminant);
        double x1 = (-b + sqrtD) / (2 * a);
        double x2 = (-b - sqrtD) / (2 * a);
        return {x1, x2};  // Два различных корня
    }
}

std::vector<double> Solver::solve(double a, double b, double c) {
    // Проверка на некорректные значения коэффициентов
    if (std::isnan(a) || std::isnan(b) || std::isnan(c) ||
            std::isinf(a) || std::isinf(b) || std::isinf(c)) {
        throw std::invalid_argument("Coefficients cannot be NaN or infinity.");
    }

    // Проверка на то, что коэффициент 'a' не равен нулю
    if (std::fabs(a) < std::numeric_limits<double>::epsilon()) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero.");
    }

    double discriminant = b * b - 4 * a * c;

    // Если дискриминант меньше нуля, корней нет
    if (discriminant < -std::numeric_limits<double>::epsilon()) {
        return {};
    }

    // Если дискриминант равен нулю, есть один корень кратности два
    if (std::fabs(discriminant) < std::numeric_limits<double>::epsilon()) {
        double x = -b / (2 * a);
        return {x, x};
    } else {
        // Иначе два различных корня
        double sqrtD = std::sqrt(discriminant);
        double x1 = (-b + sqrtD) / (2 * a);
        double x2 = (-b - sqrtD) / (2 * a);
        return {x1, x2};
    }
}
