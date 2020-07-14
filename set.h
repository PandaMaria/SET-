#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include"element.h"
class Set{
    Element *prim, *ultim;
    unsigned length;
    void popRight();
    void popLeft();
    Element* getPrim();
    Element* getUltim();
public:
    Set();
    Set(int);
    Set(const Set&);
    void insertEl(int);
    void deleteEl(int);
    int getLength();
    int getSuma();
    int unic(int);
    Set& operator%(Set&);

    bool operator>(Set&);
    bool operator<(Set&);

    Set& operator*(int);
    Element& operator[](int);
    Set& operator+(Set&);
    bool find(int x);
    friend ostream& operator<<(ostream& out,const Set& s);
    friend istream& operator>>(istream&,Set&);

};


#endif // SET_H_INCLUDED
