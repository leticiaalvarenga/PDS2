#include "Encontro.h"

Encontro::Encontro(std::string data, Endereco endereco, Usuario requisitado, Usuario requisitante, bool deu_certo, bool confirmado, int id_usuario_encontro)
{   //ctor
    _data = data;
    _endereco = endereco;
    _requisitado = requisitado;
    _requisitante = requisitante;
    _deu_certo = deu_certo;
    _confirmado = confirmado;
    _id_usuario_encontro = id_usuario_encontro;
}

Encontro::~Encontro()
{
    //dtor
}

std::string Encontro::get_data(){
    return this->_data;
}
Endereco Encontro::get_endereco(){
    return this->_endereco;
}
Usuario Encontro::get_requisitante(){
    return this->_requisitante;
}
Usuario Encontro::get_requisitado(){
    return this->_requisitado;
}
bool Encontro::get_deu_certo(){
    return this->_deu_certo;
}
bool Encontro::get_confirmado(){


    return this->_confirmado;
}
