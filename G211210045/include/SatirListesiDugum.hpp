
#ifndef SATIRLISTESIDUGUM_HPP
#define SATIRLISTESIDUGUM_HPP



#include <iostream>
using namespace std;

class SatirListesiDugum {
public:
    int data;
    SatirListesiDugum *next;
    SatirListesiDugum *prev;
    

    SatirListesiDugum(const int data, SatirListesiDugum *next, SatirListesiDugum *prev);
    SatirListesiDugum(const int data, SatirListesiDugum *next);
    SatirListesiDugum(const int data);
};



#endif 

