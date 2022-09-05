#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

class CntrServicoAutenticacao : public IServicoAutenticacao
{
public:
    virtual bool autenticar(Email, Senha);
};

class CntrServicoPessoal:public IServicoPessoal{
    public:
        bool cadastrarUsuario(Usuario);
};

// listar hospedagens disponiveis

#endif // CONTROLADORASSERVICO_H_INCLUDED