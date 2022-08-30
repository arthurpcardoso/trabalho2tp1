#include "../Headers/controladorapresentacao.h"

bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[] = "Digite o Email: ";
    char texto2[] = "Digite a senha: ";
    char texto3[] = "Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha; // Instancia a classe Senha.

    while (true)
    {

        // Apresenta tela de autentica��o.

        CLR_SCR; // Limpa janela.

        cout << texto1 << " "; // Imprime nome do campo.
        cin >> campo1;         // L� valor do campo.
        cout << texto2 << " "; // Imprime nome do campo.
        cin >> campo2;         // L� valor do campo.

        try
        {
            email->setValor(string(campo1)); // Atribui valor ao CPF.
            senha.setValor(string(campo2));  // Atribui Valor � senha.
            break;                           // Abandona la�o em caso de formatos corretos.
        }
        catch (invalid_argument &exp)
        {                           // Captura exce��o devido a formato incorreto.
            CLR_SCR;                // Limpa janela.
            cout << texto3 << endl; // Informa formato incorreto.
            getch();                // L� caracter digitado.
        }
    }
    return (cntr->autenticar(*email, senha)); // Solicita servi�o de autentica��o.
}