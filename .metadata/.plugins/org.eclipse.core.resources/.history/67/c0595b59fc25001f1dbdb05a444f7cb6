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
	Clientes cliente;
	DataNascimento dataNascimento;
	int numeroSequencial = 1;

	receberNomePreenchido(&cliente);
	solicitarDataDeNascimento(&dataNascimento);
    gerarCodigoSequencial(&cliente, &dataNascimento, &numeroSequencial);
    verificarTipoContrato(&cliente);
    quantidadePlacas(&cliente);
}

void inserirPlaca(){
	Carros carro;
	Clientes cliente;
	int numeroSequencial = 1;

	chamarFuncoesPlacas();
	//gerarCodigoSequencialCarro(&carro,&cliente,&numeroSequencial);
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

void receberNomePreenchido(Clientes *cliente) { //chamada da função: receberNomePreenchido(&cliente);

	printf("Digite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; // Remover o caractere de enter (nova linha lido pelo fgets)

    formatarNomeRecursiva(cliente->nome,0,1);
	printf("Nome formatado: %s\n", cliente->nome);
}

void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego) {
	if (nome[indice] == '\0') {
		return; // Caso base: fim da string
	}

	// Converter para maiúscula se for a primeira letra de uma palavra
	if (caractereDeveSerPego && isalpha(nome[indice])) { //A função isalpha é uma função da biblioteca <ctype.h> que verifica
		nome[indice] = toupper(nome[indice]);         //se o caractere fornecido é uma letra alfabética (a-z ou A-Z)
	} else {
		nome[indice] = tolower(nome[indice]);
	}

	// Verificar se o próximo caractere deve ser capitalizado
	if (nome[indice] == ' ') {
		caractereDeveSerPego = 1; //SIM
	} else {
		caractereDeveSerPego = 0; //NÃO
	}

	// Chamada recursiva para o próximo caractere
	formatarNomeRecursiva(nome, indice + 1, caractereDeveSerPego);
}

void solicitarDataDeNascimento(DataNascimento *dataNascimento){
	char data_str[11];

	int solicitarNovamente = 1;
	while (solicitarNovamente) {
		printf("Digite sua data de nascimento no formato DD/MM/AAAA: ");
		fgets(data_str, sizeof(data_str), stdin);
		data_str[strcspn(data_str, "\n")]  = '\0';

		*dataNascimento = converterData(data_str);

		if (isDataValida(dataNascimento->dia, dataNascimento->mes, dataNascimento->ano)) {
			int idade = verificarIdade(dataNascimento->ano);
			if (idade < 18 || idade > 100) {
				printf("Idade menor que 18 ou maior que 100\n");
				solicitarNovamente = 1; // Solicitar novamente
			} else {
				printf("Idade apta\n");
				solicitarNovamente = 0; // Saída do loop
			}
		} else {
			printf("Formato de data incorreto.\n");
		}
	}
	printf("Data de nascimento válida: %02d/%02d/%d\n", dataNascimento->dia, dataNascimento->mes, dataNascimento->ano);
}

DataNascimento converterData(char *data_string) {
    DataNascimento data;
    sscanf(data_string, "%d/%d/%d",
    		&data.dia, &data.mes, &data.ano);
    return data;
}

int verificarIdade(int ano) {
    int idade = 2024 - ano;
    return idade;
}

int isAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int isDataValida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12) return 0;

    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mes == 2 && isAnoBissexto(ano)) {
        diasNoMes[1] = 29;
    }

    return dia >= 1 && dia <= diasNoMes[mes - 1];
}

void gerarCodigoSequencial(Clientes *cliente, DataNascimento *dataNascimento, int *numeroSequencial) {
    printf("Primeira letra do nome: %c\n", cliente->nome[0]);
    printf("Ano de nascimento: %d\n", dataNascimento->ano);
    printf("Número sequencial: %02d\n", *numeroSequencial);

    char codigo[7];
    sprintf(codigo, "%c%d%02d", toupper(cliente->nome[0]), dataNascimento->ano, *numeroSequencial);
    printf("Código sequencial gerado: %s\n", codigo);

    (*numeroSequencial)++;
}

void verificarTipoContrato(Clientes *cliente){

	char tipoContrato;
	int contratoInvalido = 1;

	while(contratoInvalido){
		printf("Digite o tipo de contrato ( D - Diária | P - Parcial | M - Mensal): \n");
		scanf(" %c", &tipoContrato);
		if (tipoContrato == 'D' || tipoContrato == 'P' || tipoContrato == 'M') {
			printf("Tipo de contrato válido.\n");
			cliente->tipoContrato = tipoContrato;
			contratoInvalido = 0;
		} else {
			printf("Tipo de contrato inválido.\n");
		}
	}
    printf("Tipo de contrato selecionado: %c\n", cliente->tipoContrato);
}

void quantidadePlacas(Clientes *cliente){

	do {
		printf("Digite a quantidade de placas: ");
		scanf("%d", &cliente->quantidadePlacas);
		if (cliente->quantidadePlacas < 1) {
			printf("\nErro, você deve ter pelo menos 1 placa cadastrada\n");
		} else if (cliente->quantidadePlacas > MAX_CARROS) {
			printf("\nErro, 5 é o numero maximo de placas para cadastro\n");
		}
	} while (cliente->quantidadePlacas < 1 || cliente->quantidadePlacas > MAX_CARROS);
	printf("%d", cliente->quantidadePlacas);
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

void gerarCodigoSequencialCarro(Carros *carro,Clientes *cliente, int *numeroSequencial){
	printf("Primeira letra do nome: %s\n", cliente->codigo);
	printf("Número sequencial: %02d\n", *numeroSequencial);

	strcpy(carro->codigoSequencial, cliente->codigo);

	char numeroSequencialString[3];
	sprintf(numeroSequencialString, "%02d", *numeroSequencial);
	strcat(carro->codigoSequencial, numeroSequencialString);

	printf("Código sequencial gerado para o carro: %s\n", carro->codigoSequencial);

	(*numeroSequencial)++;
}

