#include<stdio.h>

int main()
{
	int path, path0, price, number, leavenum, change, changeback, buynum, totalprice, totalpay;
	char goods, goods0, p;
	printf("请摆放货物 (格式: 商品 货道 价格 数量): ");
	scanf(" %c %d %d %d", &goods, &path, &price, &number);
	leavenum = number;
	while(1)
	{	 
		printf("请输入购买内容 (格式: 商品 货道 数量): ");
		scanf(" %c %d %d", &goods0, &path0, &buynum);
		if(goods==goods0)
		{
			if(path0==path)
			{
				leavenum -= buynum;
				if(leavenum < 0)
				{
					printf("抱歉货源不足，只剩下%d件\n", leavenum + buynum);
					leavenum += buynum;
					continue;
				}
				totalprice = buynum*price;
				totalpay = 0;
				while(1)
				{
					printf("请投入零钱：");
					scanf("%d", &change);
					totalpay += change;
					if(totalpay >= totalprice) break;
				}
				changeback = totalpay - totalprice;
				printf("这是您的找零：%d\n", changeback);
			}
			else
			{
				printf("通道输入错误\n");
			}
		}
		else
		{
			printf("不存在此货物\n");
		}
		printf("您是否继续购买（Y/n）");
		scanf(" %c",&p);
		if(p=='n') return 0; 
	}
	return 0;
}

