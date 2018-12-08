#include "Encontro.h"
#include "Usuario.h"
#include "Endereco.h"
#include <string>
#include <iostream>
#include <map>




Encontro::Encontro(std::string data, Endereco endereco, Usuario requisitado, Usuario requisitante, std::bool deu_certo, _confirmado, int id_usuario_encontro)
{   //ctor
    _data = data;
    _endereco = endereco;
    _requisitado = requisitado._nome;
    _requisitante = requisitante._nome;
    _deu_certo = deu_certo;
    _confirmado = confirmado;
    _id_usuario_encontro = id_usuario_encontro;
}

Encontro Encontro::Busca_Encontro(int id_usuario, tipo_mapa_encontros mapa_encontro){
    //Essa busca de encontros, passa o id do usuário que está querendo fazer a busca,
    //(necessário para conseguir procurar o usuário e procura a lista de vetores de
    //inteiros que tem todos os encontros daquela pessoa e compara os
    //inteiros com os ids do mapa e retorna: nome do lixo, endereço e data.

    Usuario usuario;
    Usuario usuario_que_procura = usuario.Busca(id_usuario); //Essa busca poderá ser feita com o id

    for (std::vector<int>::iterator it = usuario_que_procura._encontros.begin(); it != usuario_que_procura._encontros.end(); ++it){
        map::const_iterator pos = mapa_encontro.find(*it);
        if(pos != mapa_encontro.end()){
            Encontro value = pos->second; //Pega o valor encontro
            value._requisitado.
        }
    }
    //ctor
}

Encontro::~Encontro()
{
}
    //dtor
}


std::string Encontro::get_data(){
    return this->_data;
}
Endereco Encontro::get_endereco(){
    return this->_endereco;
}
Usuario Encontro::get_usuario(){
    return this->_usuario;
}
std::bool Encontro::get_deu_certo(){
    return this->_deu_certo;
}
std::bool Encontro::get_confirmado(){
    return this->_confirmado;
}
