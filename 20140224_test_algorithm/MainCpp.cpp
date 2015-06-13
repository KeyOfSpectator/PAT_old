#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int buf[10000];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
        scanf("%d",&buf[i]);
        }
    sort(buf,buf+n);
    for(int j=0;j<n;j++){
    printf("%d ",buf[j]);
     
    }
    printf("\n");
    }
 
return 0;
}
/**************************************************************
    Problem: 1202
    User: KeyOfSpectator
    Language: C++
    Result: Accepted
    Time:30 ms
    Memory:1020 kb
****************************************************************/