
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a non-zero element in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    vector<Element> elements;
};

// Function to display a sparse matrix
void displaySparseMatrix(SparseMatrix& matrix) {
    int k = 0;
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            if (k < matrix.numElements && matrix.elements[k].row == i && matrix.elements[k].col == j) {
                cout << matrix.elements[k].value << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(SparseMatrix& A, SparseMatrix& B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        cerr << "Matrices must have the same dimensions for addition." << endl;
        exit(1);
    }

    SparseMatrix result;
    result.rows = A.rows;
    result.cols = A.cols;
    result.numElements = 0;

    int i = 0, j = 0;
    while (i < A.numElements && j < B.numElements) {
        if (A.elements[i].row < B.elements[j].row || (A.elements[i].row == B.elements[j].row && A.elements[i].col < B.elements[j].col)) {
            result.elements.push_back(A.elements[i]);
            i++;
        } else if (A.elements[i].row > B.elements[j].row || (A.elements[i].row == B.elements[j].row && A.elements[i].col > B.elements[j].col)) {
            result.elements.push_back(B.elements[j]);
            j++;
        } else {
            Element newElement;
            newElement.row = A.elements[i].row;
            newElement.col = A.elements[i].col;
            newElement.value = A.elements[i].value + B.elements[j].value;
            result.elements.push_back(newElement);
            i++;
            j++;
        }
        result.numElements++;
    }

    // Copy any remaining elements from A
    for (; i < A.numElements; i++) {
        result.elements.push_back(A.elements[i]);
        result.numElements++;
    }

    // Copy any remaining elements from B
    for (; j < B.numElements; j++) {
        result.elements.push_back(B.elements[j]);
        result.numElements++;
    }

    return result;
}

// Function to multiply two sparse matrices
SparseMatrix multiplySparseMatrices(SparseMatrix& A, SparseMatrix& B) {
    if (A.cols != B.rows) {
        cerr << "Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication." << endl;
        exit(1);
    }

    SparseMatrix result;
    result.rows = A.rows;
    result.cols = B.cols;
    result.numElements = 0;

    // Initialize a vector to store the columns of matrix B
    vector<vector<int>> Bcols(B.cols);

    // Populate the Bcols vector
    for (int i = 0; i < B.numElements; ++i) {
        Bcols[B.elements[i].col].push_back(i);
    }

    // Perform matrix multiplication
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            int sum = 0;
            for (int k = 0; k < A.cols; ++k) {
                // Search for matching elements in A's row and B's column
                for (int idx : Bcols[j]) {
                    if (A.elements[k].row == i && B.elements[idx].row == k) {
                        sum += A.elements[k].value * B.elements[idx].value;
                        break;
                    }
                }
            }
            if (sum != 0) {
                Element newElement;
                newElement.row = i;
                newElement.col = j;
                newElement.value = sum;
                result.elements.push_back(newElement);
                result.numElements++;
            }
        }
    }

    return result;
}

int main() {
    // Example sparse matrices
    SparseMatrix A = {3, 3, 4, {{0, 1, 3}, {1, 0, 4}, {2, 1, 2}, {2, 2, 5}}};
    SparseMatrix B = {3, 3, 3, {{0, 1, 2}, {1, 2, 6}, {2, 2, 1}}};

    cout << "Sparse Matrix A:" << endl;
    displaySparseMatrix(A);
    cout << endl;

    cout << "Sparse Matrix B:" << endl;
    displaySparseMatrix(B);
    cout << endl;

    // Addition of sparse matrices
    SparseMatrix sum = addSparseMatrices(A, B);
    cout << "Addition of A and B:" << endl;
    displaySparseMatrix(sum);
    cout << endl;

    // Multiplication of sparse matrices
    SparseMatrix product = multiplySparseMatrices(A, B);
    cout << "Multiplication of A and B:" << endl;
    displaySparseMatrix(product);

    return 0;
}
