#include "Fractal.hpp"

Fractal::Fractal(){
}

int Fractal::Newton_finite(float x_0, float y_0, int max_iteration){
  float x = 0.0;
  float y = 0.0;
  int nb_iterations = 0;
  while (x*x + y*y <= 4.0 && nb_iterations < max_iteration){
    float x_temp = x*x - y*y + x_0;
    y = 2*x*y + y_0;
    x = x_temp;
    nb_iterations++;
  }
  return nb_iterations;
}

int Fractal::Mandelbrot_finite(float x_0, float y_0, int max_iteration){
  float x = 0.0;
  float y = 0.0;
  int nb_iterations = 0;
  while (x*x + y*y <= 4.0 && nb_iterations < max_iteration){
    float x_temp = x*x - y*y + x_0;
    y = 2*x*y + y_0;
    x = x_temp;
    nb_iterations++;
  }
  return nb_iterations;
}


vector<int> Fractal::compute_color(float x_color){
  // cf. https://stackoverflow.com/questions/20792445/calculate-rgb-value-for-a-range-of-values-to-create-heat-map  
  
  int blue_neg = (int)(255 * (1 - 2 * x_color));
  int blue =  max(blue_neg, 0);
  int green;
  if (x_color <=0.5){          
    green = (int)(2*x_color*255);
  } else{
    green = (int)(-2*(x_color - 1)*255);
  }
  int red_neg = (int)(255 * (2 * x_color - 1));
  int red = max(red_neg, 0);
  vector<int> colors;
  colors.push_back(red);
  colors.push_back(green);
  colors.push_back(blue);
  return colors;
}
