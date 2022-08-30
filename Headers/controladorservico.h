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

#endif // CONTROLADORASSERVICO_H_INCLUDED