#include<stdio.h>

int main()
{
	int i = 1;
	char p1='Y', goods[10], goods0, p2; 
	int path[10], price[10], originalnum[10], remainingnum[10], path0, buynum, totalprice, totalpay, change, changeback;
	int item;
	while(p1 == 'Y' && i <= 5)
	{
		printf("请摆放货物 (格式: 商品 货道 价格 数量): ");
		scanf(" %c %d %d %d", &goods[i], &path[i], &price[i], &originalnum[i]);
		remainingnum[i] = originalnum[i];
		i++;
		printf("您是否继续摆放（Y/n）");
		scanf(" %c",&p1);
	}
	if(i==6) printf("我装不下辣！！给我停！！\n"); 
	else printf("已摆放完成\n");
	while(1)
	{
		totalprice=0;
		totalpay=0;
		while(1)
		{
			item = 0;
			printf("请输入购买内容 (格式: 商品 货道 数量)（输入P付款，输入Q放弃购买）: ");
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
							printf("抱歉货源不足，只剩下%d件\n", remainingnum[j]);
							continue;
						}
						remainingnum[j] -= buynum;
						totalprice += buynum*price[j];
						break;
					}
					break;
				}
			}
			if(item == 0) printf("此通道内不存在此货物\n");
		}
		if(goods0 == 'Q') continue;
		while(1)
		{
			printf("请投入零钱：");
			scanf(" %d", &change);
			totalpay += change;
			if(totalpay >= totalprice) break;
		}
		changeback = totalpay - totalprice;
		printf("这是您的找零：%d\n", changeback);
		printf("您是否继续购买（Y/n）");
		scanf(" %c",&p2);
		if(p2=='n') return 0;
	}
	return 0;
}

