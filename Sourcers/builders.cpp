#include "../Headers/builders.h"

CntrApresentacaoControle* BuilderSistema::construir()
{

    // Instanciar controladoras da camada de apresentacao.

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    
    // Instanciar controladoras da camada de servico.

    cntrServicoPessoal = new CntrServicoPessoal();
    cntrServicoAutenticacao = new CntrServicoAutenticacao();


    // Interligar as controladoras.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrServicoPessoal(cntrServicoPessoal);

    // Retornar referencia para instancia de CntrApresentacaoControle.

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
