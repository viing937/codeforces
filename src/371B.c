#include <stdio.h>

void div(int *cnt2, int *cnt3, int *cnt5, int *x)
{
    *cnt2 = *cnt3 = *cnt5 = 0;
    while ( *x%2 == 0 )
    {
        *cnt2 += 1;
        *x /= 2;
    }
    while ( *x%3 == 0 )
    {
        *cnt3 += 1;
        *x /= 3;
    }
    while ( *x%5 == 0 )
    {
        *cnt5 += 1;
        *x /= 5;
    }
    return;
}

int dis(int a, int b)
{
    return a>b ? a-b : b-a;
}

int main()
{
    int cnta2, cnta3, cnta5;
    int cntb2, cntb3, cntb5;
    int a, b;
    scanf("%d%d", &a, &b);
    div(&cnta2, &cnta3, &cnta5, &a);
    div(&cntb2, &cntb3, &cntb5, &b);
    if ( a != b )
        printf("-1\n");
    else
        printf("%d\n", dis(cnta2,cntb2)+dis(cnta3,cntb3)+dis(cnta5,cntb5));
    return 0;
}
