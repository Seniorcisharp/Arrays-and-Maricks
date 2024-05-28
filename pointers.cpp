#include <iostream>
#include "Matrix.h"
#include "arrays.h"
using namespace std;
using namespace WorkingWithArrays;
using namespace WorkingWithMatrix;

int main()
{
	int n;
	cin >> n;
	int* array = WorkingWithArrays::allocateMemory(n);
	WorkingWithArrays::randomValues(array, n);
	WorkingWithArrays::displayArray(array, n);
	cout << endl;

	int k = 0;
	int* oddArray = WorkingWithArrays::filterByPredicate(array, n, k, WorkingWithArrays::isOdd);
	WorkingWithArrays::displayArray(oddArray, k);
	cout << endl;

	int* evenArray = WorkingWithArrays::filterByPredicate(array, n, k, WorkingWithArrays::isEven);
	WorkingWithArrays::displayArray(evenArray, k);
	cout << endl;

	int** lowTriangleMatrix = WorkingWithMatrix::lowTriangleMatrix(5);
	int** highTriangleMatrix = WorkingWithMatrix::convertToHighTriangleMatrix(lowTriangleMatrix, 5);
	WorkingWithMatrix::displayMatrixHigh(highTriangleMatrix, 5);

	
	
}




