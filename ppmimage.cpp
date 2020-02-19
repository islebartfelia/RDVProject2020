//
// Created by Corentin on 19/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ppmimage.h"

Image* NouvelleImage(int w,int h)
{
    Image* I = static_cast<Image *>(malloc(sizeof(Image)));
    I->w = w;
    I->h = h;
    I->dat = static_cast<Pixel *>(calloc(1, w * h * sizeof(Pixel*)));
    return I;
}
Image* CopieImage(Image* I)
{
    Image* res;
    if (!I)
        return NULL;
    res = NouvelleImage(I->w,I->h);
    memcpy(res->dat,I->dat,I->w*I->h*sizeof(Pixel));
    return res;
}

void DelImage(Image* I)
{
    if (I)
    {
        free(I->dat);
        free(I);
    }
}

void SetPixel(Image* I,int i,int j,Pixel p)
{
    assert(I && i>=0 && i<I->w && j>=0 && j<I->h);
    I->dat[I->w*j+i] = p;
}

Pixel GetPixel(Image* I,int i,int j)
{
    assert(I && i>=0 && i<I->w && j>=0 && j<I->h);
    return I->dat[I->w*j+i];
}

int Sauver(Image* I,const char* fichier)
{
    int i;
    FILE* F = fopen(fichier,"w");
    if (!F)
        return -1;
    fprintf(F,"P3\n%d %d\n255\n",I->w,I->h);
    for(i=0;i<I->w*I->h;i++)
        fprintf(F,"%d %d %d ",I->dat[i].r,I->dat[i].g,I->dat[i].b);
    fclose(F);
    return 0;
}