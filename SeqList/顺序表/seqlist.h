#define _CRT_SECURE_NO_WARNINGS
#define N 100//用于静态开辟顺序表

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdint.h>

typedef int	SDataType;

//typedef struct Seqlist{
//	SDataType *array[N];
//	size_t size;
//}Seqlist;



typedef struct SeqList {
	SDataType	*array;		// 指向堆上的空间(指向动态开辟的数组)
	int size;		// 表示当前顺序表里有多少个有效数据(也表示了即将插入的下标)
	int	capacity;	// 容量空间的大小
}SeqList;

//初始化
void IniSeqlist(SeqList *seqlist, int capacity);
//容量检查（扩容）
void CheckCapacity(SeqList *seqlist);
//头删
void SeqListPopFront(SeqList *seqlist);
//头插
void SeqListPushFront(SeqList *seqlist, SDataType value);
//尾删
void SeqListPopBack(SeqList *seqlist);
//打印
void ShowSeqlist(const SeqList *seqlist);
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value);
// 中间插入，往 pos 所在的下标插入 value
void SeqListInsert(SeqList *seqlist, int pos, SDataType value);
//中间删除
void SeqListErase(SeqList *seqlist, int pos);
//查找
int SeqListFind(const SeqList *seqlist, SDataType value);