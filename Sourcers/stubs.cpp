#include "../Headers/stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoPessoal::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes stub.

bool StubServicoAutenticacao::autenticar(Email email, Senha senha)
{
    if (email.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::cadastrarUsuario(Usuario usuario)
{
    if (usuario.getEmail().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}