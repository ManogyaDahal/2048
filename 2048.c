#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables 
int gameMat[3][3];

//functions 
void init(); //Initialize the game 
void drawBoard(); //drawing board

int main(void)
{
    init(); 
    drawBoard(); 
    return EXIT_SUCCESS;
}

// function defination
void init(){
    printf("Initializing the game.....\n"); 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            gameMat[i][j] = 0;  
        }
    }
}

void drawBoard(){
        printf("Initializing the board.. \n"); 
        printf("-------------\n"); 
        printf("| %d | %d | %d |\n",gameMat[0][0], gameMat[0][1], gameMat[0][2]);
        printf("-------------\n"); 
        printf("| %d | %d | %d |\n",gameMat[1][0], gameMat[1][1], gameMat[1][2]);
        printf("------------\n"); 
        printf("| %d | %d | %d |\n",gameMat[2][0], gameMat[2][1], gameMat[2][2]);
        printf("-------------\n"); 
}
