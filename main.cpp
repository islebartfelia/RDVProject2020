#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "ppmimage.h"






void line(int x0, int y0, int x1, int y1, Image * image, Pixel pixel) { //with Bresenham methode
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
    for (int x = x0; x <= x1; x++) {
         
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

std::vector< std::vector<float> > read(std::string Filename, std::string w  ) {

    std::ifstream file(Filename.c_str());
    std::vector< std::vector<float> > coord;
    std::vector<float> p;
    std::string line;


    if (file) {

        while (file >> line) {

            while (line == w) {

                file >> line;
                p.push_back((atof(line.c_str())*100) +400); //x 

                file >> line;
                p.push_back((atof(line.c_str() )* 100) + 400);//y

                file >> line;
                //  p.push_back(atof(line.c_str()) );//z
                file >> line;
                coord.push_back(p);

              
            }
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
     for (width = 0; width < 800; width++)
     {
         for (height = 0; height < 800; height++)
         {
             Pixel p;
             p.r = 102;
             p.g =153;
             p.b =153;

             Image::setPixel(I, width, height, p);
         }
     }
     //image.sauver
     Image::sauver(I, "test.PPM");
     std::vector< std::vector<float> > coord = read("diablo3_pose.obj", "v");
   

     std::vector<float> pt;
     std::vector<float> p1;
     std::vector<float> p2;
     std::vector<float> p3;

     int i = 1;
     for (auto point : coord)
     {  
    
             pt = point;
             
            
        
     }
     Pixel pi;
     pi.r = 255;
     pi.g = 0;
     pi.b = 0;

    
     for (i = 0; i < pt.size()-5; i++) {
         p1.push_back(pt[i]);
         p1.push_back(pt[i+1] );
         p2.push_back(pt[i+2] );
         p2.push_back(pt[i+3] );
         p3.push_back(pt[i+4] );
         p3.push_back(pt[i+5] );

         
         triangle(p1, p2, p3, I, pi);
         p1.clear();
         p2.clear();
         p3.clear();
        
     }
     //image.sauver
     Image::sauver(I, "triangle.PPM");
 
    return 0;

}