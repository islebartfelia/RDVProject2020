#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "ppmimage.h"




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
            //std::cout << "okk" << std::endl;
        }

    }
    else {
        std::cout << "File not found " << std::endl;
    }
    return coord;
}

void line(int x0, int y0, int x1, int y1, Image * image, Pixel pixel) {
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
            Image::setPixel(image, y, x, pixel);
        }
        else {
            Image::setPixel(image, x, y, pixel);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}

void triangle(std::vector<float> p, std::vector<float> p1, std::vector<float> p2 , Image* image, Pixel pixel)
{
    line(p[0], p[1], p1[0], p1[1],image, pixel);
    line(p1[0], p1[1], p2[0], p2[1],image, pixel);
    line(p2[0], p2[1], p[0], p[1], image, pixel);
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
             p.g =0;
             p.b =200;

             Image::setPixel(I, width, height, p);
         }
     }
    //image.sauver
     Image::sauver(I, "test.PPM");
    std::vector< std::vector<float> > coord = read("diablo3_pose.obj", "v");


   // Tester triangle
    std::vector<float> p;
    std::vector<float> p1;
    std::vector<float> p2;
    p.push_back(10);
    p.push_back(50);
    p1.push_back(40);
    p1.push_back(20);
    p2.push_back(30);
    p2.push_back(12);      
            Pixel pi;
            pi.r = 0;
            pi.g = 0;
            pi.b = 155;
         triangle(p, p1, p2,I, pi);
           
    
        
    
  



    return 0;

}