// Exemplo de uso de template list e de template vector.

#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "../Headers/dominios.h"
#include "../Headers/interfaces.h"
#include "../Headers/controladorapresentacao.h"
#include "../Headers/stubs.h"

using namespace std;

int main()
{
    // Declarar poteiros e instanciar controladoras.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();

    // Instanciar stubs.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoPessoal *stubServicoPessoal;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoPessoal = new StubServicoPessoal();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoPessoal->setCntrServicoPessoal(stubServicoPessoal);

    cntrApresentacaoControle->executar(); // Solicitar servico.

    return 0;
}