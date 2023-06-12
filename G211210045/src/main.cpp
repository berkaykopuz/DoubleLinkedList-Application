#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "DosyaOkuyucu.hpp"
#include "SatirListesiDugum.hpp"


using namespace std;

int main(int argc, char** argv){
	DosyaOkuyucu* dosyaOkuyucu = new DosyaOkuyucu("veriler.txt");
	YoneticiListesi *yoneticiListesi = dosyaOkuyucu->GetYoneticiListesi();
	SatirListesi *satirListesi = new SatirListesi();
	
	char cevap;
	int yoneticisayac = 0;
	int sayac = 0;
	int yedeksira = 0;

	yoneticiListesi->printYoneticiListesi(8,yoneticisayac);
	yoneticiListesi->printMevcutSatirListesi(yedeksira,1/14,yoneticiListesi);
	
	do{
		
		cin>>cevap;
		switch(cevap){
			case 'c':
				system("CLS");
				yoneticiListesi->printYoneticiListesi(8,yoneticisayac);

				++yedeksira;
				++sayac;
				yoneticiListesi->printMevcutSatirListesi(yedeksira,sayac,yoneticiListesi);

				break;
			case 'z':
				system("CLS");
				--yedeksira;
				--sayac;
				if(yedeksira<0){
					cout << endl << "Listede daha geriye gidilemez.";
					sayac=-1;
					yedeksira=-1;
					break;
				}
				else if(yedeksira==1){
					yoneticiListesi->printYoneticiListesi(8,yoneticisayac);
					yoneticiListesi->printMevcutSatirListesi(yedeksira,sayac,yoneticiListesi);
				}
				else{
					yoneticiListesi->printYoneticiListesi(8,yoneticisayac);
					yoneticiListesi->printMevcutSatirListesi(yedeksira,sayac,yoneticiListesi);
				}
				
				break;

			case 'd':
				system("CLS");
				++yoneticisayac;
				
				yoneticiListesi->printYoneticiListesi(8,yoneticisayac);

				if(yoneticisayac==1){
					yedeksira = 8;
				}
				else if(yoneticisayac==2){
					yedeksira = 16;
				}
				else if(yoneticisayac==3){ //error
					yedeksira = 24;
				}
				yoneticiListesi->printMevcutSatirListesi(yedeksira,sayac,yoneticiListesi);
				
				break;
			case 'a':
				system("CLS");
				--yoneticisayac;

				yoneticiListesi->printYoneticiListesi(8,yoneticisayac);

				if(yoneticisayac==1){
					yedeksira = 8;
				}
				else if(yoneticisayac==2){
					yedeksira = 16;
				}
				else if(yoneticisayac==3){ //error
					yedeksira = 24;
				}
				yoneticiListesi->printMevcutSatirListesi(yedeksira,sayac,yoneticiListesi);
				
				break;
			default:
				break;
			

		}





	}while(true);
	
	

}
