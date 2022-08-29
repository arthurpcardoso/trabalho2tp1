#include "../Headers/dominios.h"
#include <string>
using namespace std;

// Metodos da classe Cidade

void Cidade::validar(string cidade)
{
    bool flag = false;
    for (int i = 0; i < qtdcidades; i++)
    {
        if (cidade == cidades[i])
        {
            flag = true;
        }
    }
    if (!flag)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Cidade::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Codigo

void Codigo::validar(string codigo)
{
    bool flag = true;
    for (int i = 0; i < codigo.size(); i++)
    {
        if (std::isdigit(codigo[i]) == 0)
        {
            flag = false;
        }
    }

    int nDigits = codigo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--)
    {

        int d = codigo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }

    if (nSum % 10 != 0)
    {
        flag = false;
    }

    if (!flag)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Codigo::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Data

void Data::validar(string data)
{
    bool flagmes = false;
    bool flagdia = true;
    int dia = stoi(data.substr(0, 2));
    for (int i = 0; i < 12; i++)
    {
        if (data.substr(3, data.length()) == meses[i])
        {
            flagmes = true;
        }
    }
    if (dia > Limite)
    {
        flagdia = false;
    }

    if (flagmes == false)
    {
        throw invalid_argument("Argumento invalido.");
    }
    else if (flagdia == false)
    {
        cout << "falha" << endl;
        throw invalid_argument("Argumento invalido.");
    }
}

void Data::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Descricao

void Descricao::validar(string descricao)
{
    bool flag = true;
    bool anteriorspace = false;
    bool anteriorpunct = false;
    if (descricao.length() > 40)
    {
        flag = false;
    }

    for (int i = 0; i < descricao.length(); i++)
    {
        if (isspace(descricao[i]))
        {
            if (anteriorspace)
            {
                flag = false;
            }
            else
            {
                anteriorspace = true;
            }
        }
        else if (ispunct(descricao[i]))
        {
            if (anteriorpunct)
            {
                flag = false;
            }
            else
            {
                anteriorpunct = true;
            }
        }
        else
        {
            anteriorspace = false;
            anteriorpunct = false;
        }
    }
    if (!flag)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Descricao::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Email

void Email::validar(string email)
{
    bool flag = true;
    size_t at_position = email.find('@');

    if (at_position == string::npos)
    {
        flag = false;
    }

    else
    {
        string parte_local = email.substr(0, at_position);
        string dominio = email.substr(at_position + 1, email.length());

        if (parte_local.length() > 64 || parte_local[0] == '.')
        {
            flag = false;
        }
        else
        {
            bool anterior = false;
            for (int i = 0; i < parte_local.length(); i++)
            {
                if (ispunct(parte_local[i]))
                {
                    if (anterior)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        anterior = true;
                    }
                }
                else
                {
                    anterior = false;
                }
            }
        }
        if (flag)
        {
            string delimitador = ".";
            size_t dot_position = 0;
            string termo;

            if (dominio[0] == '.')
            {
                flag = false;
            }

            bool anterior = false;

            for (int i = 0; i < dominio.length(); i++)
            {
                if (dominio[i] == '.')
                {
                    if (anterior)
                    {
                        flag = false;
                    }
                    else
                    {
                        anterior = true;
                    }
                }
                else
                {
                    anterior = false;
                }
            }

            if (flag)
            {
                while ((dot_position = dominio.find(delimitador)) != string::npos)
                {
                    termo = dominio.substr(0, dot_position);
                    if (termo[0] == '-' || termo[termo.length() - 1] == '-')
                    {
                        flag = false;
                    }
                    dominio.erase(0, dot_position + 1);
                }
                if (dominio[0] == '-' || dominio[dominio.length() - 1] == '-')
                {
                    flag = false;
                }
            }
        }
    }

    if (!flag)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Email::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Métodos da classe Idioma

void Idioma::validar(string valor)
{
    bool idiomaValido = false;
    for (int i = 0; i < quantidadeIdiomas; i++)
    {
        if (valor == idiomasPossiveis[i])
        {
            idiomaValido = true;
        }
    }
    if (!idiomaValido)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Idioma::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Nome

void Nome::validar(string valor)
{
    for (int i = 0; i < valor.length(); i++)
    {
        if (isspace(valor[i]))
        {
            posicaoEspaco = i;
        }
    }

    if (valor.length() <= 30)
    {
        string primeiroNome = valor.substr(0, (posicaoEspaco));
        for (int i = 0; i < primeiroNome.length(); i++)
        {
            if (!isalpha(primeiroNome[i]))
            {
                nomeValido = false;
            }
            else if ((i != 0) && (isupper(primeiroNome[i])))
            {
                nomeValido = false;
            }
            else if (islower(primeiroNome[0]))
            {
                nomeValido = false;
            }
        }
        string ultimoNome = valor.substr((posicaoEspaco + 1), valor.length());
        for (int i = 0; i < ultimoNome.length(); i++)
        {
            if (!isalpha(ultimoNome[i]))
            {
                nomeValido = false;
            }
            else if ((i != 0) && (isupper(ultimoNome[i])))
            {
                nomeValido = false;
            }
            else if (islower(ultimoNome[0]))
            {
                nomeValido = false;
            }
        }
        if (!nomeValido)
        {
            throw invalid_argument("Argumento invalido.");
        }
    }
}

void Nome::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Métodos da classe Nota

void Nota::validar(int valor)
{
    if ((valor < limiteInferior) || (valor > limiteSuperior))
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Nota::setValor(int valor)
{
    validar(valor);
    this->valor = valor;
}

// Métodos da classe Pais

void Pais::validar(string valor)
{
    bool paisValido = false;
    for (int i = 0; i < quantidadePaisesPossiveis; i++)
    {
        if (valor == paisesPossiveis[i])
        {
            paisValido = true;
        }
    }
    if (!paisValido)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Pais::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Metodos da classe Senha

void Senha::validar(string valor)
{
    if (tamanhoSenha != valor.length())
    {
        senhaValida = false;
    }

    for (int i = 0; i < tamanhoSenha; i++)
    {
        if (isupper(valor[i]))
        {
            temMaiuscula = true;
        }
        if (islower(valor[i]))
        {
            temMinuscula = true;
        }
        if (isdigit(valor[i]))
        {
            temDigito = true;
        }
    }

    for (int i = 0; i < tamanhoSenha; i++)
    {
        if (!isalnum(valor[i]))
        {
            if (valor[i] == caracteresEspeciais[0])
            {
                temCaracteresEspeciais = true;
            }
            else if (valor[i] == caracteresEspeciais[1])
            {
                temCaracteresEspeciais = true;
            }
            else if (valor[i] == caracteresEspeciais[2])
            {
                temCaracteresEspeciais = true;
            }
            else if (valor[i] == caracteresEspeciais[3])
            {
                temCaracteresEspeciais = true;
            }
            else if (valor[i] == caracteresEspeciais[4])
            {
                temCaracteresEspeciais = true;
            }
            else
            {
                temCaracteresInvalidos = true;
            }
        }
    }

    if (!temMaiuscula || !temMinuscula || !temDigito || !temCaracteresEspeciais || temCaracteresInvalidos)
    {
        senhaValida = false;
    }

    if (!senhaValida)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Senha::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}
