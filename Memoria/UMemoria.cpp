// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMemoria.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int Numero_Ids(string cadena){
 int cantidad=0;
 for (int i = 0; i < cadena.length(); i++) {
	if(cadena[i]==','){
	  cantidad++;
	}
 }
  if(!cadena.empty()){
	 cantidad+=1;
  }else{
	cantidad+=0;
  }
  return cantidad;
}

string Obtener_Id(string cadena,int n){
	string palabra="" ;
	int contador=0;
	int i=0;
	while(contador<n-1 && i<cadena.length()){
	  if(cadena.at(i)==','){
		 contador++;
		 cadena=cadena.substr(i+1,cadena.length()-(cadena.substr(0,i).length()));
		 i=-1;
	  }
	  i++;
	}
	i=0;
		while(cadena[i]!=',' && i<cadena.length()){
		  i++;
		}
	palabra=cadena.substr(0,i);
	return palabra;
}










 void eliminarFlecha(string &cadena){
  int pos=0;
  if(cadena!=""){
	 while(cadena[pos]!='-'&& cadena[pos+1]!='>'){
		 pos++;
	 }
	 cadena=cadena.substr(pos+2,cadena.length()-(cadena.substr(0,pos+1).length()));
  }

 }














CSMemoria::CSMemoria() {
	mem = new NodoMem[MAX];
	for (int i = 0; i < MAX; i++) {
		mem[i].link = i + 1;
	}
	mem[MAX - 1].link = -1;
	this->libre = 0;
}

direccion_mem CSMemoria::new_espacio(string cadena){

 int  cant = Numero_Ids(cadena);
 int dir=libre;
 int d=libre;//0
 for (int i = 1; i <= cant-1; i++) {
	mem[d].id=Obtener_Id(cadena,i);
	d=mem[d].link;
 }
 libre= mem[d].link;
 mem[d].link=-1;
 mem[d].id=Obtener_Id(cadena,cant);
 return dir;

}
void CSMemoria::Delete_espacio(direccion_mem dir){
int x = dir;
 while (mem[x].link != -1){
   x=mem[x].link;
 }
 mem[x].link=libre;
 libre=x;


}

void CSMemoria::poner_dato(direccion_mem dir ,string  id, int valor){

 int z=dir;
 eliminarFlecha(id);
 while(z!=NULO){
   if(mem[z].id==id){
	  mem[z].dato=valor;
   }
   z=mem[z].link;
 }




}























int CSMemoria::obtenerDato(direccion_mem dir, string id) {

int z= dir;
bool ex=false;
 eliminarFlecha(id);
 while (z!=NULO){
   if (mem[z].id == id){
	return mem[z].dato;
   }
   z=mem[z].link;
 }

}

int CSMemoria::Espacio_Disponible(){
int x = libre;
 int c = 0; // CONTADOR
 while( x!= NULO){
  c++;
  x=mem[x].link;
 }
return c;
}
int CSMemoria::Espacio_ocupado(){
 return (MAX)-Espacio_Disponible();
}

bool CSMemoria::dir_libre(direccion_mem dir){
   int x = libre;
   bool c=false; // BANDERA
while(( x != NULL) && (c== false)){
  if(x ==dir){
   c = true;
   }

 x=mem[x].link;
}
 return c;
}
void CSMemoria::mostrar(){
	cout<<"+";
	for(int i=2;i<=3+4+8+3+5; i=i+1){
		cout<<"-";
	};
	cout<<"+"<<"\n";
	cout<<"|DIR|"<<"DATO|"<<"---ID---|"<<"LINK|\n";
	for (int i = 0; i<MAX; i = i+1){
		cout<<"|"<<"   "<<i<<"|"<<"    "<<
			mem[i].dato<<"|"<<"        "<<mem[i].id<<
			"|"<<"     "<<mem[i].link<<"|\n";
	};
	cout<<"+";
	for(int i=2;i<=2+4+8+4+5; i=i+1){
		cout<<"-";
	};
	cout<<"+\n";
	cout<<"LIBRE:"<<libre<<"\n";
	cout<<"ESPACIO DISPONIBLE:"<<Espacio_Disponible()<<"\n";
	cout<<"ESPACIO OCUPADO:"<<Espacio_ocupado()<<"\n";

}




