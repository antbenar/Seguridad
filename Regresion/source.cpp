#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//Para representar un punto usamos x, y = f(x)
struct Data
{
	float x, y;
	Data(float x, float y): x(x), y(y){}
};

void calcularConstantes(vector<Data*>& datos, float& a, float& b){
	size_t n = datos.size();
	float promedioX = 0, promedioLnY = 0;
	float sumatoriaX = 0, sumatoriaY = 0, sumatoriaX_2 = 0, sumatoriaLnY = 0, sumatoriaX_lny = 0;
	
	//-------------------------------sumatorias
	for (int i = 0; i < n; i++)
	{
		sumatoriaX += datos[i]->x;
		sumatoriaY += datos[i]->y;
		sumatoriaX_2 += pow(datos[i]->x,2);
		sumatoriaLnY += log (datos[i]->y);
		sumatoriaX_lny += datos[i]->x * log (datos[i]->y);
	}
	
	//------------------------------promedioX
	promedioX = sumatoriaX / n;
	
	//-------------------------------promedioLnY
	promedioLnY = sumatoriaLnY / n;
	
	b = (sumatoriaX_lny - (promedioLnY * sumatoriaX)) / (sumatoriaX_2 - (promedioX * sumatoriaX));
	a = exp(promedioLnY - (b * promedioX));
}

float predecir(float xi, float a, float b){
	return a * exp(b * xi);
}

// Los puntos
// xi es el punto a ser predicho
/*
double interpolacionLagrange(vector<Data*> datos, float xi)
{
	float result = 0;
	size_t n = datos.size();
	
	for (int i = 0; i < n; i++)
	{
		// Computar los terminios individualmente para la interpolacion de Lagrange
		float term = datos[i]->y;
		
		for (int j = 0; j<  n; j++)
		{
			if (j != i)
				term = term*(xi - datos[j]->x)/float(datos[i]->x - datos[j]->x);
		}
		
		result += term;
	}
	
	return result;
}
*/


int main()
{
	vector<Data*> datos;
	float x, y, n, numPeriodos;
	float a, b;
	cout << "Ingrese la cantidad de puntos a procesar: "; cin >> n;
	
	cout << "Ingrese y en base al periodo x proporcionado: " << endl;
	
	for (int i = 1; i <= n; ++i){
		cout << i << "\t->\t"; cin  >> y;
		datos.push_back(new Data(i,y));
	}
	
	cout << "Ingrese la cantidad de periodos a calcular: "; cin >> numPeriodos;

	
	cout << endl << endl << "-----Periodos ingresados: (" << n << "): " << endl;
	
	for (int i = 0; i < n; ++i){
		cout << "[" << i+1 << "]" << "\t->\t" << datos[i]->y << endl;
	}
	/*
	cout << "-----Periodos predichos(" << numPeriodos << "): " << endl;
	
	for (int i = n+1; i <= numPeriodos + n; ++i){
		cout << "[" << i << "]"  << "\t->\t" << interpolacionLagrange(datos, i) << endl;
	}
	*/
	
	//--------------------------------calcular constantes
	calcularConstantes(datos, a, b);
	
	//--------------------------------predecir
	
	cout << "-----Periodos predichos(" << numPeriodos << "): " << endl;
	
	for (int i = n+1; i <= numPeriodos + n; ++i){
		cout << "[" << i << "]"  << "\t->\t" << predecir(i,a,b) << endl;
	}
	
	system("pause");
	return 0;
}
