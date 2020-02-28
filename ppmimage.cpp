//
// Created by Corentin on 19/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ppmimage.h"

Image::Image() : dat(nullptr), width(0), height(0){}

Image* Image::nouvelleImage(int w,int h)
{
    Image* I = static_cast<Image *>(malloc(sizeof(Image)));
    I->width = w;
    I->height = h;
    I->dat = static_cast<Pixel *>(calloc(1, w * h * sizeof(Pixel*)));
    return I;
}
Image* Image::copieImage(Image* I)
{
    Image* res;
    if (!I)
        return nullptr;
    res = nouvelleImage(I->width,I->height);
    memcpy(res->dat,I->dat,I->width*I->height*sizeof(Pixel));
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

void Image::setPixel(Image* I,int i, int j, Pixel p)
{
    assert(I && i>=0 && i<I->width && j>=0 && j<I->height);
    I->dat[I->width*j+i] = p;
}

Pixel Image::getPixel(Image* I, int i, int j)
{
    assert(I && i>=0 && i<I->width && j>=0 && j<I->height);
    return I->dat[I->width*j+i];
}

int Image::sauver(Image* I, const char* fichier)
{
    int i;
    FILE* F = fopen(fichier,"w");
    if (!F)
        return -1;
    fprintf(F,"P3\n%d %d\n255\n",I->width,I->height);
    for(i=0;i<I->width*I->height;i++)
        fprintf(F,"%d %d %d ",I->dat[i].r,I->dat[i].g,I->dat[i].b);
    fclose(F);
    return 0;
}