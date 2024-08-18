#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.75

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct HashMapEntry {
    char* key;
    int data;
} HashMapEntry;

typedef struct HashMap {
    HashMapEntry* entries;
    int size;
    int count;
}HashMap;


int hashFunction(const char* key, int mapSize) {
    int hash = 0;
    while (*key) {
        hash += *key++;
    }
    return hash % mapSize;
};

HashMap* createHashMap() {
    HashMap* map = (HashMap*) malloc(sizeof(HashMap));
    map->entries = calloc(TABLE_SIZE, sizeof(HashMapEntry));
    map->size = TABLE_SIZE;
    map->count = 0;
    return map;
}


void resizeHashMap(HashMap* map) {
    int oldSize = map->size;
    HashMapEntry* oldEntries = map->entries;

    map->size = oldSize * 2;
    map->entries = calloc(map->size, sizeof(HashMapEntry));
    map->count = 0;

    for (int i = 0; i < oldSize; i++) {
        if (oldEntries[i].key != NULL) {
            insertAtMap(map, oldEntries[i].key, oldEntries[i].data);
        }
    }
}

void insertAtMap(HashMap* map, const char* key, int value) {

    float loadFactor = (float)map->count / map->size;
    if (loadFactor > LOAD_FACTOR_THRESHOLD) {
        resizeHashMap(map);
    }

    int index = hashFunction(key, map->size);

    for (int i = 0; i < map->size; i++) {
        int probeIndex = (index + i) % map->size;
        if (map->entries[probeIndex].key == NULL) {
            map->entries[probeIndex].key = strdup(key);
            map->entries[probeIndex].data = value;
            map->count++;
            return;
        }else if (strcmp(map->entries[probeIndex].key, key) == 0) {
            map->entries[probeIndex].data = value;
            return;
        }
    }

    printf("Failed to insert key into the hash map\n");
}

int searchEntry(HashMap* map, const char* key) {
    int index = hashFunction(key, map->size);

    for (int i = 0; i < map->size; i++) {
        int probeIndex = (index + i) % map->size;
        if (map->entries[probeIndex].key == NULL) {
            break;
        }else if (strcmp(map->entries[probeIndex].key, key) == 0) {
            return map->entries[probeIndex].data;
        }
    }

    printf("Key not found\n");
    return -1;
}

void deleteEntry(HashMap* map, const char* key) {
    int index = hashFunction(key, map->size);

    for (int i = 0; i < map->size; i++) {
        int probeIndex = (index + i) % map->size;
        if (map->entries[probeIndex].key == NULL) {
            break;
        }else if (strcmp(map->entries[probeIndex].key, key) == 0) {
            free(map->entries[probeIndex].key);
            map->entries[probeIndex].key = NULL;
            map->entries[probeIndex].data = 0;
            map->count--;
            return;
        }
    }
    printf("Key not found\n");
    return;
}

void printMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key != NULL) {
            printf("%s : %d\n", map->entries[i].key, map->entries[i].data);
        }
    }
    printf("\n");
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key != NULL) {
            free(map->entries[i].key);
        }
    }
    free(map->entries);
    free(map);
}

#endif //HASHMAP_H
