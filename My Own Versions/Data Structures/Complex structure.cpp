#include <iostream>
using namespace std;
class complexe{
private:
    static int  nb;
    float x,y;
public:
    
    //constructeur avec parametre :
    
    complexe(int re,int im) {
        x = re;
        y = im;
        nb+=1; 
    }
    /*ou bien :
    complexe(int re,int im) x(re),y(im)
    {nb++;}*/

    //constructeur avec initialisation a 0 :
    
    complexe(int=0,int=0);
   
    //une methode static pour afficher le nb d'objet complex instanciée
    
    //destructeur:n'est pas obligatoir car tt les attribus sont statique
    
    ~complexe(){
        nb--;
    }

    static void show_nb(){
        cout<<"vous avez instanciée " <<nb <<" objet complex.\n";
    } 
    //Rq:les methode static ne peut manipuler que les attribus static
    
    //les geteur:
    
    float getx(){return x;}
    float gety(){return y;}
    
    //les seteur:   
    
    void setx(float re){ x= re;}
    void sety(float im){ x= im;}
    
    //surcharge de l'operateur << (pour l'affichage)
    
    friend ostream& operator<<( ostream& ,const complexe& );
    
    //operateur+:
    
    complexe operator+(const complexe&);
    
    //operateur++(prefixee):
    
    complexe operator++();
    
    //operateur++(postfixee):
    
    complexe operator++(int);
    
    //operateur==:
    
    bool operator==(const complexe&);
    
    //operateur!=:
    
    bool operator!=(const complexe&);

    complexe operator=(const complexe&);
    
    //operateur== avec une fct amie de complexe:
    
    /*friend bool operator==(const complexe&,const complexe&);*/  
    
    //operateur!= avec une fct amie de complexe:
    
    /*friend bool operator!=(const complexe&,const complexe&);*/

}; 

//initialisation de l'attribue static :

int complexe::nb=0;

ostream& operator<<( ostream& out ,const complexe& c ){
    out<<"Z="<<c.x<<"+"<<c.y<<"i\n";
return out;
}

complexe complexe::operator+(const complexe& c){
    complexe nv(x,y);
    nv.setx(nv.x+c.x);
    nv.sety(nv.y+c.y);
    return nv;}
    /*ou tous simplement: 
    {complex nv(x+c.x,y+c.y);
    return nv;}*/

complexe complexe::operator++(){};


complexe complexe::operator++(int){};


bool complexe::operator==(const complexe& c){return (c.x==x && c.y==y);}

bool complexe::operator!=(const complexe& c){return !(c.x==x && c.y==y);}

//bool operator==(const complexe& c1,const complexe& c2){return (c1.x==c2.x && c1.y==c2.y);}
//bool operator!=(const complexe c1,const complexe& c2){return !(c1.x==c2.x && c1.y==c2.y);}


int main(void){
    complexe::show_nb();
    complexe c1(3,2);
    c1.setx(4);c1.sety(5);
    complexe::show_nb();
    complexe c2(2.5,2.5);
    complexe::show_nb;
    complexe c3=c1+c2;
    complexe c4=c3++;
    c4=++c3;
    complexe c5=c4;
    complexe::show_nb();

















c1.~complexe();
complexe::show_nb;
c2.~complexe();
complexe::show_nb;
c3.~complexe();
complexe::show_nb;
c4.~complexe();
complexe::show_nb;
c5.~complexe();







}
