#include <stdio.h>
#include <stdlib.h>

struct HoopsPlayer { // do typedef struct HoopsPlayer so you don't need to do struct Hoopsplater every time. However, tyou have to do struct HoopsPlater *next in the definition
  int player_number;
  float ppg;
  struct HoopsPlayer* next;

};

int main(void) {

    struct HoopsPlayer* players;

    players = (struct HoopsPlayer*) malloc(sizeof(struct HoopsPlayer));

    players->next = NULL; // NEED TO DO OR ELSE CONDITIONAL JUMP

    int index;
    for (index = 0; index < 10; index ++) {

        struct HoopsPlayer* current = players;

        int player_num = 0;

        printf("Enter the number of your favorite Duke basketball player \n");
        scanf("%d", &player_num);

        if (player_num < 0) {
            break;
        }

        struct HoopsPlayer* newPlayer = (struct HoopsPlayer*) malloc(sizeof(struct HoopsPlayer));
        newPlayer->next = NULL;


        (*newPlayer).player_number = player_num; // same as newPlayer -> player_number

        float inputppg;
        printf("Enter average ppg: ");
        scanf("%f", &inputppg);

        newPlayer->ppg = inputppg;

        current->next = newPlayer;
        current = current->next;
    }

    for (int i = 0; i < index; i++) {
        printf("Player %d scored an average of %f points per game\n",
                players[i].player_number, players[i].ppg);
    }

    while(players != NULL) {
        struct HoopsPlayer* next = players -> next;
        free(players);
        players = next;
    }

    return 0;
}