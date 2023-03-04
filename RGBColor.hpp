#ifndef RGBColor_H
#define RGBColor_H
#include <cstdint>
namespace EasyBMP 
{
    class RGBColor 
        {
        public:
            RGBColor() {}; // Don't use void constructor, just for variable definition
            ~RGBColor() {};
            RGBColor(uint8_t _r, uint8_t _g, uint8_t _b);
            void SetColor(uint8_t _r, uint8_t _g, uint8_t _b);

            uint8_t r;
            uint8_t g;
            uint8_t b;
        };
}
#endif