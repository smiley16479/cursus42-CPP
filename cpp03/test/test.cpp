#include <iostream>
using namespace std;


// Classe de base du système
class A
{
  public:
    A (int a) : _a(a), _b(1), _c(2)
    {
      cout << "Constructeur de A" << endl;
    }
	void get_abc() { cout << "a : " << _a << " b : " << _b << " c : " << _c << endl; }
	virtual void display() { cout << "Display A" << endl; }

  private:
    int _a;
    int _b;
    int _c;
};


// Sous classe directe de A
class B : virtual public  A
{
  public:
    // Le constructeur de B appelle celui de A
    // afin d'initialiser correctement les attributs de A
    // présents dans la classe B


    B(int a) : A(a)
    {
      cout << "Constructeur de B" << endl;
    };
	void display() { cout << "Display B" << endl; }

  private:
    int b;
};


// Sous classe directe de A
class C : virtual public A
{
  public:
    // Le constructeur de C appele celui de A
    // afin d'initialiser correctement les attributs de A
    // présents dans la classe C


    C(int a) : A (a) 
    {
      cout << "Constructeur de C" << endl;
    };
	// void display() { cout << "Display C" << endl; }

  private:
    int c;
};


// Sous classe de B et C
// Afin de gérer l'héritage à répétition, on introduit également A dans la liste
// des super classes
class D : virtual public A, public B, public C
{
  public:
    D(int a) :	A (a), 
    			B (a), 
        		C (a) 

    {
      cout << "Constructeur de D" << endl;
    };
	// void display() { cout << "Display D" << endl; }

  private:
    int d;
};

int main()
{
	// A a(4);
	D d(5);
	d.get_abc();
	d.display();
	return 0;
}