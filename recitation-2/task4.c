#include <stdio.h>
#include <stdlib.h>

int sumArray(int* ptr) {
    int sum = 0;

    for (int i = 0; i < 100; i++) {
        sum += *(ptr + i);
    }

    return sum;
}

int main (int argc, char* argv[]) {
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    
    int int_array[100];

    for (int i = 0; i < 100; i++) {
        *(int_array + i) = i;
    }

    int sum = sumArray(int_array);

    printf("Total sum is %d\n", sum);

    return 0;
}


/*
sumArray(int* ptr) {
    int sum = 0;

    int i = 0;

    while(i<100) {
        sum += *(ptr);
        ptr++;
        i++;
    }

    for (int i = 0; i < 100; i++) {
        sum += ptr[i]; // sum += *(ptr + i)
        // or sum += ptr and do ptr++
    }

    return sum;
}*/