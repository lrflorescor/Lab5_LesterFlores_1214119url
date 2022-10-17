#pragma once
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

class Pokedex
{
	struct Node {

		int nGeneracion;
		int nNational;
		string nombre;
		Node* next;
	};

private:
	Node* header = nullptr;

public:

	void AgregarLista(int gNumber, int nNumber, string pNombre);

	void SacarLista(int& gNumber, int& nNumber, string& pNombre);

	void QuickSort();

	void SelectionGen();

	void ShellNational();

	void LeerArchivo();

	int Count();

	int fStringtInt(char c);

};

