// RayTracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"box.h"
#include"Ray.h"
#include "Figure.h"
#include <SFML/Graphics.hpp>
#include"Header.h"
#include"Factorybox.h"
using namespace std;
void render(const int width, const int height);
int scan(const std::string& inp1, const std::string& inp2);
int main()
{
    std::cout << "begin" << std::endl;
    /*std::array<int, 3> a;

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    std::array<int, 3> b;

    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
    Ray ray(a, b);
    ray.out();
    render(100,300);*/
    scan("databox.txt","data.txt");
    return 0;
}

/*#include <iostream>
#include<stdio.h>
#include <fstream>
#include <sstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
    const int width = 200;
    const int height = 100;
#define CHANNEL_NUM 3

    /*** NOTICE!! You have to use uint8_t array to pass in stb function  ***/
    // Because the size of color is normally 255, 8bit.
    // If you don't use this one, you will get a weird imge.
    /*uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

    int index = 0;
#pragma omp parallel for
    for (int j = height - 1; j >= 0; --j)
    {
        for (int i = 0; i < width; ++i)
        {
            float r = (float)i / (float)width;
            float g = (float)j / (float)height;
            float b = 0.2f;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            pixels[index++] = ir;
            pixels[index++] = ig;
            pixels[index++] = ib;
        }
    }

    // if CHANNEL_NUM is 4, you can use alpha channel in png
    stbi_write_png("stbpng.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);

    // You have to use 3 comp for complete jpg file. If not, the image will be grayscale or nothing.
    stbi_write_jpg("stbjpg3.jpg", width, height, 3, pixels, 100);
    stbi_write_bmp("stbmp.bmp", width, height, CHANNEL_NUM, pixels);
    delete[] pixels;

    return 0;
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
