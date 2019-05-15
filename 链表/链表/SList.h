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

// 已通过
// 链表的初始化
void SListInit(SList *SList);
// 链表的销毁
void SListDestroy(SList *SList);
// 申请新结点
Node * SListBuyNode(SLDataType value);
// 头插
void SListPushFront(SList *SList, SLDataType value);
// 尾插
void SListPushBack(SList *SList, SLDataType value);
// 头删
void SListPopFront(SList *list);
// 尾删
void SListPopBack(SList *list);
// 打印函数
void PrintList(SList *list);

// 未通过
// 在pos位置插入
void SListInPos(SList *list, SLDataType pos);
// 搜索
int SListFind(SList *list, SLDataType target);





