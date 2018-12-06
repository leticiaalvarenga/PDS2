#include "Usuario.h"
#include <iostream>

static unsigned int _novo_id = 1;

Usuario::Usuario(tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral){

    int tipo_de_lixo;
    char aux;
    std::string nome_do_lixo;
    std::vector<  > vetor;

    _id = _novo_id;
    _novo_id++;

    std::cout << "Digite seu nome: ";
    std::cin >> _nome;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    std::cout << "Você pretende doar ou coletar? (D para doador e C para coletor)" <<std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if( (aux == 'd') || (aux == 'D') ){
        _is_doador = true;
    }

    else{

        if( (aux == 'c') || (aux == 'C') ){
            _is_doador = false;
        }

        else {
            //dê um throw aqui letícia
        }
    }

    std::cout << "Digite o nome do seu lixo: ";
    std::cin >> nome_do_lixo;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    nome_do_lixo = to_upper_case(nome_do_lixo);

    if(verifica_no_mapa_geral_se_existe_o_lixo(mapa_geral, tipo_de_lixo, nome_do_lixo) == true){

        if (_is_doador == true){

            mapa_geral[nome_do_lixo][0].push_back(_id);
        }
        else{
            mapa_geral[nome_do_lixo][1].push_back(_id);
        }

    }

    //Se o lixo do usuário não estiver no mapa geral, o programa entra nesse "else" para criar um novo lixo
    else {

        mensagem_de_armazenamento();
        mapa_geral.insert( std::pair< std::string, std::vector< std::vector<int>, std::vector<int>> >(nome_do_lixo, ));

    }


}

bool Usuario::is_doador(bool answer){

}

Void Usuario::Atualiza(){

}

Usuario* Usuario::Busca(){

}

void Usuario::mensagem_de_armazenamento(){

    bool _is_toxico;
    bool _is_perecivel;
    bool _is_cortante;
    bool _is_solido;
    bool _is_liquido;
    bool _is_metal;
    bool _is_plastico;
    bool _is_organico;

    std::cout << "É tóxico? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_toxico = true;};

    std::cout << "É perecível? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_perecivel = true;};

    std::cout << "É cortante? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_cortante = true;};

    std::cout << "É sólido? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_solido = true;};

    std::cout << "É líquido? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_liquido = true;};

    std::cout << "É metal? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_metal = true;};

    std::cout << "É plástico? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_plastico = true;};

    std::cout << "É orgânico? (s/n)" << std::endl;
    std::cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(aux == 's' || aux == 'S') {_is_organico = true;};

    //letícia, coloque as mensagens aqui usando if-else, fazendo favor

}
