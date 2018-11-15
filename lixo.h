#ifndef LIXO_H_INCLUDED
#define LIXO_H_INCLUDED

class Lixo{
        private:
            string _nome;
            //string _descricao;
            bool _is_toxico;
            bool _is_perecivel;
            bool _is_cortante;
            bool _is_solido;
            bool _is_liquido;
            bool _is_metal;
            bool _is_plastico;
            bool _is_organico;

        public:
            Lixo(string); //Criar lixo
            string Atualizar_lixo(bool, bool, bool, bool, bool, bool, bool); //Atualizar lixo
            //Lixo Buscar_lixo(string); //Buscar lixo



}


#endif // LIXO_H_INCLUDED
