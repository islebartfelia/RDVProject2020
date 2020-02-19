//
// Created by Corentin on 19/02/2020.
//

#ifndef PROJET_PPMIMAGE_H
#define PROJET_PPMIMAGE_H

typedef struct Pixel {
    unsigned char r, g, b;
}Pixel;

typedef struct Image{
    int w, h;
    Pixel* dat;
}Image;

int Sauver(Image*, const char* fichire);
Image* NouvelleImage(int w, int h);
Image* CopieImage(Image*);
void SetPixel(Image*, int i, int j,Pixel p);
Pixel GetPixel(Image*, int i, int j);
void DelImage(Image*);

#endif //PROJET_PPMIMAGE_H
