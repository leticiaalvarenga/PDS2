#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

#include "Encontro.h"

using namespace std;

class Usuario{
private:

	string _nome;

	string _quantidade;

	static unsigned int _novo_id;

	unsigned int _id;

	bool _is_doador;

	vector<int> _lista_de_encontros;

	//Endereco do usuario (Tipo Lugar)
    //Lugar _endereco;

public:

    Usuario();
	Usuario(map< int, Usuario > & mapa_usuario, map< string, vector<int>* > & mapa_doador, map<string, vector<int>* > & mapa_coletor);

	string get_nome();
	string get_quantidade();
	int get_id();

	void adiciona_encontro(int _id_encontro);
	void cancela_encontro(int _id_encontro);

    void Atualiza();
    void Visualiza_encontros(map<int, Encontro> & mapa_encontro, map<int, Usuario> & mapa_usuario);
    void Busca(map<int, Usuario> & mapa_usuario, map<int, Encontro> & mapa_encontro, map<string, vector<int>* > mapa_doador, map<string, vector<int>* > mapa_coletor);

};

#endif // USUARIO_H
