#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables 
int gameMat[3][3];

//Game functions 
void init(); //Initialize the game 
void drawBoard(); //drawing board (And yes board is hardcoded)
int gameWin(); //game Win condition 
int randomGen(); //To generate 2 in random empty blocks

//game movements
void downPress(); 
void rightPress(); 
void leftPress(); 
void upPress(); 


int main(void)
{
    char ch; //character for inputing the values for the game

    init(); 
    drawBoard(); 
    //game loop 

    while(true){
        printf("Enter w , a , s ,d: \n"); 
        scanf(" %c",&ch);
        switch (ch) {
            case 'w':
                upPress(); 
                drawBoard();  
                break; 
            case 'a':
                leftPress(); 
                drawBoard(); 
                break; 
            //logic for downpress
            case 's':
                downPress();
                drawBoard(); 
                break; 
            case 'd':
                rightPress(); 
                drawBoard();
                break; 
            default:
                printf("Wrong key Press %c \n press w a s d only!!",ch); 
                drawBoard(); 
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
            gameMat[i][j] = 2;  
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

void downPress(){

    //logic for shifthing 2 numbers
    for(int i=0; i<1; i++){
        for(int j=0; j<3; j++){
            if( i==0 && gameMat[i+2][j]==0 ){
                gameMat[i+2][j] = gameMat[i+1][j]; 
                gameMat[i+1][j] = gameMat[i][j]; 
                gameMat[i][j] = 0; 
                if(gameMat[i+2][j]==0){
                    gameMat[i+2][j] = gameMat[i+1][j];
                    gameMat[i+1][j]=0; 
                }
            }
            if(gameMat[i+1][j]==0 && gameMat[i][j] != 0){
                gameMat[i+1][j] = gameMat[i][j];
                gameMat[i][j] = 0; 
            }
        }
    }
    //logic for combining 2 numbers 
    for(int i=2; i>0; i--){
        for(int j=0; j<3; j++){
            if(gameMat[i][j] == gameMat[i-1][j] && gameMat[i][j] != 0){
                gameMat[i][j] *= 2; 
                if(i==2){
                    gameMat[i-1][j] = gameMat[i-2][j]; 
                    gameMat[i-2][j] = 0;
                }else{
                    gameMat[i-1][j] = 0;
                }
            }
        }
    }
}
void upPress(){
    //logic for shifting
    for(int i=2; i<3; i++){
        for(int j=0; j<3; j++){
            if( i==2 && gameMat[i-2][j]==0 ){
                gameMat[i-2][j] = gameMat[i-1][j]; 
                gameMat[i-1][j] = gameMat[i][j]; 
                gameMat[i][j] = 0; 
                if(gameMat[i-2][j]==0){
                    gameMat[i-2][j] = gameMat[i-1][j];
                    gameMat[i-1][j] = 0;
                }
            }
            if(gameMat[i-1][j]==0 && gameMat[i][j] != 0){
                gameMat[i-1][j] = gameMat[i][j];
                gameMat[i][j] = 0; 
            }
        }
    }
        //logic for combining or adding 2 numbers
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(gameMat[i][j] == gameMat[i+1][j] && gameMat[i][j] != 0){
                gameMat[i][j] *= 2; 
                if(i==0){
                    gameMat[i+1][j] = gameMat[i+2][j]; 
                    gameMat[i+2][j] = 0;
                }else{
                    gameMat[i+2][j] = 0;
                }
            }
        }
    }
}
void leftPress(){
    //logic for shifting
    for(int j=2; j<3; j++){ //it is enough to run the loop once
        for(int i=0; i<3; i++){
            if( j==2 && gameMat[i][j-2]==0 && gameMat[i][j-1] != 0){
                gameMat[i][j-2] = gameMat[i][j-1]; 
                gameMat[i][j-1] = gameMat[i][j]; 
                gameMat[i][j] = 0; 
                if(gameMat[i][j-2]==0){
                    gameMat[i][j-2] = gameMat[i][j-1];
                    gameMat[i][j-1]=0;
                }
            }
            if(gameMat[i][j-1]==0 && gameMat[i][j] != 0){
                gameMat[i][j-1] = gameMat[i][j];
                gameMat[i][j] = 0; 
            }
        }
    }
    //logic for combining
    for(int j=0; j<3; j++){
        for(int i=0; i<3; i++){
            if(gameMat[i][j] == gameMat[i][j+1] && gameMat[i][j] != 0){
                gameMat[i][j] *= 2; 
                if(i==0){
                    gameMat[i][j+1] = gameMat[i][j+2]; 
                    gameMat[i][j+2] = 0;
                }else{
                    gameMat[i][j+2] = 0;
                }
            }
        }
    }
}
void rightPress(){
    //logic for shifting
    for(int j=0; j<1; j++){ //it is enough to run the loop once
        for(int i=0; i<3; i++){
            if( j==0 && gameMat[i][j+2]==0 && gameMat[i][j+1] != 0){
                gameMat[i][j+2] = gameMat[i][j+1]; 
                gameMat[i][j+1] = gameMat[i][j]; 
                gameMat[i][j] = 0; 
                if(gameMat[i][j+2]==0){
                    gameMat[i][j+2] = gameMat[i][j+1];
                    gameMat[i][j+1]=0;
                }
            }
            if(gameMat[i][j+1]==0 && gameMat[i][j] != 0){
                gameMat[i][j+1] = gameMat[i][j];
                gameMat[i][j] = 0; 
            }
        }
    }
    //logic for combining
    for(int j=2; j>0; j--){
        for(int i=0; i<3; i++){
            if(gameMat[i][j] == gameMat[i][j-1] && gameMat[i][j] != 0){
                gameMat[i][j] *= 2; 
                if(i==0){
                    gameMat[i][j-1] = gameMat[i][j-2]; 
                    gameMat[i][j-2] = 0;
                }else{
                    gameMat[i][j-2] = 0;
                }
            }
        }
    }
}
