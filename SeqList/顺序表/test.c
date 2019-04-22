#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

void TestSeqlist(){
	SeqList seqlist;

	IniSeqlist(&seqlist, 100);
	//头插
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 3);
	SeqListPushFront(&seqlist, 4);
	SeqListPushFront(&seqlist, 5);
	//5 4 3 2 1

	//头删
	SeqListPopFront(&seqlist);
	//4 3 2 1

	//尾插
	SeqListPushBack(&seqlist, 5);
	//4 3 2 1 5

	//在pos位置插入
	SeqListInsert(&seqlist, 2, 9);
	//4 3 9 2 1 5

	//尾删
	SeqListPopBack(&seqlist);
	//4 3 9 2 1 

	//pos位置删除
	SeqListErase(&seqlist, 2);
	//4 3 2 1

	//查找
	printf("找到了，下标为%d\n",SeqListFind(&seqlist, 1));

	//打印
	ShowSeqlist(&seqlist);
}


int main(){
	TestSeqlist();

	system("pause");
	return 0;
}
