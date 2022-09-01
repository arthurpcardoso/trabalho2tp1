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
    CPF cpf;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;
    IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros;

public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *);
    void setCntrApresentacaoPessoal(IApresentacaoPessoal *);
    void setCntrApresentacaoProdutosFinanceiros(IApresentacaoProdutosFinanceiros *);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr)
{
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr)
{
    cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoProdutosFinanceiros(IApresentacaoProdutosFinanceiros *cntr)
{
    cntrApresentacaoProdutosFinanceiros = cntr;
}

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

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED