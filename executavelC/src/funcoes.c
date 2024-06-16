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
                menuInserir(&inicio, &fim, &codigoSequencial);
                break;
            case 'B':
                menuExcluir(&inicio);
                break;
            case 'C':
                menuRelatorios(inicio);
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

void menuInserir(Clientes **inicio, Clientes **fim, int *codigoSequencial){
    int opcao;
    printf("\nMenu Inserir:\n");
    printf("1 - Inserção de cliente\n");
    printf("2 - Inserção de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
        case 1:
            inserirCliente(inicio, fim, codigoSequencial);
            break;
        case 2:
            inserirPlaca(inicio, codigoSequencial);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuExcluir(Clientes **inicio){
    int opcao;
    printf("\nMenu Excluir:\n");
    printf("1 - Exclusão de cliente\n");
    printf("2 - Exclusão de placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            excluirCliente(inicio);
            break;
        case 2:
            excluirPlaca(inicio);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void menuRelatorios(Clientes *inicio){
    int opcao;
    printf("\nMenu Relatórios:\n");
    printf("1 - Listar todos os clientes cadastrados (e seus carros)\n");
    printf("2 - Listar dados do cliente por código (dados e carros)\n");
    printf("3 - Listar clientes por tipo de contrato\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            listarTodosClientes(inicio);
            break;
        case 2:
        	listarClientePorCodigo(inicio);
            break;
        case 3:
            listarClientesPorContrato(inicio);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void inserirCliente(Clientes **inicio, Clientes **fim, int *numeroSequencial){
    Clientes *novoCliente = criarCliente(inicio, fim, numeroSequencial);

    for(int i=0; i < novoCliente->quantidadePlacas; i++){
        criaCarro(novoCliente, numeroSequencial);
    }
}

Clientes* criarCliente(Clientes **inicio, Clientes **fim, int *codigo){
    Clientes *novoCliente = (Clientes *)malloc(sizeof(Clientes));
    if (novoCliente == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    receberNomePreenchido(novoCliente);
    solicitarDataDeNascimento(novoCliente);
    verificarTipoContrato(novoCliente);
    quantidadePlacas(novoCliente);
    gerarCodigoSequencial(novoCliente, (*codigo));

    novoCliente->carros = NULL;
    novoCliente->anterior = NULL;
    novoCliente->proximo = NULL;

    if (*fim == NULL) {
        *inicio = novoCliente;
        *fim = novoCliente;
    } else {
        (*fim)->proximo = novoCliente;
        novoCliente->anterior = *fim;
        *fim = novoCliente;
    }
    return novoCliente;
}

Carros* criaCarro(Clientes *cliente, int *codigo){
    if (cliente->quantidadePlacas > MAX_CARROS) {
        printf("Número máximo de placas atingido.\n");
        return NULL;
    }

	Carros *novoCarro = (Carros*)malloc(sizeof(Carros));
    if (novoCarro == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    chamarFuncoesPlacas(novoCarro);
    gerarCodigoSequencialCarro(novoCarro, cliente, (*codigo)++);
    receberMarcaModeloCarro(novoCarro);
    receberAnoCarro(novoCarro);
    novoCarro->proximo = cliente->carros;
    cliente->carros = novoCarro;

    return novoCarro;
}

void inserirPlaca(Clientes **inicio, int *numeroSequencial) {
    char codigoCliente[10];
    printf("Digite o código do cliente para adicionar a placa: ");
    scanf("%s", codigoCliente);

    Clientes *cliente = buscarClientePorCodigo(*inicio, codigoCliente);
    if (cliente != NULL) {
    	if (cliente->quantidadePlacas >= MAX_CARROS){
    		printf("Quantidade maxima de carros permitida\n");
    		return;
    	} else {
    		criaCarro(cliente, numeroSequencial);
    	}
    } else {
        printf("Cliente não encontrado.\n");
    }
}

char* buscarCodigo(char* mensagem) {
    char digitacao[8];
    printf("%s", mensagem);
    fgets(digitacao, sizeof(digitacao), stdin);
    getchar();

    char* codigo = malloc((strlen(digitacao) + 1) * sizeof(char));
    if (codigo == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }

    strcpy(codigo, digitacao);
    return codigo;
}

Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente) {
    Clientes *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigoCliente) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void imprimeCarroRecursivo(Carros *carro, int numCarro) {
    if (carro == NULL) {
        return;
    }

    printf("   Carro %d:\n", numCarro);
    printf("   Placa: %s\n", carro->placa);
    printf("   Codigo: %s\n", carro->codigoSequencial);
    printf("   Modelo: %s\n", carro->marcaModelo);
    printf("   Ano: %d\n", carro->ano);
    printf("   ----------------------------\n");

    imprimeCarroRecursivo(carro->proximo, numCarro + 1);
}

void imprimeClienteRecursivo(Clientes *cliente, int numCliente) {
    if (cliente == NULL) {
        return;
    }

    printf("=====================================\n");
    printf("           Cliente %d                \n", numCliente);
    printf("=====================================\n");
    printf("Nome: %s\n", cliente->nome);
    printf("Data de nascimento válida: %02d/%02d/%d\n",
            cliente->dataNascimento->dia,
            cliente->dataNascimento->mes,
            cliente->dataNascimento->ano);
    printf("Contrato: %c\n", cliente->tipoContrato);
    printf("Codigo: %s\n", cliente->codigo);
    printf("Quantidade de Carros: %d\n", cliente->quantidadePlacas);
    printf("-------------------------------------\n");

    imprimeCarroRecursivo(cliente->carros, 1);
    printf("\n");

    imprimeClienteRecursivo(cliente->proximo, numCliente + 1);
}

void listarTodosClientes(Clientes *inicio) {
    imprimeClienteRecursivo(inicio, 1);
}

void listarClientePorCodigo(Clientes *inicio) {
    getchar();
    char *codigoCliente = buscarCodigo("Digite o código do cliente: ");
    Clientes *cliente = buscarClientePorCodigo(inicio, codigoCliente);

    if (cliente != NULL) {
        imprimeClienteRecursivo(cliente, 1); // Imprime os detalhes do cliente e carros
    } else {
        printf("Cliente com código %s não encontrado.\n", codigoCliente);
    }

    free(codigoCliente);
}

void listarClientesPorContrato(Clientes *inicio) {
    char tipoContrato;
    int contratoInvalido = 1;

    while (contratoInvalido) {
        printf("Digite o tipo de contrato para listar (D - Diária, P - Parcial, M - Mensal): ");
        scanf(" %c", &tipoContrato);

        if (tipoContrato == 'D' || tipoContrato == 'P' || tipoContrato == 'M') {
            contratoInvalido = 0;
        } else {
            printf("Tipo de contrato inválido.\n");
        }
    }

    Clientes *cliente = inicio;
    int encontrados = 0;

    while (cliente != NULL) {
        if (cliente->tipoContrato == tipoContrato) {
            imprimeClienteRecursivo(cliente, encontrados + 1);
            encontrados++;
        }
        cliente = cliente->proximo;
    }

    if (encontrados == 0) {
        printf("Nenhum cliente encontrado com o tipo de contrato %c.\n", tipoContrato);
    }
}

void excluirCliente(Clientes **inicio) {
    char codigoCliente[10];
    int clienteValido = 0;

    do {
        printf("Digite o código do cliente para excluir: ");
        scanf("%9s", codigoCliente);

        Clientes *atual = *inicio;
        while (atual != NULL) {
            if (strcmp(atual->codigo, codigoCliente) == 0) {
                clienteValido = 1;

                if (atual->anterior != NULL) {
                    atual->anterior->proximo = atual->proximo;
                } else {
                    *inicio = atual->proximo;
                }
                if (atual->proximo != NULL) {
                    atual->proximo->anterior = atual->anterior;
                }

                Carros *carro = atual->carros;
                while (carro != NULL) {
                    Carros *tempCarro = carro;
                    carro = carro->proximo;
                    free(tempCarro);
                }
                free(atual);
                printf("Cliente excluído com sucesso.\n");
                return;
            }
            atual = atual->proximo;
        }
        printf("Cliente com código '%s' não encontrado. Digite novamente.\n", codigoCliente);
    } while (!clienteValido);

}

void excluirPlaca(Clientes **inicio) {
    char codigoCarro[10];
    int placaValida = 0;
	Clientes *anterior = NULL;
	Clientes *clienteAtual = *inicio;

	if (clienteAtual->quantidadePlacas <= 1){
		printf("O Cliente so possui um carro cadastrado, não podendo ficar com 0\n");
		excluirCliente(inicio);
		return;
	}

    do {
    	printf("Digite o codigo do carro: ");
        scanf("%9s", codigoCarro);

        while (clienteAtual != NULL) {
            Carros *carroAtual = clienteAtual->carros;

            while (carroAtual != NULL) {
                if (strcmp(carroAtual->codigoSequencial, codigoCarro) == 0) {
                    anterior = clienteAtual;
                    placaValida = 1;
                    break;
                }
                carroAtual = carroAtual->proximo;
            }
            if (placaValida) {
                break;
            }
            clienteAtual = clienteAtual->proximo;
        }
        if (!placaValida) {
            printf("Carro com a placa '%s' não encontrado. Digite novamente.\n", codigoCarro);
        }
    } while (!placaValida);

    if (placaValida) {
        Carros *carro = anterior->carros;
        while (carro != NULL) {
            if (strcmp(carro->codigoSequencial, codigoCarro) == 0) {
                if (anterior->carros == carro) {
                    anterior->carros = carro->proximo;
                } else {
                    Carros *temp = anterior->carros;
                    while (temp->proximo != carro) {
                        temp = temp->proximo;
                    }
                    temp->proximo = carro->proximo;
                }
                free(carro);
                anterior->quantidadePlacas--;
                printf("Carro excluído com sucesso.\n");
                return;
            }
            carro = carro->proximo;
        }
    } else {
        printf("Erro na exclusão do carro. Carro não encontrado.\n");
    }

}

void receberNomePreenchido(Clientes *cliente) {
	printf("\nDigite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';

    formatarNomeRecursiva(cliente->nome,0,1);
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
	formatarNomeRecursiva(nome, indice + 1, caractereDeveSerPego);
}

void solicitarDataDeNascimento(Clientes *cliente) {
	DataNascimento *novaData = (DataNascimento *)malloc(sizeof(DataNascimento));
	if (novaData == NULL) {
		printf("Erro de alocação de memória!\n");
		exit(1);
	}

	char data_str[11];

	int solicitarNovamente = 1;
	while (solicitarNovamente) {
		printf("\nDigite sua data de nascimento no formato DD/MM/AAAA: ");
		fgets(data_str, sizeof(data_str), stdin);
		data_str[strcspn(data_str, "\n")]  = '\0';

		*novaData = converterData(data_str);

		if (isDataValida(novaData->dia, novaData->mes, novaData->ano)) {
			int idade = verificarIdade(novaData->ano);
			if (idade < 18 || idade > 100) {
				printf("Idade menor que 18 ou maior que 100\n");
				solicitarNovamente = 1; // Solicitar novamente
			} else {
				solicitarNovamente = 0; // Saída do loop
			}
		} else {
			printf("Formato de data incorreto.\n");
		}
	}
	cliente->dataNascimento = novaData;
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
    sprintf(cliente->codigo, "%c%d%02d", cliente->nome[0], cliente->dataNascimento->ano, numeroSequencial);
}

void verificarTipoContrato(Clientes *cliente) {
    char tipo;
    do {
        printf("\nDigite o tipo de contrato (D - Diária, P - Parcial, M - Mensal): ");
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        getchar();
    } while (tipo != 'D' && tipo != 'P' && tipo != 'M');
    cliente->tipoContrato = tipo;
}

void quantidadePlacas(Clientes *cliente) {
    int result;
    do {
        printf("\nDigite a quantidade de placas: ");
        result = scanf("%d", &cliente->quantidadePlacas);

        if (result != 1) {
            while (getchar() != '\n');
            printf("\nErro, entrada inválida. Por favor, insira um número.\n");
            continue;
        }

        if (cliente->quantidadePlacas < 1) {
            printf("\nErro, você deve ter pelo menos 1 placa cadastrada.\n");
        } else if (cliente->quantidadePlacas > MAX_CARROS) {
            printf("\nErro, 5 é o número máximo de placas para cadastro.\n");
        }
    } while (cliente->quantidadePlacas < 1 || cliente->quantidadePlacas > MAX_CARROS);
}

void chamarFuncoesPlacas(Carros *carro){
	char escolha;
	int placaInvalida = 1;
	while (placaInvalida){
		printf("\nCadastro de placa modelo novo ou modelo antigo?"
			   "\n(A - Antigo OU N - Novo)\n");
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
        printf("\nDigite a placa seguindo o modelo antigo"
        		"\n(exemplo: ABC1234):");
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

        strcpy(carros->placa, digitacao);

        placaInvalida = 0;

    } while (placaInvalida);
}

void validarPlacaNova(Carros *carros) {

    char digitacao[9];
    int placaInvalida = 1;

    do {
        printf("\nDigite a placa seguindo o modelo novo"
        		"\n(exemplo: ABC1D23):");
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

void gerarCodigoSequencialCarro(Carros *carro, Clientes *cliente, int numeroSequencial) {
    strncpy(carro->codigoSequencial, cliente->codigo, sizeof(carro->codigoSequencial));
    carro->codigoSequencial[sizeof(carro->codigoSequencial) - 1] = '\0'; // Garante o terminador nulo
    int remaining_space = sizeof(carro->codigoSequencial) - strlen(carro->codigoSequencial);
    snprintf(carro->codigoSequencial + strlen(carro->codigoSequencial), remaining_space, "%02d", numeroSequencial);
}


void receberMarcaModeloCarro(Carros *carro) {
    printf("\nInsira a marca/modelo do carro: ");
    fgets(carro->marcaModelo, sizeof(carro->marcaModelo), stdin);
    carro->marcaModelo[strcspn(carro->marcaModelo, "\n")] = '\0';
}

void receberAnoCarro(Carros *carro) {
    int ano;
    int anoInvalido = 1;
    do {
        printf("Digite o ano do carro (1950 - 2024): ");
        scanf("%d", &ano);
        getchar();
        if (ano >= 1950 && ano <= 2024) {
            carro->ano = ano;
            anoInvalido = 0;
        }
    } while (anoInvalido);
}

