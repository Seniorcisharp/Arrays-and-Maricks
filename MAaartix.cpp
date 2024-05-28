#include "matrix.h"
#include "arrays.h"
#include <iostream>

int** WorkingWithMatrix::lowTriangleMatrix(int size)
{
    if (size <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int** matrix = new int* [size];
    for (size_t i = 0; i < size; i++)
    {
        int k = i + 1;
        matrix[i] = WorkingWithArrays::allocateMemoryInt(k);

        WorkingWithArrays::randomValues(matrix[i], k);
    }
    return matrix;
}

void WorkingWithMatrix::displayMatrixLow(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        WorkingWithArrays::displayArrayInt(matrix[i], i + 1);
        for (size_t j = i + 1; j < size; j++)
        {
            std::cout.width(5);
            std::cout << 0;
        }

        std::cout << std::endl;
    }
}

int** WorkingWithMatrix::convertToHighTriangleMatrix(int** matrix, int size)
{
    if (matrix == nullptr)
    {
        throw std::invalid_argument("Nullptr pointer");
    }
    if (size <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int** copy = new int* [size];
    for (size_t i = 0; i < size; i++)
    {
        copy[i] = WorkingWithArrays::allocateMemoryInt(size - i);
        for (size_t j = 0; j < size - i; j++)
        {
            copy[i][j] = matrix[j + i][i];
        }
    }
    return copy;
}

void WorkingWithMatrix::displayMatrixHigh(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            std::cout.width(5);
            std::cout << 0;
        }

        WorkingWithArrays::displayArrayInt(matrix[i], size - i);

        std::cout << std::endl;
    }
}