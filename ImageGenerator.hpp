#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H
#include <iostream>
#include <unistd.h> 
#include <vector>
#include "Fractal.hpp"
#include "Point.hpp"
#include "RGBColor.hpp"
#include "Image.hpp"

#include "omp.h"
using namespace std;
using namespace EasyBMP;
//using namespace EasyBMP;
//namespace EasyBMP { class RGBColor; };

class ImageGenerator{
    public:
        Point center;
        float width;
        int N_pixels;
        int max_iteration; 
        
        Fractal frctl;
        RGBColor white; 
        RGBColor black; 
        string img_name;
        Image img;

        ImageGenerator();
        void parse_params(int argc, char *argv[]); 
        void generate_image();
        int compute_one_pixel(int x, int y);
        RGBColor choose_color(int x, int y, int nb_iterations);

};

#endif