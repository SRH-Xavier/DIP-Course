/*
功能：输出100以内的质数
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int m,n,i;
	printf("2 ");	//输出质数中唯一的偶数2
	for (n = 3; n <= 100; n+=2)		//n为当前数字
	{
		m = sqrt(n);		//m为当前数字的算术平方根，缩减因数范围
		for (i = 2; i <= m; i++)		//遍历可能的因数
		{
			if (n%i == 0)		//存在非1和本身外的因数直接跳出循环
				break;
		}
		if (i > m)		//素数输出
			printf("%d ",n);
	}
	return 0;
}