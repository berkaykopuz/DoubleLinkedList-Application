/**
* @file yoneticilistesidugum.cpp
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date 14/27/2022
* @author berkay kopuz
*/
#include "YoneticiListesiDugum.hpp"


YoneticiListesiDugum::YoneticiListesiDugum(SatirListesi* data, YoneticiListesiDugum *next , YoneticiListesiDugum *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}

YoneticiListesiDugum::YoneticiListesiDugum(SatirListesi* data, YoneticiListesiDugum *next ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}

YoneticiListesiDugum::YoneticiListesiDugum(SatirListesi* data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}
double YoneticiListesiDugum::calculateAverage() {
    double total = 0;
    if (this->data->isEmpty())
        return total;

    int count = this->data->Count();
    for (int i = 0; i < count; ++i) {
        total += this->data->elementAt(i);
    }
    return total / count;
} 
