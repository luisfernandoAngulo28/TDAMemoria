//---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

typedef int direccion_mem;
/*
Constantes MAX = 20
 NULO =-1
*/
const int MAX=20;
const int NULO=-1;
/*
NodoM
 Dato TipoDato (Entero)
 id cadena(12)
 Link Direccion de Memoria(Entero)
 Fin tipo
*/

struct NodoMem{
	int dato;
	string id;
	int link;

};



class CSMemoria{
//Atributos

	private:
	//MEM arreglo(MAX) de tipo NodoM
	NodoMem* mem;
	//libre Direccion de memoria (entero)
	direccion_mem libre;


	public:

	 CSMemoria(); // crear
	direccion_mem new_espacio(string cadena);
	void Delete_espacio(int dir);
	void poner_dato(int dir ,string  cadena_id, int valor);
	int obtenerDato(int dir, string lugar) ;
	int Espacio_Disponible();
	int Espacio_ocupado();
	bool dir_libre(int dir);
	void mostrar();


};



#endif
