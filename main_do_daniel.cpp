#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "usuario.h"

//Não esquecer de declarar o iterator dos mapas
// Caso percorrer o vector dentro do chave do mapa geral for muito complexo, 
// podemos dividir o mapa geral em mapa_de_coletores e mapa_de_doadores
typedef std::map< std::string, std::vector< std::vector<int>, std::vector<int> > > tipo_mapa_geral;
typedef std::map<int, Usuario> tipo_mapa_usuario;
//typedef std::map<int, Encontro> tipo_mapa_encontros;

//Recebe uma string e retorna a mesma em upper case
//std::string to_upper_case(string s);

//Retorna true se a string lixo estiver no mapa geral e false no caso contrário
// Daniel: Seria uma boa jogar isso pra dentro dos contrutores?
bool verifica_no_mapa_geral_se_existe_o_lixo(tipo_mapa_geral mapa, string s)
{
	if (mapa.empty == 1)
	{
		return false;
	}
		
	else if (mapa.find[s] == mapa.end)
		{
			return false;
		}
			
		else
		{
			return true;
		}
			
};

int main(){

    tipo_mapa_usuario mapa_usuario;
    tipo_mapa_geral mapa_geral;
    //tipo_mapa_encontros mapa_encontros;
	
	Usuario Cleber(mapa_usuario, mapa_geral);


    return 0;
}

/*string to_upper_case(string s)
{

    aux = s;

	std::for_each(aux.begin(), aux.end(), [](char & c) {
		c = ::toupper(c);
	});

	return aux;
}*/
