#include <iostream>
#include<vector>
#include"box.h"
#include"Ray.h"
#include "Figure.h"
#include"Header.h"
#include"Factorybox.h"
#include<fstream>
#include <SFML/Graphics.hpp>
/*uint8_t Strtoint(std::string& s)
{
	uint8_t temp = 0;
	int i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		temp = temp + (s[i]-'0');
		temp = temp * 10;
		i++;
	}
	std::cout << "temp " << temp;
	temp = temp / 10;
	return temp;
}*/
int scan(const std::string& inp1, const std::string& inp2)
{
	std::ifstream in;
	in.open(inp1);
	Factorybox* b = new Factorybox;
	std::array<float, 3> c;
	int n=0;
	//std::string rgb;
	int rg;
	uint8_t rgb;
	int width, height;
	std::vector<box*> arr;
	std::vector<Ray> raybuff;
	std::vector<box*>::iterator it;
	float tmin=INFINITY;
	if (!in.is_open()) {
		std::cout << "Something went wrong, there is no such file: " << inp1;
		return -1;
	}
	else
	{
		while (in >> c[0])
		{
			arr.resize(arr.size() + 1);
			if (arr.size() == 1)
				it = arr.begin();
			else
				it = --arr.end();
			(*it) = b->create();
			in >> c[1];
			in >> c[2];
			(*it)->min_point = c;
			for (int i = 0; i < 3; i++)
			{
				std::cout << (*it)->min_point [i]<<", "<<std::endl;
			}
			for (int i = 0; i < 3; i++)
			{
				in>>(*it)->max_point[i];
			}
			
			//in >> rg;
			//rgb = static_cast<uint8_t>(rg);
			//std::cout << rg << std::endl;
			//rg = Strtoint(rgb);
			in >> rg;
			rgb = static_cast<uint8_t>(rg);
			//std::cout <<"rgb" <<rgb;
			(*it)->color.r = rgb;
			//std::cout<<"r:"<< (*it)->color.r<<std::endl;
			in >> rg;
			rgb = static_cast<uint8_t>(rg);
			//rg = Strtoint(rgb);
			(*it)->color.g=rg;
			//std::cout << "g:" << (*it)->color.g << std::endl;
			in >> rg;
			//in >> rg;
			rgb = static_cast<uint8_t>(rg);
			//rg = Strtoint(rgb);

			(*it)->color.b=rg;
			//std::cout << "b:" << (*it)->color.b << std::endl;
			(*it)->color.a = 255;
			//std::cout << std::endl;
			
			n++;
		}
		in.close();
		in.open(inp2);
		if (!in.is_open()) {
			std::cout << "Something went wrong, there is no such file: " << inp2;
			return -1;
		}
		else
		{
			in >> width;
			in >> height;
			for (int i = 0; i < 3; i++)
				in >> c[i];
		
			raybuff.resize(width * height);
			sf::Image img;
			img.create(width, height, sf::Color::Blue);
#pragma omp parallel for
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					tmin = INFINITY;
					raybuff[i + j * width].dot[0] = float(j);
					raybuff[i + j * width].dot[1] = float(i);
					raybuff[i + j * width].dot[2] = 0;//, i / float(width), 0);
					raybuff[i + j * width].direction = c;
					/*for (int k = 0; k < n; k++)
					{
						arr[]
					}*/
					//int m = width-i;
					//int m1 = height - j;
#pragma omp parallel for
					for (int k = 0; k < n; k++)
					{
						if (arr[k]->Intersect(raybuff[i + j * width])&&raybuff[i+j*width].t<tmin)//here is no check if it is closest? so it is half write
						{
							raybuff[i + j * width].color = arr[k]->color;
							img.setPixel(i,j , arr[k]->color);
							tmin = raybuff[i + j * width].t;
						}
					}
				}

			}
			//img.flipHorizontally();
			//img.flipVertically();
			if (!img.saveToFile("result.bmp"))
			{
				std::cout << "Failed to save";
				return -1;
			}
			else return 0;

		}
	}
	//return n;
}