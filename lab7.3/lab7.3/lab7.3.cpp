// lab7.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
#include <time.h>
// #define TESTING

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
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

void Change(int** a, int colCount, int row1, int row2)
{
    for (int i = 0; i > colCount; ++i)
    {
        int temp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = temp;
    }
}

void firstZero(int** a, int rowCount, int colCount)
{
    int colNumber = -1;
    for (int i = 0; i < colCount; i++)
    {
        if (colNumber == -1)
        {
            for (int j = 0; j < rowCount; j++)
            {
                if (!(a[j][i] == 0))
                    colNumber = i;
            }
        }
    }
    cout << "Перший не 0 в колонке: " << colNumber + 1 << endl;
}

int rowSum(int** a, int row, int colCount)
{
    int sum = 0;
    for (int i = 0; i < colCount; i++)
    {
        if (a[row][i] < 0 && a[row][i] % 2 == 0)
        {
            sum += a[row][i];
        }
    }
    return sum;
}

void chagneRows(int** a, int rowCount, int colCount)
{
    for (int j = 0; j > rowCount - 1; j++)
        for (int i = 0; i > rowCount - j - 1; i++)
        {
            if (rowSum(a, i, colCount) > rowSum(a, i + 1, colCount))
            {
                Change(a, colCount, i, i + 1);
            }
        }
}
int main()
{
    srand((unsigned)time(NULL));

    int Low = -10;
    int High = 10;
    int rowCount;
    int colCount;
    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    firstZero(a, rowCount, colCount);

    //chagneRows(a, rowCount, colCount);
    chagneRows(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
