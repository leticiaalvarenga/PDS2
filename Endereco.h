#ifndef ENDERECO_H_INCLUDED
#define ENDERECO_H_INCLUDED

#include "Erro.h"
#include <iostream>
#include <string>

class Endereco
{
private:
    std::string _cidade;
    std::string _nome;
    std::string _rua;
    int _numero;
public:
    Endereco(std::string cidade,std::string nome,std::string rua,int numero);
    std::string get_cidade();
    std::string get_nome();
    std::string get_rua();
    int get_numero();
};

#endif // ENDERECO_H_INCLUDED
