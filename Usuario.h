#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario{
private:

	std::string _nome;

	static unsigned int _novo_id;

	unsigned int _id;

	bool _is_doador;

	//Endereco do usuario (Tipo Lugar)
	Lugar _endereco;

public:

	Usuario(tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral);

	Void Atualiza();
	Usuario* Busca();
	void mensagem_de_armazenamento();

}

#endif // USUARIO_H
