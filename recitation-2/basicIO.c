#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char name[64];
    printf("Enter the Name of your favorite Duke basketball player \n");
    scanf("%s", name); // name is a pointer so no need for & (address)
    int playerheight;
    printf("Enter player height \n");
    scanf("%d", &playerheight);

    int ppg = 0;
    printf("Enter player average points per game\n");
    scanf("%d", &ppg);

    float avg;
    avg = ((float) ppg / (float) playerheight);
    printf("%s scored an average of %f points per inch\n", name, avg);

    return 0;


}