#include <iostream>
#include"box.h"
#include"Ray.h"
#include "Figure.h"
#include <SFML/Graphics.hpp>
void render(const int width, const int height)
{
    /*std::vector<std::array<float,3>> framebuffer(width * height);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            framebuffer[i + j * width][0] = j / float(height);
            framebuffer[i + j * width][1] = i / float(width); // Vec3f(j / float(height), i / float(width), 0);
            framebuffer[i + j * width][2] = 0;
        }
    }*/
    sf::Image image;
    //sf::Color color;
    image.create(width, height, sf::Color::Black);
    for (int i = 0; i < width; i++)
    {
        image.setPixel(i, i, sf::Color::White);
        image.setPixel(i, i+1, sf::Color::White);
        image.setPixel(i+1, i, sf::Color::White);
        image.setPixel(i+1, i+1, sf::Color::White);
    }
    if (!image.saveToFile("try.bmp"))
        std::cout << "Something went wrong";
}