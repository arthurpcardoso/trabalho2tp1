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
            }
            else
            {
                CLR_SCR;                 // Limpa janela.
                cout << texto10 << endl; // Imprime mensagem.
                getch();                 // Leitura de caracter digitado.
            }
            break;
        case 2:
            cntrApresentacaoPessoal->cadastrar();
            break;
        case 3:
            cout << "Em producao" << endl;
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
    return;
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

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::cadastrar()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Nome            :";
    char texto3[] = "Email           :";
    char texto6[] = "Senha           :";
    char texto10[] = "Dados em formato incorreto. Digite algo.";
    char texto11[] = "Sucesso no cadastramento. Digite algo.";
    char texto12[] = "Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo5[80]; // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Email email;
    Senha senha;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl;              // Imprime solicita��o ao usu�rio.
    cout << texto2 << " ";               // Imprime nome do campo.
    cin.getline(campo1, sizeof(campo1)); // L� valor do campo composto.

    cout << "Valor lido" << campo1 << " ";

    cout << texto3 << " "; // Imprime nome do campo.
    cin >> campo2;         // L� valor do campo.
    cout << texto6 << " "; // Imprime nome do campo.
    cin >> campo5;         // L� valor do campo.

    try
    {
        nome.setValor(string(campo1));
        email.setValor(string(campo2));
        senha.setValor(string(campo5));
    }
    catch (invalid_argument &exp)
    {
        cout << texto10 << endl; // Informa formato incorreto.
        getch();                 // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);

    // Cadastra usu�rio e conta.

    if (cntrServicoPessoal->cadastrarUsuario(usuario))
    {
        cout << texto11 << endl; // Informa sucesso.
        getch();
        return;
    }

    cout << texto12 << endl; // Informa falha.
    getch();

    return;
}
