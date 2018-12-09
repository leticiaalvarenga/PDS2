#include "Usuario.h"
#include <iostream>
#include <limits>
#include <algorithm>

unsigned int Usuario::_novo_id = 0;

unsigned int Usuario::get_new_id()
{
    _novo_id++;
    return _novo_id;
}

Usuario::Usuario(tipo_mapa_usuario mapa_usuario, tipo_mapa_geral mapa_geral)
{
    int numero_da_rua;
    char aux;
    std::string nome_do_lixo, nome_da_cidade, nome_do_endereco, nome_da_rua;

    _id = get_new_id();

    std::cout << "Digite seu usuario: ";
    std::cin >> _nome;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


    std::cout << "Voc� pretende doar ou coletar? (D para doador e C para coletor)" <<std::endl;
    try
    {
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if( (aux == 'd') || (aux == 'D') )
            {
            _is_doador = true;
        }
        else if( (aux == 'c') || (aux == 'C') )
        {
            _is_doador = false;
        }
        else
        {
            throw Erro("Entrada invalida: Caractere diferente de D ou C");
        }
    }
    catch (Erro &e)
    {
        e.exibe_mensagem();
    }

    std::cout << "Insira o nome da sua cidade: ";
    std::cin >> nome_da_cidade;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Insira o nome do endereco: ";
    std::cin >> nome_do_endereco;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Insira o nome da rua: ";
    std::cin >> nome_da_rua;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Insira o numero do endereco: ";
    try
    {
        std::cin >> numero_da_rua;
        if (!cin.good())
            throw Erro("Entrada invalida: Esperado numero");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    catch (Erro &e)
    {
        e.exibe_mensagem();
    }
    Endereco endereco(nome_da_cidade, nome_do_endereco, nome_da_rua, numero_da_rua);
    _endereco = endereco;

    std::cout << "Digite o nome do seu lixo: ";
    std::cin >> nome_do_lixo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    nome_do_lixo = to_upper_case(nome_do_lixo);
    _lixo = nome_do_lixo;
    if(/*verifica_no_mapa_geral_se_existe_o_lixo(mapa_geral, tipo_de_lixo, nome_do_lixo)*/ == true)
    {
        if (_is_doador == true){
            mapa_geral[nome_do_lixo][0].push_back(_id);
        }
        else{
            mapa_geral[nome_do_lixo][1].push_back(_id);
        }
    }
    //Se o lixo do usu�rio n�o estiver no mapa geral, o programa entra nesse "else" para criar um novo lixo
    else
    {
        mensagem_de_armazenamento();
        std::vector<int> doadores, coletores;
        std::vector< vector<int> > usuarios;
        //junta os vetores doadores e coletores no vetor de vetores usuarios
        mapa_geral.insert( std::pair< std::string, std::vector< std::vector<int>, std::vector<int>> >(nome_do_lixo,usuarios));
    }
}

/*Void Usuario::Atualiza()
{

}

Usuario* Usuario::Busca()
{

}*/

void Usuario::mensagem_de_armazenamento()
{
    char aux;
    bool _is_toxico;
    bool _is_perecivel;
    bool _is_cortante;
    bool _is_solido;
    bool _is_liquido;
    bool _is_metal;
    bool _is_plastico;
    bool _is_organico;

    try
    {
        std::cout << "� t�xico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_toxico = true;
        else if (aux == 'n' || aux == 'N')
            _is_toxico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� perec�vel? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_perecivel = true;
        else if (aux == 'n' || aux == 'N')
            _is_perecivel = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� cortante? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_cortante = true;
        else if (aux == 'n' || aux == 'N')
            _is_cortante = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� s�lido? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_solido = true;
        else if (aux == 'n' || aux == 'N')
            _is_solido = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� l�quido? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_liquido = true;
        else if (aux == 'n' || aux == 'N')
            _is_liquido = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� metal? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_metal = true;
        else if (aux == 'n' || aux == 'N')
            _is_metal = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� pl�stico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_plastico = true;
        else if (aux == 'n' || aux == 'N')
            _is_plastico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "� org�nico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_organico = true;
        else if (aux == 'n' || aux == 'N')
            _is_organico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");
    }
    //let�cia, coloque as mensagens aqui usando if-else, fazendo favor
    catch (Erro &e)
    {
        e.exibe_mensagem();
    }
}

std::string to_upper_case(std::string s)
{
    std::string aux;
    aux = s;

	std::for_each(aux.begin(), aux.end(), [](char & c){
		c = ::toupper(c);
	});

	return aux;
}
