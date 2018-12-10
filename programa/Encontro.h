#ifndef ENCONTRO_H
#define ENCONTRO_H

#include <iostream>

class Usuario;

using namespace std;

class Encontro{
private:

    static unsigned int _novo_id_encontro;
    unsigned int _id_encontro;

    string estado;
    string cidade;
    string rua;
    string numero;
    string ponto_de_referencia;

    string data;

    int id_requisitante;
    int id_requisitado;

    bool confirmado;
    bool deu_certo;

public:

    Encontro();
    Encontro(map<int,Encontro> & mapa_encontro, int id_requisitante, int id_requisitado);

    int get_id_encontro();
    int get_requisitante();
    int get_requisitado();
    bool get_confirmado();

    void mudar_data();
    void mudar_endereco();
    void cancelar();
    void confirmou();
    void mostra_encontro();

};

#endif // ENCONTRO_H
