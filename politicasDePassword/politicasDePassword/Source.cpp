#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "funcionesAuxiliares.h"


using namespace std;

const string usuarioA = "anthony.benavides";
const string passwordA = "Antb3n@r3626";



int main() {
	string estadoPassword = "Password no válido",
		estadoLogin = "El usuario y/o contrasenia es incorrecto",
		estadoIntentos = "",
		password = "sdfddfdZfhkbanthond@ff",
		usuario = "anthony.benavides";
	bool passwordValido, loginValido;
	auto t = time(nullptr);
	auto tm = *localtime(&t);
	ostringstream oss, currentTime;

	while (true) {
		system("Cls");
		oss.str(""); currentTime.str("");
		oss << put_time(&tm, "%d-%m-%Y %H-%M");
		currentTime << put_time(&tm, "%H");
		auto hora = oss.str();
		auto currentTimeStr = currentTime.str();

		cout << endl << endl;
		cout << "------------------------- SISTEMA DE SEGURIDAD ------------------------" << endl;
		cout << "_______________________________________________________________________" << endl;
		cout << "____________________________" << hora << "___________________________" << endl;
		cout << "\t\t" << verificarHora(currentTimeStr) << endl;
		cout << "_______________________________________________________________________" << endl;
		cout << estadoIntentos << endl;//aqui va el estado del login
		cout << "_______________________________________________________________________" << endl << endl;
		cout << "\tIngrese su usuario: ";
		cin  >> usuario; 
		cout << endl;

		if (validarUsuario(usuario, usuarioA)) {
			for (int intentos = 1; intentos <= 3; ++intentos) {
				estadoIntentos = "\t Intento " + to_string(intentos);
				oss.str(""); currentTime.str("");
				oss << put_time(&tm, "%d-%m-%Y %H-%M");
				currentTime << put_time(&tm, "%H");
				auto hora_ = oss.str();
				auto currentTimeStr_ = currentTime.str();

				system("Cls");
				cout << endl << endl;
				cout << "------------------------- SISTEMA DE SEGURIDAD ------------------------" << endl;
				cout << "_______________________________________________________________________" << endl;
				cout << "____________________________" << hora_ << "___________________________" << endl;
				cout << "\t\t" << verificarHora(currentTimeStr_) << endl;
				cout << "_______________________________________________________________________" << endl;
				
				cout << estadoIntentos << endl;//aqui va el estado del login
				cout << "_______________________________________________________________________" << endl << endl;
				cout << "\tIngrese su usuario: " << usuario << endl;


				cout << "\tIngrese su password: ";
				cin  >> password; 
				cout << endl << endl;

				passwordValido = validarPassword(password, usuario, estadoPassword);

				if (passwordValido) {
					//verificar si el password y el usuario son los correctos
					//usuarioA y PasswordA son los datos para iniciar sesión
					loginValido = validarUsuario(usuario, password, usuarioA, passwordA, estadoLogin);

					if (loginValido) {
						//se logueó correctamente
						//aqui se deberia mostrar el programa de la empresa despues de haber iniciado sesión
						imprimirIngreso();
						system("pause");
						return 1;
					}
				}

				cout << "_______________________________________________________________________" << endl;
				cout << "\tEstado Password: " << estadoPassword << endl;
				cout << "\tEstado Login: " << estadoLogin << endl;
				cout << "_______________________________________________________________________" << endl;


				system("Pause");
			}	

			estadoIntentos = "\tUsted coloco incorrectamente su password 3 veces, no puede continuar logueandose";
		}
		else {
			cout << "\tIngrese su password: ";
			cin  >> password; 
			cout << endl << endl;

			passwordValido = validarPassword(password, usuario, estadoPassword);

			if (passwordValido) {
				//verificar si el password y el usuario son los correctos
				//usuarioA y PasswordA son los datos para iniciar sesión
				loginValido = validarUsuario(usuario, password, usuarioA, passwordA, estadoLogin);
			}

			cout << "_______________________________________________________________________" << endl;
			cout << "\tEstado Password: " << estadoPassword << endl;
			cout << "\tEstado Login: " << estadoLogin << endl;
			cout << "_______________________________________________________________________" << endl;
			system("Pause");
		}		
	}

	return 0;
}


/*

1.	--El usuario será su nombre y su apellido y el password deberá de tener por lo menos 8 caracteres, Cualquier otro usuario no permitirá el acceso.
2.	--El password no debe contener el nombre de usuario.
3.	--El password debe contener al menos una mayúscula.
4.	--El password debe contener al menos una minúscula.
5.	--El password debe contener al menos un carácter no alfanumérico.
6.	--El password no debe repetir ningún carácter  tres veces consecutivos.
7.	--Si el usuario es correcto y el password falla más de 3 veces en 60 segundos debe indicar que posteriormente se bloqueara al usuario (solo indicar que se bloqueará, para poder hacer las pruebas)
8.	--El password solo se puede digitar de 8 am a 10 am. Tomará de referencia la hora del ordenador donde corre el programa.

*/