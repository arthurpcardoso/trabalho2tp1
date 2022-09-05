#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoControle
{
private:
    Email email;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;

public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr)
{
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr)
{
    cntrApresentacaoPessoal = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe  controladora de apresentacao autenticacao

class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao
{
private:
    IServicoAutenticacao *cntr;

public:
    bool autenticar(Email *);
    void setCntrServicoAutenticacao(IServicoAutenticacao *);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr)
{
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentacao pessoal

class CntrApresentacaoPessoal : public IApresentacaoPessoal
{
    private:
        IServicoPessoal *cntrServicoPessoal;
        void consultarDadosPessoais()
    public:
        void executar(Email);
        void cadastrar():
        void setCntrServicoPessoal(IServicoPessoal*);
    
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr)
{
    cntrServicoPessoal = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED