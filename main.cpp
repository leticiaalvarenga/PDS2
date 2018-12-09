#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Usuario.h"


typedef std::map< std::string, std::vector< std::vector<int>, std::vector<int>>> tipo_mapa_geral;
typedef std::map<int, Usuario> tipo_mapa_usuario;
typedef std::map<int, Encontro> tipo_mapa_encontros;

//Recebe uma string e retorna a mesma em upper case
string to_upper_case(string s);

//Retorna true se a string lixo estiver no mapa geral e false no caso contrário
bool verifica_no_mapa_geral_se_existe_o_lixo(tipo_mapa_geral mapa, string lixo);

int main(){

    tipo_mapa_usuario mapa_usuario;
    tipo_mapa_geral mapa_geral;
    tipo_mapa_encontros mapa_encontros;
	
     Endereco endereco;
    endereco.Endereco();

    Usuario u;
    u._nome = "Leticia";
    u._is_doador = true;
    u._lixo = "Plastico";
    u._endereco = endereco;

    Usuario requisitante;
    requisitante._nome = "Jacare";
    requisitante._is_doador = false;
    requisitante._lixo = "Plastico";
    requisitante._endereco = endereco;

    Encontro encontro = new Encontro("08-12-2018", endereco, u, requisitante, false, false, 0);


    return 0;
}

string to_upper_case(string s){

    aux = s;

	std::for_each(aux.begin(), aux.end(), [](char & c) {
		c = ::toupper(c);
	});

	return aux;
}

bool verifica_no_mapa_geral_se_existe_o_lixo(tipo_mapa_geral mapa, string lixo){
    return true;
}
