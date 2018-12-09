#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <map>
#include <vector>
#include "Erro.h"

class Usuario
{
private:
    static unsigned int _novo_id;

	std::string _nome;
	std::string _lixo;
	unsigned int _id;
	bool _is_doador;
	//Endereco _endereco;

public:
    static unsigned int get_new_id();

	Usuario(tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral);
	void Atualiza_infos(std::map<std::string, std::vector<std::vector<int> > > mapa);
	void Atualiza_lixo(std::map<std::string, std::vector<std::vector<int> > > mapa);
	void Busca(std::map<std::string, std::vector<std::vector<int> > > mapa_geral, std::map<int, Usuario> mapa_usuario); //add
	void mensagem_de_armazenamento();
	std::string get_lixo(); //add
	bool get_if_doador(); //add
	unsigned int get_id(); //add
	std::string get_nome(); //add
};

typedef std::map<int, Usuario> tipo_mapa_usuario;
typedef std::map<std::string, std::vector< std::vector<int> > > tipo_mapa_geral;
std::string to_upper_case(std::string s);

#endif // USUARIO_H_INCLUDED
