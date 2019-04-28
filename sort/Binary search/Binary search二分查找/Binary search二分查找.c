#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


//写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）



int binary_search(int s, int left, int right, int arr [])

{
	int mid = 0;
	while (right>=left)
	{
		//这样写可以防止越界
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
	//二分函数查找需要下标数据，但是形参不能操作实参，
	//所以要在函数外寻找下标数据
	int left = 0;
	int ret = 0;
	int s = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	printf("请输入你要查找的数；");
	scanf("%d", &s);
	ret=binary_search(s,left,right,arr);
	//若找到了则返回下标，没找到返回-1
	if (!(ret+1))
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，下标为%d。\n",ret);
	}
	system("pause");
	return 0;
}