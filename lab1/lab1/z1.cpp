#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int processArray(int a[], int sort[], size_t N) {

    for (int i = 0; i < N; i++)//çàïîëíÿåì ñòåïåíÿìè 2 è 3
    {
        if (i % 2 == 0)
        {
            a[i] = pow(2, i / 2);//ïîëó÷àåì, ÷òî åñëè ÷èñëî ê ïðèìåðó 0, òî åìó äàåòñÿ ñòåïåíü 0
        }
        else
        {
            a[i] = pow(3, (i + 1) / 2);// çäåñü ÷òîáû ïîëó÷èòü íóæíóþ ñòåïåðü ê ÷èñëó ïðèáàâëÿåì 1 è äåëèì
        }
    }

    int cnt = 0;// ñ÷åò÷èê

    for (int i = 0; i < N; i++)
    {
        int number = a[i];
        int copyn = number;// êîïèÿ ÷èñëà ÷òîáû íå òðîãàòü îñíîâíûå (íà âñÿêèé ñëó÷àé)

        while (copyn > 0)
        {
            int num1 = copyn % 10;// ïîëó÷àåì ïîñëåäíþþ öèôðó
            if (num1 == 1)
            {
                cnt++; // óâåëè÷èâàåì ñ÷¸ò÷èê åñëè íàøëè
                break; // âûõîäèì èç öèêëà äëÿ ýòîãî ÷èñëà
            }
            copyn = copyn / 10;// óáèðàåì ïîñëåäíþþ öèôðó
        }
    }

    for (int i = 0; i < N; i++)// êîïèðóåì ìàññèâ â sort
    {
        sort[i] = a[i];// êîïèÿ îñíîâíîãî ìàññèâà
    }

    for (int i = 0; i < N - 1; i++)// ñîðòèðîâêà ïóçûðüêîì
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (sort[j] > sort[j + 1]) {
                int temp = sort[j];// îáìåí ìåñòàìè
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }

    return cnt;// âîçâðàùàåì êîëè÷åñòâî ÷èñåë, ñîäåðæàùèõ 1
}

int main() 

{

    setlocale(LC_ALL, "Rus");
    const size_t N = 16;// ðàçìåð ìàññèâà
    int a[N];// ìàññèâ
    int sort[N];// ìàññèâ îòñîðòèðîâàííûé

    for (int i = 0; i < N; i++)// çàïîëíÿåì åäèíèöàìè 
    { 
        a[i] = 1; 
    }

    int cnt = processArray(a, sort, N);

    //âûâîäû
    printf("Èñõîäíûé ìàññèâ: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Îòñîðòèðîâàííûé: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", sort[i]);
    }
    printf("\n");

    printf("Êîë-âî ÷èñåë ñ öèôðîé 1: %d\n", cnt);

    return 0;
}
