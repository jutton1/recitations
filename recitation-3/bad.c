#include <stdio.h>
#include <stdlib.h>

char* p;

void my_bad_function() {
    *p = 55;
}

int main (int argc, char* argv[]) {
    my_bad_function();
    return EXIT_SUCCESS;
}