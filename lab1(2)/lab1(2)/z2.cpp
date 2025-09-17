#include <iostream>//дл€ ввода и вывода
#include <iomanip>//дл€ форматировани€ вывода
#include <algorithm>// дл€ sort
using namespace std;

int* initializeArray(int n)//функци€ инициализации (функци€ вернет не просто число, а адрес в пам€ти на первое число в массиве)
{
    int* arr = new int[n];//динамическое выделение (записываем адрес того куска пам€ти, который нам выделил new)
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * i - 1;
        if (i % 2 != 0) arr[i] *= -1;// умножаем на -1 при нечетном индексе
    }
    return arr;//возвращает указатель arr
}

void print1D(int* arr, int n)// вывод 1D массива
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << arr[i];// setw(5) ставит ширину пол€ дл€ вывода следующего элемента в 5 символов
    }
    cout << endl;
}

int** convert1Din2D(int* arr, int rows, int cols)// преобразовани€ 1D в 2D (заполнение по столбцам)
{// int** - адрес массива, в котором хран€тс€ адреса строк двумерной матрицы
    int** matrix = new int* [rows];// выделение пам€ти. каждый элемент будет хранить адрес одномерного массива (одной строки будущей матрицы)
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];//дл€ каждой строки выдел€ем пам€ть под cols
    }

    int index = 0;//счетчик, который будет бежать по элементам исходного одномерного массива arr
    for (int j = 0; j < cols; j++)//столбцы
    {
        for (int i = 0; i < rows; i++)//строки
        {
            matrix[i][j] = arr[index++];//присвоение значений по ij
        }
    }

    return matrix;
}

void print2D(int** matrix, int rows, int cols)// вывод 2D массива
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

    int* arr = initializeArray(n);// в переменную arr (указатель типа int*) записываетс€ адрес нового массива

    cout << "»сходный массив (1D):" << endl;
    print1D(arr, n);

    sort(arr, arr + n, greater<int>());// сортировка: sort - функци€ из <algorithm>, arr - указатель на начало массива
                                       //arr + n - указатель на конец массива, greater<int>() - это способ сортировки, в нашем случае от большего к меньшему

    cout << "\nќтсортированный массив (1D):" << endl;
    print1D(arr, n);

    int** matrix = convert1Din2D(arr, rows, cols);// ¬ переменную matrix (указатель на указатель типа int**) записываетс€ адрес новой матрицы

    cout << "\nƒвумерный массив:" << endl;
    print2D(matrix, rows, cols);

    delete[] arr;// освобождаем пам€ть, зан€тую одномерным массивом
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];// освобождаем пам€ть каждой строки матрицы
    }
    delete[] matrix;// освобождаем пам€ть массива указателей

    return 0;
}

