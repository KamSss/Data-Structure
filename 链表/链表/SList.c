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

}

