#include<cmath>
#include<cstdio>
#include<cstring>

bool prim(int n)
{
    int k=sqrt(n)+0.5;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(int i=3; i<=k; i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int f(int n,int k)
{
    if(n<k||prim(k)==0)
        return 0;
    int a=n/=k;
    for(int i=2; i<k&&i<=n; i++)
        a-=f(n,i);
    return a;
}

int main()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    printf("%d\n",f(b,k)-f(a-1,k));
    return 0;
}

