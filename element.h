#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include<iostream>

class Element{
    int info;
    Element* next;
    Element* anter;
public:
    Element();                          //constructor fara parametrii
    Element(int,Element*,Element*);              //constructor cu parametrii
    Element(const Element&);            //constructor de copiere
    void setInfo(int);
    void setAnter(Element*);
    void setNext(Element*);
    int getInfo();
    Element* getNext();
    Element* getAnter();
};








#endif // ELEMENT_H_INCLUDED
