#include <stdlib.h>
#include <stdio.h>

// be sure to free up memory if it is proportioned using "malloc"

int main(int argc, char* argv[]) {
    // declare and allocate
    int* a = (int*) malloc(25*sizeof(int)); // array of 25 ints
    
    // initialize
    for (int i=0; i<25; i++) {
        a[i] = i*i;
    }
    
    // do some simple math; let's just sum the array
    int sum=0;
    for (int i=0; i<25; i++) {
        sum += a[i];
    }
    printf("Sum=%d\n",sum);

    free(a);

    // WHOOPS WE FORGOT TO FREE THE MEMORY!
    
}