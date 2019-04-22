#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"


// ����Ƿ���Ҫ���ݣ������Ҫ���ݾͽ�������
// ��֤��������������һ������
void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);

	if (seqlist->size < seqlist->capacity) {
		return;
	}

	// �ߵ�����һ����Ҫ������
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(array);

	// �������ݰ��ƹ���
	for (int i = 0; i < seqlist->size; i++) {
		array[i] = seqlist->array[i];
	}

	free(seqlist->array);
	seqlist->array = array;
}

//˳���ĳ�ʼ��
void IniSeqlist(SeqList *seqlist, int capacity){
	assert(seqlist != NULL);

	seqlist->array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(seqlist->array);

	seqlist->size = 0;
	seqlist->capacity = capacity;
}

//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//Ҫ����϶�Ҫ������
	CheckCapacity(seqlist);

	//���ݰ���
	for (int i = seqlist->size; i > 0 ; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}

//ͷɾ
void SeqListPopFront(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	assert(seqlist->array != NULL);

	//��ǰ���󸲸�
	for (int i = 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

//β��
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//Ҫ����϶�Ҫ������
	CheckCapacity(seqlist);

	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}

//βɾ
void SeqListPopBack(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);

	seqlist->size--;
}

// �м���룬�� pos ���ڵ��±���� value
void SeqListInsert(SeqList *seqlist, int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	//Ҫ����϶�Ҫ������
	CheckCapacity(seqlist);

	for (int i = seqlist->size; i > pos; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}

	seqlist->array[pos] = value;
	seqlist->size++;
}

//ɾ��posλ��
void SeqListErase(SeqList *seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	for (int i = pos + 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

//���Һ��� �ҵ������±� û�ҵ�����-1
int SeqListFind(const SeqList *seqlist, SDataType value){
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}
	}

	return -1;
}

//˳����ӡ
void ShowSeqlist(const SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	for (int i = 0; i < seqlist->size - 1; i++){
		printf("%d -> ", seqlist->array[i]);
	}
	printf("%d size = %d", seqlist->array[seqlist->size - 1],seqlist->size);
	printf("\n");
}