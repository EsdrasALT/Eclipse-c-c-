//FUNÇÕES - funcoes.c = https://codeshare.io/4YPo1d

#include "biblioteca.h"

void menuPrincipal(){
    Clientes *inicio = NULL;
    Clientes *fim = NULL;
    int codigoSequencial = 1;
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
            	menuInserir(&inicio, &fim, codigoSequencial);
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

void menuInserir(Clientes **inicio, Clientes **fim, int codigoSequencial){
    int opcao;
    printf("\nMenu Inserir:\n");
    printf("1 - Inserção de cliente\n");
    printf("2 - Inserção de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
        case 1:
        	inserirCliente(&inicio, &fim, codigoSequencial);
            break;
        case 2:
        	inserirPlaca(&inicio, codigoSequencial);
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


void inserirCliente(Clientes **inicio, Clientes **fim, int numeroSequencial){
	Clientes *novoCliente = criarCliente(numeroSequencial++);
    insereClienteFim(inicio, fim, novoCliente);


    for(int i=0;i<novoCliente->quantidadePlacas;i++){
		Carros *novoCarro = criaCarro(novoCliente,numeroSequencial++);
		insereCarroInicio(novoCliente, novoCarro);
    }

    printf("Cliente inserido com sucesso!\n");
}

void inserirPlaca(Clientes *inicio, int numeroSequencial){
    char clienteCodigo[8]; // Supondo que o código do cliente seja de até 7 caracteres + '\0'
    printf("Digite o codigo do cliente: ");
    scanf("%7s", clienteCodigo);
    //getchar();
    Clientes *cliente = encontraCliente(inicio, clienteCodigo);
    if (cliente == NULL) {
        printf("Cliente com codigo %s nao encontrado.\n", clienteCodigo);
    } else if (cliente->quantidadePlacas > MAX_CARROS){
    	printf("Espaço limite de carros atingindo.\n");
    } else {
		Carros *novoCarro = criaCarro(cliente, numeroSequencial++);
		insereCarroInicio(cliente, novoCarro);
    }
}

Clientes* criarCliente(int codigo){
    Clientes *novoCliente = (Clientes *)malloc(sizeof(Clientes));
    if (novoCliente == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    receberNomePreenchido(novoCliente);
    novoCliente->dataNascimento = solicitarDataDeNascimento(); //solicitarDataDeNascimento(&novoCliente->dataNascimento);
    verificarTipoContrato(novoCliente);
    quantidadePlacas(novoCliente);
    gerarCodigoSequencial(novoCliente, codigo);
    novoCliente->carros = NULL;
    novoCliente->anterior = NULL;
    novoCliente->proximo = NULL;
    return novoCliente;
}

void insereClienteFim(Clientes **inicio, Clientes **fim, Clientes *novoCliente){
	 if (*fim == NULL) { // Lista vazia
		*inicio = novoCliente;
		*fim = novoCliente;
	} else {
		(*fim)->proximo = novoCliente;
		novoCliente->anterior = *fim;
		*fim = novoCliente;
	}
}

Carros* criaCarro(Clientes *cliente,int numeroSequencial){
	Carros *novoCarro = (Carros*)malloc(sizeof(Carros));
	 if (novoCarro == NULL) {
		printf("Erro de alocação de memória!\n");
		exit(1);
	}

	chamarFuncoesPlacas(novoCarro);
	gerarCodigoSequencialCarro(novoCarro,cliente,numeroSequencial);
	receberMarcaOuModeloCarro(novoCarro);
	receberAnoCarro(novoCarro);
	novoCarro->proximo = NULL;

	return novoCarro;
}

void insereCarroInicio(Clientes *cliente, Carros *carro){
	carro->proximo = cliente->carros;
	cliente->carros = carro;
}

Clientes* encontraCliente(Clientes *inicio, char *codigoCliente) {
    Clientes *cliente = inicio;
    while (cliente != NULL) {
        if (strcmp(cliente->codigo, codigoCliente) == 0) {
            return cliente;
        }
        cliente = cliente->proximo;
    }
    return NULL;
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

DataNascimento* solicitarDataDeNascimento() {
	DataNascimento *novaData = (DataNascimento *)malloc(sizeof(DataNascimento));
	if (novaData == NULL) {
		printf("Erro de alocação de memória!\n");
		exit(1);
	}

	char data_str[11];

	int solicitarNovamente = 1;
	while (solicitarNovamente) {
		printf("Digite sua data de nascimento no formato DD/MM/AAAA: ");
		fgets(data_str, sizeof(data_str), stdin);
		data_str[strcspn(data_str, "\n")]  = '\0';

		*novaData = converterData(data_str);

		if (isDataValida(novaData->dia, novaData->mes, novaData->ano)) {
			int idade = verificarIdade(novaData->ano);
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
	printf("Data de nascimento válida: %02d/%02d/%d\n", novaData->dia, novaData->mes, novaData->ano);
	return novaData;
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

void gerarCodigoSequencial(Clientes *cliente, int numeroSequencial) {
    printf("Primeira letra do nome: %c\n", cliente->nome[0]);
    printf("Ano de nascimento: %d\n", cliente->dataNascimento->ano);
    printf("Número sequencial: %02d\n", numeroSequencial);

    char codigo[7];
    sprintf(codigo, "%c%d%02d", toupper(cliente->nome[0]), cliente->dataNascimento->ano, numeroSequencial);
    printf("Código sequencial gerado: %s\n", codigo);

    numeroSequencial++;
}

void verificarTipoContrato(Clientes *cliente){

	char tipoContrato;
	int contratoInvalido = 1;

	while(contratoInvalido){
		printf("Digite o tipo de contrato ( D - Diária | P - Parcial | M - Mensal): \n");
		scanf(" %c", &tipoContrato);
		if (tipoContrato == 'D' || tipoContrato == 'P' || tipoContrato == 'M') {
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
	printf("Quantidade de placas : %d\n", cliente->quantidadePlacas);
}

void chamarFuncoesPlacas(Carros *carro){
	char escolha;
	int placaInvalida = 1;
	while (placaInvalida){
		printf("Cadastro de placa modelo novo ou modelo antigo? (A - Antigo OU N - Novo)\n");
		scanf (" %c", &escolha);

		if (escolha == 'A' || escolha == 'N'){
			if (escolha == 'A'){
				placaInvalida = 0;
				validarPlacaAntiga(carro);
			} else {
				placaInvalida = 0;
				validarPlacaNova(carro);
			}
		} else {
			printf("Invalido\n");
		}
	}
}

void validarPlacaAntiga(Carros *carros) {
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
        strcpy(carros->placa, digitacao);
        placaInvalida = 0;

    } while (placaInvalida);
}

void validarPlacaNova(Carros *carros) {

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
        strcpy(carros->placa, digitacao);
        placaInvalida = 0;

    } while (placaInvalida);
}

void gerarCodigoSequencialCarro(Carros *carro, Clientes *cliente, int numeroSequencial){
	printf("Codigo do cliente: %s\n", cliente->codigo);
	printf("Número sequencial: %02d\n", numeroSequencial);

	strcpy(carro->codigoSequencial, cliente->codigo);

	char numeroSequencialString[3];
	sprintf(numeroSequencialString, "%02d", numeroSequencial);
	strcat(carro->codigoSequencial, numeroSequencialString);

	printf("Código sequencial gerado para o carro: %s\n", carro->codigoSequencial);

	numeroSequencial++;
}

void receberMarcaOuModeloCarro(Carros *carro) {
    int marcaEModeloInvalido = 1;
    int marca;
    int modelo;
    do {
        int marcaInvalida = 1;
        do {
            marca = mostrarMenuMarca();
            if (marca >= 1 && marca <= 3) {
                marcaInvalida = 0;
            } else {
                printf("Escolha dentre um dos modelos disponíveis\n");
            }
        } while (marcaInvalida);

        int modeloInvalido = 1;
        do {
            modelo = mostrarSubmenuModelos(marca);
            if (modelo >= 1 && modelo <= 3) {
                modeloInvalido = 0;
            } else {
                printf("Escolha dentre um dos modelos disponíveis\n");
            }
        } while (modeloInvalido);

        concatenarMarcaModelo(carro, marca, modelo);

        printf("Você escolheu: %s\n", carro->marcaModelo);
        marcaEModeloInvalido = 0;
    } while (marcaEModeloInvalido);
}

int mostrarMenuMarca() {
    int escolha;
    printf("Escolha uma marca:\n");
    printf("1. Toyota\n");
    printf("2. Ford\n");
    printf("3. Honda\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int mostrarSubmenuModelos(int marca) {
    int escolha;
    switch (marca) {
        case 1: // Toyota
            printf("Escolha um modelo de Toyota:\n");
            printf("1. Corolla\n");
            printf("2. Camry\n");
            printf("3. Prius\n");
            break;
        case 2: // Ford
            printf("Escolha um modelo de Ford:\n");
            printf("1. Fiesta\n");
            printf("2. Focus\n");
            printf("3. Mustang\n");
            break;
        case 3: // Honda
            printf("Escolha um modelo de Honda:\n");
            printf("1. Civic\n");
            printf("2. Accord\n");
            printf("3. CR-V\n");
            break;
        default:
            printf("Escolha inválida.\n");
            return 0;
    }
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void concatenarMarcaModelo(Carros *carro, int marca, int modelo) {
    char marcaTemporaria[15] = "";
    char modeloTemporario[15] = "";

    switch (marca) {
        case 1:
            strcpy(marcaTemporaria, "Toyota");
            switch (modelo) {
                case 1: strcpy(modeloTemporario, "Corolla"); break;
                case 2: strcpy(modeloTemporario, "Camry"); break;
                case 3: strcpy(modeloTemporario, "Prius"); break;
                default: strcpy(modeloTemporario, "Desconhecido"); break;
            }
            break;
        case 2:
            strcpy(marcaTemporaria, "Ford");
            switch (modelo) {
                case 1: strcpy(modeloTemporario, "Fiesta"); break;
                case 2: strcpy(modeloTemporario, "Focus"); break;
                case 3: strcpy(modeloTemporario, "Mustang"); break;
                default: strcpy(modeloTemporario, "Desconhecido"); break;
            }
            break;
        case 3:
            strcpy(marcaTemporaria, "Honda");
            switch (modelo) {
                case 1: strcpy(modeloTemporario, "Civic"); break;
                case 2: strcpy(modeloTemporario, "Accord"); break;
                case 3: strcpy(modeloTemporario, "CR-V"); break;
                default: strcpy(modeloTemporario, "Desconhecido"); break;
            }
            break;
        default:
            strcpy(marcaTemporaria, "Desconhecida");
            strcpy(modeloTemporario, "Desconhecido");
            break;
    }

    strcpy(carro->marcaModelo, marcaTemporaria);
    strcat(carro->marcaModelo, "-");
    strcat(carro->marcaModelo, modeloTemporario);
}

void receberAnoCarro(Carros *carro) {
    int ano;
    int anoInvalido = 1;
    do {
        printf("Digite o ano do carro (1950 - 2024): ");
        scanf("%d", &ano);
        if (ano >= 1950 && ano <= 2024) {
            carro->ano = ano;
            anoInvalido = 0;
        } else {
            printf("Ano inválido. Tente novamente.\n");
        }
    } while (anoInvalido);
    printf("Ano cadastrado: %d\n", carro->ano);
}

