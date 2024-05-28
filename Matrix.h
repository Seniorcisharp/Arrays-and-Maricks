 namespace WorkingWithMatrix 
{
     using key = long long (*)(int*, int);
     int** lowTriangleMatrix(int);
     int** convertToHighTriangleMatrix(int**, int);
     int** displayMatrixHigh(int** matrix, int size);
     int** Summarikc(int** MatrixLow, int** MatrixHight, int size);
     int* convertTo(int* array, int rows, int columns);
     int** allocateMemory(int rows, int columns);
     void sortMatrix(int**, int, int, key);
     void initMatrix(int**, int, int);
     void displayMatrix(int**, int, int, int width);
     void swap(int*&, int*&);
     long long   sumOfElement(int*, int);
     long long productOfElement(int* array, int size);

}


