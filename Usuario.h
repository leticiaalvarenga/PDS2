#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario
{
private:

	std::string _nome;

	static unsigned int _novo_id;

	unsigned int _id;
	
	std::string _lixo;

	bool _is_doador;

	//Endereco do usuario (Tipo Lugar)
	Lugar _endereco;

public:

	Usuario(tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral);
	std::string get_lixo();
	bool get_if_doador();
	unsigned int get_id();
	std::string get_nome();
	void Atualiza_infos(std::map<std::string, std::vector<std::vector<int> > > mapa);
	void Atualiza_lixo(std::map<std::string, std::vector<std::vector<int> > > mapa);
	void Busca(std::map<std::string, std::vector<std::vector<int> > > mapa_geral, std::map<int, Usuario> mapa_usuario);
	void mensagem_de_armazenamento();

}

#endif // USUARIO_H
