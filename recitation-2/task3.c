#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_phrase\n", argv[0]);
        return 1;
    }
    
    char* ptr = argv[1];
    int count = 0;
    while(ptr != 0) {
        printf("count: %d, ptr Value: %c\n", count, *ptr);
        ptr++;
        count ++;
    }

    printf("%d\n", count);

    return 0;
}


/*int mystrelen(char* str) {
    int count = 0;

    while (str != 0) {
        count++;
        str++;
    }

    return count;
}*/