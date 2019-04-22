#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"


// 检查是否需要扩容，如果需要扩容就进行扩容
// 保证函数结束后，容量一定够用
void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);

	if (seqlist->size < seqlist->capacity) {
		return;
	}

	// 走到这里一定需要扩容了
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(array);

	// 把老数据搬移过来
	for (int i = 0; i < seqlist->size; i++) {
		array[i] = seqlist->array[i];
	}

	free(seqlist->array);
	seqlist->array = array;
}

//顺序表的初始化
void IniSeqlist(SeqList *seqlist, int capacity){
	assert(seqlist != NULL);

	seqlist->array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(seqlist->array);

	seqlist->size = 0;
	seqlist->capacity = capacity;
}

//头插
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//要插入肯定要先扩容
	CheckCapacity(seqlist);

	//数据搬移
	for (int i = seqlist->size; i > 0 ; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}

//头删
void SeqListPopFront(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	assert(seqlist->array != NULL);

	//从前往后覆盖
	for (int i = 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//要插入肯定要先扩容
	CheckCapacity(seqlist);

	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}

//尾删
void SeqListPopBack(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);

	seqlist->size--;
}

// 中间插入，往 pos 所在的下标插入 value
void SeqListInsert(SeqList *seqlist, int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//要插入肯定要先扩容
	CheckCapacity(seqlist);

	for (int i = seqlist->size; i > pos; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}

	seqlist->array[pos] = value;
	seqlist->size++;
}

//删除pos位置
void SeqListErase(SeqList *seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	for (int i = pos + 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

//查找函数 找到返回下标 没找到返回-1
int SeqListFind(const SeqList *seqlist, SDataType value){
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}
	}

	return -1;
}

//顺序表打印
void ShowSeqlist(const SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	for (int i = 0; i < seqlist->size - 1; i++){
		printf("%d -> ", seqlist->array[i]);
	}
	printf("%d size = %d", seqlist->array[seqlist->size - 1],seqlist->size);
	printf("\n");
}