/**
* @file satirlistesidugum.cpp
* @description Dugum.
* @course 2A
* @assignment 1
* @date 14/27/2022
* @author berkay kopuz
*/
#include "SatirListesiDugum.hpp"

SatirListesiDugum::SatirListesiDugum(const int data, SatirListesiDugum *next , SatirListesiDugum *prev ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiDugum::SatirListesiDugum(const int data, SatirListesiDugum *next) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiDugum::SatirListesiDugum(const int data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}