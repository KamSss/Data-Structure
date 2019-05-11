#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

//���Ľṹ
typedef struct SLNode{
	SLDataType value;
	struct SLNode* next;
}Node;

//����Ľṹ
typedef struct SList{
	Node* head;
}SList;

//����ĳ�ʼ��
void SListInit(SList *SList);
//���������
void SListDestroy(SList *SList);
// �����½��
Node * SListBuyNode(SLDataType value);







