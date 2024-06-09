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
        	inserirCliente();
            break;
        case 2:
        	inserirPlaca();
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

void inserirCliente(){
	Clientes clientes;
	receberNomePreenchido(&clientes);
	DataNascimento solicitarDataDeNascimento();
	verificarTipoContrato();
}

void inserirPlaca(){
	chamarFuncoesPlacas();
}

void inserirFimUltimo(Carros **ultimoLista){
	Carros *novo = (Carros*) malloc (sizeof(Carros));

	//Exemplo
	strcpy(novo->placa, "ABCD123");
	strcpy(novo->codigoSequencial, "E1999011");
	strcpy(novo->marcaModelo, "Corsa");
	novo->ano = 2000;
	//Exemplo
	novo->proximoDaLista = NULL;

	if(*ultimoLista != NULL){
		(*ultimoLista)->proximoDaLista = novo;
	}

	(*ultimoLista) = novo;
}

void impressao(Carros *lista){
	if (lista != NULL) { 	// if (lista) {
		printf("Placa %s\n"
				"Codigo Sequencial -%s\n"
				"Marca Modelo - %s\n"
				"Ano - %d\n"
				"Endereço - %p\n"
				"Proximo - %p\n\n",
				lista->placa,lista->codigoSequencial,
				lista->marcaModelo,lista->ano,
				lista, lista->proximoDaLista);
		impressao(lista->proximoDaLista);
	}
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

//TODO IMPLEMENTAR PRIMERAS MAISCULAS O RESTO MINUSCULAS
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

//TODO CRIAR FUNCAO PARA CODIGO

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

//TODO IMPLEMENTAR VERIFICAÇÃO DE IDADE
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

void verificarTipoContrato(){

	Clientes clientes;
	char tipoContrato='Z';
	int contratoInvalido = 1;
	while(contratoInvalido){

		printf("Digite o tipo de contrato ( D - Diária | P - Parcial | M - Mensal): \n");
		scanf(" %c", &tipoContrato);

		if (tipoContrato == 'D' || tipoContrato == 'P' || tipoContrato == 'M') {
			printf("Tipo de contrato válido.\n");
			clientes.tipoContrato = tipoContrato;
			contratoInvalido = 0;
		} else {
			printf("Tipo de contrato inválido.\n");
		}
	}
}

void quantidadePlacas() {
	Clientes clientes;
	do {
		printf("Digite a quantidade de placas: ");
		scanf("%d", &clientes.quantidadePlacas);
		if (clientes.quantidadePlacas < 1) {
			printf("\nErro, você deve ter pelo menos 1 placa cadastrada\n");
		} else if (clientes.quantidadePlacas > MAX_CARROS) {
			printf("\nErro, 5 é o numero maximo de placas para cadastro\n");
		}
	} while (clientes.quantidadePlacas < 1 || clientes.quantidadePlacas > MAX_CARROS);
	printf("%d", clientes.quantidadePlacas);
}

void chamarFuncoesPlacas(){
	char escolha;
	int placaInvalida = 1;
	while (placaInvalida){
		printf("Cadastro de placa modelo novo ou modelo antigo? (A - Antigo OU N - Novo)\n");
		scanf (" %c", &escolha);

		if (escolha == 'A' || escolha == 'N'){
			if (escolha == 'A'){
				placaInvalida = 0;
				validarPlacaAntiga();
			} else {
				placaInvalida = 0;
				validarPlacaNova();
			}
		} else {
			printf("Invalido\n");
		}
	}
}

void validarPlacaAntiga() {
    Carros carros;
    char digitacao[9];
    int placaInvalida = 1;

    do {
        printf("Digite a placa seguindo o modelo antigo (exemplo: ABC1234): \n");
        scanf("%8s", digitacao);
        getchar();

        if (strlen(digitacao) != PLACA_LENGTH) {
            printf("Tamanho da placa incorreto, digite 7 caracteres.\n");
            continue;
        }
        int valido = 1;

        for (int i = 0; i < 3; i++) {
        	if (!isupper(digitacao[i])){ //== if (!(digitacao[i] >= 'A' && digitacao[i] <= 'Z')) {
                printf("Padrão incorreto na posição %d (os três primeiros devem ser letras maiúsculas)\n", i + 1);
                valido = 0;
                break;
            }
        }
        if (!valido) continue;

        for (int i = 3; i < PLACA_LENGTH; i++) {
            if (!isdigit(digitacao[i])){ // == if (!(digitacao[i] >= '0' && digitacao[i] <= '9')) {
                printf("Padrão incorreto na posição %d (os quatro últimos devem ser dígitos)\n", i + 1);
                valido = 0;
                break;
            }
        }
        if (!valido) continue;

        printf("Placa registrada: %s\n", digitacao);
        strcpy(carros.placa, digitacao);
        placaInvalida = 0;

    } while (placaInvalida);
}

void validarPlacaNova() {
    Carros carros;
    char digitacao[9];
    int placaInvalida = 1;

    do {
        printf("Digite a placa seguindo o modelo novo (exemplo: ABC1D23): \n");
        scanf("%8s", digitacao);
        getchar();

        if (strlen(digitacao) != PLACA_LENGTH) {
            printf("Tamanho da placa incorreto, digite 7 caracteres.\n");
            continue;
        }
        int valido = 1;

        //1° ao 3° caractere
        for (int i = 0; i < 3; i++) {
        	if (!isupper(digitacao[i])){
                printf("Padrão incorreto na posição %d (os três primeiros devem ser letras maiúsculas)\n", i + 1);
                valido = 0;
                break;
            }
        }
        if (!valido) continue;

        //4° caractere
        if (!isdigit(digitacao[3])){
			printf("Padrão incorreto(o 4° caractere deve ser digito)\n");
			valido = 0;
		}
        if (!valido) continue;

        //5° caractere
		if (!isupper(digitacao[4])){
			printf("Padrão incorreto (o 5° caractere deve ser letra)\n");
			valido = 0;
		}
        if (!valido) continue;

        //6° ao 7° caractere
        for (int i = 5; i < PLACA_LENGTH; i++) {
            if (!isdigit(digitacao[i])){
                printf("Padrão incorreto na posição %d (os dois últimos devem ser dígitos)\n", i + 1);
                valido = 0;
                break;
            }
        }
        if (!valido) continue;

        printf("Placa registrada: %s\n", digitacao);
        strcpy(carros.placa, digitacao);
        placaInvalida = 0;

    } while (placaInvalida);
}
