#include "./basicos.h"

void print_title_test(string title){

     int len = title.length();

     string asterix;
     for(int i=0;i<len;i++)asterix.append("*");
     
     cout << asterix <<endl;
     cout << title << endl;
     cout << asterix <<endl;
}

int main(){

     print_title_test("Test: Jugador y Territorios");
     
     Jugador jugador1(ROJO,"Ruben");
     Jugador jugador2(AZUL,"Jose Manuel");
 
     Territorio territorio1("Zealand");
     Territorio territorio2("Australasia");
   
     cout << "Nombre:" << jugador1.get_nombre_jugador() << endl;
     cout << "Color: " << jugador1.get_color_jugador() << endl;

     cout << "Nombre:" << jugador2.get_nombre_jugador() << endl;
     cout << "Color: " << jugador2.get_color_jugador() << endl;

     cout << "Nombre terreno 1:"  << territorio1.get_nombre() << endl;
     cout << "Nombre terreno 2:"  << territorio2.get_nombre() << endl;

     print_title_test("Test: Datos");

     Dado dado_d6(6),dado_d8(8);
     
     for(int i=0;i<5;i++)
	  cout << "Lanza dado de 6:" << dado_d6.tirar_dado() << endl;

     for(int j=0;j<5;j++)
	  cout << "Lanza dado de 8:" << dado_d8.tirar_dado() << endl; 

     float conta1=0;
     int intentos=500000;
     for(int k=0;k<intentos;k++)
	  if( dado_d6.tirar_dado() > dado_d8.tirar_dado())
	       conta1++;     

     cout << "Numero de veces en que un dado D6 gana a otro dado D8 en " <<
	  intentos <<" lanzamientos: " << conta1 << endl;
 
     float pr=(float)conta1/(float)intentos;

     cout << "y su probabilidad limite es " << pr << "." << endl;

     print_title_test("Test: Batallas");
     
     int num_atacantes = 3;
     int num_defensores= 2;
  
     Batalla_basica batalla1(num_atacantes,num_defensores);
     batalla1.jugar_batalla();

}
