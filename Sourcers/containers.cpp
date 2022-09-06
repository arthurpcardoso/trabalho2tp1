#include "../Headers/containers.h"

ContainerUsuario *ContainerUsuario::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementacoes de metodos de classe container.

ContainerUsuario *ContainerUsuario::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::incluir(Usuario usuario)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getValor() == usuario.getEmail().getValor())
        {
            return false;
        }
    }
    container.push_back(usuario); // Incluir objeto.
    return true;
}

bool ContainerUsuario::remover(Email email)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getValor() == email.getValor())
        {
            container.erase(elemento); // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::pesquisar(Usuario *usuario)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getValor() == usuario->getEmail().getValor())
        {
            usuario->setNome(elemento->getNome()); // Copiar dados do objeto localizado.
            usuario->setSenha(elemento->getSenha());

            return true;
        }
    }
    return false;
}

bool ContainerUsuario::atualizar(Usuario usuario)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getValor() == usuario.getEmail().getValor())
        {
            elemento->setNome(usuario.getNome());
            elemento->setSenha(usuario.getSenha());
            return true;
        }
    }
    return false;
}
