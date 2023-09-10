#include <iostream>
#include <string>
#include "UMemoria.h"
using namespace std;
//int Numero_Ids(string cadena);
//string Obtener_Id(string cadena,int n);
 //void eliminarFlechas(string &cadena);
 void menu();
int main(){
	// int* n=new int [5];   asi de define un vector

	 /*

   cout <<"Hola mundoo"<<endl;

  string cadena="->mes";
  //cout<<"cantidad"<<Numero_Ids(cadena)<<endl;
  // cout<<"la palabra es "<<Obtener_Id(cadena,2)<<endl;
   //eliminarFlechas(cadena);
   //cout<<cadena<<endl; */
   CSMemoria *MiMemoria=new CSMemoria();
  MiMemoria->mostrar();
  int x= MiMemoria->new_espacio ("juan,Perez");
  cout << "\nLa x es: "<<x<<endl;

   int y= MiMemoria->new_espacio ("40253");
	cout << "\nLa y es: "<<y<<endl;
   int z= MiMemoria->new_espacio ("INF220,SA");
   //(y,"->40253",100)
   MiMemoria->poner_dato(y,"->40253",100);
   MiMemoria->Delete_espacio(y);

  MiMemoria->mostrar();
  // menu();
	   system("pause");
   return 0;
}
void menu(){
CSMemoria *mem;
int opcion;

do{

cout<< "1.Crear"<<endl;
cout<< "2.Pedir Espacio"<<endl;
cout<< "3.Liberar Espacio"<<endl;
cout<< "4.Poner Dato"<<endl;
cout<< "5.Mostrar memoria"<<endl;
cout<< "6.Salir"<<endl;
 cin>> opcion;
   switch(opcion){
   case 1:{
		  mem=new CSMemoria();
		  cout<<"Memoria Creada \n";

		} break;
   case 2:{
		  string ids;
		  cout<<"Ids:";
		  cin.ignore();
		  getline(cin,ids);
		  mem->new_espacio(ids);

		} break;
		case 3:{
		  int dir_delete;
		  cout<<"Liberar Espacio";
		  cin>> dir_delete;
		  mem->Delete_espacio(dir_delete);

		} break;
	case 4:{
		  int dir,valor;
		  string id;
		  cout<<"Direccion:"<<endl;
		  cin>> dir;
		  cout<<"Id: "<<endl;
		  cin.ignore();
		  getline(cin,id);
		  cout<<"Valor:"<<endl;
		  cin>> valor;
		  mem->poner_dato(dir,id,valor);

		} break;

		case 5:{
		 mem->mostrar();
		} break;
   }
   system("pause");
   system("cls");

 }while(opcion!=6);
}




