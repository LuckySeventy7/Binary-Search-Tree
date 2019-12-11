#include <iostream>
#include "Arbol.h"
#include "stdlib.h"
using namespace std;

/*
RUIZ RUVALCABA, SERGIO -217292617
ESTRUCTURA DE DATOS 2, ACT ARBOL
*/

int main()
{
    Arbol obj;
    int op;
    string nom;
    do{


        cout << "Arbol de Busqueda Binario"<<endl<<"1. Insertar "<<endl<<"2. Mostrar Todo"<<endl<<"3. Buscar"<<endl<<"4. Eliminar"<<endl<<"Ingresar Opcion: ";
        cin>>op;
        if(op==1){
            cout<<"Ingrese nombre: ";
            cin>>nom;
            obj.SetName(nom);
            system("pause");

        }
        else if(op==2){
            obj.imprimir();
            system("pause");



        }
        else if(op==3){

            cout<<"Ingrese nombre que desea buscar: ";
            cin>>nom;
            if(obj.buscNom(nom))
                cout<<"El nombre "<<nom<<" si esta registrado en el Arbol"<<endl;
            else
                cout<<"Nombre no encontrado"<<endl;


        }

        else if(op==4){
            cout<<"Ingrese nombre que desea eliminar: ";
            cin>>nom;

            if(obj.eliminarNodo(nom))
                cout<<"Nombre fue eliminado exitosamente"<<endl;
            else
                cout<<"Nombre no fue encontrado";
            system("pause");
        }
         system("cls");
    }while(op!=5);
    return 0;
}
