#include "ImageGen.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

ImageGen::ImageGen(const string& file, int width, int height)
{
	ppmFile.open(file);

	ppmFile << "P3" << endl 
			<< "# CREATOR: ImageGen.cpp" << endl 
			<< width << " " <<  height << endl 
			<< "255" << endl;
}

ImageGen::~ImageGen()
{
	if(ppmFile.is_open())
		ppmFile.close();
}

void ImageGen::genPixel(int red, int green, int blue)
{
	ppmFile << red << endl
		<< green << endl
		<< blue << endl;
}