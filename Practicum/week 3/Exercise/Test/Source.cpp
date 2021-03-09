#include <iostream>
#include <fstream>

struct Point2D
{
	double mX;
	double mY;

	int mSomething;

	int mOtherThing[50];

	char* mName;
};

void write()
{
	Point2D a{ 3.45, 7.18 };

	std::ofstream outFile("point.dat", std::ios::binary | std::ios::trunc);

	outFile.write((char*)&a, sizeof(Point2D));

	outFile.close();
}

int main()
{

	std::ifstream inFile("point.dat", std::ios::binary);

	Point2D b;

	inFile.read((char*)&b, sizeof(Point2D));

	std::cout << b.mX << " " << b.mY << "\n";
	
	inFile.close();
	
	return 0;
}