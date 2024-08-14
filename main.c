
#include "binaryTree.h"

int main(void) {

    Node* root = createNode(10);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 11);
    insertNode(root, 14);
    insertNode(root, 15);
    insertNode(root, 16);

    inOrder(root);

    freeTree(root);

    return 0;
}
