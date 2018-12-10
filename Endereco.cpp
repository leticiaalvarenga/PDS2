#include "Endereco.h"
#include <iostream>
#include <string>

Endereco::Endereco(std::string cidade,std::string nome,std::string rua,int numero)
{
    _cidade= cidade;
    _nome= nome;
    _rua= rua;
    _numero= numero;
}

std::string Endereco::get_cidade()
{
    return _cidade;
}

std::string Endereco::get_nome()
{
    return _nome;
}

std::string Endereco::get_rua()
{
    return _rua;
}

int Endereco::get_numero()
{
    return _numero;
}
