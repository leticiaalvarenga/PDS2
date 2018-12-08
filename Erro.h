#ifndef ERRO_H_INCLUDED
#define ERRO_H_INCLUDED

class Erro
{
private:
    std::string tipo_erro;
public:
    Erro(const std::string &tp) : tipo_erro(tp) {}
    void exibe_mensagem() {std::cout << tipo_erro << std::endl;};
};

#endif // ERRO_H_INCLUDED
