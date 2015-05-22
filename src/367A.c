#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int m, l, r;
    char s[100005];
    int cntx[100005], cnty[100005], cntz[100005];
    memset(cntx, 0, sizeof(cntx));
    memset(cnty, 0, sizeof(cnty));
    memset(cntz, 0, sizeof(cntz));
    scanf("%s", s);
    for ( i = 0; s[i] != '\0'; i++ )
    {
        cntx[i+1] = cntx[i];
        cnty[i+1] = cnty[i];
        cntz[i+1] = cntz[i];
        if ( s[i] == 'x' )
            cntx[i+1] += 1;
        else if ( s[i] == 'y' )
            cnty[i+1] += 1;
        else if ( s[i] == 'z' )
            cntz[i+1] += 1;
    }
    scanf("%d", &m);
    while ( m-- )
    {
        scanf("%d%d", &l, &r);
        if ( r-l <= 1 )
            printf("YES\n");
        else if ( cntx[r]-cntx[l-1] < (r-l+1)/3 || cntx[r]-cntx[l-1] > (r-l+1)/3+1 || 
                  cnty[r]-cnty[l-1] < (r-l+1)/3 || cnty[r]-cnty[l-1] > (r-l+1)/3+1 ||
                  cntz[r]-cntz[l-1] < (r-l+1)/3 || cntz[r]-cntz[l-1] > (r-l+1)/3+1 )
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
