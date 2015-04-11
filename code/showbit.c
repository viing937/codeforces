#include <stdio.h>

void showbit( int a )
{
    int i;
    int temp;
    for ( i = 0; i < 32; i++ )
    {
        temp = 1;
        if ( (a&temp<<(31-i)) != 0 )
            printf( "1" );
        else
            printf( "0" );
    }
    printf( "\n" );
    return;
}

int main()
{
    int a;
    scanf("%d",&a);
    showbit(a);
    return 0;
}
