#include<stdio.h>

int main()
{
	int i = 1;
	char p1='Y', goods[10], goods0, p2; 
	int path[10], price[10], originalnum[10], remainingnum[10], path0, buynum, totalprice, totalpay, change, changeback;
	int item;
	while(p1 == 'Y' && i <= 5)
	{
		printf("��ڷŻ��� (��ʽ: ��Ʒ ���� �۸� ����): ");
		scanf(" %c %d %d %d", &goods[i], &path[i], &price[i], &originalnum[i]);
		remainingnum[i] = originalnum[i];
		i++;
		printf("���Ƿ�����ڷţ�Y/n��");
		scanf(" %c",&p1);
	}
	if(i==6) printf("��װ��������������ͣ����\n"); 
	else printf("�Ѱڷ����\n");
	while(1)
	{
		totalprice=0;
		totalpay=0;
		while(1)
		{
			item = 0;
			printf("�����빺������ (��ʽ: ��Ʒ ���� ����)������P�������Q��������: ");
			scanf(" %c", &goods0);
			if(goods0 == 'P') break;
			if(goods0 == 'Q') break;
			scanf(" %d %d", &path0, &buynum);
			for(int j=1; j<i; j++)
			{
				if(path[j]==path0)
				{
					item=1;
					if(goods0 == goods[j])
					{
						if(remainingnum[j] < buynum)
						{
							printf("��Ǹ��Դ���㣬ֻʣ��%d��\n", remainingnum[j]);
							continue;
						}
						remainingnum[j] -= buynum;
						totalprice += buynum*price[j];
						break;
					}
					break;
				}
			}
			if(item == 0) printf("��ͨ���ڲ����ڴ˻���\n");
		}
		if(goods0 == 'Q') continue;
		while(1)
		{
			printf("��Ͷ����Ǯ��");
			scanf(" %d", &change);
			totalpay += change;
			if(totalpay >= totalprice) break;
		}
		changeback = totalpay - totalprice;
		printf("�����������㣺%d\n", changeback);
		printf("���Ƿ��������Y/n��");
		scanf(" %c",&p2);
		if(p2=='n') return 0;
	}
	return 0;
}

