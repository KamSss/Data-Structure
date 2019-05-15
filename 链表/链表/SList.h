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

// ��ͨ��
// ����ĳ�ʼ��
void SListInit(SList *SList);
// ���������
void SListDestroy(SList *SList);
// �����½��
Node * SListBuyNode(SLDataType value);
// ͷ��
void SListPushFront(SList *SList, SLDataType value);
// β��
void SListPushBack(SList *SList, SLDataType value);
// ͷɾ
void SListPopFront(SList *list);
// βɾ
void SListPopBack(SList *list);
// ��ӡ����
void PrintList(SList *list);

// δͨ��
// ��posλ�ò���
void SListInPos(SList *list, SLDataType pos);
// ����
int SListFind(SList *list, SLDataType target);





