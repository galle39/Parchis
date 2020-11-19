#include <iostream>
#include <stdio.h>
#include <cmath>
#include<stdlib.h>
#include<time.h>
#include <string>

using namespace std;

// Damos nombre a las variables
typedef enum { amarillo, azul, rojo, verde } tcolor;

typedef struct {
	int casillainicio;
	int casilla;
	int contador6;
	tcolor color;
}control;


int dado() {

	cout << "\nPulsa enter para lanzar los dados" << endl;

	cin.ignore();//recuerda esto

	return  1 + rand() % (7 - 1);;// es una funcion que hace de dado

};

string ncolor(tcolor color) {

	if (color == rojo) 
		return "Rojo";
	 
	else if (color == amarillo) 
		return "Amarillo";
	
	else if (color == verde) 
		return "Verde";
	
	else return "Azul";

}//Devuelve la cadena del color

string letra(tcolor color) {

	if (color == rojo)
		return "R";

	else if (color == amarillo)
		return "M";

	else if (color == verde)
		return "V";

	else return "A";

}//Devuelve la letra del color

int casillasalida(tcolor color) {
	if (color == rojo)
		return 39;

	else if (color == amarillo)
		return 5;

	else if (color == verde)
		return 56;

	else return 22;

}//Devuelve la casilla de salida

tcolor eleccionjug(int o) {
	int eleccion = 0;

		while ((eleccion < 1) || (eleccion > 4)) {
			cout << "\n\nJugador "<< o <<" Elije color  ( 1=Rojo, 2=Verde, 3=Amarillo y 4=Azul ) " << endl;
			cout << "   " << endl;
			cin >> eleccion;
		}

		if (eleccion == 1) {
			
			return rojo;
		}

		else if (eleccion == 2) {
			
			return verde;
		}

		else if (eleccion == 3) {
			
			return amarillo;
		}

		else {
			
			return azul;
		}

}//Eliges color 


//te queda EL TABLERO {0, 5, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63} mira el comando for

void tablero() {
	for (int i = 0; i < 68; i++){
		int casillasegura[]{ 0, 5, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63 };
		bool segura;  //hay que hacer que el bool sea 0 si es una de las casillas seguras 
		if ((i == 0) || (i == 5) || (i == 12) || (i == 17) || (i == 22) || (i == 29) || (i == 34) || (i == 39) || (i == 46) || (i == 51) || (i == 56) || (i == 63)) {
			segura = 1;
		}
		else {
			segura = 0;
		}

		if (segura == 1) {
			cout << "o";
			}
		else {
			cout << "-";
		}
	}
}

void numerostablero() {
	for (size_t i = 0; i < 68; i++)
		cout << i / 10;
	cout << endl;
	for (size_t i = 0; i < 68; i++)
		cout << (i - ((i / 10) * 10));
	cout << endl;
}


void juego(int casilla1, int casilla2, int inicio1, int inicio2, tcolor color1, tcolor color2) {
	numerostablero();
	tablero();
	for (size_t i = 0; i < 68; i++) {
	
		if (i == casilla1) {

			cout << letra(color1);
		}
		else if (i == casilla2) {

			cout << letra(color2);
		}
		else {

			cout << " ";
		}
	}
}



int main() {
	
	int casillasegura[]{ 0, 5, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63 }, m = 1,ganador =0, dados, win1, win2;
	control uno, dos;
	 uno.color = eleccionjug(1),
	 dos.color = eleccionjug(2),
	 uno.casilla=-1,
	 dos.casilla=-1,
	 uno.casillainicio = casillasalida(uno.color),
	 dos.casillainicio = casillasalida(dos.color);
	 uno.contador6 = 0;
	 dos.contador6 = 0;
	 bool segura2;
	 bool gan1 = 0;
	 bool gan2 = 0;
	while (uno.color == dos.color) {
		cout << "\n\nPorfavor JUGADOR 2  elige un color diferente al del JUGADOR 1 ";
		dos.color = eleccionjug(2);
	}//para que no se repita color

	cout << "El JUGADOR 1 es el color " << ncolor(uno.color) << endl;
	cout << "El jUGADOR 2 es el color " << ncolor(dos.color) << endl;
	
	while (ganador == 0) {
		juego(uno.casilla,dos.casilla,uno.casillainicio,dos.casillainicio,uno.color,dos.color);

		if (m % 2 == 0) {
			dados = dado();
			cout << "El JUGADOR 1 ha sacado un:  " << dados << endl;
			if (uno.casilla == uno.casillainicio - 5) {
				ganador = 1;
				win1 = 1;
			}

			else if ((uno.casilla == -1) && (dados == 5)) {
				uno.casilla = uno.casillainicio;
			}//si sacas un 5 sales de casa

			else if (uno.casilla == -1) {
				continue;
			}//si no sacas 5 sigues en casa

			else if (dados == 6) {
				uno.contador6++;
				if (uno.contador6 == 3) {
					uno.casilla = uno.casillainicio;
					uno.contador6 = 0;
				}
				else {
					uno.casilla = uno.casilla + dados;
					m--;
				}

			}//si sacas 6 repites tirada si sacas 3 seis vuelves a casa

			else if (uno.casilla + dados >= 68) {
				uno.casilla = uno.casilla + dados;
				uno.casilla = uno.casilla - 68;
			}//si te sales del tablero vueves al principio

			else if (uno.casilla + dados == dos.casilla) {

				uno.casilla = uno.casilla + dados;

				for (int i = 0; i < 68; i++) {
					int casillasegura[]{ 0, 5, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63 };
					
					if ((i == 0) || (i == 5) || (i == 12) || (i == 17) || (i == 22) || (i == 29) || (i == 34) || (i == 39) || (i == 46) || (i == 51) || (i == 56) || (i == 63)) {
						segura2 = 1;
					}
					else {
						segura2 = 0;
					}
				}
				if ((uno.casilla == dos.casilla) && (segura2 == 0)) {

					uno.casilla = uno.casilla + 20;
					dos.casilla = dos.casillainicio;
				}
				if ((uno.casilla == dos.casilla) && (segura2 == 1)) {
					uno.casilla = dos.casilla;
				}
			}

			else {
				uno.casilla = uno.casilla + dados;
				uno.contador6 = 0;

			}
		}//JUEGO PARA EL JUGADOR UNO

		else {
			dados = dado();
			cout << "El JUGADOR 2 ha sacado un:  " << dados << endl;
			if (dos.casilla == dos.casillainicio - 5) {
				ganador = 1;
				win2 = 1;
			}

			else if ((dos.casilla == -1) && (dados == 5)) {
				dos.casilla = dos.casillainicio;
			}//si sacas un 5 sales de casa

			else if (dos.casilla == -1) {
				continue;
			}//si no sacas 5 sigues en casa

			else if (dados == 6) {
				dos.contador6++;
				if (dos.contador6 == 3) {
					dos.casilla = dos.casillainicio;
					dos.contador6 = 0;
				}
				else {
					dos.casilla = dos.casilla + dados;
					m--;
				}

			}//si sacas 6 repites tirada si sacas 3 seis vuelves a casa

			else if (dos.casilla + dados >= 68) {
				dos.casilla = dos.casilla + dados;
				dos.casilla = dos.casilla - 68;
			}//si te sales del tablero vueves al principio

			else if (dos.casilla + dados == uno.casilla) {

				dos.casilla = dos.casilla + dados;

				for (int i = 0; i < 68; i++) {
					int casillasegura[]{ 0, 5, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63 };

					if ((i == 0) || (i == 5) || (i == 12) || (i == 17) || (i == 22) || (i == 29) || (i == 34) || (i == 39) || (i == 46) || (i == 51) || (i == 56) || (i == 63)) {
						segura2 = 1;
					}
					else {
						segura2 = 0;
					}
				}
				if ((dos.casilla == uno.casilla) && (segura2 == 0)) {

					dos.casilla = dos.casilla + 20;
					uno.casilla = uno.casillainicio;
				}
				if ((dos.casilla == uno.casilla) && (segura2 == 1)) {
					dos.casilla = uno.casilla;
				}
			}

			else {
				dos.casilla = dos.casilla + dados;
				dos.contador6 = 0;

			}
		} //Este el juego del jugador 2




	}//si sales del while ganador = 1 hay un ganador

	if (gan1 == 1) {
		cout << "Jugador 1 has ganado, ¡¡Enhorabuena!! :)" << endl;
	}

	if (gan2== 1) {
		cout << "Jugador 2 has ganado, ¡¡Enhorabuena!! :)" << endl;
	}

	


	return 0;
}
	


 

