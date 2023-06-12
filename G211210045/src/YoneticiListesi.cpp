/**
* @file yoneticilistesi.cpp
* @description Dugum 
* @course 2A
* @assignment 1
* @date 14/27/2022
* @author berkay kopuz
*/
#include "YoneticiListesi.hpp"
#include <iomanip>
#include <iostream>


using namespace std;

//////////////////////// işlevsel fonksiyonlar ///////////////////////////////////////

YoneticiListesi::YoneticiListesi() {
    head = NULL;
    size = 0;
}

YoneticiListesiDugum* YoneticiListesi::FindPrevByPosition(int index) {
    if (index < 0 || index > size)throw "No Such Element";
    YoneticiListesiDugum *prv = head;
    int i = 1;
    for (YoneticiListesiDugum *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

YoneticiListesiDugum* YoneticiListesi::FindPosition(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    return this->FindPrevByPosition(index + 1);

}

SatirListesi*& YoneticiListesi::first(){
    if (isEmpty()) throw "No Such Element";
    return head->data;
}

SatirListesi*& YoneticiListesi::last(){
    if (isEmpty()) throw "No Such Element";
    return FindPrevByPosition(size)->data;
}


int YoneticiListesi::Count()const {
    return size;
}

bool YoneticiListesi::isEmpty()const {
    return size == 0;
}

void YoneticiListesi::add(SatirListesi*& data) {
    insert(size, data);
}

void YoneticiListesi::insert(int index, SatirListesi*& data) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new YoneticiListesiDugum(data, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiListesiDugum *prv = FindPrevByPosition(index);
        prv->next = new YoneticiListesiDugum(data, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}



int YoneticiListesi::indexOf(SatirListesi*& data) {
    int index = 0;
    for (YoneticiListesiDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == data) return index;
        index++;
    }
    throw "No Such Element";
}

void YoneticiListesi::remove(SatirListesi*& data) {
    int index = indexOf(data);
    removeAt(index);
}



void YoneticiListesi::calculateAveragee(int index) {
    YoneticiListesiDugum* itr = this->FindPosition(index);

    if (itr == NULL) {

        throw "error";
    }


    double total = 0;
    if (itr->data->isEmpty()) {

        itr->average = total;
        return;
    }


    int count = itr->data->Count();
    for (int i = 0; i < count; ++i) {
        total += itr->data->elementAt(i);
    }
    itr->average = total / count;



}



void YoneticiListesi::removeAt(int index) {
    if (index < 0 || index >= size) throw "Index out of Range";
    YoneticiListesiDugum *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiListesiDugum *prv = FindPrevByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}



bool YoneticiListesi::find(SatirListesi*& item) {
    for (YoneticiListesiDugum *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}

void YoneticiListesi::reverse() {
    for (YoneticiListesiDugum *itr = head; itr != NULL;) {
        YoneticiListesiDugum *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}



SatirListesi*& YoneticiListesi::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPrevByPosition(index)->next->data;
}

void YoneticiListesi::clear() {
    while (!isEmpty())
        removeAt(0);
}

/////////////////////////////////// Print fonksiyonları /////////////////////////////////////

 void YoneticiListesi :: cizgiOlustur(int adet){
    
	for(int i=0; i<adet; i++){
		cout<< "---------- ";
	}
	
	cout<<endl;
}

 void YoneticiListesi :: mevcutyoneticiadresiYaz(int adet,int yoneticisayac){


	YoneticiListesiDugum *tmp = head;

    if(yoneticisayac==1){
    for(int i=0; i<adet; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==2){
    for(int i=0; i<adet+8; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==3){
    for(int i=0; i<adet+8+8; i++){
        tmp = tmp->next;
    }
    }
	for(int i=0; i<adet; i++, tmp= tmp->next){
		cout<< " " << tmp << " " << " ";
	}
	
	cout << endl;
}
void YoneticiListesi :: oncekiYaz(int adet,int yoneticisayac){
	YoneticiListesiDugum *tmp = head;
    if(yoneticisayac==1){
    for(int i=0; i<adet; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==2){
    for(int i=0; i<adet+8; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==3){
    for(int i=0; i<adet+8+8; i++){
        tmp = tmp->next;
    }
    }
    
	for(int i=0; i<adet; i++, tmp=tmp->next){
        if(i==0)
        {
            cout<< "|" << "0       " << "  ";
        }
        else{
            cout<< "|" << tmp->prev << "  ";
        }
		
	}
	
	cout << endl;
}
void YoneticiListesi :: ortalamaYaz(int adet,int yoneticisayac){
	
	YoneticiListesiDugum *tmp = head;
    
    if(yoneticisayac==1){
    for(int i=0; i<adet; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==2){
    for(int i=0; i<adet+8; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==3){
    for(int i=0; i<adet+8+8; i++){
        tmp = tmp->next;
    }
    }
	
	for(int i=0; i<adet; i++){
        
		cout<< "|  " << tmp->average << "  |" << "  ";
        tmp=tmp->next;

	}
	
	cout << endl;
}

 void YoneticiListesi :: sonrakiYaz(int adet,int yoneticisayac){
	YoneticiListesiDugum *tmp = head;
    
    if(yoneticisayac==1){
    for(int i=0; i<adet; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==2){
    for(int i=0; i<adet+8; i++){
        tmp = tmp->next;
    }
    }
    else if(yoneticisayac==3){
    for(int i=0; i<adet+8+8; i++){
        tmp = tmp->next;
    }
    }
    
	for(int i=0; i<adet; i++,tmp=tmp->next){
		cout<< "|" << tmp->next << "  ";
        
	}
    
    
	cout << endl;
}

void YoneticiListesi :: printYoneticiListesi(int adet,int yoneticisayac){
	cout << "ilk" << setw(20) << "--->" << endl;
	
	mevcutyoneticiadresiYaz(adet,yoneticisayac);
	cizgiOlustur(adet);
	oncekiYaz(adet,yoneticisayac);
	cizgiOlustur(adet);
	ortalamaYaz(adet,yoneticisayac);
	cizgiOlustur(adet);
	sonrakiYaz(adet,yoneticisayac);
    
}






