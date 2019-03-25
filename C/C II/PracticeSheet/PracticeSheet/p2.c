#include <stdio.h>

void itobs(unsigned int no, char* str)
{
	int i = 31, j = 0;
	while(!(no & (1 << i)) && i != 0)
		i--;
	for(;i >= 0;i--)
	{
		if(no & (1 << i))
			str[j] = '1';
		else
			str[j] = '0';
		j++;
	}
	str[j] = '\0';
	printf("%s\n",str);
}

int main()
{
	char str[32];
	unsigned int no;
	scanf("%u",&no);
	itobs(no,str);
	return 0;
}