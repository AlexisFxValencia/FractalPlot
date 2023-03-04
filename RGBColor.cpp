#include "RGBColor.hpp"
using namespace EasyBMP;

RGBColor::RGBColor(uint8_t _r, uint8_t _g, uint8_t _b) 
{
    SetColor(_r, _g, _b);
} 

void RGBColor::SetColor(uint8_t _r, uint8_t _g, uint8_t _b) 
{
    r = _r;
    g = _g;
    b = _b;
}