//
// Created by Corentin on 19/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>


#include "ppmimage.h"

Pixel P;

Image::Image() :  width(0), height(0) {}

Image* Image::nouvelleImage(int w, int h)
{
    Image* I = static_cast<Image*>(malloc(sizeof(Image)));
    I->width = w;
    I->height = h; 

   
    return I;
}
Image* Image::copieImage(Image* I)
{
    Image* res;
    if (!I)
        return nullptr;
    res = nouvelleImage(I->width, I->height);
    memcpy(res->dat, I->dat, I->width * I->height * sizeof(Pixel));
    return res;
}

void Image::delImage(Image* I)
{
    if (I)
    {
        free(I->dat);
        free(I);
    }
}

void Image::setPixel(Image* I, int i, int j, Pixel p)
{
    assert(I && i >= 0 && i < I->width && j >= 0 && j < I->height);
    I->dat[i][j] = p;
  
}

Pixel Image::getPixel(Image* I, int i, int j)
{
    assert(I && i >= 0 && i < I->width && j >= 0 && j < I->height);
    return I->dat[i][j];
}

int Image::sauver(Image* I, const char * Filename)
{
    int i; 
    int x;
    std::ofstream file(Filename);
    if (file)
    {
       
        file <<"P3"<< std::endl;
        file << I->width << " " << I->height << std::endl;
        file << "255"<< std::endl;
       
        for (i = 0; i < I->width ; i++) {
            for (x = 0; x < I->height; x++) {
                Pixel p = I->getPixel(I, i, x);
                file << p.r %256 << "  ";
                file << p.g %256 << " ";
                file << p.b %256 << " ";

            }
        }
               
    }
    else {
        std::cout << "File could not be created " << std::endl;
    }
    

    return 0;
}