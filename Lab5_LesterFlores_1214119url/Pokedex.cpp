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
