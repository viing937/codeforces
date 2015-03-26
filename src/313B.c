#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int m, l, r;
    int cnt[100005] = {0};
    char prech, ch;
    scanf("%c",&prech);
    for(i=1;prech!='\n';i++)
    {
        scanf("%c",&ch);
        if (ch==prech)
            cnt[i] = cnt[i-1]+1;
        else
            cnt[i] = cnt[i-1];
        prech = ch;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",cnt[r-1]-cnt[l-1]);
    }
    return 0;
}
