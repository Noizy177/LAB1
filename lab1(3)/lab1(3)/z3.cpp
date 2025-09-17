#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char* my_strncpy(char* dest, const char* src, size_t num)// фцнкция копирования по аналогии с strncpy.char* dest - куда копируем, const char* src(откуда копируем)
{                                              
    size_t i;
    for (i = 0; i < num && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    for (; i < num; i++)// если символов меньше, чем num — заполняем нулями
    {
        dest[i] = '\0';
    }
    return dest;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const char* src = "DONETSK";//исходный текст
    char dest1[20];//массив на 20 ячеек для стандартной функции
    char dest2[20];//для нашей

    printf("Исходная строка: %s\n", src);

    //копируем 5 символов
    strncpy(dest1, src, 5);
    dest1[5] = '\0';
    printf("Стандартная strncpy (5 символов): %s\n", dest1);

    my_strncpy(dest2, src, 5);
    dest2[5] = '\0';
    printf("Моя strncpy (5 символов): %s\n", dest2);

    //копируем 15 символов
    strncpy(dest1, src, 15);
    printf("Стандартная strncpy (15 символов): %s\n", dest1);

    my_strncpy(dest2, src, 15);
    printf("Моя strncpy (15 символов): %s\n", dest2);

    //копируем пустую строку
    const char* empty = "";
    strncpy(dest1, empty, 5);
    printf("Стандартная strncpy (без символов): %s\n", dest1);

    my_strncpy(dest2, empty, 5);
    printf("Моя strncpy (без символов): %s\n", dest2);

    return 0;
}
