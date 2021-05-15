//
//  GambleGame.c
//  LearnC
//
//  Created by Amit Jangirh on 15/05/21.
//

#include "GambleGame.h"
#define INIT_CHAR(n)  (char*) malloc(n*sizeof(char))

int cash = 1000; // Global mem

char* shuffleArray(char *array) {
    printf("Shuffle ...");
    srand((unsigned int) time(NULL));          // Seeding random number generator
    int i;
    for(i = 0; i < 5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = array[x];
        array[x] = array[y];
        array[y] = temp;   // swaping char at positioning x and y
    }
    return array;
}

void play(int bet) {
    char *c = INIT_CHAR(100); // Dynamic allocation, stored in HEAP meme
    c[0] = 'J'; c[1] = 'Q'; c[2] = 'K';     // initialise
    c = shuffleArray(c);
    int playerGuess;
    printf("Whats your guess for Q's postion - 1,2, or 3");;
    scanf("%d", &playerGuess);
    if(c[playerGuess-1] == 'Q') {
        cash += 3*bet;
        printf("You Win! Result = \"%c, %c, %c\" with Total cash = %d\n", c[0], c[1], c[2], cash);
    } else {
        cash -= bet;
        printf("You loose! Result = \"%c, %c, %c\" with Total cash = %d\n", c[0], c[1], c[2], cash);
    }
    free(c); // Freeing up as it would create mem leakes
}

// Main func
void startGame() {
    int bet;
    printf("Welocome to Gamble game");
    printf("Total Cash available = R%d\n", cash);
    while(cash > 0) {
        printf("What your bet? R");
        scanf("%d", &bet);
        play(bet);
    }
}
