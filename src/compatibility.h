
#ifndef PRLIB_COMPATIBILITY_HPP
#define PRLIB_COMPATIBILITY_HPP

#include <cctype>

typedef int LONG;
typedef unsigned char BYTE;
typedef unsigned int DWORD;
typedef unsigned short WORD;

struct BITMAPFILEHEADER
{
    ushort bfType;
    uint bfSize;
    uint bfReserved;
    uint bfOffBits;
};

struct BITMAPINFOHEADER
{
    uint biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    uint biCompression;
    uint biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    uint biClrUsed;
    uint biClrImportant;
};

struct RGBQUAD
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct BITMAPINFO
{
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

#endif //PRLIB_COMPATIBILITY_HPP
