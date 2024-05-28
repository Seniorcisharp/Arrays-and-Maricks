namespace WorkingWithArrays
{
	using predicate = bool(*)(int);

	void defualtvelues(int*, int);
	int* allocateMemory(long long);
	void randomValues(int*, int);
	void displayArray(int*, int);
	int* resizeArray(int*& p, int oldLenght, int newLenght);
	void  Extendarray(int*& p, int oldLenght, int newLenght);
	int* filterByPredicate(int*, int, int&, predicate);
	bool isEven(int);
	int* transform(int*& p, int newLenght);
	int* addToStart(int* p, int value, int length);
	int* addToPosition(int* p, int value, int position, int length);
	int* removeFromPosition(int*, int, int);
	int* removeFromStart(int*, int);
	bool isOdd(int);
	bool isPositive(int);
	void bubbleSortBykey(int* array, int n);
	int sum(int* p, int n);
	int averagevalue(int* p, int n);
	int minvalue(int* p, int n);
	int maxvalue(int* p, int n);
}

