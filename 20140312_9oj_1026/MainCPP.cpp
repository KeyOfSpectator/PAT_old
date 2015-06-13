
#include <stdio.h>
 
 
int main(){
    int m;
    //long long a,b;
    long a,b;
    //char a[20],b[20],c[20];
    //while(scanf("%d%lld%lld",&m,&a,&b)!=EOF){
    while(scanf("%d",&m)!=EOF){
        if(m==0)break;
        scanf("%ld%ld",&a,&b);
        a=a+b;
        char ans[100];
        int i=0;
        do{
            ans[i++]=a%m+'0';
            a/=m;
        }while(a!=0);
 
        for(int j=i-1;j>=0;j--){
            printf("%d",ans[j]-'0');
        }
        printf("\n");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1026
    User: KeyOfSpectator
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1020 kb
****************************************************************/
