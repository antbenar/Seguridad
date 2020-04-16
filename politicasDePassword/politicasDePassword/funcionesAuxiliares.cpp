#include <iostream>
#include <cstdlib>
#include <string>
#include "funcionesAuxiliares.h"

using namespace std;

bool validarPassword(string password, string usuario, string& estado) {
	if (password.size() < 8) {
		estado = "Password menor a 8 caracteres";
		return false;
	}

	if (!verificarMayusculas(password)) {//ASCII 65 - 90
		estado = "El password debe contener una Mayuscula por lo menos";
		return false;
	}

	if (!verificarMinusculas(password)) {//ASCII 65 - 90
		estado = "El password debe contener una Minuscula por lo menos";
		return false;
	}

	if (!verificarMinusculas(password)) {
		estado = "El password debe contener una Minuscula por lo menos";
		return false;
	}

	if (!verificarCaracterNoAlfanumerico(password)) {
		estado = "El password debe contener un caracter no alfanumerico por lo menos";
		return false;
	}

	if (verificarCaracteresConsecutivos(password)) {
		estado = "El password no debe repetir caracteres  tres veces consecutivas";
		return false;
	}

	if (!verificarUsuarioEnPassword(password, usuario)) {
		estado = "El password no debe contener el nombre de usuario";
		return false;
	}

	if (!verificarNumero(password)) {
		estado = "El password debe contener al menos un numero";
		return false;
	}

	if (!verificarSecuenciasBasicas(password)) {
		estado = "El password no debe contener secuencias basicas (por ejemplo: qwerty, asdf, 1234 o 98765)";
		return false;
	}

	estado = "Password valido";
	return true;
}

bool validarUsuario(string usuario, string password, string usuarioDB, string passwordDB, string& estado) {
	if (usuario == usuarioDB && password == passwordDB) {
		// se logueó correctamente
		estado = "Se logueo correctamente";
		return true;
	}

	//no existe ese usuario o contraseña
	estado = "El usuario y/o contrasenia es incorrecto";
	return false;
}

void imprimirIngreso() {
	system("Cls");
	cout << endl << endl;
	cout << "------------------------- SISTEMA DE SEGURIDAD ------------------------" << endl;
	cout << "_______________________________________________________________________" << endl;
	cout << "_______________________________________________________________________" << endl << endl;
	cout << "________________¡INGRESASTE CORRECTAMENTE AL SISTEMA!__________________" << endl;
	cout << "_______________________________________________________________________" << endl;
}

bool validarUsuario(string usuario, string usuarioDB) {
	if (usuario == usuarioDB) return true;
	return false;
}

string verificarHora(string hora) {
	if (atoi(hora.c_str()) >= 8 && atoi(hora.c_str()) <= 10) {
		return "Estas en horario de poder escribir tu password";
	}
	else {
		return "No estas en horario de poder escribir tu password";
	}
}


bool verificarMayusculas(string password) {
	size_t passSize = password.size();

	for (unsigned int i = 0; i < passSize; ++i) {
		if ((int)password[i] - 65 <= 25 && (int)password[i] - 65 >= 0) {
			//cout << "-Primera Mayuscula: " << password[i] << endl;
			return true;
		}
	}

	return false;
}

bool verificarMinusculas(string password) {
	size_t passSize = password.size();

	for (unsigned int i = 0; i < passSize; ++i) {
		if ((int)password[i] - 97 <= 25 && (int)password[i] - 97 >= 0) {
			//cout << "-Primera Minuscula: " << password[i] << endl;
			return true;
		}
	}

	return false;
}

bool verificarCaracterNoAlfanumerico(string password) {
	size_t passSize = password.size();

	for (unsigned int i = 0; i < passSize; ++i) {
		if (!((int)password[i] - 48 < 10 && (int)password[i] - 48 >= 0) && ((int)password[i] > 0 && (int)password[i] < 65) || ((int)password[i] > 90 && (int)password[i] < 97) || (int)password[i] > 126) {
			return true;
		}
	}

	return false;
}

bool verificarCaracteresConsecutivos(string password) {
	size_t passSize = password.size();
	char temp;
	unsigned int consecutivos;

	for (unsigned int i = 0; i < passSize; ++i) {
		temp = password[i];
		consecutivos = 1;

		for (unsigned int j = i + 1; j < i + 3 && j < passSize; ++j) {
			if (password[j] == temp) {
				++consecutivos;
			}
		}

		if (consecutivos == 3) {
			return true;
		}

	}

	return false;
}

bool verificarUsuarioEnPassword(string password, string usuario) {
	size_t puntoPos = usuario.find('.');
	string nombre = usuario.substr(0, puntoPos);
	string apellido = usuario.substr(puntoPos+1);

	//cout << nombre << "-" << apellido << endl;

	size_t nombreInPassword = password.find(nombre);
	size_t apellidoInPassword = password.find(apellido);

	//cout << apellidoInPassword << "-" << string::npos << endl;

	if (nombreInPassword != std::string::npos || apellidoInPassword != std::string::npos) {
		return false;
	}

	return true;
}

bool verificarNumero(string password) {
	size_t passSize = password.size();

	for (unsigned int i = 0; i < passSize; ++i) {
		if ((int)password[i] - 48 < 10 && (int)password[i] - 48 >= 0) {
			return true;
		}
	}

	return false;
}

bool verificarSecuenciasBasicas(string password) {
	const string secuenciasBasicas[9] = { "123", "1234", "12345", "qwerty", "qwer", "asdf", "asdfg", "98765", "9876"};

	for (unsigned int i = 0; i < 9; ++i) {
		if ( password.find(secuenciasBasicas[i]) != string::npos ) {
			cout << endl << secuenciasBasicas[i] << endl;
			return false;
		}
	}

	return true;
}