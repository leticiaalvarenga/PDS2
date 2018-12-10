#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Encontro.h"
#include "Usuario.h"

using namespace std;

unsigned int Encontro::_novo_id_encontro = 1;

int Encontro::get_id_encontro(){
    return this->_id_encontro;
}

Encontro::Encontro(){}

Encontro::Encontro(map<int,Encontro> & mapa_encontro, int id_requisitante, int id_requisitado){

    _id_encontro = Encontro::_novo_id_encontro;
    Encontro::_novo_id_encontro++;

    this->mudar_endereco();
    this->mudar_data();

    this->id_requisitante = id_requisitante;
    this->id_requisitado = id_requisitado;

    confirmado = false;
    deu_certo = false;

    mapa_encontro.insert( pair< int, Encontro >(_id_encontro, *this) );

    cout << "Solicitação de encontro enviada!" << endl;
}

void Encontro::confirmou(){
    this->confirmado = true;
}

void Encontro::cancelar(){
    this->~Encontro();
}

void Encontro::mudar_data(){
    cout << "Digite a data e a hora: ";
    getline(cin, data);
}

void Encontro::mudar_endereco(){
    cout << "Digite o estado: ";
    getline(cin, estado);

    cout << "Digite a cidade: ";
    getline(cin, cidade);

    cout << "Digite a rua: ";
    getline(cin, rua);

    cout << "Digite o numero: ";
    getline(cin, numero);

    cout << "Digite um ponto de referência: ";
    getline(cin, ponto_de_referencia);
}

int Encontro::get_requisitado(){
    return this->id_requisitado;
}

int Encontro::get_requisitante(){
    return this->id_requisitante;
}

bool Encontro::get_confirmado(){
    return this->confirmado;
}

void Encontro::mostra_encontro(){
    cout << "Estado: " << estado << endl;
    cout << "Cidade: " << cidade << endl;
    cout << "Rua: " << rua << endl;
    cout << "Número: " << numero << endl;
    cout << "Ponto de referência: " << ponto_de_referencia << endl;
    cout << "Data: " << data << endl;
}
