#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


//д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�



int binary_search(int s, int left, int right, int arr [])

{
	int mid = 0;
	while (right>=left)
	{
		//����д���Է�ֹԽ��
		 mid = left + (right - left) / 2;
		 if (arr[mid] < s)
		{
			left = mid+1;
		}
		else if (arr[mid]>s)
		{
			right = mid-1;
		}
		else
		{
			return mid;
		}
	}
		return -1;
}





int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//���ֺ���������Ҫ�±����ݣ������ββ��ܲ���ʵ�Σ�
	//����Ҫ�ں�����Ѱ���±�����
	int left = 0;
	int ret = 0;
	int s = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	printf("��������Ҫ���ҵ�����");
	scanf("%d", &s);
	ret=binary_search(s,left,right,arr);
	//���ҵ����򷵻��±꣬û�ҵ�����-1
	if (!(ret+1))
	{
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ��ˣ��±�Ϊ%d��\n",ret);
	}
	system("pause");
	return 0;
}