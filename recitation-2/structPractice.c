#include <stdio.h>
#include <stdlib.h>

struct HoopsPlayer {
  int playerNumber;
  float ppg;
};

void printList(struct HoopsPlayer* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("player: %d, ppg: %f\n", array[i].playerNumber, array[i].ppg);
    }
}

void sortList(struct HoopsPlayer array[], int length) {
    int mindex;
    int minval;

    for (int i = 0; i < length - 1; i++) {
        minval = array[i].ppg;
        mindex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j].ppg < minval) {
                minval = array[j].ppg;
                mindex = j;
            }
        }
        if (mindex != i) {
            int temp_num = array[mindex].playerNumber;
            float temp_ppg = array[mindex].ppg;
            array[mindex].playerNumber = array[i].playerNumber;
            array[mindex].ppg = array[i].ppg;
            array[i].playerNumber = temp_num;
            array[i].ppg = temp_ppg;
        }
    }
}

/*void sortList(struct HoopsPlayer* ptr, int length) {
    int mindex;

    // selection sort
    for (int i = 0; i < length - 1; i++) {
        mindex = i; //index containing the minimum value
        for (int j = i + 1; j < length; j++) {
            if((ptr + j)-> ppg < (ptr+mindex) -> ppg) mindex = j;
        }

        if (mindex != i) {
            //swap values
            int temp_num = (ptr+i)->playerNumber;
            float temp_ppg = (ptr+i)->ppg;
            (ptr+i)->playerNumber = (ptr+mindex)->playerNumber;
            (ptr+i)->ppg = (ptr+mindex)->ppg;
            (ptr+mindex)->playerNumber = temp_num;
            (ptr+mindex)->ppg = temp_ppg;
        }
    }
}*/

int main (int argc, char** argv) { // or char* argv[]

    struct HoopsPlayer array[10];
    int playerNum;
    float ppg;
    int length = 10;

    for (int i = 0; i < 10; i ++) {
        
        printf("Enter Duke BB player number\n");
        scanf("%d", &playerNum);

        if (playerNum == -1) {
            length = i;
            break;
        }

        printf("Enter this player's ppg\n");
        scanf("%f", &ppg);

        array[i].playerNumber = playerNum;
        array[i].ppg = ppg;

    }

    sortList(array, length);
    printList(array, length);
    return 0;

}

