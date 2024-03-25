//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// ������� ��� ���������� ������������ ������� ��� �����
//void generatingFunction(int n, vector<int>& edges) {
//    vector<long long int> dp(n + 1, 0);
//    dp[0] = 1;
//
//    for (int i = 1; i <= n; ++i) {
//        for (int edge : edges) {
//            if (i - edge >= 0) {
//                dp[i] += dp[i - edge];
//            }
//        }
//    }
//
//    cout << "������������ ������� ��� �����: ";
//    for (int i = 0; i <= n; ++i) {
//        cout << dp[i] << "x^" << i;
//        if (i < n) {
//            cout << " + ";
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    int n = 5; // ������ �����
//    vector<int> edges = { 1, 2 }; // ������� ����
//
//    generatingFunction(n, edges);
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <cmath>
//
//long long int generatingFunction(const std::vector<std::vector<int>>& adjacencyMatrix, int vertex, int z) {
//    long long int result = 0;
//
//    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
//        if (adjacencyMatrix[vertex][i] == 1) {
//            result += std::pow(z, i);
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    std::vector<std::vector<int>> adjacencyMatrix = { {0, 1, 1}, {1, 0, 0}, {1, 0, 0} }; // ������ ������� ���������
//
//    int z = 2; // �������� z ��� ������������ �������
//    int vertex = 1; // ��������� ������� ��� ���������� ������������ �������
//
//    long long int result = generatingFunction(adjacencyMatrix, vertex, z);
//
//    std::cout << "Generating function for vertex " << vertex << ": " << result << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// ������� ��� ���������� ������������ ������� ��� �����
//void generatingFunction(int n, vector<vector<int>>& adjacencyMatrix) {
//    vector<long long int> dp(n + 1, 0);
//    dp[0] = 1;
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (i - adjacencyMatrix[j][j] >= 0) {
//                dp[i] += dp[i - adjacencyMatrix[j][j]];
//            }
//        }
//    }
//
//    cout << "������������ ������� ��� �����: ";
//    for (int i = 0; i <= n; ++i) {
//        cout << dp[i] << "x^" << i;
//        if (i < n) {
//            cout << " + ";
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    int n = 5; // ������ �����
//    vector<vector<int>> adjacencyMatrix = {
//        {0, 1, 1, 0, 0},
//        {1, 0, 1, 1, 0},
//        {1, 1, 0, 1, 0},
//        {0, 1, 1, 0, 1},
//        {0, 0, 0, 1, 0} }; // ������� ��������� �����
//    
//    generatingFunction(n, adjacencyMatrix);
//    return 0;
//}

#include <iostream>
#include <vector>

// ������� ��� ������������ ���� ������
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // ��������� ����������� ��������� ������
    if (cols1 != rows2) {
        throw std::runtime_error("���������� ����������� �������: ������������ �������");
    }

    // ������� ����� ������� � ��������� ������
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    // ��������� ������������ ������
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// ������� ��� ���������� ������� � �������
std::vector<std::vector<int>> matrixPower(const std::vector<std::vector<int>>& matrix, int power) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // ���������, ��� ������� ����������
    if (rows != cols) {
        throw std::runtime_error("���������� �������� �� ���������� ������� � �������");
    }

    // �������������� ��������� �������
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        result[i][i] = 1;
    }

    // ����������� ������� ���� �� ���� power ���
    std::vector<std::vector<int>> tempMatrix = matrix;
    while (power > 0) {
        if (power % 2 == 1) {
            result = multiplyMatrices(result, tempMatrix);
        }
        tempMatrix = multiplyMatrices(tempMatrix, tempMatrix);
        power /= 2;
    }

    return result;
}

int main() {
    // ������ ������������� �������

    // �������� �������
    std::vector<std::vector<int>> matrix = { {1, 2}, {3, 4} };

    // �������� �������
    int power = 3;

    try {
        // ��������� �������, ����������� � �������
        std::vector<std::vector<int>> result = matrixPower(matrix, power);

        // ������� ���������
        for (const auto& row : result) {
            for (const auto& element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
    catch (const std::exception& error) {
        std::cout << "������: " << error.what() << std::endl;
    }

    return 0;
}