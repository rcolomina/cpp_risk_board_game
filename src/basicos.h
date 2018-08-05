#ifndef BASICOS_CABECERA_
#define BASICOS_CABECERA_

#include <iostream>
#include <math.h>
#include <list>
#include <stdlib.h>
#include <string>

using namespace std;

enum Color{ROJO, NEGRO, AMARILLO, AZUL};

class Jugador{
  public:
  Jugador(Color color,string nombre_jugador):color(color),nombre_jugador(nombre_jugador){}
     ~Jugador(){}
     Color get_color_jugador() {return color;}
     string get_nombre_jugador() {return nombre_jugador;} 
  
  private:
     Color color;
     string nombre_jugador;
};

class Territorio{
  public:
  Territorio(string nombre_territorio):
     nombre_territorio(nombre_territorio){}

     ~Territorio(){}
     void set_jugador_propietario(Jugador *new_jugador_propietario);
     Jugador get_jugador_propietario();
     string get_nombre() { return nombre_territorio;}
  private:
     string nombre_territorio;
     Jugador *jugador_propietario;
};


class Conexion{
  public:
  Conexion(Territorio *territorio_A,Territorio *territorio_B):
     territorio_A(territorio_A),
	  territorio_B(territorio_B){}
  private:
     
     Territorio *territorio_A, *territorio_B;
};

class Unidad{
  public:
     
     Unidad(Color color) {}
     Unidad(Color color,Territorio *territorio) {}
     ~Unidad() {}
     void set_color(Color new_color);
     Color get_color();

     void poner_territorio(Territorio *new_territorio);
     void mover_territorio(Territorio *new_territorio);    
    
  private:
     Territorio *territorio;
     Color color;
};


class Dado{
  public:
  Dado(int caras):
     caras(caras){
	  srand (time(NULL));}
     
     int tirar_dado() {      
	  return ((rand() % caras) + 1);
     }
    
  private:
     int caras;
};


class Batalla_basica{
  public:
  Batalla_basica(int numero_atacantes,int numero_defensores):
     numero_atacantes(numero_atacantes),
	  bajas_atacantes(0),
	  numero_defensores(numero_defensores),
	  bajas_defensoras(0),
	  dado_atac_1(6),dado_atac_2(6),dado_atac_3(6),
	  dado_def_1(6),dado_def_2(6){}

     void jugar_batalla(){
	  //lista_ataques.erase();
	  //lista_defensas.erase();
	  
	  lista_ataques.push_front(dado_atac_1.tirar_dado());
	  lista_ataques.push_front(dado_atac_2.tirar_dado());
	  lista_ataques.push_front(dado_atac_3.tirar_dado());

	  lista_ataques.sort();
	  lista_ataques.reverse();


	  lista_defensas.push_front(dado_def_1.tirar_dado());
	  lista_defensas.push_front(dado_def_2.tirar_dado());

	  lista_defensas.sort();
	  lista_defensas.reverse();

	  cout << "Lista de resultados atacante" << endl;
	  for(iterador1=lista_ataques.begin();iterador1 != lista_ataques.end(); ++iterador1)
	       cout << *iterador1 << " ";   
	  cout << endl;
	  
	  cout << "Lista de resultados defensor" << endl;
	  for(iterador1=lista_defensas.begin();iterador1 != lista_defensas.end(); ++iterador1)
	       cout << *iterador1 << " ";   
	  cout << endl;


	  if(numero_atacantes==3 and numero_defensores==2){

	       cout << "Numero atacantes 3 and Numbero de defensores 2" << endl;
	       
	       iterador1=lista_ataques.begin();
	       iterador2=lista_defensas.begin();

	       if(*iterador1>*iterador2)
		    bajas_defensoras++;
	       else
		    bajas_atacantes++;

	       iterador1++;
	       iterador2++;

	       if(*iterador1>*iterador2)
		    bajas_defensoras++;
	       else
		    bajas_atacantes++;                       	
	  }

	  cout << endl;
	  cout << " Bajas atacantes: " << bajas_atacantes << endl;
	  cout << " Bajas defensoras:" << bajas_defensoras << endl;
	  cout << endl;

	  if(numero_atacantes==3 and numero_defensores==1);
	  if(numero_atacantes==2 and numero_defensores==2);
	  if(numero_atacantes==2 and numero_defensores==1);  
	  if(numero_atacantes==1 and numero_defensores==2);
	  if(numero_atacantes==1 and numero_defensores==1);
     }
  private:
     int numero_atacantes;
     int bajas_atacantes;
     int numero_defensores;
     int bajas_defensoras;
     Dado dado_atac_1,dado_atac_2,dado_atac_3;
     Dado dado_def_1,dado_def_2;
     list<int> lista_ataques,lista_defensas;
     list<int>::iterator iterador1,iterador2;
};



#endif
