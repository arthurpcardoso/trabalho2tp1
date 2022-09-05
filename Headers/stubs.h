#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declaracoes de classes stub.

class StubServicoAutenticacao : public IServicoAutenticacao
{
private:
    static const string INVALIDO;

public:
    bool autenticar(Email, Senha);
};

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarUsuario(Usuario);
};

#endif // STUBS_H_INCLUDED
