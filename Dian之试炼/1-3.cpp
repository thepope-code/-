#include<stdio.h>

int main()
{
	int path, path0, price, number, leavenum, change, changeback, buynum, totalprice, totalpay;
	char goods, goods0, p;
	printf("��ڷŻ��� (��ʽ: ��Ʒ ���� �۸� ����): ");
	scanf(" %c %d %d %d", &goods, &path, &price, &number);
	leavenum = number;
	while(1)
	{	 
		printf("�����빺������ (��ʽ: ��Ʒ ���� ����): ");
		scanf(" %c %d %d", &goods0, &path0, &buynum);
		if(goods==goods0)
		{
			if(path0==path)
			{
				leavenum -= buynum;
				if(leavenum < 0)
				{
					printf("��Ǹ��Դ���㣬ֻʣ��%d��\n", leavenum + buynum);
					leavenum += buynum;
					continue;
				}
				totalprice = buynum*price;
				totalpay = 0;
				while(1)
				{
					printf("��Ͷ����Ǯ��");
					scanf("%d", &change);
					totalpay += change;
					if(totalpay >= totalprice) break;
				}
				changeback = totalpay - totalprice;
				printf("�����������㣺%d\n", changeback);
			}
			else
			{
				printf("ͨ���������\n");
			}
		}
		else
		{
			printf("�����ڴ˻���\n");
		}
		printf("���Ƿ��������Y/n��");
		scanf(" %c",&p);
		if(p=='n') return 0; 
	}
	return 0;
}

