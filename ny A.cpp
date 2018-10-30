#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		char a[55];
		//memset(a,-1,sizeof(a));
		scanf("%s",a);
		char *p = a;
		while(*p!='=') p++;
		p++;
		char *q = p;
		while(*q!='+' && *q!='\0') q++;
		q--;
		char *t=p;
		int res = 0;
		int m;
		if(*t>='0' && *t<='9')
		{
			m = *t - '0';
			t++;
		}
		else m = 1;
		while(t<=q)
		{
			
			if(*t=='N')
			{
				if(*(t+1)=='a')
				{
					if(*(t+2)<='9' && *(t+2)>='0') 
					{
						res += 23 * (*(t+2)-'0');
						t += 3;
					}
					else 
					{
						res += 23;
						t += 2;
					}
				}
				else
				{
					if(*(t+1)<='9' && *(t+1)>='0')
					{
						res += 14 * (*(t+1)-'0');
						t += 2;
					}
					else 
					{
						res += 14;
						t++;
					}
				}
			}
			if(*t=='C')
			{
				if(*(t+1)=='a')
				{
					if(*(t+2)<='9' && *(t+2)>='0') 
					{
						res += 40 * (*(t+2)-'0');
						t += 3;
					}
					else 
					{
						res += 40;
						t += 2;
					}
				}
				else if(*(t+1)=='l')
				{
					if(*(t+2)<='9' && *(t+2)>='0') 
					{
						res += 35 * (*(t+2)-'0');
						t += 3;
					}
					else 
					{
						res += 35;
						t += 2;
					}
				}
				else 
				{
					if(*(t+1)<='9' && *(t+1)>='0')
					{
						res += 12 * (*(t+1)-'0');
						t += 2;
					}
					else 
					{
						res += 12;
						t++;
					}
				}
			}
			if(*t=='O')
			{
				if(*(t+1)<='9' && *(t+1)>='0')
				{
					res += 16 * (*(t+1)-'0');
					t += 2;
				}
				else 
				{
					res += 16;
					t++;
				}
			}
			if(*t=='S')
			{
				if(*(t+1)<='9' && *(t+1)>='0')
				{
					res += 32 * (*(t+1)-'0');
					t += 2;
				}
				else 
				{
					res += 32;
					t++;
				}
			}
			if(*t=='H')
			{
				if(*(t+1)<='9' && *(t+1)>='0')
				{
					res += 2 * (*(t+1)-'0');
					t += 2;
				}
				else 
				{
					res += 2;
					t++;
				}
			}
			if(*t=='A')
			{
				if(*(t+2)<='9' && *(t+2)>='0')
				{
					res += 27 * (*(t+2)-'0');
					t += 3;
				}
				else 
				{
					res += 27;
					t += 2;
				}
			}
			if(*t=='Z')
			{
				if(*(t+2)<='9' && *(t+2)>='0')
				{
					res += 65 * (*(t+2)-'0');
					t += 3;
				}
				else 
				{
					res += 65;
					t += 2;
				}
			}
			if(*t=='(')
			{
				char *tt=t+1;
				int res1 = 0;
				while(*tt!=')')
				{
					if(*tt=='N')
						{
							if(*(tt+1)=='a')
							{
								if(*(tt+2)<='9' && *(tt+2)>='0') 
								{
									res1 += 23 * (*(tt+2)-'0');
									tt += 3;
								}
								else 
								{
									res1 += 23;
									tt += 2;
								}
							}
							else
							{
								if(*(tt+1)<='9' && *(tt+1)>='0')
								{
									res1 += 14 * (*(tt+1)-'0');
									tt += 2;
								}
								else 
								{
									res1 += 14;
									tt++;
								}
							}
						}
						if(*tt=='C')
						{
							if(*(tt+1)=='a')
							{
								if(*(tt+2)<='9' && *(tt+2)>='0') 
								{
									res1 += 40 * (*(tt+2)-'0');
									tt += 3;
								}
								else 
								{
									res1 += 40;
									tt += 2;
								}
							}
							else if(*(tt+1)=='l')
							{
								if(*(tt+2)<='9' && *(tt+2)>='0') 
								{
									res1 += 35 * (*(tt+2)-'0');
									tt += 3;
								}
								else 
								{
									res1 += 35;
									tt += 2;
								}
							}
							else 
							{
								if(*(tt+1)<='9' && *(tt+1)>='0')
								{
									res1 += 12 * (*(tt+1)-'0');
									tt += 2;
								}
								else 
								{
									res1 += 12;
									tt++;
								}
							}
						}
						if(*tt=='O')
						{
							if(*(tt+1)<='9' && *(tt+1)>='0')
							{
								res1 += 16 * (*(tt+1)-'0');
								tt += 2;
							}
							else 
							{
								res1 += 16;
								tt++;
							}
						}
						if(*tt=='S')
						{
							if(*(tt+1)<='9' && *(tt+1)>='0')
							{
								res1 += 32 * (*(tt+1)-'0');
								tt += 2;
							}
							else 
							{
								res1 += 32;
								tt++;
							}
						}
						if(*tt=='H')
						{
							if(*(tt+1)<='9' && *(tt+1)>='0')
							{
								res1 += 2 * (*(tt+1)-'0');
								tt += 2;
							}
							else 
							{
								res1 += 2;
								tt++;
							}
						}
						if(*tt=='A')
						{
							if(*(tt+2)<='9' && *(tt+2)>='0')
							{
								res1 += 27 * (*(tt+2)-'0');
								tt += 3;
							}
							else 
							{
								res1 += 27;
								tt += 2;
							}
						}
						if(*tt=='Z')
						{
							if(*(tt+2)<='9' && *(tt+2)>='0')
							{
								res1 += 65 * (*(tt+2)-'0');
								tt += 3;
							}
							else 
							{
								res1 += 65;
								tt += 2;
							}
						}
				}
				t = tt;
				if(*(t+1)>='0' && *(t+1)<='9')
				{
					res += res1 * (*(t+1)-'0');
					t += 2;
				}
				else 
				{
					res += res1;
					t++;
				}
			}
		}
	int yy = res * m;
	if(yy>=0 && yy<=9) printf("000%d\n",yy);
	else if(yy>=10 && yy<=99) printf("00%d\n",yy);
	else if(yy>=100 && yy<=999) printf("0%d\n",yy);
	else printf("%d\n",yy);
	}
}