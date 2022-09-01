#include "../Headers/controladorapresentacao.h"

void CntrApresentacaoControle::executar()
{

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Em producao";
    char texto5[] = "4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o.

    char texto9[] = "3 - Encerrar sessao.";

    char texto10[] = "Falha na autenticacao. Digite algo para continuar."; // Mensagem a ser apresentada.

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de la�o.

    while (apresentar)
    {

        // Apresenta tela inicial.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

        switch (campo)
        {
        case 1:
            if (cntrApresentacaoAutenticacao->autenticar(&email))
            { // Solicita autentica��o.
                cout << "autenticado" << endl;
                break;
            // case 2: cntrApresentacaoPessoal->cadastrar();
            //         break;
            // case 3: cntrApresentacaoProdutosFinanceiros->executar();
            //         break;
            case 4:
                apresentar = false;
                break;
            }
        }
        return;
    }
}

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