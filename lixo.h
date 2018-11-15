#ifndef LIXO_H_INCLUDED
#define LIXO_H_INCLUDED

class Lixo{
        private:
            std::string _nome;
            bool _is_toxico;
            bool _is_perecivel;
            bool _is_cortante;
            bool _is_solido;
            bool _is_liquido;
            bool _is_metal;
            bool _is_plastico;
            bool _is_organico;

        public:
            Lixo(std::string); //Criar lixo
            string Atualizar_lixo(bool, bool, bool, bool, bool, bool, bool); //Atualizar lixo



}


#endif // LIXO_H_INCLUDED
