
#include "binaryTree.h"
#include "linkedList.h"

int main(void) {

    ListNode* head = createListNode(1);
    insertAtBeginning(&head, 0);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 5);
    insertAtPosition(&head, 4, 4);

    printList(head);

    int x = getListPosition(head, 2);
    printf("%d\n", x);

    printListPosition(head, 3);

    deleteListPosition(&head, 3);

    printList(head);


    freeList(&head);

    printList(head);







    // struct Node* root = createNode(55);
    // root = insertNode(root, 50);
    // root = insertNode(root, 30);
    // root = insertNode(root, 20);
    // root = insertNode(root, 40);
    // root = insertNode(root, 70);
    // root = insertNode(root, 60);
    // root = insertNode(root, 80);
    // root = insertNode(root, 90);
    // root = insertNode(root, 100);
    //
    // printf("In-order traversal before deletion: ");
    // inOrder(root);
    // printf("\n");
    //
    // root = deleteNode(root, 20);
    // printf("In-order traversal after deleting 20: ");
    // inOrder(root);
    // printf("\n");
    //
    // root = deleteNode(root, 30);
    // printf("In-order traversal after deleting 30: ");
    // inOrder(root);
    // printf("\n");
    //
    // root = deleteNode(root, 50);
    // printf("In-order traversal after deleting 50: ");
    // inOrder(root);
    // printf("\n");
    //
    // root = deleteNode(root, 90);
    // printf("In-order traversal after deleting 90: ");
    // inOrder(root);
    // printf("\n");
    //
    // printf("\n");
    //
    // printf("%d", root->data);
    //
    // freeTree(root);

    return 0;
}
