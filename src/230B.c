#include <stdio.h>
#include <math.h>

int isprime(int num)
{
    int i;
    for(i=2; i<=sqrt(num); i++ )
        if(num%i==0)
            return 0;
    return 1;
}

int main()
{
    int n;
    long long x, sq;
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&x);
        if( x<=2 )
            printf("NO\n");
        else
        {
            sq = (long long)sqrt(x);
            if( sq*sq==x && isprime(sq) )
                printf("YES\n");
            else
                printf("NO\n");
        }   
    }
    return 0;
}
