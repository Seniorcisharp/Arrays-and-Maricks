#include "Matrix.h"
#include "arrays.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace WorkingWithArrays;

namespace WorkingWithMatrix
{
    using key = long long (*)(int*, int);

    int** lowTriangleMatrix(int size)
    {
        if (size <= 0)
        {
            throw std::out_of_range("Array length must be more than 0");
        }

        int** matrix = new int* [size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[i + 1];
            randomValues(matrix[i], i + 1);
        }
        return matrix;
    }

    void displayMatrixLow(int** matrix, int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            displayArray(matrix[i], i + 1);
            for (size_t j = i + 1; j < size; j++)
            {
                std::cout.width(5);
                std::cout << 0;
            }
            std::cout << std::endl;
        }
    }

    int** convertToHighTriangleMatrix(int** matrix, int size)
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
            copy[i] = new int[size - i];
            for (size_t j = 0; j < size - i; j++)
            {
                copy[i][j] = matrix[j + i][i];
            }
        }
        return copy;
    }

    int** Summarikc(int** MatrixLow, int** MatrixHigh, int size)
    {
        if (size <= 0)
        {
            throw std::out_of_range("Array length must be more than 0");
        }
        int** resultMatrix = new int* [size];
        for (int i = 0; i < size; i++)
        {
            resultMatrix[i] = new int[size];
            for (int j = 0; j < i + 1; j++)
            {
                if (i == j)
                {
                    resultMatrix[i][j] = MatrixLow[i][j] + MatrixHigh[i][j];
                    resultMatrix[j][i] = resultMatrix[i][j];
                }
            }
        }
        return resultMatrix;
    }

    int** displayMatrixHigh(int** matrix, int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                std::cout.width(5);
                std::cout << 0;
            }

            displayArray(matrix[i], size - i);

            std::cout << std::endl;
        }
        return matrix;
    }
    int* convertTo(int* array, int rows, int columns)
    {
        if (rows <= 0)
        {
            throw std::out_of_range("Matrix width must be more than 0");
        }

        if (columns <= 0)
        {
            throw std::out_of_range("Matrix length must be more than 0");
        }

        int** matrix = allocateMemory(rows, columns);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                matrix[i][j] = array[columns * i + j];
            }
        }

        return *matrix;
    }

    int* convertTo(int** matrix, int rows, int columns)
    {
        if (rows <= 0)
        {
            throw std::out_of_range("Matrix width must be more than 0");
        }

        if (columns <= 0)
        {
            throw std::out_of_range("Matrix length must be more than 0");
        }

        int* array = new int[rows * columns];
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                array[columns * i + j] = matrix[i][j];
            }
        }
        return array;
    }

    int** allocateMemory(int rows, int columns)
    {
        if (rows <= 0)
        {
            throw std::out_of_range("Matrix width must be more than 0");
        }

        if (columns <= 0)
        {
            throw std::out_of_range("Matrix length must be more than 0");
        }

        int** matrix = new int* [rows];
        for (size_t i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
        }

        return matrix;
    }

    void sortMatrix(int** matrix, int rows, int columns, key func)
    {
        if (matrix == nullptr)
        {
            throw std::invalid_argument("Nullptr pointer");
        }

        long long* array = new long long[rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = func(matrix[i], columns);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = rows - 1; j > i; j--)
            {
                if (array[j] < array[j - 1])
                {
                    std::swap(array[j], array[j - 1]);
                    std::swap(matrix[j], matrix[j - 1]);
                }
            }
        }

        delete[] array;
    }

    void initMatrix(int** matrix, int rows, int columns)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                cout << "[" << (i + 1) << "," << (j + 1) << "] = ";
                cin >> matrix[i][j];
            }
        }
        system("cls");
    }

    void displayMatrix(int** matrix, int rows, int columns, int width)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                cout.width(width);
                cout << matrix[i][j];
            }
            cout << endl;
        }
        system("cls");
    }

    void swap(int*& a, int*& b)
    {
        int* temp = a;
        a = b;
        b = temp;
    }

    long long sumOfElement(int* array, int size)
    {
        long long sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            sum += array[i];
        }
        return sum;
    }

    long long productOfElement(int* array, int size)
    {
        long long product = 1;
        for (size_t i = 0; i < size; i++)
        {
            product *= array[i];
        }
        return product;
    }
}