#include "hash_table.c"

/*  Linear probing functions    */

//  division method hashing
int lp_div(int x, int i, int m){
    return ((hash_div(x, m) + i) % m);
}

//  multiplication method hashing
int lp_multi(int x, int i, int m){
    return ((hash_multi(x, m) + i) % m);
}


/*  quadratic probing functions */

//  division method hashing
int qp_div(int x, int i, int m){
    static int c1=0, c2=0;
    if(!c1 && !c2){     //  c1 and c2 are set randomly from 1 to 9
        srand(time(NULL));
        c1 = (rand() % (9 - 1 + 1) + 1);
        c2 = (rand() % (9 - 1 + 1) + 1);
    }
    printf("%d %d\n", c1, c2);

    return ((hash_div(x, m) + (c1*i) + (c2*i*i)) % m);
}

//  multiplication method hashing
int qp_multi(int x, int i, int m){
    static int c1=0, c2=0;
    if(!c1 && !c2){     //  c1 and c2 are set randomly from 1 to 9
        srand(time(NULL));
        c1 = (rand() % (9 - 1 + 1) + 1);
        c2 = (rand() % (9 - 1 + 1) + 1);
    }

    return ((hash_multi(x, m) + (c1*i) + (c2*i*i)) % m);
}


/*  double hashing functions */

//  division method hashing
int dh_div(int x, int i, int m){
    return ((hash_div(x, m) + hash_div(x, m-1)) % m);
}

//  multiplication method hashing
int dh_multi(int x, int i, int m){
    return ((hash_multi(x, m) + hash_multi(x, m-1)) % m);
}