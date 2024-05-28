#include "arrays.h"
#include "iostream"

void WorkingWithArrays::defualtvelues(int* p, int lenght)
{
    for (int* q = p; q < p + lenght;q++)
    {
        *q = 1;
    }
}

int* WorkingWithArrays::allocateMemory(long long n)
{
    if (n <= 0) {
        throw std::out_of_range("Array lenght must be more ");
    }
    return new int[n];
}

void WorkingWithArrays::randomValues(int* p, int n) {
    if (n <= 0)
    {
        return;
    }
    srand(time(nullptr));
    for (int* q = p; q < p + n; q++) {
        *q = rand() % 100 - 50;
    }
}

int* WorkingWithArrays::removeFromPosition(int* p, int position, int length)
{
    if (length <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int* q = allocateMemory(length);

    for (int* r = p; r < p + position; r++, q++)
    {
        *q = *r;
    }

    q++;

    for (int* r = ++p; r < p + length - 1; r++, q++)
    {
        *q = *r;
    }

    delete[]p;
    return q;
}




int* WorkingWithArrays::filterByPredicate(int* p, int lenght, int& newLenght, predicate func)
{
    newLenght = 0;
    int* result = allocateMemory(lenght);
    for (int* r = p, *q = result;r < p + lenght; r++)
    {
        if (func(*r))
        {
            *q = *r;
            q++;
            newLenght++;
        }
    }
    return newLenght == lenght ? result : resizeArray(result, lenght, newLenght);
}

bool WorkingWithArrays::isEven(int number)
{
    return !(number % 2);
}

int* WorkingWithArrays::transform(int*& p, int newLenght)
{
    int* result = allocateMemory(newLenght);
    for (int* r = p, *q = result; r < p + newLenght; r++, q++)
    {
        *q = *r * *r;
    }
    return result;
}

void WorkingWithArrays::displayArray(int* p, int n)
{
    if (n <= 0)
    {
        return;
    }
    for (int* q = p; q < p + n; q++) {
        std::cout << *q << " ";
    }
}

void WorkingWithArrays::Extendarray(int*& p, int oldLenght, int newLenght)
{
    if (newLenght < oldLenght) {
        throw std::invalid_argument("cant less");
    }
    if (newLenght == oldLenght) {
        return;
    }
    int* q = allocateMemory(newLenght);
    for (int* r = p, *s = q; r < p + oldLenght; r++, q++)
    {
        *q = *r;
    }
    delete[]p;
    p = q;
}

int* WorkingWithArrays::addToStart(int* p, int value, int length)
{
    int* q = allocateMemory(length + 1);
    *q++ = value;
    for (int* r = p; r < p + length; r++, q++)
    {
        *q = *r;
    }
    delete[]p;
    return q;
}

int* WorkingWithArrays::addToPosition(int* p, int value, int position, int length)
{
    int* q = allocateMemory(length + 1);
    for (int* r = p; r < p + position; r++, q++)
    {
        *q = *r;
    }
    *++q = value;
    for (int* r = ++p; r < p + length + 1; r++, q++)
    {
        *q = *r;
    }
    delete[]p;
    return q;
}

int* WorkingWithArrays::removeFromStart(int* p, int length)
{
    if (length <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int* q = allocateMemory(length - 1);

    for (int* r = ++p; r < p + length; r++, q++)
    {
        *q = *r;
    }

    delete[]p;
    return q;
}




bool WorkingWithArrays::isOdd(int number)
{
    return (number % 2);
}

bool WorkingWithArrays::isPositive(int number)
{
    return number > 0;
}

void WorkingWithArrays::bubbleSortBykey(int* array, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int WorkingWithArrays::sum(int* p, int n)
{
    int sum = 0;
    for (int* q = p; q < p + n; q++)
    {
        sum += *q;
    }
    return sum;
}

int WorkingWithArrays::averagevalue(int* p, int n)
{
    int sum = 0;
    for (int* q = p; q < p + n; q++)
    {
        sum += *q;
    }
    return sum / n;
}

int WorkingWithArrays::minvalue(int* p, int n)
{
    int value = *p;
    for (int* q = p + 1; q < p + n; q++)
    {
        if (*q < value)
        {
            value = *q;
        }
    }
    return value;
}

int WorkingWithArrays::maxvalue(int* p, int n)
{
    int value = *p;
    for (int* q = ++p; q < p + n; q++)
    {
        if (*q > value)
        {
            value = *q;
        }

    }
    return value;
}




