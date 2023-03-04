# FractalPlot
a C++ command line program to generate mandelbrot and Newton fractal images.

  ![mandelbrot_8000_50](https://user-images.githubusercontent.com/84465552/218670477-5d80f7e5-6488-4e05-95cb-c8f3096cac2a.jpeg)
![Newton_2048_100](https://user-images.githubusercontent.com/84465552/222930055-4e970119-82e1-4930-aa36-7543219b01a5.jpg)

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

./fractalplot -t Newton -w 0.0000005 -x 0.00
