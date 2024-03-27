#include <iostream>
#include <vector>

// Функция для умножения матриц
std::vector<std::vector<int>> matrixMultiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Функция для вычисления факториала числа
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество вершин в графе: ";
    std::cin >> n;

    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    std::cout << "Введите матрицу смежности графа размером " << n << " x " << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int>> I(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        I[i][i] = 1;
    }

    std::vector<std::vector<int>> G(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> Ak = I;
    double factorial_val;
    std::cout << "G(x) = ";
    for (int k = 0; k < n; ++k) {
        factorial_val = factorial(k);
        if (k > 0) {
            std::cout << " + ";
        }
        std::cout << "(";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Ak[i][j] != 0) {
                    if (Ak[i][j] > 1) {
                        std::cout << Ak[i][j] << "*";
                    }
                    std::cout << "x^" << k;
                    if (factorial_val > 1) {
                        std::cout << "/" << factorial_val;
                    }
                    std::cout << " + ";
                }
            }
            
        }
        std::cout << 0;
        std::cout << ")";
        Ak = matrixMultiply(Ak, A);
    }

    return 0;
}