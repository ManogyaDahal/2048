#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables 
int gameMat[3][3];

//functions 
void init(); //Initialize the game 
void drawBoard(); //drawing board (And yes board is hardcoded)
int gameWin(); //game Win condition 
int randomGen(); //To generate 2 in random empty blocks


int main(void)
{
    char ch; //character for inputing the values for the game

    init(); 
    drawBoard(); 
    //game loop 
    
    while(true){
        switch (ch) {
            case 'w':
                
            break; 
            case 'a':
                
            break; 
            //logic for downpress
            case 's':
              for(int i=2; i<0; i--){
                    for(int j=0; j<3; j++){
                       if(gameMat[i][j] == gameMat[i-1][j] && gameMat[i][j] != 0){
                            gameMat[i][j] *= 2; 
                            if(i==2){
                            gameMat[i-1][j] = gameMat[i-2][j]; 
                            }else{
                            gameMat[i-1][j] = 0;
                            }
                        }
                    }
                }
            break; 
            case 'd':
                
            break; 
        }

        if(gameWin()){
            break; 
        }
    }
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
int gameWin(){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(gameMat[i][j] == 2048){
                return 1; 
            }
        }
    }
    return 0; 
}
