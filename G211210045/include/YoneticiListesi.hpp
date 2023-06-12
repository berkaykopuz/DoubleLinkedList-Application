
#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <fstream>
#include "SatirListesi.hpp"
#include "YoneticiListesiDugum.hpp"

class YoneticiListesi{
	private:
	
    YoneticiListesiDugum *head;
    YoneticiListesiDugum* FindPrevByPosition(int index);
    YoneticiListesiDugum* FindPosition(int index);
    int size;
	
	public:

	//işlevsel fonksiyonlar
	YoneticiListesi();
	int Count()const;
	SatirListesi*& first();
    SatirListesi*& last();
    bool isEmpty()const;
    void add(SatirListesi*& item);
    void insert(int index, SatirListesi*& item);
    int indexOf(SatirListesi*& item);
    void remove(SatirListesi*& item);
    void calculateAveragee(int index);
    void removeAt(int index);
    bool find(SatirListesi*& item);
    void reverse();
    SatirListesi*& elementAt(int index);
    void clear();
    ~YoneticiListesi();
	
	// Print fonksiyonları
	void oncekiYaz(int adet,int sayac);
	void mevcutyoneticiadresiYaz(int adet,int yoneticisayac);
	void ortalamaYaz(int adet,int yoneticisayac);
	void sonrakiYaz(int adet,int yoneticisayac);
    void cizgiOlustur(int adet);
	void printYoneticiListesi(int adet,int yoneticisayac);
    void printSatirListesi();
    int lineCount();
    void printMevcutSatirListesi(int sira,int sayac,YoneticiListesi *yoneticiListesi);
    
    
    
};

#endif