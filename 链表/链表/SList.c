#include "SList.h"

//����ĳ�ʼ��
void SListInit(SList *list){
	assert(list != NULL);
	list->head = NULL;
}

//���������
void SListDestroy(SList *list){
	assert(list != NULL);

	Node* cur = list->head;
	Node* next = NULL;
	//��ΪҪfree��cur ������һ��nextָ���¼λ��
	while (cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}

	list->head = NULL;
}

// �����½��
Node * SListBuyNode(SLDataType value){
	Node *node = (Node *)malloc(sizeof(Node));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}

//ͷ��
void SListPushFront(SList *list, SLDataType value){
	assert(list);
	Node *node = (Node *)malloc(sizeof(Node));
	assert(node);
	node->value = value;
	node->next = list->head;
	list->head = node;
}

// β��
void SListPushBack(SList *list, SLDataType value){
	assert(list != NULL);
	//���ͷΪ�գ�����ͷ��
	if (list->head == NULL){
		SListPushFront(list, value);
		return;
	}
	//��һ��curָ��ȥ�����һ�����
	Node *cur = list->head;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//��cur��nextָ��node����
	Node *node = SListBuyNode(value);
	cur->next = node;
}


