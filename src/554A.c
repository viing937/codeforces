#include <stdio.h>
#include <string.h>

int main()
{
    char s[30];
    scanf("%s", s);
    printf("%d\n", 26+(int)strlen(s)*25);
    return 0;
}
