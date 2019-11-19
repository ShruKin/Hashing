#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct node{
    int data;
    struct node *next;
};

struct HashTable{
    struct node **table;
    int size;
};

// initialise the hash table
struct HashTable init_hash_table(int size){
    struct HashTable ht = {NULL, 0};

    ht.size = size;
    ht.table = (struct node **)malloc(size * sizeof(struct node));

    for(int i=0; i<ht.size; i++)
        ht.table[i] = NULL;

    return ht;
}

void print_hash_table(struct HashTable ht){
    for(int i=0; i<ht.size; i++){
        if(ht.table[i] == NULL)
            printf("NULL ");
        else{
            struct node *ptr = ht.table[i];
            printf("(");
            while(ptr != NULL){
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
            printf("\b) ");
        }
    }
}


/*  hash functions  */

//  division method
int hash_div(int x, int m){
    return x % m;
}

// multiplication methos
int hash_multi(int x, int m){
    double A = (sqrt(5) - 1)/2;
    double t = (x*A) - floor(x*A);
    return floor(m * t);
}