#include "Pokedex.h"

#include <vector>

void Pokedex::AgregarLista(int gNumber, int nNumber, string nombre)
{
	Node* nuevo = new Node();
	nuevo->nGeneracion = gNumber;
	nuevo->nNational = nNumber;
	nuevo->nombre = nombre;
	nuevo->next = header;
	header = nuevo;
}

void Pokedex::SacarLista(int& gNumber, int& nNumber, string& pNombre)
{
	Node* actual = new Node();
	actual = header;
	gNumber = actual->nGeneracion;
	nNumber = actual->nNational;
	pNombre = actual->nombre;
	header = actual->next;
	delete actual;
}

void Pokedex::QuickSort()
{
	int n = 0;
	n = Count();
	vector<string> aNombre;
	vector<int> aNumGen;
	vector<int> aNumNat;
	vector<int> Retorno;
	string dNombre;
	int dNumGen, dNumNat;

	for (int i = 0; i < n; i++)
	{
		SacarLista(dNumGen, dNumNat, dNombre);
		aNombre.push_back(dNombre);
		aNumGen.push_back(dNumGen),
			aNumNat.push_back(dNumNat);
		Retorno.push_back(aNombre[i][0]);
	}




	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (Retorno[j] > Retorno[j + 1])
			{
				int temp = Retorno[j];
				Retorno[j] = Retorno[j + 1];
				Retorno[j + 1] = temp;

				string aux = aNombre[j];
				aNombre[j] = aNombre[j + 1];
				aNombre[j + 1] = aux;

				int aux2 = aNumGen[j];
				aNumGen[j] = aNumGen[j + 1];
				aNumGen[j + 1] = aux2;

				int aux3 = aNumNat[j];
				aNumNat[j] = aNumNat[j + 1];
				aNumNat[j + 1] = aux3;

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		AgregarLista(aNumGen[i], aNumNat[i], aNombre[i]);
	}
}
