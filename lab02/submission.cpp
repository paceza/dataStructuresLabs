#include "checker.cpp"
#include "sierpinski.cpp"
#include "EasyBMP.h"
#include "EasyBMP.cpp"

int main( int argc, char* argv[])
{
  BMP myImage;
  myImage.ReadFromFile(argv[1]);
  colorToGray(myImage);
  myImage.WriteToFile(argv[2]);
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
  return 0;
}

