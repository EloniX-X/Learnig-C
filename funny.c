#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>

struct gametrix {
    char one, two, three, four, five, six, seven, eight, nine;
};



struct gametrix gm = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 

void game (int move, char character) {

    char *target = &gm.one + (move - 1);
    if (*target == 'x' || *target == 'o') {
        printf("used up lmao\n");
    } else{
        *target = character;
    }
    


    printf(" %c", gm.one);
    printf(" %c", gm.two);
    printf(" %c\n", gm.three);
    printf(" %c", gm.four);
    printf(" %c", gm.five);
    printf(" %c\n", gm.six);
    printf(" %c", gm.seven);
    printf(" %c", gm.eight);
    printf(" %c\n", gm.nine);

};

int random_int(int min, int max)
{
    time_t t;
    srand((unsigned) time(&t));
    return min + rand() % max + 1;
    
};

//ok int goes in and that gets checked against the
// structure and then when its found in the structure
//that part of the structure is changed
//then we print
int games[8][3] = {
    {1, 2, 3},  
    {4, 5, 6},  
    {7, 8, 9},  
    {1, 4, 7},  
    {2, 5, 8},  
    {3, 6, 9},  
    {1, 5, 9},  
    {3, 5, 7}   
};


int checkcombo(int move, char character) {
    int size = 8;  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {  
            if (games[i][j] == move) {
                if (games[i][j] != -1 || games[i][j] != 0) {  // Check if the position is unoccupied
                    if (character == 'x') {
                        games[i][j] = 0;
                    } else {
                        games[i][j] = -1;
                    }
                     
                 
                    return 1;  // Indicate success
                } else {
                    
                    return 0;  
                }
            }
        }
    }
    printf("move not found\n");
    return 0;  // Indicate the move was not valid
}

int main () {
    int move;
    int i;
    int won;
   // printf(" %d\n", r);
    //game(1, 'x');

    while (won != 1) {
        for (i=0; i<8; i++) {
        if (games[i][0] == -1 && games[i][1] == -1 && games[i][2] == -1) {
           // printf("hey"); 
            won = 1;   // hey It's special case
            break;
        }
        if (games[i][0] == 0 && games[i][1] == 0 && games[i][2] == 0) {
            won = 1; // It's special case
        }   
        }
            for (int i = 0; i < 8; i++) {
       // printf("Winning combination %d: ", i + 1);
        // Iterate over each number in the set
        for (int j = 0; j < 3; j++) {
            printf("%d ", games[i][j]);
        }
        printf("\n");  
    }
        printf("Player one; \n"); 
        scanf(" %d", &move);
        int dme = checkcombo(move, 1);
        if (dme == 0) {
            printf("please choose another number <3 thank you ily\n");
            scanf(" %d", &move);
            checkcombo(move, 1);
        }
        game(move, 'x');

        printf("\n \n");

        printf("BOTS TON \n");

        int r = random_int(1, 9);
        
        game(r, 'o');
        scanf(" ");
        system("clear");   
    };
    printf("the game has been removed from the completion stage, wow");
    
};

