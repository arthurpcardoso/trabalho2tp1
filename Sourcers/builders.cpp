#include "../Headers/builders.h"

CntrApresentacaoControle* BuilderSistema::construir()
{

    // Instanciar controladoras da camada de apresentacao.

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    
    // Instanciar controladoras da camada de servico.

    cntrServicoPessoal = new CntrServicoPessoal();

    // --------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoAutenticacao por instancia da controladora.
    // --------------------------------------------------------------------------------------------

    cntrServicoAutenticacao = new StubServicoAutenticacao();

    // ---------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoProdutosFinanceiros por inst�ncia da controladora.
    // ---------------------------------------------------------------------------------------------

    cntrServicoProdutosFinanceiros = new StubServicoProdutosFinanceiros();

    // Interligar as controladoras.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrServicoPessoal(cntrServicoPessoal);

    // Retornar refer�ncia para inst�ncia de CntrApresentacaoControle.

    return cntrApresentacaoControle;
}

BuilderSistema::~BuilderSistema()
{
        delete cntrApresentacaoControle;
        delete cntrApresentacaoAutenticacao;
        delete cntrApresentacaoPessoal;
        delete cntrServicoAutenticacao;
        delete cntrServicoPessoal;
}
