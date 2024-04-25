#include <iostream>
#include <cstdlib> // for rand()

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to initialize a matrix with random values
void initializeMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        throw std::invalid_argument("Number of columns of A must match the number of rows of B");
    }

    int** C = allocateMatrix(rowsA, colsB);

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0; // Initialize result to 0
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][j] * B[k][j];
            }
        }
    }

    return C;
}

// Main function
int main() {
    int rowsA = 2, colsA = 3;
    int rowsB = 3, colsB = 2;

    // Allocate and initialize matrices A and B
    int** A = allocateMatrix(rowsA, colsA);
    int** B = allocateMatrix(rowsB, colsB);

    initializeMatrix(A, rowsA, colsA);
    initializeMatrix(B, rowsB, colsB);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, rowsA, colsA);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B, rowsB, colsB);

    // Multiply A and B
    int** C = multiplyMatrices(A, rowsA, colsA, B, rowsB, colsB);

    std::cout << "Resulting Matrix C:" << std::endl;
    printMatrix(C, rowsA, colsB);

    // Deallocate matrices
    deallocateMatrix(A, rowsA);
    deallocateMatrix(B, rowsB);
    deallocateMatrix(C, rowsA);

    return 0;
}
