/**
 * @file entidades.h
 * @author Arthur Pereira Cardoso e Lucas de Sa Gomes Licio
 * @brief
 * @version 0.1
 * @date 2022-07-19
 *
 * @copyright Copyright (c) 2022
 *
 */

// Diretivas de compilação para controlar processo de inclusão.

#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

// Incluir cabeçalhos.

#include "./dominios.h"
#include <string>

using namespace std;

// Declaracao das classes entidade


/**
 * @brief Entidade Usuario: utiliza nome, email, senha, idioma, data e descricao para caracterizar o usuario - Feito por: Arthur Pereira Cardoso 211038191
 * 
 */
class Usuario
{
private:
    Nome nome;
    Email email;
    Senha senha;
    Idioma idioma;
    Data data;
    Descricao descricao;

public:
    void setEmail(const Email &);
    Email getEmail() const;
    void setNome(const Nome &);
    Nome getNome() const;
    void setSenha(const Senha &);
    Senha getSenha() const;
    void setIdioma(const Idioma &);
    Idioma getIdioma() const;
    void setData(const Data &);
    Data getData() const;
    void setDescricao(const Descricao &);
    Descricao getDescricao() const;
};

inline void Usuario::setEmail(const Email &email)
{
    this->email = email;
}

inline Email Usuario::getEmail() const
{
    return email;
}

inline void Usuario::setNome(const Nome &nome)
{
    this->nome = nome;
}

inline Nome Usuario::getNome() const
{
    return nome;
}

inline void Usuario::setSenha(const Senha &senha)
{
    this->senha = senha;
}

inline Senha Usuario::getSenha() const
{
    return senha;
}

inline void Usuario::setIdioma(const Idioma &idioma)
{
    this->idioma = idioma;
}

inline Idioma Usuario::getIdioma() const
{
    return idioma;
}

inline void Usuario::setData(const Data &data)
{
    this->data = data;
}

inline Data Usuario::getData() const
{
    return data;
}

inline void Usuario::setDescricao(const Descricao &descricao)
{
    this->descricao = descricao;
}

inline Descricao Usuario::getDescricao() const
{
    return descricao;
}


/**
 * @brief Entidade Hospedagem: utiliza codigo, cidade, pais, nota e descricao como feedback de uma hospedagem - Feito por: Lucas de Sa Gomes Licio 211043342
 * 
 */
class Hospedagem
{
private:
    Codigo codigo;
    Cidade cidade;
    Pais pais;
    Nota nota;
    Descricao descricao;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;
    void setCidade(const Cidade &);
    Cidade getCidade() const;
    void setPais(const Pais &);
    Pais getPais() const;
    void setNota(const Nota &);
    Nota getNota() const;
    void setDescricao(const Descricao &);
    Descricao getDescricao() const;
};

inline void Hospedagem::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline Codigo Hospedagem::getCodigo() const
{
    return codigo;
}

inline void Hospedagem::setCidade(const Cidade &cidade)
{
    this->cidade = cidade;
}

inline Cidade Hospedagem::getCidade() const
{
    return cidade;
}

inline void Hospedagem::setPais(const Pais &pais)
{
    this->pais = pais;
}

inline Pais Hospedagem::getPais() const
{
    return pais;
}

inline void Hospedagem::setNota(const Nota &nota)
{
    this->nota = nota;
}

inline Nota Hospedagem::getNota() const
{
    return nota;
}

inline void Hospedagem::setDescricao(const Descricao &descricao)
{
    this->descricao = descricao;
}

inline Descricao Hospedagem::getDescricao() const
{
    return descricao;
}


/**
 * @brief Entidade Avaliacao: utiliza codigo, nota e descricao inseridas por um usuario em determinada hospedagem - Feito por: Lucas de Sa Gomes Licio 211043342
 * 
 */
class Avaliacao
{
private:
    Codigo codigo;
    Nota nota;
    Descricao descricao;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;
    void setNota(const Nota &);
    Nota getNota() const;
    void setDescricao(const Descricao &);
    Descricao getDescricao() const;
};

inline void Avaliacao::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline Codigo Avaliacao::getCodigo() const
{
    return codigo;
}

inline void Avaliacao::setNota(const Nota &nota)
{
    this->nota = nota;
}

inline Nota Avaliacao::getNota() const
{
    return nota;
}

inline void Avaliacao::setDescricao(const Descricao &descricao)
{
    this->descricao = descricao;
}

inline Descricao Avaliacao::getDescricao() const
{
    return descricao;
}

#endif // ENTIDADES_H_INCLUDED
