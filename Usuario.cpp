#include "Usuario.h"
#include <iostream>
#include <limits>
#include <algorithm>

unsigned int Usuario::_novo_id = 0;

unsigned int Usuario::get_id()
{
	return this-> _id;
}

std::string Usuario::get_lixo()
{
	return this-> _lixo;
}

bool Usuario::get_if_doador()
{
	return this-> _is_doador;
}

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


    std::cout << "Você pretende doar ou coletar? (D para doador e C para coletor)" <<std::endl;
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
    //Se o lixo do usuário não estiver no mapa geral, o programa entra nesse "else" para criar um novo lixo
    else
    {
        mensagem_de_armazenamento();
        std::vector<int> doadores, coletores;
        std::vector< vector<int> > usuarios;
        //junta os vetores doadores e coletores no vetor de vetores usuarios
        mapa_geral.insert( std::pair< std::string, std::vector< std::vector<int>, std::vector<int>> >(nome_do_lixo,usuarios));
    }
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
        std::cout << "É tóxico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_toxico = true;
        else if (aux == 'n' || aux == 'N')
            _is_toxico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É perecível? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_perecivel = true;
        else if (aux == 'n' || aux == 'N')
            _is_perecivel = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É cortante? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_cortante = true;
        else if (aux == 'n' || aux == 'N')
            _is_cortante = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É sólido? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_solido = true;
        else if (aux == 'n' || aux == 'N')
            _is_solido = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É líquido? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_liquido = true;
        else if (aux == 'n' || aux == 'N')
            _is_liquido = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É metal? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_metal = true;
        else if (aux == 'n' || aux == 'N')
            _is_metal = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É plástico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_plastico = true;
        else if (aux == 'n' || aux == 'N')
            _is_plastico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");

        std::cout << "É orgânico? (s/n)" << std::endl;
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(aux == 's' || aux == 'S')
            _is_organico = true;
        else if (aux == 'n' || aux == 'N')
            _is_organico = false;
        else
            throw Erro("Entrada invalida: Nao pode ser determinada carater toxico");
	    
	    
	 //Mensagens
	 if(_is_toxico){
	      std::cout << "Cuidado para não intoxicar. Descarte em locais que pegam apenas materiais tóxicos." << std:endl;
	 }  
	 else if(_is_perecivel){
	      std::cout << "Coloque em local fresco e arejado." << std:endl;
	 }
	 else if(_is_solido){
	      std::cout << "Guarde em locais que não machuque os outros até o dia de sua coleta." << std:endl;
	 } 
	 else if(_is_liquido){
	      std::cout << "Coloque em garrafas e tampe bem." << std:endl;
	 }
	 else if(_is_cortante){
	      std::cout << "Embale bem os objetos cortantes para não machucar quem for receber estes materiais." << std:endl;
	 }
	 else if(_is_metal){
	      std::cout << "Guarde bem os metais para não machucar quem for recolher." << std:endl;
	 }
	 else if(_is_plastico){
	      std::cout << "Feche bem as garrafas plásticas (para não acumular água) até o dia de sua coleta." << std:endl;
	 } 
	 else{ //_is_organico
	      std::cout << "Deixe em lugar arejado até o dia de sua coleta." << std:endl;
	 }   
    }
    
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
			
			mapa[this->_lixo][1].erase(std::remove(mapa[this->_lixo][1].begin(), mapa[this->_lixo][1].end(), this->get_id()), mapa[this->_lixo][1].end());
				// fonte: https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
			
			/*adiciono*/
			mapa[this->_lixo][0].push_back(this->get_id());
		}
	}
}

void Atualiza_lixo(//Forncer os mapas
				  //std::map<std::string, std::vector<int> > mapa_coletores,
				  //std::map<std::string, std::vector<int> > mapa_doadores,
				  // Vou fazer com o mapa geral
				  std::map<std::string, std::vector<std::vector<int> > > mapa
				  )
{
	std::cout <<"Você pretende atualizar seu lixo?" "[y/n]"<<std::endl;
	std::string resp;
	std::cin >> resp;
	if((resp == "Y")||(resp == "y"))
	{
		std::cout <<"Qual seu novo lixo?(CAIXA ALTA, por favor)"<<std::endl;
		std::string novo_lixo;
		std::cin >> novo_lixo;
		//verificar se o lixo ja existe no mapa
						// se existir, muda
						// se não, retorna com mensagem
		if(_is_doador == true)
		{
			if (mapa.empty() == 1)
			{
				return;
			}
		
			else if (mapa.find(novo_lixo) == mapa.end())
			{
				//Não existe, porém deve-se adiciona-lo antes de mudar.
				std::cout << "Lixo requerido ainda não existe! Favor adicioná-lo antes da autalização;" << std::endl;

				return;
			}
			
			else
			{
				//Existe no mapa, portanto, podemos atualizar
				//Primeiro, retiramos o id do mapa de doadores, depois adicionamos no 
				// apendice do novo lixo
				
				// mapa -> mapa_doadores
				
				mapa[get_lixo()].erase(std::remove(mapa[this->_lixo][0].begin(), mapa[this->_lixo][0].end(), get_id()), mapa[this->_lixo][0].end());
				// agora adicionamos o id no vector do novo lixo
				mapa[novo_lixo].push_back(get_id());
				this->_lixo = novo_lixo;

				return;
			}
		}
		
		else
		{
			if (mapa.empty() == 1)
			{
				return;
			}
		
			else if (mapa.find(novo_lixo) == mapa.end())
			{
				//Não existe, porém deve-se adiciona-lo antes de mudar.
				std::cout << "Lixo requerido ainda não existe! Favor adicioná-lo antes da autalização;" << std::endl;
				return;
			}
			
			else
			{
				//Existe no mapa, portanto, podemos atualizar
				//Primeiro, retiramos o id do mapa de doadores, depois adicionamos no 
				// apendice do novo lixo
				
				// mapa -> mapa_coletores
				
				mapa[this->get_lixo].erase(std::remove(mapa[this->get_lixo][1].begin(), mapa[this->get_lixo][1].end(), this-> get_id()), mapa[this->get_lixo][1].end());
				// agora adicionamos o id no vector do novo lixo
				mapa[novo_lixo].push_back(get_id());
				this->_lixo = novo_lixo;

				return;
			}
		}
	}
	
	else
	{
		return 0;
	}
}	



void Usuario::Busca_Encontro(int id_usuario, tipo_mapa_encontros mapa_encontro){
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


void Usuario::Busca(std::map<std::string, std::vector<std::vector<int> > > mapa_geral, std::map<int, Usuario> mapa_usuario) //retorna lista de users que deram "match"
{
	std::cout <<"Que lixo busca?" <<std::endl;
	std::string resp;
	std::cin >> resp;
	//conferimos, no mapa central, se existe
	//caso exista, buscamos os ids referentes, e, com eles, vamos ao mapa de usuarios
	// e retornamos as informações deles.
	if (mapa_geral.empty() == 1)
			{
				return 0;
			}
		
	else if (mapa_geral.find(resp) == mapa_geral.end())
	{
		//Não existe, porém deve-se adiciona-lo antes de mudar.
		std::cout << "Lixo requerido ainda não existe!" << std::endl;
		return 0;
	}
	
	else //lixo existe no mapa
	{
		//devemos checar se é doador ou não para saber em qual vetor consultar;
		if(_is_doador == true)//faremos pesquisas no [1]
		{
			std::vector<int> aux(mapa_geral["resp"][1]); //aparentemente isso faz a mesma coisa do swap
			// vetor guarda os ids correspondentes
			
			//busca no mapa de usuarios
			std::cout << "Coletores encontrados:" << std:: endl;
			for(int i = 0; i < aux.size(); i++)
			{
				std::cout<<"Coletor"<< i <<":"<<std::endl;
				std::cout<< "Nome: "<<mapa_usuario[aux[i]].get_nome()<<std::endl;
				// tamebém deveria retornar o endereço
			}
		}
		else //faremos pesquisa no [0]
		{
			std::vector<int> aux(mapa_geral["resp"][0]); //aparentemente isso faz a mesma coisa do swap
			// vetor guarda os ids correspondentes
			
			//busca no mapa de usuarios
			std::cout << "Doadores encontrados:" << std:: endl;
			for(int i = 0; i < aux.size(); i++)
			{
				std::cout<<"Doador"<< i <<":"<<std::endl;
				std::cout<< "Nome: "<<mapa_usuario[aux[i]].get_nome()<<std::endl;
				// tamebém deveria retornar o endereço
			}
		}
	}
	
	
}

