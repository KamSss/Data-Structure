#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

void TestSeqlist(){
	SeqList seqlist;

	IniSeqlist(&seqlist, 100);
	//ͷ��
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 3);
	SeqListPushFront(&seqlist, 4);
	SeqListPushFront(&seqlist, 5);
	//5 4 3 2 1

	//ͷɾ
	SeqListPopFront(&seqlist);
	//4 3 2 1

	//β��
	SeqListPushBack(&seqlist, 5);
	//4 3 2 1 5

	//��posλ�ò���
	SeqListInsert(&seqlist, 2, 9);
	//4 3 9 2 1 5

	//βɾ
	SeqListPopBack(&seqlist);
	//4 3 9 2 1 

	//posλ��ɾ��
	SeqListErase(&seqlist, 2);
	//4 3 2 1

	//����
	printf("�ҵ��ˣ��±�Ϊ%d\n",SeqListFind(&seqlist, 1));

	//��ӡ
	ShowSeqlist(&seqlist);
}


int main(){
	TestSeqlist();

	system("pause");
	return 0;
}
