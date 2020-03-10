#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
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

std::vector< std::vector<float> > read(std::string Filename, std::string w) {

    std::ifstream file(Filename.c_str());
    std::vector< std::vector<float> > coord;
    std::vector<float> p;
    std::string line;


    if (file) {

        while (file >> line) {

            while (line == w) {

                file >> line;
                p.push_back(atof(line.c_str()));
                file >> line;
                p.push_back(atof(line.c_str()));
                file >> line;
                file >> line;
                coord.push_back(p);

            }
            std::cout << "okk" << std::endl;
        }

    }
    else {
        std::cout << "File not found " << std::endl;
    }
    return coord;
}

int main() {

    int width = 800; int height = 800;

    /* Impression de l'image dans le fichier .ppm*/

    Image* I = Image::nouvelleImage(width, height);

    //image.sauver
    Image::sauver(I, "test.PPM");
    std::vector< std::vector<float> > coord = read("diablo3_pose.obj", "v");
    return 0;

}