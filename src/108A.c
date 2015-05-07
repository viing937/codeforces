#include <stdio.h>

int main()
{
    int h, m;
    scanf("%d:%d", &h, &m);
    if ( h%10*10+h/10 < 60 && h%10*10+h/10 > m )
        printf("%02d:%02d\n", h, h%10*10+h/10);
    else
    {
        h = (h+1)%24;
        while ( h%10*10+h/10 >= 60 )
            h++;
        printf("%02d:%02d\n", h, h%10*10+h/10);
    }
    return 0;
}
