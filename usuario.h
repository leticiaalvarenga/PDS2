#pragma once
#include <iostream>
#include <string>	

class Usuario
{
private:
	std::string _nome;
	//Tipo de Lixo que o usuáro possui (Tipo Lixo)
	Lixo _residuo;
	//Endereco do usuario (Tipo Lugar)
	Lugar _endereco;
public:
	Usuario(std::string nome, Lixo residuo, Lugar endereco);
	Void Atualiza_lixo(Lixo lixo);
	Void Atualiza_endereco(Lugar endereco);
	Void Atualiza_nome(std::string nome);
	
	Usuario* Busca(Lixo lixo);
}
