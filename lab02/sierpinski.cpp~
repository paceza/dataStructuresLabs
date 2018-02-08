#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

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

int main(){
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

}
