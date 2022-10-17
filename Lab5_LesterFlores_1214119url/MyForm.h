#pragma once
#include "Pokedex.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <list>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <iostream>


Pokedex miPokedex;

namespace Lab5LesterFlores1214119url {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::RichTextBox^ mostrar_txt;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->mostrar_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(468, 203);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Generar Lista";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(468, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ordenar por nombre";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(468, 339);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(147, 31);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Ordenar por Nat";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(468, 250);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(147, 29);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Ordenar por Gen";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// mostrar_txt
			// 
			this->mostrar_txt->Location = System::Drawing::Point(69, 117);
			this->mostrar_txt->Name = L"mostrar_txt";
			this->mostrar_txt->Size = System::Drawing::Size(241, 160);
			this->mostrar_txt->TabIndex = 4;
			this->mostrar_txt->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(752, 428);
			this->Controls->Add(this->mostrar_txt);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		mostrar_txt->Clear();
		miPokedex.LeerArchivo();
		vector<int> NumGene;
		vector<int> NumNati;
		vector<string> Nombre;
		int n = miPokedex.Count();
		int nG, nN;
		string N;

		for (int i = 0; i < n; i++)
		{
			miPokedex.SacarLista(nG, nN, N);
			NumGene.push_back(nG);
			NumNati.push_back(nN);
			Nombre.push_back(N);
		}

		for (int i = 0; i < n; i++)
		{
			String^ aNumGen = gcnew String((NumGene[i]).ToString());
			String^ aNumNat = gcnew String((NumNati[i]).ToString());
			String^ Name = gcnew String(Nombre[i].c_str());
			mostrar_txt->Text = mostrar_txt->Text + aNumGen + " - " + aNumNat + " - " + Name + "\n";
		}

		for (int i = 0; i < n; i++)
		{
			miPokedex.AgregarLista(NumGene[i], NumNati[i], Nombre[i]);
		}

		button1->Visible = false;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		mostrar_txt->Clear();
		miPokedex.QuickSort();

		int n = miPokedex.Count();
		vector <string> nombre;
		vector <int> nGen;
		vector <int> nNat;


		int numGen = 0, numNat = 0;
		string Name = "";

		for (int i = 0; i < n; i++)
		{
			miPokedex.SacarLista(numGen, numNat, Name);
			nGen.push_back(numGen);
			nNat.push_back(numNat),
				nombre.push_back(Name);
		}

		for (int i = 0; i < n; i++)
		{
			String^ aNumGen = gcnew String((nGen[i]).ToString());
			String^ aNumNat = gcnew String((nNat[i]).ToString());
			String^ Name = gcnew String(nombre[i].c_str());
			mostrar_txt->Text = aNumGen + " - " + aNumNat + " - " + Name + "\n" + mostrar_txt->Text;
		}

		for (int i = 0; i < n; i++)
		{
			miPokedex.AgregarLista(nGen[i], nNat[i], nombre[i]);
		}

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		mostrar_txt->Clear();
		miPokedex.ShellNational();


		int n = miPokedex.Count();
		vector <string> nombre;
		vector <int> nGen;
		vector <int> nNat;


		int numGen = 0, numNat = 0;
		string Name = "";

		for (int i = 0; i < n; i++)
		{
			miPokedex.SacarLista(numGen, numNat, Name);
			nGen.push_back(numGen);
			nNat.push_back(numNat),
				nombre.push_back(Name);
		}

		for (int i = 0; i < n; i++)
		{
			String^ aNumGen = gcnew String((nGen[i]).ToString());
			String^ aNumNat = gcnew String((nNat[i]).ToString());
			String^ Name = gcnew String(nombre[i].c_str());
			mostrar_txt->Text = aNumGen + " - " + aNumNat + " - " + Name + "\n" + mostrar_txt->Text;
		}

		for (int i = 0; i < n; i++)
		{
			miPokedex.AgregarLista(nGen[i], nNat[i], nombre[i]);
		}

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	mostrar_txt->Clear();
	miPokedex.SelectionGen();


	int n = miPokedex.Count();
	vector <string> nombre;
	vector <int> nGen;
	vector <int> nNat;


	int numGen = 0, numNat = 0;
	string Name = "";

	for (int i = 0; i < n; i++)
	{
		miPokedex.SacarLista(numGen, numNat, Name);
		nGen.push_back(numGen);
		nNat.push_back(numNat),
			nombre.push_back(Name);
	}

	for (int i = 0; i < n; i++)
	{
		String^ aNumGen = gcnew String((nGen[i]).ToString());
		String^ aNumNat = gcnew String((nNat[i]).ToString());
		String^ Name = gcnew String(nombre[i].c_str());
		mostrar_txt->Text = aNumGen + " - " + aNumNat + " - " + Name + "\n" + mostrar_txt->Text;
	}

	for (int i = 0; i < n; i++)
	{
		miPokedex.AgregarLista(nGen[i], nNat[i], nombre[i]);
	}

}
};
}
