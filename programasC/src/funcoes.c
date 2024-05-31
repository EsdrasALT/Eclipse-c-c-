//FUNÇÕES - funcoes.c = https://codeshare.io/4YPo1d

#include "biblioteca.h"

void menuPrincipal(){
    char opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("A - Inserir (cliente e placa)\n");
        printf("B - Excluir (cliente e placa)\n");
        printf("C - Relatórios\n");
        printf("D - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar(); // Limpar buffer

        switch(opcao) {
            case 'A':
            	menuInserir();
                break;
            case 'B':
            	menuExcluir();
                break;
            case 'C':
            	menuRelatorios();
                break;
            case 'D':
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 'D');
}

void menuInserir(){
    int opcao;
    printf("\nMenu Inserir:\n");
    printf("1 - Inserção de cliente\n");
    printf("2 - Inserção de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
          //  inserir_cliente();
            break;
        case 2:
            //inserir_placa();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuExcluir(){
    int opcao;
    printf("\nMenu Excluir:\n");
    printf("1 - Exclusão de cliente\n");
    printf("2 - Exclusão de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            //excluir_cliente();
            break;
        case 2:
            //excluir_placa();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuRelatorios(){
    int opcao;
    printf("\nMenu Relatórios:\n");
    printf("1 - Listar todos os clientes cadastrados (e seus carros)\n");
    printf("2 - Listar dados do cliente por código (dados e carros)\n");
    printf("3 - Listar clientes por tipo de contrato\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            //listar_todos_clientes();
            break;
        case 2:
            //listar_cliente_por_codigo();
            break;
        case 3:
            //listar_clientes_por_contrato();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

DataNascimento solicitarDataDeNascimento() {
	char data_str[11];
	DataNascimento data;

	int formato_incorreto = 1;
	while (formato_incorreto) {
		printf("Digite sua data de nascimento no formato MM/DD/AAAA: ");
		scanf("%10s", data_str);

		data = converterData(data_str);

		if (data.dia >= 1 && data.dia <= 31 && data.mes >= 1 && data.mes <= 12 && data.ano >= 1900 && data.ano <= 2024) {
			formato_incorreto = 0; // Saida do loop
		} else {
			printf("Formato incorreto. Por favor, insira a data no formato correto.\n");
		}
	}

    printf("Data de nascimento válida: %02d/%02d/%d\n", data.mes, data.dia, data.ano);
	return data;
}

DataNascimento converterData(char *data_string) {
    DataNascimento data;
    sscanf(data_string, "%d/%d/%d",
    		&data.dia, &data.mes, &data.ano);
    return data;
}

//TO-DO IMPLEMENTAR VERIFICAÇÃO DE IDADE
int verificarIdade(DataNascimento data_nascimento) {
    // Obter a data atual
    DataNascimento data_atual;
    // Suponha que a data atual seja 30/12/2024 para fins de exemplo
    data_atual.dia = 30;
    data_atual.mes = 12;
    data_atual.ano = 2024;

    // Calcular a idade
    int idade = data_atual.ano - data_nascimento.ano;
    if (data_atual.mes < data_nascimento.mes || (data_atual.mes == data_nascimento.mes && data_atual.dia < data_nascimento.dia)) {
        idade--; // Ainda não fez aniversário neste ano
    }
    return idade;
}

void receberNomePreenchido(Clientes *cliente) {
    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);

    if (cliente->nome[strlen(cliente->nome) - 1] == '\n') {
        cliente->nome[strlen(cliente->nome) - 1] = '\0';
    }

    printf("Nome formatado: %s\n", cliente->nome);
    formatarNomeRecursiva(cliente->nome);

    printf("Nome formatado: %s\n", cliente->nome);
}

//TO-DO IMPLEMENTAR PRIMERAS MAISCULAS O RESTO MINUSCULAS
void formatarNomeRecursiva(char *nome) {

    printf("Nome formatado: %s\n", nome);
	if (*nome == '\0') {
        return;
    }

    if (*nome == ' ') {
    	formatarNomeRecursiva(nome + 1);
    }
    else if (isalpha(*nome)) {
        *nome = toupper(*nome);
        formatarNomeRecursiva(nome + 1);
    }
}

void inicializarCliente(Clientes *cliente) {
    cliente->quantidadePlacas = 0;
    for(int i = 0; i < MAX_CARROS; i++) {
        cliente->carros[i] = NULL;
    }
}

void adicionarCarro(Clientes *cliente, const char *placa, int ano) {
    if (cliente->quantidadePlacas < MAX_CARROS) {
    	Carros *novoCarro = (Carros *)malloc(sizeof(Carros));
        strncpy(novoCarro->placa, placa, sizeof(novoCarro->placa) - 1);
        novoCarro->placa[sizeof(novoCarro->placa) - 1] = '\0';
        novoCarro->ano = ano;
        cliente->carros[cliente->quantidadePlacas] = novoCarro;
        cliente->quantidadePlacas++;
    } else {
        printf("Número máximo de carros atingido.\n");
    }
}

void exibirCliente(const Clientes *cliente) {
    printf("Cliente possui %d carros cadastrados:\n", cliente->quantidadePlacas);
    for(int i = 0; i < cliente->quantidadePlacas; i++) {
        printf("Carro %d: Placa: %s, Ano: %d\n", i+1, cliente->carros[i]->placa, cliente->carros[i]->ano);
    }
}



//TO-DO
//TIPO DE CONTRATO
//A) Criar a funcao verificarTipoContrato()


//TO-DO
//PLACA
//A) Criar a funcao validarPlaca(char *placa)
//B) Verificar se placa = 3 letras + 4 numeros (tamanho)
//C) Verificar 3 primeiros são letras e 4 ultimos são numeros

