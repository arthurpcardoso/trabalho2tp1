#include "../Headers/controladorservico.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes controladoras da camada de servi�o.

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha)
{

    Usuario usuario;

    // ---------------------------------------------------------------------------------------
    // Instanciar container de usu�rios.
    // ---------------------------------------------------------------------------------------

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // ---------------------------------------------------------------------------------------
    // Recuperar e comparar senha de usu�rio.
    // ---------------------------------------------------------------------------------------

    usuario.setEmail(email);

    if (usuario.getSenha().getValor() == senha.getValor())
    {
        cout << "deu certo" << endl;
    }

    // ---------------------------------------------------------------------------------------
    // Retornar resultado.
    // ---------------------------------------------------------------------------------------

    return true;
    ;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario)
{

    // Instancia container de usu�rios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usu�rio e retornar resultado da solicita��o de servi�o.

    return container->incluir(usuario);
}

//--------------------------------------------------------------------------------------------