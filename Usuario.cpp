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

void Usuario::Atualiza_infos(std::map<std::string, std::vector<std::vector<int> > > mapa)
{
	std::cout << "Deseja alterar:" <<std::endl;
	std::cout << "		a)Nome?" <<std::endl;
	std::cout << "		b)Perfil de doador?" <<std::endl;
	std::cout << "[a/b?]" <<std::endl;
	
	std::string answer;
	std::cin >> answer;
	
	if((answer == "a")||(answer == "A"))
	{
		std::string nome_aux = this->_nome;
		std::cout << "Qual nome deseja por?" <<std::endl;
		std::string novo_nome;
		std::cin >> novo_nome;
		_nome = novo_nome;
		std::cout << "Nome antigo: "<< nome_aux << std::endl;
		std::cout << "Nome novo: "<< this->_nome << std::endl;
		return;
	}
	
	else if((answer == "b")||(answer == "B"))
	{
		if(this->_is_doador == true)
		{
			std::cout << "Trocando de doador para coletor" << std::endl;
			this->_is_doador == false;
			// Agora, no mapa geral, se o usurio possui seu id associado ao vector 
			// de doadores, deve-se tirar o seu id desse vector e jogá-lo para o 
			// vector de coletores.
			// Obrigatoriamente, o lixo do usuario ja vai existir e estar no mapa geral
			// Caso não esteja (dependendo da implementação do Duda), devo checar se
			// o usuário tem ou não algum lixo definido na classe.
			
			// myMap[key].push_back('c'); => para adicionar no final do vetor em um mapa
			
			// Provavelmente devo ter que iterar o mapa todo, até achar o id do usuario 
			// no vector de doadores
			
			/*CHECAR SINTAXE DE MANIPULAÇAO DO MAPA_GERAL COM O DUDA*/
			
			/*retiro*/
			mapa[this->_lixo][0].erase(std::remove(mapa[this->_lixo][0].begin(), mapa[this->_lixo][0].end(), this-> get_id()), mapa[this->_lixo][0].end());
				// fonte: https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
			
			/*adiciono*/
			mapa[this->_lixo][1].push_back(this->get_id());
		}
		
		else
		{
			std::cout << "Trocando de coletor para doador" << std::endl;
			this->_is_doador == true;
			
            /*retiro*/
			mapa[this->_lixo][1].erase(std::remove(mapa[this->_lixo][1].begin(), mapa[this->_lixo][1].end(), this->get_id()), mapa[this->_lixo][1].end());
				// fonte: https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
			
			/*adiciono*/
			mapa[this->_lixo][0].push_back(this->get_id());
		}
	}
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
    
    if(_is_toxico == true){
        std::cout << "Para o descarte de material tóxico, envolva o lixo em sacolas plásticas ou em caixa plasticas e deposite em postos de coleta específicos. " << endl;
    }
    else if(_is_perecivel == true){
        std::cout << "Para o descarte de material perecível..." << endl;
    } 
    else if(_is_cortante == true){
        std::cout << "Para o descarte de material cortante..." << endl;
    }
    else if(_is_solido == true){
        std::cout << "Para o descarte de material sólido..." << endl;
    }
    else if(_is_liquido == true){
        std::cout << "Para o descarte de líquidos..." << endl;
    }
    else if(_is_metal == true){
        std::cout << "Para o descarte de metal..." << endl;
    }
    else if(_is_plastico == true){
        std::cout << "Para o descarte de material plástico.." << endl;
    }
    else {//organico
        std::cout << "Para o descarte de material orgânico..." << endl;
    }
    

}
