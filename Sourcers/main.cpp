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

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();

    IServicoAutenticacao *stubServicoAutenticacao;

    stubServicoAutenticacao = new StubServicoAutenticacao();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoControle->executar();
}