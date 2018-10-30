 
#include<stdio.h>
#include<string.h>
int main()
{
 char str[1010];
 int i,j,n,a;
 while(gets(str)&&strcmp(str,"EOF"))
 {   
 /* gets(str);
     if(strcmp(str,EOF)==0)
  break;
  */
  n=strlen(str);
  for(i=0;i<n;i++)
  {    
   if(str[i]=='y'&&str[i+1]=='o'&&str[i+2]=='u'
            )
   {   
    str[i]='w';
    str[i+1]='e';
    a=i;
    for(a=i+3,j=i+2;a<=n;a++,j++)
     str[j]=str[a];
    i=i+1;
    n--;
   }
   
  /* else{ 
   if(str[i-1]==' '&&str[i]=='y'&&str[i+1]=='o'&&str[i+2]=='u'&&(str[i+3]>'z'||str[i+3]<'a'))
   {   
    str[i]='w';
    str[i+1]='e';
    a=i;
    for(a=i+3,j=i+2;a<=n;a++,j++)
     str[j]=str[a];
    i=i+1;
    n--;
   }
   }*/
  }
  printf("%s\n",str);
 }
 return 0;
}
  