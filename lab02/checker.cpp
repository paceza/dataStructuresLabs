#include "EasyBMP.h"
#include "EasyBMP.cpp"

using namespace std;

int main(){
  //Declare an instance of BMP Class 
  BMP board;
  board.SetSize(256, 256);
  for(int i = 0; i < 256; i++){
    for(int j = 0; j < 256; j++){
      int row = i/32;
      int col = j/32;
      // when (i,j) cordinates are both even OR both are odd
      if(row%2 == 0 && col%2 == 0 || row%2 != 0 && col%2 != 0){
	board(i,j)->Red = 255;
	board(i,j)->Blue = 0;
	board(i,j)->Green = 0;
      }
      else{
	board(i,j)->Red = 0;
	board(i,j)->Blue = 0;
	board(i,j)->Green = 0;
      }
    }   
  }
  board.WriteToFile("board.bmp");
  return 0;
}
