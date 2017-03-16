#include <iostream> 
#include <stdlib.h>
#include <string>


bool gameOver;
const int height = 20;
const int width = 20; 
int x,y,fruitX,fruitY; 
int score; 

enum eDirection { 
 STOP = 0, LEFT, RIGHT, UP, DOWN
}; 
 eDirection dir;

void setup() 
{
 gameOver = false; 
 dir = STOP;
 x = width/2; // setup the head to be at the center of the board 
 y = height/2;
 fruitX = rand() % width; // the fruit can be any where within the board 
 fruitY = rand() % height;
 score = 0; 

}

void draw () 
{
 system("clear"); // clear the screen 
 
 for (int i = 1; i <= width+1 ; i++ ) { 
      std::cout << "#" ;
   }

  std::cout << std::endl;

 for (int i = 1; i <= height; i++){
    for (int j = 1; j <= width; j++){
        if (j == 1){
           std::cout << "#"; 
        }else if (i == y && j == x){
           std::cout << "O";
        }else if (i == fruitY && j == fruitX) { 
           std::cout << "F";
        }
        else{ 
           std::cout << " ";
        }
        if (j == width){
           std::cout << "#";
        }
     }
    std::cout << std::endl;
  }
 for ( int i = 1; i <= width+1 ; i++) { 
      std::cout << "#" ;
  }
  std::cout << std::endl;

}
void input ()
{
 int decision = rand() % 10;
 switch(decision) {
     case 1:
     dir = LEFT;
     break;
     case 2:
     dir = RIGHT;
     break;
     case 3:
     dir = UP;
     break;
     case 4:
     dir = DOWN;
     break;
     default:
     gameOver = true;
 }
}
void logic() 
{
 switch(dir) { 
  case LEFT:
  if (x != 0){
    x--;
  }else {
    input();
  }
    break;
  case UP:
  if (y != 0 ) {
    y--;
  }else {
    input(); 
  } 
  break;
  case DOWN:
  if ( y != 20 ) { 
    y++;
  }else { 
   input();
  }
   break;
  case RIGHT:
  if (x != 20 ) { 
    x++;
  }else {
    input();
  }   
  break;
 }
}

int main() 
{ 

  setup();
 while(!gameOver){ 
    draw();
    input();
    logic();
 }

} 
