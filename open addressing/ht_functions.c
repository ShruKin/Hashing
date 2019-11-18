#include "open_addressing.c"

/*  LINEAR PROBING  */

/*  insertion functions */

//  division method hashing
struct HashTable insert_hash_div_lp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = lp_div(data, i, ht.size);
        if(ht.table[key].is_vacant){
            ht.table[key].data = data;
            ht.table[key].is_vacant = 0;
            break;
        }
    }
    return ht;
}

//  multiplication method hashing
struct HashTable insert_hash_multi_lp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = lp_multi(data, i, ht.size);
        if(ht.table[key].is_vacant){
            ht.table[key].data = data;
            ht.table[key].is_vacant = 0;
            break;
        }
    }
    return ht;
}


/*  searching functions */

//  division method hashing
int search_hash_div_lp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = lp_div(data, i, ht.size);
        if(ht.table[key].is_vacant)
            return 0;
        else if(ht.table[key].data == data)
            return 1;
    }
    return 0;
}

//  multiplication method hashing
int search_hash_multi_lp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = lp_multi(data, i, ht.size);
        if(ht.table[key].is_vacant)
            return 0;
        else if(ht.table[key].data == data)
            return 1;
    }
    return 0;
}



/*  QUADRATIC PROBING  */

/*  insertion functions */

//  division method hashing
struct HashTable insert_hash_div_qp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = qp_div(data, i, ht.size);
        if(ht.table[key].is_vacant){
            ht.table[key].data = data;
            ht.table[key].is_vacant = 0;
            break;
        }
    }
    return ht;
}

//  multiplication method hashing
struct HashTable insert_hash_multi_qp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = qp_multi(data, i, ht.size);
        if(ht.table[key].is_vacant){
            ht.table[key].data = data;
            ht.table[key].is_vacant = 0;
            break;
        }
    }
    return ht;
}


/*  searching functions */

//  division method hashing
int search_hash_div_qp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = qp_div(data, i, ht.size);
        if(ht.table[key].is_vacant)
            return 0;
        else if(ht.table[key].data == data)
            return 1;
    }
    return 0;
}

//  multiplication method hashing
int search_hash_multi_qp(struct HashTable ht, int data){
    int key;
    for(int i=0; i<ht.size; i++){
        key = qp_multi(data, i, ht.size);
        if(ht.table[key].is_vacant)
            return 0;
        else if(ht.table[key].data == data)
            return 1;
    }
    return 0;
}