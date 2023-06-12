#ifndef DOSYAOKUYUCU_HPP
#define DOSYAOKUYUCU_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

using namespace std;

class DosyaOkuyucu{

	private:
	
	string fileName;
	void readLine();
	int lineCount();
	SatirListesi **lines;
	
	public:
	
	DosyaOkuyucu(string fileName);
	~DosyaOkuyucu();
	YoneticiListesi* GetYoneticiListesi();
	
};





#endif