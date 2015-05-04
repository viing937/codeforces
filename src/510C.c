#include <stdio.h>
#include <string.h>

int find(char letter[], char target)
{
    int i = 0;
    for ( i = 0; i < 26; i++ )
        if ( letter[i] == target )
            return i;
    return -1;
}

int diff(char s1[], char s2[])
{
    int i;
    for ( i = 0; s1[i] != '\0' && s2[i] != '\0'; i++ )
        if ( s1[i] != s2[i] )
            return i;
    return -1;
}

int main()
{
    int i, j;
    int n;
    int tmp, index1, index2;
    char tmpchar;
    char letter[26];
    char s[105][105];
    for ( i = 0; i < 26; i++ )
        letter[i] = 'a'+i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%s", s[i]);
    for ( i = 1; i < n; i++ )
    {
        tmp = diff(s[i], s[i-1]);
        if ( tmp == -1 )
        {
            if ( strlen(s[i-1]) > strlen(s[i]) )
            {
                printf("Impossible\n");
                return 0;
            }
        }
        else
        {
            index1 = find(letter, s[i-1][tmp]);
            index2 = find(letter, s[i][tmp]);
            if ( index1 > index2 )
            {
                tmpchar = letter[index2];
                for ( j = index2; j < index1; j++ )
                    letter[j] = letter[j+1];
                letter[index1] = tmpchar;
            }
        }
    }
    //again
    for ( i = 1; i < n; i++ )
    {
        tmp = diff(s[i], s[i-1]);
        if ( tmp == -1 )
        {
            if ( strlen(s[i-1]) > strlen(s[i]) )
            {
                printf("Impossible\n");
                return 0;
            }
        }
        else
        {
            index1 = find(letter, s[i-1][tmp]);
            index2 = find(letter, s[i][tmp]);
            if ( index1 > index2 )
            {
                tmpchar = letter[index2];
                for ( j = index2; j < index1; j++ )
                    letter[j] = letter[j+1];
                letter[index1] = tmpchar;
            }
        }
    }
    for ( i = 1; i < n; i++ )
    {
        tmp = diff(s[i], s[i-1]);
        if ( tmp != -1 )
        {
            index1 = find(letter, s[i-1][tmp]);
            index2 = find(letter, s[i][tmp]);
            if ( index1 > index2 )
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    for ( i = 0; i < 26; i++ )
        printf("%c", letter[i]);
    printf("\n");
    return 0;
}
