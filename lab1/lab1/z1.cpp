#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int processArray(int a[], int sort[], size_t N) {

    for (int i = 0; i < N; i++)//��������� ��������� 2 � 3
    {
        if (i % 2 == 0)
        {
            a[i] = pow(2, i / 2);//��������, ��� ���� ����� � ������� 0, �� ��� ������ ������� 0
        }
        else
        {
            a[i] = pow(3, (i + 1) / 2);// ����� ����� �������� ������ ������� � ����� ���������� 1 � �����
        }
    }

    int cnt = 0;// �������

    for (int i = 0; i < N; i++)
    {
        int number = a[i];
        int copyn = number;// ����� ����� ����� �� ������� �������� (�� ������ ������)

        while (copyn > 0)
        {
            int num1 = copyn % 10;// �������� ��������� �����
            if (num1 == 1)
            {
                cnt++; // ����������� ������� ���� �����
                break; // ������� �� ����� ��� ����� �����
            }
            copyn = copyn / 10;// ������� ��������� �����
        }
    }

    for (int i = 0; i < N; i++)// �������� ������ � sort
    {
        sort[i] = a[i];// ����� ��������� �������
    }

    for (int i = 0; i < N - 1; i++)// ���������� ���������
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (sort[j] > sort[j + 1]) {
                int temp = sort[j];// ����� �������
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }

    return cnt;// ���������� ���������� �����, ���������� 1
}

int main() 

{

    setlocale(LC_ALL, "Rus");
    const size_t N = 16;// ������ �������
    int a[N];// ������
    int sort[N];// ������ ���������������

    for (int i = 0; i < N; i++)// ��������� ��������� 
    { 
        a[i] = 1; 
    }

    int cnt = processArray(a, sort, N);

    //������
    printf("�������� ������: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("���������������: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", sort[i]);
    }
    printf("\n");

    printf("���-�� ����� � ������ 1: %d\n", cnt);

    return 0;
}
