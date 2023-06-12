/**
* @file dosyaokuyucu.cpp
* @description Dugum.
* @course 2A
* @assignment 1
* @date 14/27/2022
* @author berkay kopuz
*/


#include "DosyaOkuyucu.hpp"




DosyaOkuyucu :: DosyaOkuyucu(string fileName){
	this->fileName = fileName;
	
	int linecount = lineCount();
	
	this->lines = new SatirListesi*[linecount];
	for(int i=0; i<linecount; i++){
		this->lines[i] = new SatirListesi();
	}
	
	
}
void DosyaOkuyucu :: readLine(){
	
	ifstream readfile(this->fileName);
	string context;
	string str;
	int index = 0;
	
	
	while(getline(readfile,context)){
		
		istringstream s1(context);
		
		while(getline(s1, str, ' ')){
			this->lines[index]->Add(stoi(str));
		}
		
		index++;
	
		
	}
	readfile.close();
}



YoneticiListesi* DosyaOkuyucu :: GetYoneticiListesi(){ 
	readLine(); //okuma islemi yapildi tum listedekiler satir listesi nesnelerine eklendi.
	YoneticiListesi *tmp = new YoneticiListesi();
	int linecount = lineCount();
	
	for(int i=0; i<linecount; ++i){
		tmp->add(this->lines[i]);
		
	}
	
	return tmp;  
}



int DosyaOkuyucu ::  lineCount(){
	int count = 0;
	ifstream readfile(this->fileName);
	string context;
	while(getline(readfile, context)){
		++count;
	}
	
	readfile.close();
	
	return count;
}

DosyaOkuyucu :: ~DosyaOkuyucu(){
	if(lines!=0){
		int count = lineCount();
		
		for(int i=0; i<count; i++){
			if(lines[i]!=0) delete lines[i];
		}
	
		
		delete[] lines;
	}
}
	
