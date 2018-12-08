#include "Encontro.h"
#include "Usuario.h"
#include "Endereco.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>




Encontro::Encontro(std::string data, Endereco endereco, Usuario requisitado, Usuario requisitante, bool deu_certo, bool confirmado, int id_usuario_encontro)
{   //ctor
    _data = data;
    _endereco = endereco;
    _requisitado = requisitado._nome;
    _requisitante = requisitante._nome;
    _deu_certo = deu_certo;
    _confirmado = confirmado;
    _id_usuario_encontro = id_usuario_encontro;
}

void Encontro::Busca_Encontro(int id_usuario, tipo_mapa_encontros mapa_encontro){
    //Essa busca de encontros, passa o id do usuário que está querendo fazer a busca,
    //(necessário para conseguir procurar o usuário e procura a lista de vetores de
    //inteiros que tem todos os encontros daquela pessoa e compara os
    //inteiros com os ids do mapa e retorna: nome do lixo, endereço e data.

    Usuario usuario;
    Usuario usuario_que_procura = usuario.Busca(id_usuario); //Essa busca poderá ser feita com o id
    std::string aux_encontro;
    std::string aux_cancelar;
    std::string aux_confirmar;

    //for para imprimir a lista de encontros
    int indice = 0;
    for (std::vector<int>::iterator it = usuario_que_procura._encontros.begin(); it != usuario_que_procura._encontros.end(); ++it){
        map::const_iterator pos = mapa_encontro.find(*it);
        if(pos != mapa_encontro.end()){
            Encontro valor = pos->second; //Pega o valor encontro
            std::cout << indice << " - ";
            std::cout << "Nome do lixo: " << valor._requisitante._lixo <<
                         ". Data do encontro: " << valor.get_data() <<
                         ". Endereco do encontro " << valor.get_endereco() << std::endl;

            std::cout << "Deseja escolher este encontro? sim [s], nao [n]" << std::endl;
            std::cin >> aux_encontro;
            //Colocar aqui um try catch -> se não for nem s e nem n..
            if(aux_encontro == "s"){
                if((usuario_que_procura._id == valor._requisitante._id) && (valor.get_confirmado() == true)){ //usuário que procura é o requisitante
                    if(valor.get_deu_certo() == true){
                        ~valor();
                    }
                    else{
                        std::cout << "Cancelar encontro? [s]/ [n]" << std::endl;
                        std::cin >> aux_cancelar;

                        if(aux_cancelar == "s"){
                            ~valor();
                        }
                        else{
                            aux_encontro = "n";
                            break;
                        }
                    }
                }



                if((usuario_que_procura._id != valor._requisitante._id) && (valor.get_confirmado() == false)){//usuário que procura não é o requisitante
                    std::cout << "Deseja confirmar o encontro? [s]/ [n] ";
                    std::cin >> aux_confirmar;

                    if(aux_confirmar == "s"){
                        valor._confirmado = true;
                    }
                    else{
                        ~valor();
                    }

                }
            }
            else{
                std::cout << "Próximo da lista.. " << std::endl;
                indice++;
            }

        }
    }



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
