#include <iostream>
#include <random>
std::vector<std::vector<int>> gen_left_matrix(int col) {
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> int_dis(1, 100); //[1,100)
    int row(int_dis(engine));
    std::vector<std::vector<int>> left_matrix;
    for (int i = 0; i < row; i++) {
        std::vector<int> cols;
        for (int j = 0; j < col; j++) {
            cols.emplace_back(int_dis(engine));
        }
        left_matrix.emplace_back(cols);
    }
    return left_matrix;
}

std::vector<std::vector<int>> gen_right_matrix(int row) {
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> int_dis(1, 100); //[1,100)
    int col(int_dis(engine));
    std::vector<std::vector<int>> right_matrix;
    for (int i = 0; i < row; i++) {
        std::vector<int> cols;
        for (int j = 0; j < col; j++) {
            cols.emplace_back(int_dis(engine));
        }
        right_matrix.emplace_back(cols);
    }
    return right_matrix;
}

int get_2_n(int base) {
    int res = 1;
    for (; res < base; res *= 2)
        ;
    return res;
}

std::vector<std::vector<int>>
expand(int size, const std::vector<std::vector<int>> &base) {
    std::vector<std::vector<int>> res = base;
    int row = base.size();
    int col = base[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = col; j < size; j++) {
            res[i].emplace_back(0);
        }
    }
    std::vector<int> tmp(col, 0);
    for (int i = row; i < size; i++) {
        res.emplace_back(tmp);
    }
    return res;
}

std::vector<std::vector<int>>
getA_B_11(const std::vector<std::vector<int>> &A) {
    int n = A.size() / 2;
    std::vector<std::vector<int>> vec;
    for (int i = 0; i < n; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.emplace_back(A[i][j]);
        }
        vec.emplace_back(tmp);
    }
    return vec;
}
std::vector<std::vector<int>>
getA_B_12(const std::vector<std::vector<int>> &A) {
    int size = A.size();
    int n = size / 2;
    std::vector<std::vector<int>> vec;
    for (int i = 0; i < n; i++) {
        std::vector<int> tmp;
        for (int j = n; j < size; j++) {
            tmp.emplace_back(A[i][j]);
        }
        vec.emplace_back(tmp);
    }
    return vec;
}

std::vector<std::vector<int>>
getA_B_21(const std::vector<std::vector<int>> &A) {
    int size = A.size();
    int n = size / 2;
    std::vector<std::vector<int>> vec;
    for (int i = n; i < size; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.emplace_back(A[i][j]);
        }
        vec.emplace_back(tmp);
    }
    return vec;
}

std::vector<std::vector<int>>
getA_B_22(const std::vector<std::vector<int>> &A) {
    int size = A.size();
    int n = size / 2;
    std::vector<std::vector<int>> vec;
    for (int i = n; i < size; i++) {
        std::vector<int> tmp;
        for (int j = n; j < size; j++) {
            tmp.emplace_back(A[i][j]);
        }
        vec.emplace_back(tmp);
    }
    return vec;
}

std::vector<std::vector<int>>
matrix_add(const std::vector<std::vector<int>> &A,
           const std::vector<std::vector<int>> &B) {
    int row = A.size();
    int col = A[0].size();
    std::vector<std::vector<int>> res = A;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] += B[i][j];
        }
    }
    return res;
}

std::vector<std::vector<int>>
matrix_sub(const std::vector<std::vector<int>> &A,
           const std::vector<std::vector<int>> &B) {
    int row = A.size();
    int col = A[0].size();
    std::vector<std::vector<int>> res = A;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] -= B[i][j];
        }
    }
    return res;
}

std::vector<std::vector<int>> merge(const std::vector<std::vector<int>> &C11,
                                    const std::vector<std::vector<int>> &C12,
                                    const std::vector<std::vector<int>> &C21,
                                    const std::vector<std::vector<int>> &C22) {
    int row1 = C11.size();
    int col1 = C11[0].size();
    int row2 = C22.size();
    int col2 = C22[0].size();
    std::vector<std::vector<int>> res;
    for (int i = 0; i < row1; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < col1; j++) {
            tmp.emplace_back(C11[i][j]);
        }
        for (int j = 0; j < col2; j++) {
            tmp.emplace_back(C12[i][j]);
        }
        res.emplace_back(tmp);
    }

    for (int i = 0; i < row2; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < col1; j++) {
            tmp.emplace_back(C21[i][j]);
        }
        for (int j = 0; j < col2; j++) {
            tmp.emplace_back(C22[i][j]);
        }
        res.emplace_back(tmp);
    }
    return res;
}

const std::vector<std::vector<int>>
strassen(const std::vector<std::vector<int>> &A,
         const std::vector<std::vector<int>> B) {
    int n = A.size();
    if (n == 1) {
        return std::vector<std::vector<int>>{
            std::vector<int>{A[0][0] * B[0][0]}};
    }
    auto A11 = getA_B_11(A);
    auto A12 = getA_B_12(A);
    auto A21 = getA_B_21(A);
    auto A22 = getA_B_22(A);

    auto B11 = getA_B_11(B);
    auto B12 = getA_B_12(B);
    auto B21 = getA_B_21(B);
    auto B22 = getA_B_22(B);

    auto M1 = strassen(matrix_add(A11, A22), matrix_add(B11, B22));
    auto M2 = strassen(matrix_add(A21, A22), B11);
    auto M3 = strassen(A11, matrix_sub(B12, B22));
    auto M4 = strassen(A22, matrix_sub(B21, B11));
    auto M5 = strassen(matrix_add(A11, A12), B22);
    auto M6 = strassen(matrix_sub(A21, A11), matrix_add(B11, B12));
    auto M7 = strassen(matrix_sub(A12, A22), matrix_add(B21, B22));

    auto C11 = matrix_add(matrix_add(M1, M7), matrix_sub(M4, M5));
    auto C12 = matrix_add(M3, M5);
    auto C21 = matrix_add(M2, M4);
    auto C22 = matrix_add(matrix_add(M1, M3), matrix_sub(M6, M2));
    auto C = merge(C11, C12, C21, C22);
    return C;
}

std::vector<std::vector<int>>
traditional_matrix_mul(const std::vector<std::vector<int>> &A,
                       const std::vector<std::vector<int>> &B) {
    std::vector<std::vector<int>> res;
    int row1 = A.size();
    int row2 = B.size();
    int col2 = B[0].size();
    for (int i = 0; i < row1; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < col2; j++) {
            int res = 0;
            for (int k = 0; k < row2; k++) {
                res += A[i][k] * B[k][j];
            }
            tmp.emplace_back(res);
        }
        res.emplace_back(tmp);
    }
    return res;
}

bool matrix_equal(const std::vector<std::vector<int>> &tradition,
                  const std::vector<std::vector<int>> &modern) {
    int row = tradition.size();
    int col = tradition[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (tradition[i][j] != modern[i][j]) {
                std::cout << i << "," << j << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> left_matrix = gen_left_matrix(12);
    std::vector<std::vector<int>> right_matrix = gen_right_matrix(12);
    std::cout << left_matrix.size() << "," << left_matrix[0].size()
              << std::endl;
    std::cout << right_matrix.size() << "," << right_matrix[0].size()
              << std::endl;
    int row1 = left_matrix.size();
    int col1 = left_matrix[0].size();
    int row2 = right_matrix.size();
    int col2 = right_matrix[0].size();

    int nmax = std::max(std::max(row1, col1), std::max(row2, col2));
    int nearest = get_2_n(nmax);
    auto left_matrix_expand = expand(nearest, left_matrix);
    auto right_matrix_expand = expand(nearest, right_matrix);

    auto tradition = traditional_matrix_mul(left_matrix, right_matrix);
    auto modern = strassen(left_matrix_expand, right_matrix_expand);
    if (matrix_equal(tradition, modern)) {
        std::cout << "the result of strassen is right" << std::endl;
    } else {
        std::cout << "the result of strassen is wrong" << std::endl;
    }

    return 0;
}
