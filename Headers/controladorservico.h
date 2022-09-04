#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras de servi�o.

class CntrServicoAutenticacao : public IServicoAutenticacao
{
public:
    virtual bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal : public IServicoPessoal
{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED