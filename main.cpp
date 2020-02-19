#include <iostream>
#include "ppmimage.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    int i,j;
    Image* I = NouvelleImage(256,256);
    for(i=0;i<256;i++)
    {
        for(j=0;j<256;j++)
        {
            Pixel p;
            p.r = i;
            p.g = j;
            p.b = 0;
            SetPixel(I,i,j,p);
        }
    }
    //Image* I = Charger("test.ppm");
    Sauver(I,"test.ppm");
    DelImage(I);
    return 0;

}