#include<stdlib.h>
#include<stdio.h>

int main()
{
	FILE* fp;
	int a, b, i, j, **arr, id1, id2, n;
	fp = fopen("matrix.txt","r");
	if (fp == NULL)
		exit(1);
	fscanf(fp,"%d",&a);
	fscanf(fp,"%d",&b);
	arr = (int**)malloc(sizeof(int*) * a);
	if (arr == NULL)
		exit(1);
	for(i = 0; i < a; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * b);
		if (arr[i] == NULL)
			exit(1);
	}
	for(i = 0; i < a; i++)
		for(j = 0; j < b; j++)
			arr[i][j] = 0;
	while(fscanf(fp, "%d %d %d", &id1, &id2, &n) != EOF)
		arr[id1 - 1][id2 - 1] = n;
	for(i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	for(i = 0; i < a; i++)
		free(arr[i]);
	free(arr);
	fclose(fp);
	return 0;
}