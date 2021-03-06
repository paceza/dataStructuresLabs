#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include <iostream>
#include <cstdlib> 
using namespace std;

void pattern(BMP & image, BMP & x, BMP  y, BMP & z, BMP & p, int counter){
  if (counter != 0){
    int choose = rand() % 3;
    if(choose == 0){ // x 
      BMP midpoint;
      int width1 = ((x.TellWidth() + p.TellWidth()) / 2);
      int height1 = ((x.TellHeight() + p.TellHeight()) / 2);
      midpoint.SetSize(width1, height1);

      image(midpoint.TellWidth(), midpoint.TellHeight())->Red = 255;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Blue = 0;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Green = 0;
      pattern(image, x, y, z, midpoint, --counter);
    }
    else if(choose == 1){ // Y
      BMP midpoint;
      int width2 = ((y.TellWidth() + p.TellWidth()) / 2);
      int height2 = ((y.TellHeight() + p.TellHeight()) / 2);
      midpoint.SetSize(width2, height2);

      image(midpoint.TellWidth(), midpoint.TellHeight())->Red = 255;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Blue = 0;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Green = 0;

      pattern(image, x, y, z, midpoint, --counter);
      }
    else if (choose == 2) {
      BMP midpoint;
      int width3 = ((z.TellWidth() + p.TellWidth()) / 2);
      int height3 = ((z.TellHeight() + p.TellHeight()) / 2);
      midpoint.SetSize(width3, height3);

      image(midpoint.TellWidth(), midpoint.TellHeight())->Red = 255;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Blue = 0;
      image(midpoint.TellWidth(), midpoint.TellHeight())->Green = 0;

      pattern(image, x, y, z, midpoint, --counter);
    }
   }
}

int main(){
  BMP image;
  BMP x, y, z, p;
  x.SetSize(128, 5);
  y.SetSize(5, 251);
  z.SetSize(251, 251);
  p.SetSize(171, 34);
  pattern(image, x, y, z, p, 10000);
  image.WriteToFile("sierpinski.bmp");

}
