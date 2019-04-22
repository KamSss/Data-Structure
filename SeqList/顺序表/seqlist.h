#define _CRT_SECURE_NO_WARNINGS
#define N 100//���ھ�̬����˳���

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
	SDataType	*array;		// ָ����ϵĿռ�(ָ��̬���ٵ�����)
	int size;		// ��ʾ��ǰ˳������ж��ٸ���Ч����(Ҳ��ʾ�˼���������±�)
	int	capacity;	// �����ռ�Ĵ�С
}SeqList;

//��ʼ��
void IniSeqlist(SeqList *seqlist, int capacity);
//������飨���ݣ�
void CheckCapacity(SeqList *seqlist);
//ͷɾ
void SeqListPopFront(SeqList *seqlist);
//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value);
//βɾ
void SeqListPopBack(SeqList *seqlist);
//��ӡ
void ShowSeqlist(const SeqList *seqlist);
//β��
void SeqListPushBack(SeqList *seqlist, SDataType value);
// �м���룬�� pos ���ڵ��±���� value
void SeqListInsert(SeqList *seqlist, int pos, SDataType value);
//�м�ɾ��
void SeqListErase(SeqList *seqlist, int pos);
//����
int SeqListFind(const SeqList *seqlist, SDataType value);