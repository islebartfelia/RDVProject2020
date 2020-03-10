#include <iostream>
#include <cstdlib>
#include "ppmimage.h"

void line(int x0, int y0, int x1, int y1, Image& image, Pixel pixel) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror2 = std::abs(dy) * 2;
    int error2 = 0;
    int y = y0;
    for (int x = 0; x <= x1; x++) {
        if (steep) {
            Image::setPixel(&image, y, x, pixel);
        }
        else {
            Image::setPixel(&image, x, y, pixel);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}

int main() {

    int width = 800; int height = 800;

    /* Impression de l'image dans le fichier .ppm*/

    Image* I = Image::nouvelleImage(width, height);
    for (width = 0; width < 800; width++)
    {
        for (height = 0; height < 800; height++)
        {
            Pixel p;
            p.r = 0;
            p.g = 0;
            p.b = 155;

            Image::setPixel(I, width, height, p);
        }
    }
    //image.sauver
    Image::sauver(I, "test.PPM");
    return 0;

}