#include "../Headers/controladorservico.h"

// utiliza os containers

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha){

    // ---------------------------------------------------------------------------------------
    // Instanciar container de usu�rios.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Recuperar e comparar senha de usu�rio.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Retornar resultado.
    // ---------------------------------------------------------------------------------------

    return true;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario){

    // Instancia container de usuarios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usuario e retornar resultado da solicitacao de servico.

    return container->incluir(usuario);
}

//--------------------------------------------------------------------------------------------


