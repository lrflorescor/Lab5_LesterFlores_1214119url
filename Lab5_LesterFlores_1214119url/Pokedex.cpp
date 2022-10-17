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

void Pokedex::SelectionGen()
{
	int n = Count();
	vector<int> gNumber;
	vector<int> nNumber;
	vector<string> Name;

	int cGen, cNat;
	string cNom;

	for (int i = 0; i < n; i++)
	{
		SacarLista(cGen, cNat, cNom);
		gNumber.push_back(cGen);
		nNumber.push_back(cNat);
		Name.push_back(cNom);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (gNumber[min] > gNumber[i])
			{
				min = j;
			}
		}

		int aux = gNumber[i];
		gNumber[i] = gNumber[min];
		gNumber[min] = aux;

		int auxi = nNumber[i];
		nNumber[i] = nNumber[min];
		nNumber[min] = auxi;

		string temp = Name[i];
		Name[i] = Name[min];
		Name[min] = temp;

	}

	for (int i = 0; i < n; i++)
	{
		AgregarLista(gNumber[i], nNumber[i], Name[i]);
	}

}

void Pokedex::ShellNational()
{
	int n = Count();
	vector<int> gNumber;
	vector<int> nNumber;
	vector<string> Name;

	int cGen, cNat;
	string cNom;

	for (int i = 0; i < n; i++)
	{
		SacarLista(cGen, cNat, cNom);
		gNumber.push_back(cGen);
		nNumber.push_back(cNat);
		Name.push_back(cNom);
	}

	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int Temp = nNumber[i];
			int Tempo = gNumber[i];
			string aux = Name[i];
			int j;
			for (j = i; j >= gap && nNumber[j - gap] > Temp; j -= gap)
			{
				nNumber[j] = nNumber[j - gap];
				gNumber[j] = gNumber[j - gap];
				Name[j] = Name[j - gap];
			}
			nNumber[j] = Temp;
			gNumber[j] = Tempo;
			Name[j] = aux;
		}
	}

	for (int i = 0; i < n; i++)
	{
		AgregarLista(gNumber[i], nNumber[i], Name[i]);
	}
}

void Pokedex::LeerArchivo()
{
	string nombre = "lista.txt";
	ifstream archivo;
	archivo.open(nombre, ios_base::in);

	vector<int> NumGene;
	vector<int> NumNati;
	vector<string> Nombre;

	string linea;
	char delimitador = ',';
	int cont = 0, i = 0, n = 0;

	while (archivo.good())
	{
		while (getline(archivo, linea, delimitador))
		{

			if (cont == 0)
			{
				NumGene.push_back(atoi(linea.c_str()));
				cont++;
			}
			else if (cont == 1)
			{
				NumNati.push_back(atoi(linea.c_str()));
				cont++;
			}
			else if (cont == 2)
			{
				Nombre.push_back(linea);
				cont = 0;
				i++;
				n++;
			}

		}
	}
	archivo.close();

	for (int i = 0; i < n; i++)
	{
		AgregarLista(NumGene[i], NumNati[i], Nombre[i]);
	}

}

int Pokedex::Count()
{
	Node* actual = header;
	int n = 0;

	if (header != nullptr) {
		while (actual != nullptr)
		{
			n++;
			actual = actual->next;
		}
	}
	else {
		return n;
	}
	return n;

}

int Pokedex::fStringtInt(char c)
{
	switch (c)
	{
	case 'A':
		return 1;
		break;
	case 'a':
		return 1;
		break;

	case 'B':
		return 2;
		break;
	case 'b':
		return 2;
		break;

	case 'C':
		return 3;
		break;
	case 'c':
		return 3;
		break;

	case 'D':
		return 4;
		break;
	case 'd':
		return 4;
		break;

	case 'E':
		return 5;
		break;
	case 'e':
		return 5;
		break;

	case 'F':
		return 6;
		break;
	case 'f':
		return 6;
		break;

	case 'G':
		return 7;
		break;
	case 'g':
		return 7;
		break;

	case 'H':
		return 8;
		break;
	case 'h':
		return 8;
		break;

	case 'I':
		return 9;
		break;
	case 'i':
		return 9;
		break;

	case 'J':
		return 10;
		break;
	case 'j':
		return 10;
		break;

	case 'K':
		return 11;
		break;
	case 'k':
		return 11;
		break;

	case 'L':
		return 12;
		break;
	case 'l':
		return 12;
		break;

	case 'M':
		return 13;
		break;
	case 'm':
		return 13;
		break;

	case 'N':
		return 14;
		break;
	case 'n':
		return 14;
		break;

	case 'Ñ':
		return 15;
		break;
	case 'ñ':
		return 15;
		break;

	case 'O':
		return 16;
		break;
	case 'o':
		return 16;
		break;

	case 'P':
		return 17;
		break;
	case 'p':
		return 17;
		break;

	case 'Q':
		return 18;
		break;
	case 'q':
		return 18;
		break;

	case 'R':
		return 19;
		break;
	case 'r':
		return 19;
		break;

	case 'S':
		return 20;
		break;
	case 's':
		return 20;
		break;

	case 'T':
		return 21;
		break;
	case 't':
		return 21;
		break;

	case 'U':
		return 22;
		break;
	case 'u':
		return 22;
		break;

	case 'V':
		return 23;
		break;
	case 'v':
		return 23;
		break;

	case 'W':
		return 24;
		break;
	case 'w':
		return 24;
		break;

	case 'X':
		return 25;
		break;
	case 'x':
		return 25;
		break;

	case 'Y':
		return 26;
		break;
	case 'y':
		return 26;
		break;

	case 'Z':
		return 27;
		break;
	case 'z':
		return 27;
		break;

	default:
		char* po = &c;
		return atoi(po);
		break;
	}
}