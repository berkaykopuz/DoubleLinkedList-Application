/* 
 * File:   SatirListesi.hpp
 * Author: Berkay Kopuz
 *
 * Created on November 10, 2022, 6:26 PM
 */
 
#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "SatirListesiDugum.hpp"
#include <iomanip>
#include <ostream>
#include <iostream>




class SatirListesi{
	private:
		SatirListesiDugum *head;
		int size; //??public de olabilir
		
		SatirListesiDugum* FindPrevByPosition(int position);
	
	
	public:
		SatirListesi();
		bool isEmpty()const;
		int Count()const;
		int IndexOf(const int& data);
		void Add(const int& data);
		void Insert(const int& data, int index);
		const int& FindFirst();
		const int& FindLast();
		void Remove(const int& data);
		void RemoveAt(int index);
		void Reverse();
		const int& elementAt(int index);
		void printSatir(int sayac);
		
		
	
};

#endif