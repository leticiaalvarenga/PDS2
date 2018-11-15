#include <string>

class Lugar{
	private:

	std::string _nome;
	std::string _estado;
	std::string _cidade;
	std::string _bairro;
	std::string _rua;
	int _numero;

	public:
	
	Lugar(std::string, std::string, std::string, std::string, std::string, int); //Construtor
	
	alterar_lugar(); //Altera o lugar do usuário

};
