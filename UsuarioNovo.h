#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include "Erro.h"

class Usuario
{
private:
    static unsigned int _novo_id;

	std::string _nome;
	unsigned int _id;
	bool _is_doador;
	//Endereco do usuario (Tipo Lugar)
	//Lugar _endereco;

public:
    static unsigned int get_new_id();

	Usuario(/*tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral*/);
	//Void Atualiza();
	//Usuario* Busca();
	void mensagem_de_armazenamento();
};

std::string to_upper_case(std::string s);

#endif // USUARIO_H_INCLUDED
