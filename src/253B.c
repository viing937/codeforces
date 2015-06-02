#include <stdio.h>

int main()
{
    int i;
    int n;
    int c[5001] = {0};
    FILE *in = fopen("input.txt","r"), *out = fopen("output.txt","w");
    fscanf(in ,"%d", &n);
    for ( i = 0; i < n; i++ )
    {
        int tmp;
        fscanf(in, "%d", &tmp);
        c[tmp] += 1;
    }
    int cntl = 0, cntr = 0;
    for ( i = 3; i <= 5000; i++ )
        cntr += c[i];
    int ans = cntl+cntr;
    for ( i = 2; i <= 5000; i++ )
    {
        cntl += c[i-1];
        if ( i*2-1 <= 5000 )
            cntr -= c[i*2-1];
        if ( i*2 <= 5000 )
            cntr -= c[i*2];
        if ( cntl+cntr < ans )
            ans = cntl + cntr;
    }
    fprintf(out ,"%d\n", ans);
    fclose(in);
    fclose(out);
    return 0;
}
