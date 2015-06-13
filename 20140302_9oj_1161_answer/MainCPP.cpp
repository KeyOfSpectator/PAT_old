#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
using namespace std;
char drawing[3000][3000];
void tem(int ltx,int lty,int num){
        int i,j;
        for(i=0;i<num;++i){
                for(j=0;j<num;++j){
                        drawing[ltx+i][lty+j]=drawing[i][j];
                }
        }
}
void blank(int ltx,int lty,int num){
        int i,j;
        for(i=0;i<num;++i){
                for(j=0;j<num;++j){
                        drawing[ltx+i][lty+j]=' ';
                }
        }
}
int main(){
        int n,m,i,j,k;
        while(scanf("%d",&n)!=EOF){
                if(n==0) break;
        while(getchar() != '\n') continue;
                for(i=0;i<n;++i)
                        gets(drawing[i]);
                //cin>>m;
				scanf("%d",&m);

                for(k=1;k<m;k++){
                        for(i=0;i<n;i++)
                                for(j=0;j<n;j++){
                                        if(i!=0||j!=0){
                                                if(drawing[i][j]==' ') blank(i*pow(n,k),j*pow(n,k),pow(n,k));
                                                else tem(i*pow(n,k),j*pow(n,k),pow(n,k));
                                        }
                                }
                        if(drawing[0][0]==' ') blank(0,0,pow(n,k));
                }
                k=pow(n,m);
                for(i=0;i<k;i++){
                        for(j=0;j<k;j++)
                                cout<<drawing[i][j];
                        cout<<endl;
                }
        }
        return 0;
}