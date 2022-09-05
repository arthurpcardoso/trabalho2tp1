#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "interfaces.h"
#include "controladorapresentacao.h"
#include "controladorservico.h"
#include "stubs.h"

class BuilderSistema {
    private:
        CntrApresentacaoControle *cntrApresentacaoControle;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IServicoPessoal *cntrServicoPessoal;
    public:
        CntrApresentacaoControle* construir();
        ~BuilderSistema();
};

#endif // BUILDERS_H_INCLUDED
