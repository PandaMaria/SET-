#include"set.h"

void Set::popRight()
{                                  //metoda pentru scoaterea elementelor
    if(prim==NULL){
        throw std::runtime_error("Pop from empty set");    //daca setul este gol arunc exceptie
    }else if(prim == ultim){                            //verific daca are un singur element
        Element* toDelete = prim;
        prim = ultim = NULL;
        delete toDelete;                                //apelarea destructorului ~Element
        length--;
    }else{
        Element* toDelete = ultim;                      //daca s are mai mult de un element
        ultim = ultim->getAnter();                      //setez pointerul ultim la penultimul element
        ultim->setNext(NULL);
        delete toDelete;                                //apelez destructorul pentru ultimul element
        length--;
    }
}

void Set::popLeft(){                                   //la fel ca pentru popRight()
    if(prim==NULL){
        throw std::runtime_error("Pop from empty set");
    }else if(prim == ultim){
        Element* toDelete = prim;
        prim = ultim = NULL;
        delete toDelete;
        length--;
    }else{
        Element* toDelete = prim;
        prim = prim->getNext();
        prim->setAnter(NULL);
        delete toDelete;
        length--;
    }
}

int Set::getLength(){                    // lungimea setului
    return length;
}

Element* Set::getPrim(){
    return prim;
}

Element* Set::getUltim(){
    return ultim;
}

Set::Set(){                               //initializare
    prim = ultim = NULL;
    length = 0;
}

Set::Set(int length){                        //initializare
    prim = ultim = NULL;
    this->length = length;
}

Set::Set(const Set &s){                      //constructor de copiere
    this->length = 0;
    this->prim = NULL;
    this->ultim = NULL;
    Element *aux = s.prim;                   //element auxiliar cu care se parcurge setul
    for(int i=0; i < s.length; i++){
        this->insertEl(aux->getInfo());      //se introduc elemente in noul set
        if(aux->getNext())
            aux = aux->getNext();
    }
}

void Set::insertEl(int value){
    if(unic(value)==0){
        if(prim == NULL){                                   //verific daca setul este gol
            prim = ultim = new Element(value,NULL,NULL);
            length++;
        }else{
            Element* el = new Element(value,NULL,ultim);    //daca setul nu e gol se introduce elementul in dreapta si se
            ultim->setNext(el);                             //seteaza anter-ul lui la elementul anterior iar nextul lui la null
            el->setAnter(ultim);                             //si ii atribui pointerul ultim
            ultim = el;
            length++;
        }
    }
}

void Set::deleteEl(int value){
    Element *el = prim;
        for(int i=0;i<length;i++){
            if(el->getInfo()==value)
            {
                if(!el->getAnter()){
                    popLeft();
                }else if(!el->getNext()){
                    popRight();
                }else{
                    el->getAnter()->setNext(el->getNext());
                    el->getNext()->setAnter(el->getAnter());
                    delete el;
                    length--;
                }
            }
            el = el->getNext();
        }
}

int Set::getSuma(){
    int suma=0;
    Element *el= prim;
    for(int i=0;i<length;i++){
        suma+=el->getInfo();
        el=el->getNext();
    }
    return suma;
}

int Set::unic(int nr){
    Element *el = prim;
    for(int i=0;i<length;i++){
        if(nr = el->getInfo())
            return 1;
        el=el->getNext();
    }
    return 0;
}

Set& Set::operator%(Set& el){
    Set *par = new Set(*this);
    for(int i=0;i<el.length;i++)
        if(el[i]%2==0)
            par->insertEl(el[i].getInfo());
    Set *impar = new Set(*this);
    for(int i=0;i<el.length;i++)
        if(el[i]%2==1)
            impar->insertEl(el[i].getInfo());
}

bool Set::operator>(Set& s ){
    if(this->getLength()>s.getLength()){
        return true;
    }
    return false;
}

bool Set::operator<(Set& s ){
    if(this->getLength()<s.getLength()){
        return true;
    }
    return false;
}

Set& Set::operator*(int scalar){
    Set *s = new Set();
    for(int i=0;i<length;i++){
        s->insertEl(((*this)[i].getInfo())*scalar);
    }
    return *s;
}

Element& Set::operator[](int index){                  //supraincarcarea operatorului []
if(index >= this->getLength()){
        throw std::out_of_range ("Index out of bounds");     //daca indexul este inafara setului arunc exceptie out of range
    }else{
        Element *aux = this->prim;
        for(int i=0;i<index;i++){                       //altfel se parcurge setul cu un pointer care primeste valoarea
            aux=aux->getNext();                         //din adresa de memorie pe care o pointeaza
        }
        return *aux;
    }
}

Set& Set::operator+(Set& el){
    Set *s = new Set(*this);
    for(int i=0;i<el.length;i++){
        s->insertEl(el[i].getInfo());
    }
}

bool Set::find(int x) {
	Element *p = prim;
	while (p != NULL) {
		if (p->getInfo() == x) {
			return true;
		}
		p = p->getNext();
	}
	return false;
}

ostream& operator<<(ostream& out, const Set& s){   //supraincarcarea operatorului <<
     Element *el = s.prim;                           //parcurg setul cu un pointer
    while(el){
        out<<el->getInfo()<<" ";
        el=el->getNext();
    }
}

istream& operator>>(istream& in, Set& s){                 //suprascrierea operatorului >>
    for(int i=0;i<s.getLength();i++){
        int val;
        in>>val;
        s.insertEl(val);
        s.length--;
    }
    return in;
}

