#include "iostream"  
  
using namespace std;  
#define N 10  
  
void char_to_int(int *a , char* ch){  
    int len = strlen(ch);  
    int i = 0, term = 0;  
    for(i = 0 ; i < N ; i++){  
        a[i] = 0;  
    }  
  
    for(i = 0 ; i < len ; i++){  
        term = ch[i];  
        a[len-i-1] = (term - '0');  
  
    }  
}   
  
int main()  
{  
    int a[N],b[N],c[2*N];  
    char ch1[N], ch2[N];  
    int i = 0 , j =0;  
    cout<<"1:";  
    cin>>ch1;  
    cout<<"2:";  
    cin>>ch2;  
    scanf("s", &ch2);  
    char_to_int(a , ch1);  
    char_to_int(b , ch2);  
      
    for(i = 0 ; i < 2*N ; ++i){  
        c[i] = 0;  
    }  
    for(i = 0 ; i < N ; ++i){  
        for(j = 0 ; j < N ; ++j){  
            c[i+j] += a[i] * b[j];  
        }  
    }  
    for(i = 0 ; i < 2*N -1 ; ++i){  
        c[i+1] += c[i] /10;  
        c[i] = c[i] % 10;  
    }  
    j = 2*N -1;  
  
    while(c[j] == 0)    
               j--;    
    for(i = j;i >= 0; --i)    
           printf("%d",c[i]);    
    printf("\n");    
    return 0;    
}  