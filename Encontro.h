#ifndef ENCONTRO_H
#define ENCONTRO_H


class Encontro
{
    public:
        Encontro(std::string data, Endereco endereco, Usuario requisitado, Usuario requisitante, bool deu_certo, bool _confirmado, int id_usuario_encontro);
        virtual ~Encontro();

//        void Busca_Encontro(int id_usuario, tipo_mapa_encontros mapa_encontro);

        std::string get_data();
        Endereco get_endereco();
        Usuario get_requisitante();
        Usuario get_requisitado();
        bool get_deu_certo();
        bool get_confirmado();



    protected:

    private:
        std::string _data;
        Endereco _endereco;
        Usuario _requisitado;
        Usuario _requisitante;
        bool _deu_certo;
        bool _confirmado;
        int _id_usuario_encontro;
};

#endif // ENCONTRO_H
