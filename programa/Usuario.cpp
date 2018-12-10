#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Usuario.h"
#include "Encontro.h"

using namespace std;

unsigned int Usuario::_novo_id = 1;

string to_upper_case(string s){

    string aux = "";
    char c;
    int i = 0;

	while(s[i]){
        c = s[i];
        aux += toupper(c);
        i++;
	}

	return aux;
}

//retorna true se existir
bool verifica_nos_mapas_se_existe_o_lixo(string nome_do_lixo, map<string, vector<int>* > mapa_doador, map<string, vector<int>* > mapa_coletor){

    map<string, vector<int>* >::iterator it;

    it = mapa_doador.find(nome_do_lixo);

    //ou seja, se encontrar
    if(it != mapa_doador.end()) return true
    ;
    else{
        it = mapa_coletor.find(nome_do_lixo);

        if(it != mapa_coletor.end()) return true
        ;
        else return false;
    }
}

Usuario::Usuario(){}

Usuario::Usuario(map<int, Usuario> & mapa_usuario, map<string, vector<int>* > & mapa_doador, map< string, vector<int>* > & mapa_coletor){

    char aux;
    string nome_do_lixo;

    _id = Usuario::_novo_id;
    Usuario::_novo_id++;

    cout << "Digite seu nome: ";
    cin >> _nome;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Você pretende doar ou coletar? (D para doador e C para coletor)" << endl;
    cin >> aux;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if( (aux == 'd') || (aux == 'D') ){
        _is_doador = true;
    }

    else{
        _is_doador = false;
    }

    cout << "Digite o nome do seu lixo: ";
    cin >> nome_do_lixo;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    nome_do_lixo = to_upper_case(nome_do_lixo);

    if(verifica_nos_mapas_se_existe_o_lixo(nome_do_lixo, mapa_doador, mapa_coletor) == false){

        mapa_doador.insert( pair< string, vector<int>* >(nome_do_lixo, new vector<int>) );
        mapa_coletor.insert( pair< string, vector<int>* >(nome_do_lixo, new vector<int>) );

    }

    cout << "Digite sua quantidade de lixo (e.g.: 3 latas, 400 ml, 3 kg): ";
    getline(cin, _quantidade);

    if (_is_doador == true){
        mapa_doador[nome_do_lixo]->push_back(_id);
    }
    else{
        mapa_coletor[nome_do_lixo]->push_back(_id);
    }

    mapa_usuario.insert( pair< int, Usuario >(_id, *this) );

    cout << "Usuário criado com sucesso!\nSua senha é: " << _id << endl;

}

string Usuario::get_nome(){
    return this->_nome;
}

int Usuario::get_id(){
    return this->_id;
}

string Usuario::get_quantidade(){
    return this->_quantidade;
}

void Usuario::adiciona_encontro(int _id_encontro){
    this->_lista_de_encontros.push_back(_id_encontro);
}

void Usuario::cancela_encontro(int _id_encontro){

    vector<int>::iterator posicao_id;
    vector<int>::iterator it;

    for(it = this->_lista_de_encontros.begin(); it != this->_lista_de_encontros.end(); ++it){
        if(*it == _id_encontro){
            posicao_id = it;
            break;
        }
    }

    this->_lista_de_encontros.erase(posicao_id);
}

void Usuario::Atualiza(){

}

void Usuario::Visualiza_encontros(map<int, Encontro> & mapa_encontro, map<int, Usuario> & mapa_usuario){

    vector<int>::iterator it;
    char resposta;

    for(it = this->_lista_de_encontros.begin(); it != this->_lista_de_encontros.end(); ++it){

        mapa_encontro[*it].mostra_encontro();

        if(this->_id == mapa_encontro[*it].get_requisitante()){

            if(mapa_encontro[*it].get_confirmado() == false){

                cout << "Deseja cancelar? (s/n)" << endl;
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta == 's' || resposta == 'S'){
                    this->cancela_encontro(mapa_encontro[*it].get_id_encontro());
                    mapa_usuario[mapa_encontro[*it].get_requisitado()].cancela_encontro(*it);
                    mapa_encontro.erase(*it);
                }

            }
            else{

                cout << "O encontro já aconteceu com sucesso? (s/n)" << endl;
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta == 's' || resposta == 'S'){
                    this->cancela_encontro(mapa_encontro[*it].get_id_encontro());
                    mapa_usuario[mapa_encontro[*it].get_requisitado()].cancela_encontro(*it);
                    mapa_encontro.erase(*it);
                }
                else{


                    cout << "Deseja modificar local e data do encontro? (s/n)" << endl;
                    cin >> resposta;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');

                    if(resposta == 's' || resposta == 'S'){
                        mapa_encontro[*it].mudar_endereco();
                        mapa_encontro[*it].mudar_data();
                    }

                }

            }

        }

        if(this->_id == mapa_encontro[*it].get_requisitado()){

            if(mapa_encontro[*it].get_confirmado() == false){

                cout << "Deseja confirmar? (s/n)" << endl;
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta == 's' || resposta == 'S'){
                    mapa_encontro[*it].confirmou();
                }
            }
            else{

                cout << "Deseja cancelar? (s/n)" << endl;
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta == 's' || resposta == 'S'){
                    this->cancela_encontro(mapa_encontro[*it].get_id_encontro());
                    mapa_usuario[mapa_encontro[*it].get_requisitante()].cancela_encontro(*it);
                    mapa_encontro.erase(*it);
                }
            }
        }
    }
}

void Usuario::Busca(map<int, Usuario> & mapa_usuario, map<int, Encontro> & mapa_encontro, map<string, vector<int>* > mapa_doador, map<string, vector<int>* > mapa_coletor){

    int i = 0;
    string resposta;
    string nome_do_lixo;
    vector<int> vetor_de_ids;
    Encontro* encontro_aux;

    do{
        cout << "Digite o nome do lixo que você está buscando (ou digite 'quit' para sair): ";
        cin >> nome_do_lixo;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        nome_do_lixo = to_upper_case(nome_do_lixo);

        //se existir o lixo no mapa...
        if(verifica_nos_mapas_se_existe_o_lixo(nome_do_lixo, mapa_doador, mapa_coletor) == true && nome_do_lixo.compare("QUIT") != 0){

            if(this->_is_doador == true){

                vetor_de_ids = *mapa_coletor[nome_do_lixo];

                for(vector<int>::iterator it = vetor_de_ids.begin(); it != vetor_de_ids.end(); ++it){

                    cout << "Índice: " << i << endl;
                    cout << "Nome: " << mapa_usuario[*it].get_nome() << endl;
                    cout << "Quantidade: " << mapa_usuario[*it].get_quantidade() << "\n" << endl;
                    i++;
                }

                cout << "Digite o índice do usuário que você deseja escolher (ou digite 'quit' para sair): ";
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta.compare("quit") != 0){

                    cout << "Busca: this->_id: " << this->_id << endl;
                    cout << "Busca: outro id: " << mapa_usuario[vetor_de_ids[resposta[0] - '0']].get_id() << endl;
                    encontro_aux = new Encontro(mapa_encontro, this->_id, mapa_usuario[vetor_de_ids[resposta[0] - '0']].get_id());

                    this->adiciona_encontro(encontro_aux->get_id_encontro());
                    mapa_usuario[vetor_de_ids[resposta[0] - '0']].adiciona_encontro(encontro_aux->get_id_encontro());
                }

            }
            else{

                vetor_de_ids = *mapa_doador[nome_do_lixo];

                for(vector<int>::iterator it = vetor_de_ids.begin(); it != vetor_de_ids.end(); ++it){

                    cout << "Índice: " << i << endl;
                    cout << "Nome: " << mapa_usuario[*it].get_nome() << endl;
                    cout << "Quantidade: " << mapa_usuario[*it].get_quantidade() << "\n" << endl;
                    i++;
                }

                cout << "Digite o índice do usuário que você deseja escolher (ou digite 'quit' para sair): ";
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta.compare("quit") != 0){

                    encontro_aux = new Encontro(mapa_encontro, this->_id, mapa_usuario[vetor_de_ids[resposta[0] - '0']].get_id());

                    this->adiciona_encontro(encontro_aux->get_id_encontro());
                    mapa_usuario[vetor_de_ids[resposta[0] - '0']].adiciona_encontro(encontro_aux->get_id_encontro());
                }


            }

        }
        else{
            cout << "Lixo não encontrado!" <<endl;
            break;
        }

    }while(resposta.compare("quit") == 0 || nome_do_lixo.compare("QUIT") == 0);


}
