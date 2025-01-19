#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables
int gameMat[3][3];

// Game functions
void init();      
void drawBoard(); 
int gameWin();    
void randomGen(); 
void gameover();
void gameIntro(); 

// game movements
void downPress();
void rightPress();
void leftPress();
void upPress();

int main(void) {
  char ch; 
 gameIntro();
  init();
  drawBoard();

  while (true) {
    scanf(" %c", &ch);
    switch (ch) {
      case 'w':
        upPress();
        drawBoard();
        break;
      case 'a':
        leftPress();
        drawBoard();
        break;
      case 's':
        downPress();
        drawBoard();
        break;
      case 'd':
        rightPress();
        drawBoard();
        break;
      default:
        printf("\n\nWrong key Press %c \n press (w , a , s , d)  only!!", ch);
        drawBoard();
    }
    if (gameWin()) {
      break;
    }
    gameover(); 
  }
  return EXIT_SUCCESS;
}

// function defination
void init() {
  printf("Initializing the game.....\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      gameMat[i][j] = 0;
    }
  }
}

void gameIntro(){
  printf("!!---------HELLO-------------!!\n"); 
  printf("Hello and welcome to the game\n"); 
  printf("--CONTROLS--\n\n"); 
  printf(" s (down)\n w (up)\n d (left) \n a(right)\n\n"); 
  printf("Enter 'y' to start the game: "); 
  char ch; 
  scanf("%c", &ch); 
  if(ch != 'y'){
    printf("Exiting the game for not pressing y\n"); 
    exit(0); 
  }
  
}
void drawBoard() {
  system("clear"); 
  randomGen();
  printf("-------------\n");
  printf("| %d | %d | %d |\n", gameMat[0][0], gameMat[0][1], gameMat[0][2]);
  printf("-------------\n");
  printf("| %d | %d | %d |\n", gameMat[1][0], gameMat[1][1], gameMat[1][2]);
  printf("------------\n");
  printf("| %d | %d | %d |\n", gameMat[2][0], gameMat[2][1], gameMat[2][2]);
  printf("-------------\n");
}
int gameWin() {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (gameMat[i][j] == 2048) {
        return 1;
      }
    }
  }
  return 0;
}

void downPress() {

  // logic for shifthing 2 numbers
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 3; j++) {
      // case 1
      if (gameMat[i + 2][j] == 0) {
        gameMat[i + 2][j] = gameMat[i + 1][j];
        gameMat[i + 1][j] = gameMat[i][j];
        gameMat[i][j] = 0;
        if (gameMat[i + 2][j] == 0) {
          gameMat[i + 2][j] = gameMat[i + 1][j];
          gameMat[i + 1][j] = 0;
        }
      }
      // case 2
      if (gameMat[i + 1][j] == 0 && gameMat[i][j] != 0) {
        gameMat[i + 1][j] = gameMat[i][j];
        gameMat[i][j] = 0;
      }
    }
  }
  // logic for combining 2 numbers
  for (int i = 2; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // case 1
      if (gameMat[i][j] == gameMat[i - 1][j]) {
        gameMat[i][j] = gameMat[i - 1][j] * 2;
        gameMat[i - 1][j] = gameMat[i - 2][j];
        gameMat[i - 2][j] = 0;
      }
      // case 2
      if (gameMat[i - 1][j] == gameMat[i - 2][j]) {
        gameMat[i - 1][j] = gameMat[i - 2][j] * 2;
        gameMat[i - 2][j] = 0;
      }
      // case 3
      if (gameMat[i][j] == gameMat[i - 2][j] && gameMat[i - 1][j] == 0) {
        gameMat[i][j] = 2 * gameMat[i][j];
        gameMat[i - 2][j] = 0;
      }
    }
  }
}
void upPress() {
  // logic for shifthing 2 numbers
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 3; j++) {
      // case 1
      if (gameMat[i][j] == 0) {
        gameMat[i][j] = gameMat[i + 1][j];
        gameMat[i + 1][j] = gameMat[i + 2][j];
        gameMat[i + 2][j] = 0;
        if (gameMat[i][j] == 0) {
          gameMat[i][j] = gameMat[i + 1][j];
          gameMat[i + 1][j] = 0;
        }
      }
      // case 2
      if (gameMat[i + 1][j] == 0 && gameMat[i + 2][j] != 0) {
        gameMat[i + 1][j] = gameMat[i + 2][j];
        gameMat[i + 2][j] = 0;
      }
    }
  }
  // logic for combining 2 numbers
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 3; j++) {
      // case 1
      if (gameMat[i][j] == gameMat[i + 1][j]) {
        gameMat[i][j] = gameMat[i + 1][j] * 2;
        gameMat[i + 1][j] = gameMat[i + 2][j];
        gameMat[i + 2][j] = 0;
      }
      // case 2
      if (gameMat[i + 1][j] == gameMat[i + 2][j]) {
        gameMat[i + 1][j] = gameMat[i + 2][j] * 2;
        gameMat[i + 2][j] = 0;
      }
      // case 3
      if (gameMat[i][j] == gameMat[i + 2][j] && gameMat[i + 1][j] == 0) {
        gameMat[i][j] = 2 * gameMat[i][j];
        gameMat[i + 2][j] = 0;
      }
    }
  }
}
void leftPress() {
  // logic for shifthing 2 numbers
  for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 3; i++) {
      // case 1
      if (gameMat[i][j] == 0) {
        gameMat[i][j] = gameMat[i][j + 1];
        gameMat[i][j + 1] = gameMat[i][j + 2];
        gameMat[i + 2][j] = 0;
        if (gameMat[i][j] == 0) {
          gameMat[i][j] = gameMat[i][j + 1];
          gameMat[i][j + 1] = 0;
        }
      }
      // case 2
      if (gameMat[i][j + 1] == 0 && gameMat[i][j + 2] != 0) {
        gameMat[i][j + 1] = gameMat[i][j + 2];
        gameMat[i][j + 2] = 0;
      }
    }
  }
  // logic for combining 2 numbers
  for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 3; i++) {
      // case 1
      if (gameMat[i][j] == gameMat[i][j + 1]) {
        gameMat[i][j] = gameMat[i][j + 1] * 2;
        gameMat[i][j + 1] = gameMat[i][j + 2];
        gameMat[i][j + 2] = 0;
      }
      // case 2
      if (gameMat[i][j + 1] == gameMat[i][j + 2]) {
        gameMat[i][j + 1] = gameMat[i][j + 2] * 2;
        gameMat[i][j + 2] = 0;
      }
      // case 3
      if (gameMat[i][j] == gameMat[i][j + 2] && gameMat[i][j + 1] == 0) {
        gameMat[i][j] = 2 * gameMat[i][j];
        gameMat[i][j + 2] = 0;
      }
    }
  }
}
void rightPress() {
  // logic for shifthing 2 numbers
  for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 3; i++) {
      // case 1
      if (gameMat[i][j + 2] == 0) {
        gameMat[i][j + 2] = gameMat[i][j + 1];
        gameMat[i][j + 1] = gameMat[i][j];
        gameMat[i][j] = 0;
        if (gameMat[i][j + 2] == 0) {
          gameMat[i][j + 2] = gameMat[i][j + 1];
          gameMat[i][j + 1] = 0;
        }
      }
      // case 2
      if (gameMat[i][j + 1] == 0 && gameMat[i][j] != 0) {
        gameMat[i + 1][j] = gameMat[i][j];
        gameMat[i][j] = 0;
      }
    }
  }
  // logic for combining 2 numbers
  for (int j = 2; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      // case 1
      if (gameMat[i][j] == gameMat[i][j - 1]) {
        gameMat[i][j] = gameMat[i][j - 1] * 2;
        gameMat[i][j - 1] = gameMat[i][j - 2];
        gameMat[i][j - 2] = 0;
      }
      // case 2
      if (gameMat[i][j - 1] == gameMat[i][j - 2]) {
        gameMat[i][j - 1] = gameMat[i][j - 2] * 2;
        gameMat[i][j - 2] = 0;
      }
      // case 3
      if (gameMat[i][j] == gameMat[i][j - 2] && gameMat[i][j - 1] == 0) {
        gameMat[i][j] = 2 * gameMat[i][j];
        gameMat[i][j - 2] = 0;
      }
    }
  }
}
void randomGen() {
  int randomRow, randomCol;
  for (int i = 0; i < 9; i++) { 
    do{
      randomRow = rand() % 3; 
      randomCol = rand() % 3; 
    }while(gameMat[randomRow][randomCol] !=0 ); 
  }
  gameMat[randomRow][randomCol] = (rand() % 2 == 0) ? 2 : 4;
}

void gameover() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (gameMat[i][j] == 0) {
        return;       }
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j < 2 && gameMat[i][j] == gameMat[i][j + 1]) {
        return; 
      }
      if (i < 2 && gameMat[i][j] == gameMat[i + 1][j]) {
        return; 
      }
    }
  }

  printf("Game over!! \nBetter luck next time\n");
  exit(0);
}
