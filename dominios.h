/**
 * @file dominios.h
 * @author Arthur Pereira Cardoso e Lucas de Sa Gomes Licio
 * @brief
 * @version 0.1
 * @date 2022-07-19
 *
 * @copyright Copyright (c) 2022
 *
 */

// Diretivas de compilação para controlar processo de inclusão.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

// Incluir cabeçalhos.

#include <stdexcept>
#include <iostream>

using namespace std;

// Declaracao das classes dominio

/**
 * @brief Dominio Cidade: valida e armazena a cidade onde a hospedagem esta localizada - Dominio feito por: Arthur Pereira Cardoso 211038191
 *
 */
class Cidade
{
private:
    string cidades[18] = {"Rio de Janeiro", "Sao Paulo", "Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Seul", "Instambul", "Kuala Lumpur", "Osaka", "Phuket", "Shenzhen", "Toquio"};
    string valor; // Atributo para armazenar valor.
    const static int qtdcidades = 18;
    void validar(string); // Método para validar valor.
public:
    void setValor(string);   // Método para atribuir valor.
    string getValor() const; // Método para recuperar valor.
};

inline string Cidade::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Codigo: valida e armazena o codigo com o algoritmo de Luhn - Feito por: Arthur Pereira Cardoso 211038191
 *
 */
class Codigo
{
private:
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Codigo::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Data: valida e armazena a data, composta por dia e mes - Feito por: Arthur Pereira Cardoso 211038191
 *
 */
class Data
{
private:
    string valor;
    string meses[12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Aug", "Set", "Out", "Nov", "Dez"};
    const static int Limite = 31;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Data::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Descricao: valida e armazena a descricao dada pelo usuario a hospedagem- Feito por: Arthur Pereira Cardoso 211038191
 *
 */
class Descricao
{
private:
    string valor;
    const static int Limite = 40;
    string caracteres_especiais[8] = {".", "?", ";", ",", "-", " ", "!", ":"};
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Descricao::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Email: valida e armazena o email utilizado no cadastro dok usuario - Feito por Arthur Pereira Cardoso 211038191
 *
 */
class Email
{
private:
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Email::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Idioma: valida e armazena o idioma indicado pelo usuario - Feito por Lucas de Sa Gomes Licio 211043342
 *
 */
class Idioma
{
private:
    static const int quantidadeIdiomas = 10;
    string idiomasPossiveis[10] = {"Ingles", "Chines", "Mandarim", "Hindi", "Espanhol", "Frances", "Arabe", "Bengali", "Russo", "Portugues"};
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Idioma::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Nome: valida e armazena o nome do usuário - Feito por Lucas de Sa Gomes Licio 211043342
 *
 */
class Nome
{
private:
    string valor;
    int posicaoEspaco;
    bool nomeValido = true;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Nome::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Nota: valida e armazena a nota dada pelo usuario a hospedagem - Feito por Lucas de Sa Gomes Licio 211043342
 *
 */
class Nota
{
private:
    static const int limiteInferior = 0;
    static const int limiteSuperior = 10;
    int valor;
    void validar(int);

public:
    void setValor(int);
    int getValor() const;
};

inline int Nota::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Pais: valida e armazena o pais onde está localizada a hospedagem - Feito por Lucas de Sa Gomes Licio 211043342
 *
 */
class Pais
{
private:
    static const int quantidadePaisesPossiveis = 12;
    string paisesPossiveis[12] = {"Estados Unidos", "Brasil", "China", "Coreia do sul", "Emirados", "Franca", "India", "Japao", "Malasia", "Reino Unido", "Tailandia", "Turquia"};
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Pais::getValor() const
{
    return valor;
}

/**
 * @brief Dominio Senha: valida e armazena a senha do usuario - Feito por Lucas de Sa Gomes Licio 211043342
 *
 */
class Senha
{
private:
    string valor;
    static const int tamanhoSenha = 5;
    bool senhaValida = true;
    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;
    bool temCaracteresEspeciais = false;
    string caracteresEspeciais = "!#$%&";
    bool temCaracteresInvalidos = false;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Senha::getValor() const
{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
