#include <stdio.h>
struct oneswap{
    int a;
    int b;
};
int main()
{
    int i, j;
    int index, temp;
    int n, k=0;
    int a[3005];
    struct oneswap swaplist[3005];
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(i=0; i<n-1; i++){
        index = i;
        for(j=i+1; j<n; j++)
            if(a[j]<a[index])
                index = j;
        if(index!=i){
            swaplist[k].a = i;
            swaplist[k].b = index;
            k++;
            temp = a[index];
            a[index] = a[i];
            a[i] = temp;
        }
    }
    printf("%d\n", k);
    for(i=0; i<k; i++)
        printf("%d %d\n", swaplist[i].a, swaplist[i].b);
    return 0;
}
