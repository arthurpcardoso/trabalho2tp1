#include "../Headers/controladorservico.h"

//--------------------------------------------------------------------------------------------
// Implementacoes de metodos de classes controladoras da camada de servico.

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha)
{

    Usuario usuario;

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    usuario.setEmail(email);

    container->pesquisar(&usuario);

    if (usuario.getSenha().getValor() == senha.getValor())
    {
        return true;
    }

    return false;
    
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario)
{

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    return container->incluir(usuario);
}

//--------------------------------------------------------------------------------------------