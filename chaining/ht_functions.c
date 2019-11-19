#include "hash_table.c"

/*  insertion functions */

//  division method
struct HashTable insert_hash_div(struct HashTable ht, int data){
    int key = hash_div(data, ht.size);

    struct node *newNode = (struct node *)malloc(sizeof(struct node)), *ptr = ht.table[key];
    newNode->data = data;
    newNode->next = NULL;

    if(ht.table[key] == NULL)
        ht.table[key] = newNode;
    else{
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return ht;
}

//  multiplication method
struct HashTable insert_hash_multi(struct HashTable ht, int data){
    int key = hash_multi(data, ht.size);

    struct node *newNode = (struct node *)malloc(sizeof(struct node)), *ptr = ht.table[key];
    newNode->data = data;
    newNode->next = NULL;

    if(ht.table[key] == NULL)
        ht.table[key] = newNode;
    else{
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return ht;
}


/*  searching functions */

// division method
int search_hash_div(struct HashTable ht, int data){
    int key = hash_div(data, ht.size);

    struct node *ptr = ht.table[key];
    while(ptr != NULL){
        if(ptr->data == data)
            return 1;
        ptr = ptr->next;
    }

    return 0;
}

// multiplicatiom method
int search_hash_multi(struct HashTable ht, int data){
    int key = hash_multi(data, ht.size);

    struct node *ptr = ht.table[key];
    while(ptr != NULL){
        if(ptr->data == data)
            return 1;
        ptr = ptr->next;
    }

    return 0;
}