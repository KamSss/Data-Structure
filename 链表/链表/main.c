#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

void SListTest(){
	SList list;
	SListInit(&list);

	int ListValue[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++){
		SListPushBack(&list, ListValue[i]);
	}
	PrintList(&list); // 1 2 3 4 5
	SListPopBack(&list);
	PrintList(&list); // 1 2 3 4
	SListPopFront(&list);
	PrintList(&list); // 2 3 4
}

int main(){
	SListTest();

	system("pause");
	return 0;
}