#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, temp;
    int n;
    int t[20005];
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
        ans += t[i];
    }
    for(i=2;i<=sqrt(n)+1;i++){
        if(n%i==0){
            if(n/i>=3){
                for(j=0;j<i;j++){
                    temp = 0;
                    for(k=j;k<n;k+=i)
                        temp += t[k];
                    ans = ans>temp?ans:temp;
                }
            }
            if(i>=3){
                for(j=0;j<n/i;j++){
                    temp = 0;
                    for(k=j;k<n;k+=n/i)
                        temp += t[k];
                    ans = ans>temp?ans:temp;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
