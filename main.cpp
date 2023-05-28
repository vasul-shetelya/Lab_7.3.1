// Lab_7_3_1.cpp
// < Шетеля Василь >
// Лабораторна робота № 7.3.1)
// Опрацювання динамічних багатовимірних масивів
// Варіант 6
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int SumNegativeRows(int** a, const int rowCount, const int colCount);
void FindSaddlePoints(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = ";
    cin >> rowCount;
    cout << "colCount = ";
    cin >> colCount;

    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int sumNegativeRows = SumNegativeRows(a, rowCount, colCount);
    cout << "Sum of elements in rows with at least one negative element: " << sumNegativeRows << endl;

    cout << endl;
    FindSaddlePoints(a, rowCount, colCount);
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumNegativeRows(int** a, const int rowCount, const int colCount)
{
    int sum = 0;
    for (int i = 0; i < rowCount; i++)
    {
        bool hasNegative = false;
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative)
        {
            for (int j = 0; j < colCount; j++)
                sum += a[i][j];
        }
    }
    return sum;
}

void FindSaddlePoints(int** a, const int rowCount, const int colCount)
{
    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            int currentElement = a[i][j];
            bool isMaxInRow = true;
            bool isMinInCol = true;

            for (int k = 0; k < colCount; k++)
            {
                if (a[i][k] > currentElement)
                {
                    isMaxInRow = false;
                    break;
                }
            }

            for (int k = 0; k < rowCount; k++)
            {
                if (a[k][j] < currentElement)
                {
                    isMinInCol = false;
                    break;
                }
            }

            if (isMaxInRow && isMinInCol)
            {
                cout << setw(4) << ++No << setw(6) << i << setw(6) << j << endl;
            }
        }
    }
}


