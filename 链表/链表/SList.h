#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

//结点的结构
typedef struct SLNode{
	SLDataType value;
	struct SLNode* next;
}Node;

//链表的结构
typedef struct SList{
	Node* head;
}SList;

//链表的初始化
void SListInit(SList *SList);
//链表的销毁
void SListDestroy(SList *SList);
// 申请新结点
Node * SListBuyNode(SLDataType value);







