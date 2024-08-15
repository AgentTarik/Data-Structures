#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

ListNode* createListNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(ListNode** head, int data) {
    ListNode* newNode = createListNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(ListNode** head, int data) {
    ListNode* newNode = createListNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(ListNode** head, int data, int position) {
    ListNode* newNode = createListNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    }

    ListNode* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListPosition(ListNode* head, int position) {
    ListNode* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    printf("%d", temp->data);
}

#endif //LINKEDLIST_H
