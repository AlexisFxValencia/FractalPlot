#include "ImageGenerator.hpp"


ImageGenerator::ImageGenerator(){
    max_iteration = 100;
    center = Point(-0.5, 0.0);
    width = 2.0;
    N_pixels = 512;
    fractal_type = "Mandelbrot";
    white.SetColor(255, 255, 255);
    black.SetColor(0, 0, 0); 
    set_image_name();
    img.Init(N_pixels, N_pixels, img_name, white);

}

void ImageGenerator::set_image_name(){
    img_name = fractal_type + "_" + to_string(N_pixels) + "_" + to_string(max_iteration) + ".bmp";
}

void ImageGenerator::parse_params(int argc, char *argv[]){
    int opt;
  while((opt = getopt(argc, argv, "hs:i:x:y:w:t:")) != -1) 
  { 
      switch(opt) 
      { 
          case 'h':
            cout << endl;
            printf("-s: Size of the image in pixels (defines the width and the height of the image as it is a square). \n");
            printf("-i: Maximum number of iterations of the Newton process. \n");
            printf("-x: x-coordinate of the view's center. Default parameter is %f \n", center.x);
            printf("-y: y-coordinate of the view's center. Default parameter is %f \n", center.y);            
            printf("-w: width of the view. Default parameter is %f \n", width);
            printf("-t: type of fractal (Mandelbrot or Newton)");
            cout << endl;
            break;
          case 's': 
            N_pixels = stoi(optarg);
            printf("Image size is set to %i pixels \n", N_pixels);
            break;
          case 'i': 
            max_iteration = stoi(optarg);
            printf("Maximum number of iterations isset to %i \n", max_iteration);
            break;
          case 'x': 
            center.x = stof(optarg);
            printf("x-coordinate of the view's center is set to %f \n", center.x);
            break;
          case 'y': 
            center.y = stof(optarg);
            printf("x-coordinate of the view's center is set to %f \n", center.y);
            break;
          case 'w': 
            width = stof(optarg);
            printf("The width of the view is set to %f \n", width);
            break;
          case 't':
            fractal_type = optarg;
            set_image_name();
            img.SetFileName(img_name);
            cout << "The fractal type of the view is set to " << fractal_type << "."<< endl;
            break;
      } 
  }     
  // optind is for the extra arguments
  // which are not parsed
  for(; optind < argc; optind++){     
      printf("extra arguments: %s\n", argv[optind]); 
  }
}

int ImageGenerator::compute_one_pixel(int x, int y){
  float x_normalized = ((float)x/(float)N_pixels)*width + center.x - width/2;
  float y_normalized = ((float)(N_pixels-y)/(float)N_pixels)*width + center.y - width/2;
  int nb_iterations;
  if (fractal_type=="Mandelbrot"){
    nb_iterations = frctl.Mandelbrot_finite(x_normalized, y_normalized, max_iteration);
  }else if (fractal_type=="Newton"){
    nb_iterations = frctl.Newton_finite(x_normalized, y_normalized, max_iteration);
  }
  return nb_iterations;  
}

RGBColor ImageGenerator::choose_color(int x, int y, int nb_iterations){
  if (nb_iterations >= max_iteration){
    return black;
  } else{
      float x_color = (float)nb_iterations/(float)max_iteration;
      vector<int> colors = frctl.compute_color(x_color);
      RGBColor custom_color(colors[0], colors[1], colors[2]);
      return custom_color;
  } 
}


void ImageGenerator::generate_image(){
  double t_start = omp_get_wtime();

  int y;
  #pragma omp parallel shared(img) private(y)
  {
  #pragma omp for
  for (y = 0; y < N_pixels; ++y) { 
    for (int x = 0; x < N_pixels; ++x) {
      int nb_iterations = compute_one_pixel(x, y);     
      RGBColor mycolor = choose_color(x, y, nb_iterations);
      img.SetPixel(x, y, mycolor, false);
    }
  }

  }

  img.Write();
  double t_end = omp_get_wtime();
  cout << img_name << " generated in "<< t_end - t_start << " seconds." << endl;
}