#include "ImageGen.h"
#include "FileReader.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void readImages(vector<vector<int>>& val)
{

	FileReader in1 ("PeskyImages/Pesky1.ppm");
	FileReader in2 ("PeskyImages/Pesky2.ppm");
	FileReader in3 ("PeskyImages/Pesky3.ppm");
	FileReader in4 ("PeskyImages/Pesky4.ppm");
	FileReader in5 ("PeskyImages/Pesky5.ppm");
	FileReader in6 ("PeskyImages/Pesky6.ppm");
	FileReader in7 ("PeskyImages/Pesky7.ppm");
	FileReader in8 ("PeskyImages/Pesky8.ppm");
	FileReader in9 ("PeskyImages/Pesky9.ppm");

	int count(0);

	while(!(in1.endOfFile()))
	{
		if(count > 3)
		{
			vector<int> pVal;
		
			pVal.push_back(atoi(in1.readLine().c_str()));
			pVal.push_back(atoi(in2.readLine().c_str()));
			pVal.push_back(atoi(in3.readLine().c_str()));
			pVal.push_back(atoi(in4.readLine().c_str()));
			pVal.push_back(atoi(in5.readLine().c_str()));
			pVal.push_back(atoi(in6.readLine().c_str()));
			pVal.push_back(atoi(in7.readLine().c_str()));
			pVal.push_back(atoi(in8.readLine().c_str()));
			pVal.push_back(atoi(in9.readLine().c_str()));

			std::sort(pVal.begin(), pVal.end());
			val.push_back(pVal);
		}
		else
		{
			in1.readLine();
			in2.readLine();
			in3.readLine();
			in4.readLine();
			in5.readLine();
			in6.readLine();
			in7.readLine();
			in8.readLine();
			in9.readLine();

		}
		count++;
	}
}

void writeImage(vector<vector<int>>& val)
{
	ImageGen img ("PeskyFin.ppm", 495, 557);

	for(int i = 0; i<val.size()-2; i=i+3)
	{

		img.genPixel(val[i][5], val[i+1][5], val[i+2][5]);
	}

}

int main(int argc, char * argv[])
{
	cout << "Preparing to create picture" << endl;
	vector <vector<int>> values;
	readImages(values);
	writeImage(values);
	cout << "Your picture is ready!" << endl;



}