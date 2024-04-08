#include <stdint.h>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#include "LinkedList.h"

#define PROCESS_HEAP GetProcessHeap()
#define LAST_ERROR GetLastError()

typedef struct LListNode LListNode;

typedef struct LListNode {
	void* data;
	LListNode* next;
}LListNode;

typedef struct LinkedList {
	UINT64			count;
	LListNode* head;
	LListNode* tail;
	userFreeFunc	userFree;
	userPrintFunc	userPrint;
	HANDLE			mutexLock;
} LinkedList;

static LListNode* CreateNode(void* data);
static void ListLock(LinkedList* llist);
static void ListUnlock(LinkedList* llist);

LinkedList* llistCreate(userPrintFunc userPrint, userFreeFunc userFree) {
	LinkedList* llist = NULL;
	DWORD lastError = NULL;

	if (NULL == userPrint || NULL == userFree) {
		fprintf(stderr, "Invalid function pointer provided.\n");
		goto EXIT_LLIST_CREATE;
	}

	llist = HeapAlloc(PROCESS_HEAP, HEAP_ZERO_MEMORY, sizeof(LinkedList));
	if (NULL == llist) {
		fprintf(stderr, "HeapAlloc failed with error code: %lu\n", LAST_ERROR);
		goto EXIT_LLIST_CREATE;
	}

	llist->userPrint = userPrint;
	llist->userFree = userFree;
	llist->mutexLock = NULL;

	llist->mutexLock = CreateMutex(NULL,   // default security attributes
		FALSE,  // initially nont owned
		NULL);  // unnamed mutex

	if (NULL == llist->mutexLock) {
		fprintf(stderr, "CreateMutex failed with error code: %lu\n", LAST_ERROR);
		HeapFree(PROCESS_HEAP, 0, llist);
		llist = NULL;
		goto EXIT_LLIST_CREATE;
	}

EXIT_LLIST_CREATE:
	return llist;
}

void llistDestroy(LinkedList** llist) {
	if (NULL == llist || NULL == *llist) {
		return;
	}

	LListNode* temp = (*llist)->head;

	while (temp) {
		(*llist)->head = temp->next;
		(*llist)->userFree(temp->data);
		HeapFree(PROCESS_HEAP, 0, temp);
		temp = (*llist)->head;
	}

	CloseHandle((*llist)->mutexLock);
	(*llist)->mutexLock = NULL;

	HeapFree(PROCESS_HEAP, 0, *llist);
	*llist = NULL;
	return;
}

BOOL llistIsEmpty(LinkedList* llist) {
	return (llist->head == NULL);
}

void llistDisplay(LinkedList* llist) {
	if (NULL == llist) {
		return;
	}

	LListNode* current = llist->head;
	_tprintf(TEXT("Linked List Count: %llu\n"), llist->count);

	while (current) {
		llist->userPrint(current->data);
		current = current->next;
	}
}

void llistInsertBack(LinkedList* llist, void* data) {

	if (NULL == llist || NULL == data) {
		return;
	}

	LListNode* newNode = NULL;
	newNode = CreateNode(data);
	if (NULL == newNode) {
		return;
	}

	ListLock(llist);

	// first element to be inserted into llist
	if (NULL == llist->head) {
		llist->head = newNode;
		llist->tail = newNode;
	}

	else {
		LListNode* current = llist->head;
		llist->tail->next = newNode;
		llist->tail = newNode;
	}

	llist->count++;
	ListUnlock(llist);
}

void llistInsertFront(LinkedList* llist, void* data) {
	if (NULL == llist || NULL == data) {
		return;
	}

	LListNode* newNode = NULL;

	newNode = CreateNode(data);
	if (NULL == newNode) {
		return;
	}

	ListLock(llist);
	if (NULL == llist->tail) {
		llist->tail = newNode;
	}

	newNode->next = llist->head;
	llist->head = newNode;
	llist->count++;
	ListUnlock(llist);
}


static LListNode* CreateNode(void* data) {
	LListNode* node = NULL;

	if (NULL == data) {
		goto EXIT_CREATE_NODE;
	}

	node = HeapAlloc(PROCESS_HEAP, HEAP_ZERO_MEMORY, sizeof(LListNode));
	if (NULL == node) {
		fprintf(stderr, "HeapAlloc failed with error code: %lu\n", LAST_ERROR);
		goto EXIT_CREATE_NODE;
	}

	node->data = data;

EXIT_CREATE_NODE:
	return node;
}

static void ListLock(LinkedList* llist) {
	if (NULL == llist || NULL == llist->mutexLock) {
		return;
	}

	WaitForSingleObject(llist->mutexLock, INFINITE);
}

static void ListUnlock(LinkedList* llist) {
	if (NULL == llist || NULL == llist->mutexLock) {
		return;
	}
	ReleaseMutex(llist->mutexLock);
}

void* llistRemoveFront(LinkedList* llist) {
	LListNode* data = NULL;

	if (NULL == llist || llistIsEmpty(llist)) {
		goto EXIT_REMOVE_FRONT;
	}

	ListLock(llist);
	LListNode* temp = llist->head;
	llist->head = temp->next;
	llist->count--;
	ListUnlock(llist);

	data = temp->data;
	HeapFree(PROCESS_HEAP, 0, temp);

EXIT_REMOVE_FRONT:
	return data;
}

void* llistPeek(LinkedList* llist) {
	void* data = NULL;

	if (NULL == llist) {
		goto EXIT_PEEK;
	}

	if (NULL == llist || NULL == llist->head) {
		goto EXIT_PEEK;
	}
	data = llist->head->data;

EXIT_PEEK:
	return data;
}

void llistPush(LinkedList* llist, void* data) {
	llistInsertFront(llist, data);
}

void* llistPop(LinkedList* llist) {
	return llistRemoveFront(llist);
}

void llistEnqueue(LinkedList* llist, void* data) {
	llistInsertBack(llist, data);
}

void* llistDequeue(LinkedList* llist) {
	return llistRemoveFront(llist);
}

/* end of file */