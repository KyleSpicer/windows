#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*userFreeFunc)(void*);
typedef void (*userPrintFunc)(void*);

typedef struct LinkedList LinkedList;

/**
 * @brief Creates a new linked list.
 *
 * This function allocates memory for a new linked list and initializes it.
 *
 * @param userPrintFunc Pointer to the user-defined print function for printing list elements.
 * @param userFreeFunc Pointer to the user-defined function for freeing memory allocated to list elements.
 * @return A pointer to the newly created LinkedList structure, or NULL if memory allocation fails.
 */
LinkedList* llistCreate(userPrintFunc, userFreeFunc);

/**
 * @brief Destroys a linked list.
 *
 * This function frees the memory allocated to a linked list and its elements.
 *
 * @param llist A pointer to a pointer to the linked list to be destroyed. After the function call, this pointer will be set to NULL.
 */
void llistDestroy(LinkedList** llist);

/**
 * @brief Checks if a linked list is empty.
 *
 * This function checks whether the specified linked list is empty (contains no elements).
 *
 * @param llist A pointer to the linked list to be checked.
 * @return TRUE if the linked list is empty, FALSE otherwise.
 */
BOOL llistIsEmpty(LinkedList* llist);

/**
 * @brief Displays the contents of a linked list.
 *
 * This function iterates through the elements of the specified linked list and prints each element.
 *
 * @param llist A pointer to the linked list whose elements are to be displayed.
 */
void llistDisplay(LinkedList* llist);

/**
 * @brief Inserts an element at the end of the linked list.
 *
 * This function inserts a new element containing the specified data at the end of the linked list.
 *
 * @param llist A pointer to the linked list where the element will be inserted.
 * @param data A pointer to the data that will be stored in the new element.
 */
void llistInsertBack(LinkedList* llist, void* data);

/**
 * @brief Inserts an element at the beginning of the linked list.
 *
 * This function inserts a new element containing the specified data at the beginning of the linked list.
 *
 * @param llist A pointer to the linked list where the element will be inserted.
 * @param data A pointer to the data that will be stored in the new element.
 */
void llistInsertFront(LinkedList* llist, void* data);

/**
 * @brief Removes and returns the element at the beginning of the linked list.
 *
 * This function removes the element at the beginning of the linked list and returns a pointer to its data.
 * If the linked list is empty, it returns NULL.
 *
 * @param llist A pointer to the linked list from which the element will be removed.
 * @return A pointer to the data of the removed element, or NULL if the linked list is empty.
 */
void* llistRemoveFront(LinkedList* llist);

/**
 * @brief Returns the data of the first element in the linked list without removing it.
 *
 * This function returns a pointer to the data of the first element in the linked list without removing it.
 * If the linked list is empty, it returns NULL.
 *
 * @param llist A pointer to the linked list from which to peek the first element.
 * @return A pointer to the data of the first element in the linked list, or NULL if the linked list is empty.
 */
void* llistPeek(LinkedList* llist);

/**
 * @brief Inserts an element at the front of the linked list.
 *
 * This function inserts the specified data at the front of the linked list.
 * If the linked list is empty, the new element becomes the head of the list.
 *
 * @param llist A pointer to the linked list where the element will be inserted.
 * @param data A pointer to the data to be inserted into the linked list.
 */
void llistPush(LinkedList* llist, void* data);

/**
 * @brief Removes and returns the element at the front of the linked list.
 *
 * This function removes and returns the element at the front of the linked list.
 * If the linked list is empty, NULL is returned.
 *
 * @param llist A pointer to the linked list from which the element will be removed.
 * @return A pointer to the data that was removed from the linked list, or NULL if the list is empty.
 */
void* llistPop(LinkedList* llist);

/**
 * @brief Inserts an element at the end of the linked list.
 *
 * This function inserts the specified data at the end of the linked list.
 * If the linked list is empty, the new element becomes both the head and the tail of the list.
 *
 * @param llist A pointer to the linked list where the element will be inserted.
 * @param data A pointer to the data to be inserted into the linked list.
 */
void llistEnqueue(LinkedList* llist, void* data);

/**
 * @brief Removes and returns the element at the front of the linked list (queue behavior).
 *
 * This function removes and returns the element at the front of the linked list.
 * If the linked list is empty, NULL is returned.
 *
 * @param llist A pointer to the linked list from which the element will be removed.
 * @return A pointer to the data that was removed from the linked list, or NULL if the list is empty.
 */
void* llistDequeue(LinkedList* llist);


#endif /* LINKEDLIST_H */

/* end of file */
