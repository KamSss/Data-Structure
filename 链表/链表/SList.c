#include "SList.h"

//链表的初始化
void SListInit(SList *list){
	assert(list != NULL);
	list->head = NULL;
}

//链表的销毁
void SListDestroy(SList *list){
	assert(list != NULL);

	Node* cur = list->head;
	Node* next = NULL;
	//因为要free掉cur 所以拿一个next指针记录位置
	while (cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}

	list->head = NULL;
}

// 申请新结点
Node * SListBuyNode(SLDataType value){

}

