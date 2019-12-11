#include "Arbol.h"

Arbol::Arbol()
{
    root=NULL;
    //ctor
}

Arbol::~Arbol()
{
    //dtor
}

Nodo::Nodo(){
left=NULL;
right=NULL;
current=NULL;

}


void Arbol::SetName(string d){

    if(root==NULL){
         Nodo *node= new Nodo();
    node->nombre= d;

        root= node;
        return;


    }
  //  node=root;

    insertBin(root, d);
}
Nodo *Arbol::insertBin(Nodo *nod, string d)
{
     Nodo *nodo= nod;
    if(nodo==NULL){
        nodo= new Nodo();
        nodo->nombre= d;

    }

    if(strcmp(nodo->nombre.c_str(),d.c_str())<0)
    {

          nodo->right= insertBin(nodo->right, d);

    }
    if (strcmp(nodo->nombre.c_str(),d.c_str())>0)
    {

       nodo->left= insertBin(nodo->left, d);
    }
     return nodo;
}

bool Arbol::buscNom(string s)
{
    return buscArbol(root, s);
}


bool Arbol::buscArbol(Nodo *nodo, string s)//c b a - yes and b remved ca, c-a-b, rem b yes, a no
{
    if (nodo == NULL)
        return false;

    if (strcmp(nodo->nombre.c_str(),s.c_str())==0)
    {
        return true;
    }
    else if (strcmp(nodo->nombre.c_str(),s.c_str())<0)
    {
       return buscArbol(nodo->right, s);
    }
    else if (strcmp(nodo->nombre.c_str(),s.c_str())>0)
    {
        return buscArbol(nodo->left, s);
    }

    return false;
}

bool Arbol::eliminarNodo(string nombreElim) {

    if(root==NULL)
        return false;
	Nodo *current = root;//nodo is root
	Nodo *parent = root;
	Nodo *successo;//NULL;
	bool isLeftChild = true;
	while (current->nombre != nombreElim) {
		parent = current;
		if (strcmp(nombreElim.c_str(),current->nombre.c_str())<0) {
			isLeftChild = true;
			current = current->left;
		} else {
			isLeftChild = false;
			current = current->right;
		}
		if (current == NULL)
			return false;
	}
	if ((current->left == NULL) && (current->right== NULL))
		if (current == root)//rrot
            root = NULL;
		else if (isLeftChild)
			parent->left = NULL;
		else
			parent->right = NULL;
	else if (current->right == NULL)
		if (current == root)//root
			root = current->left;
		else if (isLeftChild)
			parent->left = current->left;
		else
			parent->right = current->right;
	else if (current->left == NULL)
		if (current == root)
			root = current->right;
		else if (isLeftChild)
			parent->left = current->right;
		else
			parent->right = current->right;
	else{
		successo = getSucesor(current);
		if (current == root)
			root = successo;
		else if (isLeftChild)
			parent->left = successo;
		else
			parent->right= successo;
			successo->right = current->left;
	}


return true;
}


Nodo* Arbol::getSucesor(Nodo *delNode) {
    Nodo *successorParent = delNode;
    Nodo *successor = delNode;
    Nodo* current = delNode->right;
    while (!(current == NULL)) {
        successorParent = current;
        successor = current;
        current = current->left;
    }
    if (!(successor == delNode->right)) {
        successorParent->left = successor->right;
        successor->right = delNode->right;
    }
    return successor;
}


void Arbol::imprimir(){
    if(root==NULL){

        cout<<"Arbol esta vacio"<<endl;
    }
    else
        mostrar(root);
}
void Arbol::mostrar(Nodo *n)
    {
        if (n == NULL)
            return;

        mostrar(n->left);
        cout<<n->nombre<<endl;
        mostrar(n->right);
    }
