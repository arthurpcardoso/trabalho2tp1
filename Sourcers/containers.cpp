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

// Novo container
/*
ContainerUsuario *ContainerHospedagem::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ContainerHospedagem();
    return instancia;
}

bool ContainerHospedagem::incluir(Hospedagem hospedagem)
{
    for (list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getCodigo().getValor() == hospedagem.getCodigo().getValor())
        {
            return false;
        }
    }
    container.push_back(hospedagem); // Incluir objeto.
    return true;
}

bool ContainerHospedagem::remover(Codigo codigo)
{
    for (list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getCodigo().getValor() == codigo.getValor())
        {
            container.erase(elemento); // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerHospedagem::pesquisar(Hospedagem *hospedagem)
{
    for (list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getCodigo().getValor() == hospedagem->getCodigo().getValor())
        {
            Hospedagem->setCidade(elemento->getCidade()); // Copiar dados do objeto localizado.
            Hospedagem->setPais(elemento->getPais());
            Hospedagem->setDescricao(elemento->getDescricao());

            return true;
        }
    }
    return false;
}

bool ContainerHospedagem::atualizar(Hospedagem Hospedagem)
{
    for (list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getCodigo().getValor() == hospedagem.getCodigo().getValor())
        {
            elemento->setCidade(hospedagem.getCidade());
            elemento->setPais(hospedagem.getPais());
            elemento->setDescricao(hospedagem.getDescricao());

            return true;
        }
    }
    return false;
}
*/