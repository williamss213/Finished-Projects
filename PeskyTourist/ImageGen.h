#ifndef IMAGEGEN_H
#define IMAGEGEN_H

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

class ImageGen
{
public: 
	ImageGen(const string& file, int width, int height);
	virtual ~ImageGen();
	void genPixel(int red, int green, int blue);
private: 
	ofstream ppmFile;
};

#endif