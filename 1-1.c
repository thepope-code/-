#include<stdio.h>

int main()
{
	int pathnum, price, number;
	char goods;
	scanf("%c %d %d %d", &goods, &pathnum, &price, &number);
	printf("%d:", pathnum);
	for(int i=1; i<=number; i++)
	{
		printf("%c", goods);
	}
	printf(" %d", price);
	return 0;
}

