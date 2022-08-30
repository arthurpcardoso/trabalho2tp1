// Exemplo de uso de template list e de template vector.

#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "../Headers/dominios.h"
#include "../Headers/entidades.h"

using namespace std;

int main()
{

    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;

    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();

    IServicoAutenticacao *stubServicoAutenticacao;

    stubServicoAutenticacao = new StubServicoAutenticacao();

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);
}