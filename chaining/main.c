#include "ht_functions.c"

int main(int argc, char const *argv[])
{
    int ch, ch3, data, size, found;
    struct HashTable ht;
    while(1){
        printf("Select Hashing type");
        printf("\n1. Division method");
        printf("\n2. Multiplication method");
        printf("\n0. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &ch);
        printf("\n");

        if(ch == 0)
            exit(0);
        else if(ch == 1 || ch == 2){
            while(1){
                printf("\nHASHING MENU");
                printf("\n1. Initialise Hash table");
                printf("\n2. Insert");
                printf("\n3. Print");
                printf("\n4. Search");
                printf("\n0. EXIT");

                printf("\nEnter choice: ");
                scanf("%d", &ch3);
                printf("\n");

                switch(ch3){
                    case 0: exit(0);

                    case 1:
                        printf("Enter size: ");
                        scanf("%d", &size);
                        ht = init_hash_table(size);
                        break;

                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        if(ch == 1)         insert_hash_div(ht, data);
                        else if(ch == 2)    insert_hash_multi(ht, data);
                        break;

                    case 3: print_hash_table(ht);   break;

                    case 4:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        if(ch == 1)         found = search_hash_div(ht, data);
                        else if(ch == 2)    found = search_hash_multi(ht, data);

                        if(found)   printf("%d is found in the hash table", data);
                        else        printf("%d is not found in the hash table", data);
                        break;

                    default:    printf("Invalid choice! Try again!");
                }

                printf("\n\n");
            }
        }
        else
            printf("Invalid choice! Try again!");
        printf("\n\n");
    }


    return 0;
}

