
#include "binaryTree.h"
#include "linkedList.h"
#include "hashMap.h"

int main(void) {

    HashMap* map = createHashMap();
    insertAtMap(map, "Bruno", 18);
    insertAtMap(map, "Isabela", 17);
    insertAtMap(map, "Jaum", 21);

    printMap(map);

    printf("making a search for 'Bruno'. Result: %d\n", searchByKey(map, "Bruno"));
    printf("Making a search for the value 17. Result: %s\n", searchByValue(map, 17));

    if (keyExists(map, "Bruno") == 1) {
        printf("Key 'Bruno' exists\n");
    }else {
        printf("Key 'Bruno' does not exist\n");
    }

    deleteEntry(map, "Jaum");
    printMap(map);

    freeHashMap(map);

    return 0;
}
