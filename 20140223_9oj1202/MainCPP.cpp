#include <stdio.h>
int main()
{
    int n;
    int buf[100];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
        scanf("%d",&buf[i]);
 
         
        }
        for(int l=0;l<n;l++)
        for(int j=0;j<n-1-l;j++){
            if(buf[j]>buf[j+1]){
            int tmp=buf[j];
            buf[j]=buf[j+1];
            buf[j+1]=tmp;
             
            }
         
        }
        for(int k=0;k<n;k++){
        printf("%d ",buf[k]);
         
        }
    printf("\n");
    }//end while
    //printf("%d",10);
    return 0;
}
/**************************************************************
    Problem: 1202
    User: KeyOfSpectator
    Language: C
    Result: Accepted
    Time:30 ms
    Memory:912 kb
****************************************************************/
