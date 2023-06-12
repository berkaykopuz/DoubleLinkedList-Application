/**
* @file satirlistesi.cpp
* @description Dugum
* @course 2A
* @assignment 1
* @date 14/27/2022
* @author berkay kopuz
*/
 
 #include <iostream>
 #include <ostream>
 #include<fstream>
 #include<string>
 #include<iomanip>
 
 #include "SatirListesi.hpp"
 #include "YoneticiListesi.hpp"
 
 using namespace std;
 
 SatirListesi :: SatirListesi(){
	 head = NULL;
	 size = 0;
 }		
 bool SatirListesi :: isEmpty()const{
	 return size == 0;
 } 
 int SatirListesi :: Count()const{
	return size;
 }
 const int& SatirListesi :: FindFirst(){
	 if(isEmpty()) throw "Node is empty.";
	 return head->data;
 }
 const int& SatirListesi ::  FindLast(){
	 if(isEmpty()) throw "Node is empty.";
	 return FindPrevByPosition(size)->data;
 }
 SatirListesiDugum* SatirListesi ::  FindPrevByPosition(int position){
	 if(position<0 || position>size) throw "Index out of Range";
			int index=1;
			for(SatirListesiDugum *tmp = head; tmp!=NULL; tmp=tmp->next,index++){
				if(position == index) return tmp;
			}
			return NULL;
 }
 void SatirListesi :: RemoveAt(int index){
	 if(index<0 || index>size) throw "Out of range";
	 SatirListesiDugum *del;
	 if(index==0){
		 del = head;
		 head = head->next;
		 if(head != NULL) head->prev = NULL;
		 
		 
	 }
	 else{
		 SatirListesiDugum *prv = FindPrevByPosition(index);
		 del= prv->next;
		 prv->next = del->next;
		 if(del->next!=NULL) del->next->prev = prv;
	 }
	 size--;
	 delete del;
 }
 void SatirListesi :: Add(const int& item){
	 Insert(item,size);
 }
 void SatirListesi ::  Insert(const int& item, int index){
	 if(index<0 || index > size) throw "Index out of range";
	 if(index==0){
		 head= new SatirListesiDugum(item,head);
		 if(head->next != NULL){
			 head->next->prev = head;
		 }
	 }
	 else{
		 SatirListesiDugum *prv = FindPrevByPosition(index);
		 prv->next=new SatirListesiDugum(item, prv->next, prv);
		 if(prv->next->next != NULL) prv->next->next->prev= prv->next;
	 }
	 size++;
	 
 }
 void SatirListesi :: Reverse(){
	 for(SatirListesiDugum *itr =head; itr!=NULL;){
		 SatirListesiDugum *tmp = itr->next;
		 itr->next = itr->prev;
		 itr->prev = tmp;
		 if(tmp==NULL){
			 head = itr;
			 break;
		 }
		 itr = tmp;
	} 
 }
 const int& SatirListesi::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPrevByPosition(index)->next->data;
}

/// PRINT FONKSIYONLARI ///

void YoneticiListesi :: printSatirListesi(){

    YoneticiListesiDugum *tmp2 = this->head;
	

	int lineCount = this->lineCount();
    
    for(int i=0;i<lineCount;i++){
        int count = tmp2->data->Count();
        for(int j=0;j<count;j++)
        {
        cout<<tmp2->data->elementAt(j)<<endl;
        }
        tmp2=tmp2->next;
    }

	
}

int YoneticiListesi ::  lineCount(){
	int count = 0;
	ifstream readfile("veriler.txt");
	string context;
	while(getline(readfile, context)){
		++count;
	}
	
	readfile.close();
	
	return count;
}


void SatirListesi :: printSatir(int sayac){
	cout<<setw(11*sayac)<<""<<"^^^^^^ " << endl;
    for (SatirListesiDugum *dugum = this->head; dugum != NULL; dugum = dugum->next) {
		
		cout<<setw(11*sayac)<<""<<"---------- "<<endl;
		cout<<setw(11*sayac)<<""<<"|"<<dugum<<"|"<<endl;
		cout<<setw(11*sayac)<<""<<"---------- "<<endl;
		cout<<setw(11*sayac)<<""<<"|"<<dugum->data<<setw(7)<<"|"<<endl;
		cout<<setw(11*sayac)<<""<<"---------- "<<endl;
		
		if(dugum->next==NULL)
		{
			cout<<setw(11*sayac)<<""<<"|"<<dugum->next<<setw(8)<<"|"<<endl;
			cout<<setw(11*sayac)<<""<<"---------- "<<endl;
		}
		else{
			cout<<setw(11*sayac)<<""<<"|"<<dugum->next<<"|"<<endl;
			cout<<setw(11*sayac)<<""<<"---------- "<<endl;
		}
    }
}
void YoneticiListesi :: printMevcutSatirListesi(int sira,int sayac,YoneticiListesi *yoneticiListesi){
	
	yoneticiListesi->elementAt(sira)->printSatir(sayac);

}
	





 
 


 