/*
���ܣ����100���ڵ�����
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int m,n,i;
	printf("2 ");	//���������Ψһ��ż��2
	for (n = 3; n <= 100; n+=2)		//nΪ��ǰ����
	{
		m = sqrt(n);		//mΪ��ǰ���ֵ�����ƽ����������������Χ
		for (i = 2; i <= m; i++)		//�������ܵ�����
		{
			if (n%i == 0)		//���ڷ�1�ͱ����������ֱ������ѭ��
				break;
		}
		if (i > m)		//�������
			printf("%d ",n);
	}
	return 0;
}