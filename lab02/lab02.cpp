// Zack Pace
// 2/6/18
// Lab02 EasyBMP
#include <iostream>
#include "EasyBMP.h"
#include "EasyBMP.cpp"
using namespace std;

void scale(BMP & input, BMP & output){
  int width = output.TellWidth()/2;
  int height = output.TellHeight()/2;
  for(int i = 1; i < width-1; ++i)
    for(int j = 1; j < height-1; ++j){
      int red = (input(2*i, 2*j)->Red + input(2*i+1, 2*j)->Red + input(2*i, 2*j+1)->Red + input(2*i+1, 2*j+1)->Red)/4;
      int blue =(input(2*i, 2*j)->Blue + input(2*i+1, 2*j)->Blue + input(2*i, 2*j+1)->Blue + input(2*i+1, 2*j+1)->Blue)/4;
      int green =(input(2*i, 2*j)->Green + input(2*i+1, 2*j)->Green + input(2*i, 2*j+1)->Green + input(2*i+1, 2*j+1)->Green)/4;
      
      output(i,j)->Red = red;
      output(i,j)->Blue = blue;
      output(i,j)->Green = green;
    }
}

void title(BMP & input, BMP & output){
  //Declare temp BMP;
  BMP temp;
  // get the width and height of the input image and store them in ints
  int width = input.TellWidth();
  int height = input.TellHeight();

  //basecase
  if (width == 1){
    //Use RangedPixelToPixelCopy to copy the single pixel to the (x, y) of output - 1 e.g. (0, output.TellWidth() -1) 
    RangedPixelToPixelCopy (input, 0, width, height, 0, output, 0, output.TellWidth()-1);
    return;
  }
  else{
    temp.SetSize(width/2, height/2);
    //call scale function (input, temp)
    scale(input, temp);
    // (x,y) coords are (0, output.Tellheight)
    //
    // SOMEWHERE here it's not copying to output correctly.
    //
    RangedPixelToPixelCopy(temp, 0, width, height, height/2, output, 0, output.TellHeight());
    BMP temp1;
    temp1.SetSize(width/2, height/2);
    
    // Recursive call
    title(temp, temp1);
    
    // (x, y) -> (0, 0)
    RangedPixelToPixelCopy(temp1, 0, temp1.TellWidth()/2, temp1.TellHeight()/2, 0, output, 0, 0);
    
    //(x, y) -> (output.TellWidth()/ 4 , 0)
    RangedPixelToPixelCopy(temp1, 0, temp1.TellWidth()/2, temp1.TellHeight(), 0, output, output.TellWidth()/4, 0);
    
    //(x, y) -> (output.TellHeight()/2 , output.TellHeight()/2)
    RangedPixelToPixelCopy(temp1, 0, temp1.TellWidth(), temp1.TellHeight()/2, 0, output, output.TellWidth()/2, output.TellHeight()/2);
    
    // (x, y)->(output.TellWidth()/2 , output.TellHeight() * 0.75)
    RangedPixelToPixelCopy(temp1, 0, temp1.TellWidth(), temp1.TellHeight()/2, 0, output, output.TellWidth()/2, output.TellHeight() * 0.75);
    
  }
}

void makeBoard(BMP & Output){
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
}

void pattern(BMP & image, int Xx, int Xy, int Yx, int Yy, int Zx, int Zy, int Px, int Py, int counter){
  //
  if (counter != 0){
    int choose = rand() % 3;
    if(choose == 0){ // x
      int width1 = ((Xx + Px) / 2);
      int height1 = ((Xy + Py) / 2);

      image(width1, height1)->Red = 255;
      image(width1, height1)->Blue = 0;
      image(width1, height1)->Green = 0;
      // pass the new midpoints in Px, Py
      pattern(image, Xx, Xy, Yx, Yy, Zx, Zy, width1, height1, --counter);
    }
    else if(choose == 1){ // Y
      int width2 = ((Yx + Px) / 2);
      int height2 = ((Yy + Py) / 2);

      image(width2, height2)->Red = 255;
      image(width2, height2)->Blue = 0;
      image(width2, height2)->Green = 0;
      pattern(image, Xx, Xy, Yx, Yy, Zx, Zy, width2, height2, --counter);
    }
    else if (choose == 2) {
      int width3 = ((Zx + Px) / 2);
      int height3 = ((Zy + Py) / 2);

      image(width3, height3)->Red = 255;
      image(width3, height3)->Blue = 0;
      image(width3, height3)->Green = 0;

      pattern(image, Xx, Xy, Yx, Yy, Zx, Zy, width3, height3, --counter);
    }
  }
}


int main( int argc, char* argv[])
{
  BMP myBoard;
  makeBoard(myBoard);
  BMP image;
  image.SetSize(256, 256);
  int Xx = 128;
  int Xy = 5;
  int Yx = 5;
  int Yy = 251;
  int Zx = 251;
  int Zy = 251;
  int Px = 171;
  int Py = 34;
  pattern(image, Xx, Xy, Yx, Yy, Zx, Zy, Px, Py, 10000);
  image.WriteToFile("sierpinski.bmp");
  BMP input;
  BMP output;
  input.ReadFromFile(argv[3]);
  output.SetSize(input.TellWidth(), input.TellHeight());
  title(input, output);
  output.WriteToFile(argv[4]);
  return 0;
}
