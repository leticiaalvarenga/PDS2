#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Usuario.h"

using namespace std;
/*
using namespace std;

typedef vector<int> v_int;
typedef vector< v_int > ###WooooW###;
typedef map< string, ###WooooW### > tipo_mapa_geral;
*/
//string to_upper_case(const string &s);

//bool verifica_no_mapa_geral_se_existe_o_lixo(tipo_mapa_geral mapa, string lixo);

bool usuario_e_senha_existem_no_mapa_usuario(std::map<int,Usuario> mapa_usuario, std::string nome_usuario, int senha_usuario);

int main(){

    map<int,Usuario> mapa_usuario;
    map<int, Encontro> mapa_encontros;
    map<string, vector<int>* > mapa_doador;
    map<string, vector<int>* > mapa_coletor;

    char resposta;
    string nome_usuario;
    int senha_usuario;
    Usuario* usuario_ativo = nullptr;

    while(true){
        cout << "TRASHAPP!\Bem-vindo ao Trashapp! Já tem conta (S/N ou Q para sair)? " << std::endl;
        std::cin >> resposta;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if(resposta == 'q' || resposta == 'Q') break;

        if(resposta == 's' || resposta == 'S'){
            cout << "Usuário: ";
            std::cin >> nome_usuario;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Senha: ";
            std::cin >> senha_usuario;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if(usuario_e_senha_existem_no_mapa_usuario(mapa_usuario, nome_usuario, senha_usuario) == false){
                cout << "Usuário ou senha_usuario incorretos" << std::endl;
                usuario_ativo = nullptr;
            }
            else{
                usuario_ativo = &mapa_usuario[senha_usuario];
            }

            //para acessar o usuario ativo, fazemos mapa_usuario[senha_usuario]

        }
        else{
            usuario_ativo = new Usuario(mapa_usuario, mapa_doador, mapa_coletor);
        }

        if(usuario_ativo != nullptr){
            do{

                cout << "1) Buscar\n2) Encontros\n3) Atualizar conta\n4) Cancelar conta\n5) Sair\nEscolha uma opção: ";
                cin >> resposta;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                if(resposta == '1'){
                    usuario_ativo->Busca(mapa_usuario, mapa_encontros, mapa_doador, mapa_coletor);
                }

                if(resposta == '2'){
                    usuario_ativo->Visualiza_encontros(mapa_encontros, mapa_usuario);
                }

                if(resposta == '3'){

                }

                if(resposta == '4'){

                }

            }while(resposta != '5');
        }
    }

    return 0;
}

bool usuario_e_senha_existem_no_mapa_usuario(std::map<int,Usuario> mapa_usuario, std::string nome_usuario, int senha_usuario){

    map<int, Usuario>::iterator it;

    it = mapa_usuario.find(senha_usuario);

    if(it != mapa_usuario.end()){

        if(mapa_usuario[senha_usuario].get_nome() == nome_usuario){

            return true;
        }
        else{

            return false;
        }

    }
    else{

        return false;
    }

}
