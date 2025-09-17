#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char* my_strncpy(char* dest, const char* src, size_t num)// ������� ����������� �� �������� � strncpy.char* dest - ���� ��������, const char* src(������ ��������)
{                                              
    size_t i;
    for (i = 0; i < num && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    for (; i < num; i++)// ���� �������� ������, ��� num � ��������� ������
    {
        dest[i] = '\0';
    }
    return dest;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const char* src = "DONETSK";//�������� �����
    char dest1[20];//������ �� 20 ����� ��� ����������� �������
    char dest2[20];//��� �����

    printf("�������� ������: %s\n", src);

    //�������� 5 ��������
    strncpy(dest1, src, 5);
    dest1[5] = '\0';
    printf("����������� strncpy (5 ��������): %s\n", dest1);

    my_strncpy(dest2, src, 5);
    dest2[5] = '\0';
    printf("��� strncpy (5 ��������): %s\n", dest2);

    //�������� 15 ��������
    strncpy(dest1, src, 15);
    printf("����������� strncpy (15 ��������): %s\n", dest1);

    my_strncpy(dest2, src, 15);
    printf("��� strncpy (15 ��������): %s\n", dest2);

    //�������� ������ ������
    const char* empty = "";
    strncpy(dest1, empty, 5);
    printf("����������� strncpy (��� ��������): %s\n", dest1);

    my_strncpy(dest2, empty, 5);
    printf("��� strncpy (��� ��������): %s\n", dest2);

    return 0;
}
