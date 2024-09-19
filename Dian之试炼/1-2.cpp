#include<stdio.h>

int main()
{
	int totalprice, change, totalpay=0, changeback;
	scanf("%d", &totalprice);
	while(1)
	{
		scanf("%d", &change);
		totalpay += change;
		if(totalpay >= totalprice) break;
	}
	changeback = totalpay - totalprice;
	printf("%d", changeback);
	return 0;
}


