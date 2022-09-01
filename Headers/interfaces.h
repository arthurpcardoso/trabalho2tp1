#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

class IServicoAutenticacao;

class IApresentacaoAutenticacao
{
public:
    virtual bool autenticar(Email *) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao *) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

class IServicoAutenticacao
{
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~IServicoAutenticacao() {}
};

#endif // INTERFACES_H_INCLUDED