#ifndef ARBOL_H
#define ARBOL_H
#include <string.h>
#include <iostream>
using namespace std;
class Nodo{

    public:
        string nombre;
        Nodo *right;
    	Nodo *left;
        Nodo *current;
        Nodo *parent;
        Nodo();
};

class Arbol
{
    public:
        Arbol();
        virtual ~Arbol();
        Nodo *root;
        void SetName(string d);
        Nodo *insertBin(Nodo *nodo, string d);
        bool buscArbol(Nodo *nodo, string s);
        bool buscNom(string s);
        void imprimir();
        void mostrar(Nodo *n);
        bool eliminarNodo(string nombreElim);
        Nodo *getSucesor(Nodo *delNode);

    protected:

    private:
};

#endif // ARBOL_H
