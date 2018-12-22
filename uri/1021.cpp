#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    scanf("%d.%d", &x, &y);
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", x / 100);
    x %= 100;
    printf("%d nota(s) de R$ 50.00\n", x / 50);
    x %= 50;
    printf("%d nota(s) de R$ 20.00\n", x / 20);
    x %= 20;
    printf("%d nota(s) de R$ 10.00\n", x / 10);
    x %= 10;
    printf("%d nota(s) de R$ 5.00\n", x / 5);
    x %= 5;
    printf("%d nota(s) de R$ 2.00\n", x / 2);
    x %= 2;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", x);
    printf("%d moeda(s) de R$ 0.50\n", y / 50);
    y %= 50;
    printf("%d moeda(s) de R$ 0.25\n", y / 25);
    y %= 25;
    printf("%d moeda(s) de R$ 0.10\n", y / 10);
    y %= 10;
    printf("%d moeda(s) de R$ 0.05\n", y / 5);
    y %= 5;
    printf("%d moeda(s) de R$ 0.01\n", y);
}