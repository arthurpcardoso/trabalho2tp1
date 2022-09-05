#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "../Headers/dominios.h"
#include "../Headers/entidades.h"

#include <list>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaracao de classe container.
//
// Declaracao adota padrao de projeto Singleton.

class ContainerUsuario{
    private:
        list<Usuario> container;                        // Lista de usuarios.
        static ContainerUsuario *instancia;             // Ponteiro para instancia da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // Metodo para instanciar classe.
        bool incluir(Usuario);                          // Metodos responsaveis por prestar servicos.
        bool remover(Email);
        bool pesquisar(Usuario*);
        bool atualizar(Usuario);
};

#endif // CONTROLADORAS_H_INCLUDED
