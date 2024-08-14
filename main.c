
#include "binaryTree.h"

int main(void) {

    struct Node* root = createNode(55);
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root, 90);
    root = insertNode(root, 100);

    printf("In-order traversal before deletion: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 90);
    printf("In-order traversal after deleting 90: ");
    inOrder(root);
    printf("\n");

    printf("\n");

    printf("%d", root->data);

    freeTree(root);

    return 0;
}
