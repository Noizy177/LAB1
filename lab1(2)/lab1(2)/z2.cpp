#include <iostream>//��� ����� � ������
#include <iomanip>//��� �������������� ������
#include <algorithm>// ��� sort
using namespace std;

int* initializeArray(int n)//������� ������������� (������� ������ �� ������ �����, � ����� � ������ �� ������ ����� � �������)
{
    int* arr = new int[n];//������������ ��������� (���������� ����� ���� ����� ������, ������� ��� ������� new)
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * i - 1;
        if (i % 2 != 0) arr[i] *= -1;// �������� �� -1 ��� �������� �������
    }
    return arr;//���������� ��������� arr
}

void print1D(int* arr, int n)// ����� 1D �������
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << arr[i];// setw(5) ������ ������ ���� ��� ������ ���������� �������� � 5 ��������
    }
    cout << endl;
}

int** convert1Din2D(int* arr, int rows, int cols)// �������������� 1D � 2D (���������� �� ��������)
{// int** - ����� �������, � ������� �������� ������ ����� ��������� �������
    int** matrix = new int* [rows];// ��������� ������. ������ ������� ����� ������� ����� ����������� ������� (����� ������ ������� �������)
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];//��� ������ ������ �������� ������ ��� cols
    }

    int index = 0;//�������, ������� ����� ������ �� ��������� ��������� ����������� ������� arr
    for (int j = 0; j < cols; j++)//�������
    {
        for (int i = 0; i < rows; i++)//������
        {
            matrix[i][j] = arr[index++];//���������� �������� �� ij
        }
    }

    return matrix;
}

void print2D(int** matrix, int rows, int cols)// ����� 2D �������
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 18;
    int rows = 6, cols = 3;

    int* arr = initializeArray(n);// � ���������� arr (��������� ���� int*) ������������ ����� ������ �������

    cout << "�������� ������ (1D):" << endl;
    print1D(arr, n);

    sort(arr, arr + n, greater<int>());// ����������: sort - ������� �� <algorithm>, arr - ��������� �� ������ �������
                                       //arr + n - ��������� �� ����� �������, greater<int>() - ��� ������ ����������, � ����� ������ �� �������� � ��������

    cout << "\n��������������� ������ (1D):" << endl;
    print1D(arr, n);

    int** matrix = convert1Din2D(arr, rows, cols);// � ���������� matrix (��������� �� ��������� ���� int**) ������������ ����� ����� �������

    cout << "\n��������� ������:" << endl;
    print2D(matrix, rows, cols);

    delete[] arr;// ����������� ������, ������� ���������� ��������
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];// ����������� ������ ������ ������ �������
    }
    delete[] matrix;// ����������� ������ ������� ����������

    return 0;
}

