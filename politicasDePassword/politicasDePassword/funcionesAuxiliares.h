#include <iostream>
using namespace std;

bool validarPassword(string password, string usuario, string& estado);
bool validarUsuario(string usuario, string password, string usuarioDB, string passwordDB, string& estado);
void imprimirIngreso();
bool validarUsuario(string usuario, string usuarioDB);
string verificarHora(string hora);

//---funciones usadas en la validación del password
bool verificarMayusculas(string password);
bool verificarMinusculas(string password);
bool verificarCaracterNoAlfanumerico(string password);
bool verificarCaracteresConsecutivos(string password);
bool verificarUsuarioEnPassword(string password, string usuario);
bool verificarNumero(string password);
bool verificarSecuenciasBasicas(string password);