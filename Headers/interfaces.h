#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

class IServicoAutenticacao;
class IServicoPessoal;

// Apresentacoes

class IApresentacaoAutenticacao
{
public:
    virtual bool autenticar(Email *) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao *) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

// Servicos

class IServicoAutenticacao
{
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~IServicoAutenticacao() {}
};

class IServicoPessoal{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual ~IServicoPessoal(){}
};

#endif // INTERFACES_H_INCLUDED