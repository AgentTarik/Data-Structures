
#include "binaryTree.h"
#include "linkedList.h"
#include "hashMap.h"

int main(void) {

    HashMap* map = createHashMap();
    insertAtMap(map, "Bruno", 18);
    insertAtMap(map, "Isabela", 17);
    insertAtMap(map, "Jaum", 21);

    printMap(map);

    printf("making a search for 'Bruno'. Result: %d\n", searchEntry(map, "Bruno"));

    deleteEntry(map, "Jaum");
    printMap(map);

    freeHashMap(map);

    return 0;
}
