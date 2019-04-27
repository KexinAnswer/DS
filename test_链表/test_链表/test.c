#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#define N 100
typedef int SLDataType;

//静态顺序表
//typedef struct SepList
//{
//	SLDataType array[N];
//	int size;
//}	SeqList;

typedef struct SeqList
{
	SLDataType* array;
	int size;
	int capacity;
}	SeqList;

void Swap(SLDataType* a, SLDataType* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void CheckCapacity(SeqList* list)
{
	assert(list != NULL);
	assert(list->array != NULL);
	assert(list->size <= list->capacity);

	//需要扩容
	int capacity = list->capacity * 2;

	SLDataType* array = (SLDataType*) malloc (sizeof(SLDataType) * capacity);
	assert(array);

	for (int i = 0; i < list->size; i++)
	{
		array[i] = list->array[i];

	}

	free(list->array);
	list->array = array;
}

void SeqListInit(SeqList* list, int capacity)
{
	assert(list != NULL);
	assert(list->array != NULL);

	SLDataType* array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	assert(array);

	list->array = array;
	list->capacity = capacity;
	list->size = 0;
}

void SeqListDestroy(SeqList* list)
{
	assert(list != NULL);
	assert(list->array != NULL);

	free(list->array);
	list->array = NULL;
	list->capacity = 0;
	list->size = 0;
}

void SeqListPushBack(SeqList* list , SLDataType x)
{ 
	assert(list != NULL);
	assert(list->array != NULL);

	//添加前先检查容量
	CheckCapacity(list);

	list->array[list->size] = x;

	list->size++;

}

void SeqListPopBack(SeqList* list)
{
	assert(list != NULL);
	assert(list->array != NULL);

	list->size--;
}

void SeqListPushFront(SeqList* list, SLDataType x)
{
	assert(list != NULL);
	assert(list->array != NULL);

	//插入时 检查容量
	CheckCapacity(list);

	for (int i = list->size; i > 0; i--)
	{
		list->array[i] = list->array[i - 1];

	}
	list->array[0] = x;
	list->size++;
}

void SeqListPopFront(SeqList* list)
{
	assert(list != NULL);
	assert(list->array != NULL);

	for (int i = 0; i < list->size - 1; i++)
	{
		list->array[i] = list->array[i + 1];
	}

	list->size--;
}

int SeqListFind(SeqList* list, SLDataType x)
{
	assert(list != NULL);
	assert(list->array != NULL);

	for (int i = 0; i < list->size; i++)
	{
		if (list->array[i] == x)
			return i;
	}

	return -1;
}

void SeqListInsert(SeqList* list, int pos,SLDataType x)
{
	assert(list != NULL);
	assert(list->array != NULL);

	CheckCapacity(list);

	//int pos = SeqListFind(list, x);
	//
	//if (pos == -1)
	//{
	//	return;
	//}
	for (int i = list->size; i > pos; i--)
	{
		list->array[i] = list->array[i - 1];
	}

	list->array[pos] = x;

	list->size++;

}

void SeqListErase(SeqList* list, int pos)
{
	assert(list != NULL);
	assert(list->array != NULL);

	for (int i = pos; i < list->size; i++)
	{
		list->array[i] = list->array[i + 1];
	}

	list->size--;
}

void SeqListRemove(SeqList* list, SLDataType x)
{
	int pos = SeqListFind(list, x);
	if (pos != -1)
	{
		SeqListErase(list, pos);
	}
}

void SeqListModify(SeqList* list, int pos, SLDataType x)
{
	assert(list != NULL);
	assert(list->array != NULL);
	assert(pos > 0 && pos < list->size);

	list->array[pos] = x;
}

void SeqListPrint(const SeqList* list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d ", list->array[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* list)
{
	int i = 0;
	int j = 0;
	int isSort = 0;

	for (i = 0; i < list->size - 1; i++)
	{
		for (int j = 0; j < list->size - 1 - i; j++)
		{
			Swap(list->array + j, list->array + j + 1);
		}
	}
}

bool SeqListEmpty(const SeqList* list)
{
	return list->size == 0;
}


void TestSeqList1() {
	SeqList seqlist;

	SeqListInit(&seqlist, 100);

	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	// 1, 2, 3
	SeqListPrint(&seqlist);

	SeqListPushFront(&seqlist, 11);
	SeqListPushFront(&seqlist, 12);
	SeqListPushFront(&seqlist, 13);
	// 13, 12, 11, 1, 2, 3
	SeqListPrint(&seqlist);

	SeqListInsert(&seqlist, 4, 100);
	// 13, 12, 11, 1, 100, 2, 3
	SeqListPrint(&seqlist);


	SeqListPopBack(&seqlist);
	// 13, 12, 11, 1, 100, 2
	SeqListPrint(&seqlist);

	SeqListPopFront(&seqlist);
	// 12, 11, 1, 100, 2
	SeqListPrint(&seqlist);

	SeqListErase(&seqlist, 2);
	// 12, 11, 100, 2
	SeqListPrint(&seqlist);

	SeqListDestroy(&seqlist);
}

int main() {
	TestSeqList1();
}