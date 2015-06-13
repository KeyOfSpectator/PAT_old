#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double n[200];
    while(1)
    {
        int index = 0;
        int j, flag = 1;
        double sum;
        char c;
        while(cin >> n[index++] ) 
            {
            c = getchar();
            if(c != ' ')
                break;
            c = getchar();
            if( c == '0')
            {
                flag = 0;
                break;
            }
            n[index++] = (int)c;
        }
        if( flag == 0 || (index == 1 && n[0] == 0))
            break;
            
        for(j = 0; j < index; j++)
        {
           if( n[j] == 42)// *
           {
               n[j+1] = n[j-1] * n[j+1];
               n[j] = -1;
               n[j-1] = -1;
           }
           else if ( n[j] == 47)// /
           {
               n[j+1] = n[j-1] / n[j+1];
               n[j] = -1;
               n[j-1] = -1;
           }
        }
        j = 0;
        while(n[j] ==  -1)
            j++;
        sum = n[j];
        for(j = 0; j < index; j++)
        {
            if( n[j] == 43)
            {
                while(n[j+1] == -1)
                    j++;
                sum += n[j+1];
            }
            else if( n[j] == 45)
            {
                while(n[j+1] == -1)
                    j++;
                sum -= n[j+1];
            }
        }
        printf("%.2f\n",sum);
                
    }
    return 0;
    
}