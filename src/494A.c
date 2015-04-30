#include <stdio.h>

int main()
{
    int i, index, tmp;
    int cnt, cnt_left, cnt_right;
    char s[100005];
    scanf("%s", s);
    for ( cnt = 0, i = 0; s[i] != '\0'; i++ )
    {
        if ( s[i] == '#' )
        {
            index = i;
            cnt += 1;
            s[i] = ')';
        }
    }
    cnt_left = cnt_right = 0;
    for ( i = 0; s[i] != '\0'; i++ )
    {
        if ( s[i] == '(' )
            cnt_left += 1;
        else if ( s[i] == ')' )
            cnt_right += 1;
    }
    tmp = cnt_left-cnt_right+1;
    if ( tmp <= 0 )
    {
        printf("-1\n");
        return 0;
    }
    cnt_left = cnt_right = 0;
    for ( i = 0; s[i] != '\0'; i++ )
    {
        if ( i == index )
            cnt_right += tmp;
        else if ( s[i] == '(' )
            cnt_left += 1;
        else if ( s[i] == ')' )
            cnt_right += 1;
        if ( cnt_right > cnt_left )
        {
            printf("-1\n");
            return 0;
        }
    }
    for ( i = 0; i < cnt-1; i++ )
        printf("1\n");
    printf("%d\n", tmp);
    return 0;
}
