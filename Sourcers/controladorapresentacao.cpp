#include "../Headers/controladorapresentacao.h"

void CntrApresentacaoControle::executar()
{

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Listar hospedagens.";
    char texto5[] = "4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de selecao de servico.

    char texto9[] = "Aperte algum botão para continuar.";

    char texto10[] = "Falha na autenticacao.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela inicial.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; 
        cout << texto2 << endl; 
        cout << texto3 << endl; 
        cout << texto4 << endl; 
        cout << texto5 << endl; 

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            if (cntrApresentacaoAutenticacao->autenticar(&email))
            {
                cntrApresentacaoPessoal->executar(email);
                break;
            }
            else
            {
                CLR_SCR;                 // Limpa janela.
                cout << texto10 << endl;
                cout << texto9 << endl;
                getch();                 // Leitura de caracter digitado.
            }
            break;
        case 2:
            cntrApresentacaoPessoal->cadastrar();
            break;
        case 3:
            CLR_SCR;
            cout << "Em producao" << endl;
            cout << texto9 << endl;
            getch();
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

    // Mensagens a serem apresentadas na tela de autenticacao.

    char texto1[] = "Digite o Email: ";
    char texto2[] = "Digite a senha: ";
    char texto3[] = "Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha; // Instancia a classe Senha.

    while (true)
    {

        // Apresenta tela de autenticacao.

        CLR_SCR; // Limpa janela.

        cout << texto1 << " "; // Imprime nome do campo.
        cin >> campo1;         // Le valor do campo.
        cout << texto2 << " "; // Imprime nome do campo.
        cin >> campo2;         // Le valor do campo.

        try
        {
            email->setValor(string(campo1)); // Atribui valor ao email.
            senha.setValor(string(campo2));  // Atribui Valor a senha.
            break;                           // Abandona laco em caso de formatos corretos.
        }
        catch (invalid_argument &exp)
        {                           // Captura excecao devido a formato incorreto.
            CLR_SCR;                // Limpa janela.
            cout << texto3 << endl; // Informa formato incorreto.
            getch();                // Le caracter digitado.
        }
    }
    return (cntr->autenticar(*email, senha)); // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::executar(Email email)
{

    // Mensagens a serem apresentadas na tela de selecao de servico..

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar dados pessoais.";
    char texto3[] = "2 - Consultar suas hospedagens.";
    char texto4[] = "3 - Consultar suas avaliacoes";
    char texto5[] = "4 - Retornar";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela de selacao de servico.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            consultarDadosPessoais();
            break;
        case 2:
            cntrApresentacaoHospedagem->executar();
            break;
        case 3:
            cntrApresentacaoAvaliacao->executar();
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::cadastrar()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Nome            :";
    char texto3[] = "Email           :";
    char texto4[] = "Senha           :";
    char texto5[] = "Idioma          :";
    char texto6[] = "Aniversario     :";
    char texto7[] = "Descricao       :";
    char texto8[] = "Dados em formato incorreto. Digite algo.";
    char texto9[] = "Sucesso no cadastramento. Digite algo.";
    char texto10[] = "Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.

    Nome nome;
    Email email;
    Senha senha;
    Idioma idioma;
    Data data;
    Descricao descricao;


    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; 
    cout << texto2 << " ";  
    cin.getline(campo1, sizeof(campo1));
    cout << texto3 << " "; 
    cin >> campo2;         
    cout << texto4 << " "; 
    cin >> campo3;
    cout << texto5 << " "; 
    cin >> campo4;    
    cout << texto6 << " "; 
    cin >> campo5;       
    cout << texto7 << " ";
    cin >> campo6;
    //cin.getline(campo6, sizeof(campo6));

    try
    {
        nome.setValor(string(campo1));
        email.setValor(string(campo2));
        senha.setValor(string(campo3));
        idioma.setValor(string(campo4));
        data.setValor(string(campo5));
        descricao.setValor(string(campo6));
    }
    catch (invalid_argument &exp)
    {
        cout << texto8 << endl; // Informa formato incorreto.
        getch();                 // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setIdioma(idioma);
    usuario.setData(data);
    usuario.setDescricao(descricao);

    // Cadastra usuario e conta.

    if (cntrServicoPessoal->cadastrarUsuario(usuario))
    {
        cout << texto9 << endl; // Informa sucesso.
        getch();
        return;
    }

    cout << texto10 << endl; // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::consultarDadosPessoais()
{

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    char texto[] = "Servico consultar dados pessoais nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                          // Limpa janela.
    cout << texto << endl;                                                            // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------
/*
void CntrApresentacaoHospedagem::executar()
{

    // Mensagens a serem apresentadas na tela de selecao de servico..

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Cadastrar hospedagem.";
    char texto3[] = "2 - Editar hospedagem.";
    char texto4[] = "3 - Descadastrar hospedagem";
    char texto5[] = "4 - Retornar";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela de selacao de servico.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            cout << "Em producao" << endl;
            break;
        case 2:
            cout << "Em producao" << endl;
            break;
        case 3:
            cout << "Em producao" << endl;
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar()
{

    // Mensagens a serem apresentadas na tela de selecao de servico..

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar avaliacao.";
    char texto3[] = "2 - Editar avaliacao.";
    char texto4[] = "3 - Descadastrar avaliacao";
    char texto5[] = "4 - Retornar";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela de selacao de servico.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            cout << "Em producao" << endl;
            break;
        case 2:
            cout << "Em producao" << endl;
            break;
        case 3:
            cout << "Em producao" << endl;
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
}
*/