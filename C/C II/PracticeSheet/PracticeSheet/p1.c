#include <stdio.h>

int main()
{
	int i, j, t;
	char ch;
	scanf("%d",&t);
	getchar();
	scanf("%c",&ch);
	
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < i+1; j++)
			printf("%c",ch);
		printf("\n");
	}
	return 0;
}