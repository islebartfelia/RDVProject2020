//
// Created by Corentin on 19/02/2020.
//

#ifndef PROJET_PPMIMAGE_H
#define PROJET_PPMIMAGE_H

typedef struct Pixel {
    unsigned char r, g, b;
}Pixel;

class Image{
protected:
    int width, height;
    Pixel* dat;
public:
    enum Format{
        GRAYSCALE = 1, RGB = 3, RGBA = 4
    };
    Image();
    static int sauver(Image*, const char* fichire);
    static Image* nouvelleImage(int width, int height);
    Image* copieImage(Image*);
    static void setPixel(Image*, int i, int j, Pixel p);
    Pixel getPixel(Image*, int i, int j);
    void delImage(Image*);

};



#endif //PROJET_PPMIMAGE_H
