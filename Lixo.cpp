#include "lixo.h"

Lixo::Lixo(string nome, bool is_toxico, bool is_perecivel, bool is_cortante, bool is_solido, bool is_liquido, bool is_metal, bool is_plastico, bool is_organico){
    this->_nome = nome;
    this->_is_toxico = is_toxico;
    this->_is_perecivel = is_perecivel;
    this->_is_cortante = is_cortante;
    this->_is_solido = is_solido;
    this->_is_liquido = is_liquido;
    this->_is_metal = is_metal;
    this->_is_plastico = is_plastico;
    this->_is_organico = is_organico;
}

string Lixo::Atualizar_lixo(bool is_toxico, bool is_perecivel, bool is_cortante, bool is_solido, bool is_liquido, bool is_metal, bool is_plastico, bool is_organico){
    this->_is_toxico = is_toxico;
    this->_is_perecivel = is_perecivel;
    this->_is_cortante = is_cortante;
    this->_is_solido = is_solido;
    this->_is_liquido = is_liquido;
    this->_is_metal = is_metal;
    this->_is_plastico = is_plastico;
    this->_is_organico = is_organico;

    string sucesso = "Lixo atualizado com sucesso!";
    return sucesso;
}

//Lixo Lixo::Buscar_lixo(string nome){}




