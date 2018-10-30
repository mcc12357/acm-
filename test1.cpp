#include<stdio.h>
#include"string.h"
#include"stdlib.h"
int main()
{
	char* src = (char*)"hello,world", *s, *d, *dest = NULL;
	int len = strlen(src);
	printf("%d\n",len);
	dest = (char*)malloc(len);
	d = dest;
	s = src + len - 1;
	for (int i = 0; i<len; i++)
	{
		*d++ = *s--;
	}
	printf("%s", dest);
}
