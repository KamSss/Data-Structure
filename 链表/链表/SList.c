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
	Node *node = (Node *)malloc(sizeof(Node));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}

//头插
void SListPushFront(SList *list, SLDataType value){
	assert(list);
	Node *node = (Node *)malloc(sizeof(Node));
	assert(node);
	node->value = value;
	node->next = list->head;
	list->head = node;
}

// 尾插
void SListPushBack(SList *list, SLDataType value){
	assert(list != NULL);
	//如果头为空，就是头插
	if (list->head == NULL){
		SListPushFront(list, value);
		return;
	}
	//拿一个cur指针去找最后一个结点
	Node *cur = list->head;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//把cur的next指向node即可
	Node *node = SListBuyNode(value);
	cur->next = node;
}


