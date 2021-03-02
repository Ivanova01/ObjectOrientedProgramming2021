#include <iostream>

//For the following structure:
struct RealEstate {
	double mPrice;
	char* mType;
};

RealEstate estate;

//how do you call price, type?
//how do you call estate?

int main() {
	//Which of the following will result in memory allocation?
	struct Flat {
		double mPrice;
		int mStorey;
	};

	struct Plot {
		double mPrice;
		double mArea;
	} plot;

	struct House {
		double mPrice;
		bool mHasNewRoof;
	};
	House kushta;

	//Which of the following lines will not compile and why?
	//Do you see anything else wrong with the following lines?
	const int STRING_MAX_LEN = 128;
	//
	//RealEstate house = { 4000, new char[STRING_MAX_LEN] };

	//{
	//	struct HorrorMovie {
	//		int mCasualties;
	//		int mDemons;
	//	};

	//	HorrorMovie theConjuring;
	//}

	//HorrorMovie anabelle;

	//struct SuperFancyModel {
	//	double mHeight;
	//	double mWeight;
	//	char* mName;
	//} kendallJenner = { 180, 50.5, new char[STRING_MAX_LEN]};

	//What is the output of the following snippet?
	struct InsanelyCoolAssistant {
		char gender;
		char* mName;
		short int mAge;
	};
	char* name = new char[STRING_MAX_LEN];
	InsanelyCoolAssistant me = {'F' , name, 22 };
	std::cin >> me.mName >> me.mAge;
	std::cout << me.mName << ", aged " << me.mAge << " years is an insanely cool assistant!" << std::endl;
	std::cout << sizeof(InsanelyCoolAssistant);

	return 0;
}