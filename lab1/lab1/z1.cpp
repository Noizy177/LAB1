#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int processArray(int a[], int sort[], size_t N) {

    for (int i = 0; i < N; i++)//заполняем степенями 2 и 3
    {
        if (i % 2 == 0)
        {
            a[i] = pow(2, i / 2);//получаем, что если число к примеру 0, то ему дается степень 0
        }
        else
        {
            a[i] = pow(3, (i + 1) / 2);// здесь чтобы получить нужную степерь к числу прибавляем 1 и делим
        }
    }

    int cnt = 0;// счетчик

    for (int i = 0; i < N; i++)
    {
        int number = a[i];
        int copyn = number;// копия числа чтобы не трогать основные (на всякий случай)

        while (copyn > 0)
        {
            int num1 = copyn % 10;// получаем последнюю цифру
            if (num1 == 1)
            {
                cnt++; // увеличиваем счётчик если нашли
                break; // выходим из цикла для этого числа
            }
            copyn = copyn / 10;// убираем последнюю цифру
        }
    }

    for (int i = 0; i < N; i++)// копируем массив в sort
    {
        sort[i] = a[i];// копия основного массива
    }

    for (int i = 0; i < N - 1; i++)// сортировка пузырьком
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (sort[j] > sort[j + 1]) {
                int temp = sort[j];// обмен местами
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }

    return cnt;// возвращаем количество чисел, содержащих 1
}

int main() 

{

    setlocale(LC_ALL, "Rus");
    const size_t N = 16;// размер массива
    int a[N];// массив
    int sort[N];// массив отсортированный

    for (int i = 0; i < N; i++)// заполняем единицами 
    { 
        a[i] = 1; 
    }

    int cnt = processArray(a, sort, N);

    //выводы
    printf("Исходный массив: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Отсортированный: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", sort[i]);
    }
    printf("\n");

    printf("Кол-во чисел с цифрой 1: %d\n", cnt);

    return 0;
}
