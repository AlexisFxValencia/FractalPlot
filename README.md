# FractalPlot
a C++ command line program to generate mandelbrot and Newton fractal images.

MandelBrot Plot :
  ![mandelbrot_8000_50](https://user-images.githubusercontent.com/84465552/218670477-5d80f7e5-6488-4e05-95cb-c8f3096cac2a.jpeg)

Newton fractal plot :
![Newton_2048_30](https://user-images.githubusercontent.com/84465552/222930147-2e633a5e-21cd-405f-adfb-d8130911b493.jpg)


## HOW TO COMPILE IT :
g++ used to compile it like this :   </br>
g++ -fopenmp -o fractalplot *.cpp  </br>
-fopenmp option is used to parallelize it with openmp.

## HOW USE IT (for now only in LINUX) :
a typical command : </br>
./fractalplot -s 1024 -i 50 </br>
s : for the size in pixel of the width and height of the generated image. </br>
i : number of iterations of the fractal algorithm

please use ./fractalplot -h to get help.


## INTERESTING POINTS
./fractalplot -x -0.749 -y 0.1 -w 0.005 </br>
![mandelbrot_512_100](https://user-images.githubusercontent.com/84465552/218671610-0fd697e4-6fac-4dcf-ac8b-2e358a9e9307.jpg)

./fractalplot -t Newton -w 4.0

./fractalplot -t Newton -w 4.0 -s 2048 -i 30
