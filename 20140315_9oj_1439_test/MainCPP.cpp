#include <stdio.h>
 
int LCM(int a,int b){
    int temp_a=a,temp_b=b;
    int c=a*b;
    while(a!=0&&b!=0){
        a>b?a=a%b:b=b%a;
    }
    if(a==0&&b==0)c=0;
    else
        //a==0?c/=b:c/=a;
        a==0?c=temp_a/b*temp_b:c=temp_b/a*temp_a;
    return c;
}
 
int main(){
    int n;
    freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt", "r", stdin );
    while(scanf("%d",&n)!=EOF){
        while(n--){
            int m;
            int data,data2;
            scanf("%d",&m);
            scanf("%d",&data);
            if(data==0){printf("%d\n",data);break;}
            for(int i=1;i<m;i++){
                scanf("%d",&data2);
                if(data2==0){data=0;break;}
                //if(data%data2!=0)
                data=LCM(data,data2);
            }
             
            printf("%d\n",data);
         
         
        }
     
     
    }
    return 0;
}
 
/**************************************************************
    Problem: 1439
    User: KeyOfSpectator
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1020 kb
****************************************************************/