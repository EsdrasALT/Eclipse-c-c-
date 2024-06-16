#include "biblioteca.h"

void cadastrarCliente(Clientes **inicio, int *numeroSequencial) {
    Clientes *novoCliente = (Clientes *)malloc(sizeof(Clientes));
    if (novoCliente == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    receberNomePreenchido(novoCliente);
    solicitarDataDeNascimento(novoCliente);
    receberCodigoPreenchido(novoCliente, numeroSequencial);
    receberTipoDeContrato(novoCliente);

    novoCliente->quantidadePlacas = 0;
    novoCliente->carros = NULL;
    novoCliente->proximo = NULL;
    novoCliente->anterior = NULL;

    if (*inicio == NULL) {
        *inicio = novoCliente;
    } else {
        Clientes *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoCliente;
        novoCliente->anterior = atual;
    }
    printf("Cliente cadastrado com sucesso!\n");
}

void criarCarro(Clientes *cliente, int *numeroSequencial) {
    Carros *novoCarro = alocarNovoCarro();
    receberPlacaPreenchida(novoCarro);
    receberCodigoSequencialCarro(novoCarro, numeroSequencial);
    receberMarcaModeloCarro(novoCarro);
    receberAnoCarro(novoCarro);

    if (cliente->carros == NULL) {
        cliente->carros = novoCarro;
    } else {
        Carros *ultimo = cliente->carros;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoCarro;
    }
}

Carros* alocarNovoCarro() {
    Carros *novoCarro = (Carros *)malloc(sizeof(Carros));
    if (novoCarro == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novoCarro->proximo = NULL;
    return novoCarro;
}

void inserirPlaca(Clientes **inicio, int *numeroSequencial) {
    char *codigoCliente = buscarCodigo("Insira o código do cliente que deseja cadastrar a placa: ");
    Clientes *cliente = buscarClientePorCodigo(*inicio, codigoCliente);

    if (cliente != NULL) {
        if (cliente->quantidadePlacas < MAX_CARROS) {
            criarCarro(cliente, numeroSequencial);
            cliente->quantidadePlacas++;
        } else {
            printf("O cliente já possui a quantidade máxima de placas cadastradas.\n");
        }
    } else {
        printf("Cliente não encontrado!\n");
    }
}

void imprimeCliente(Clientes *cliente, int numCliente) {
    printf("\nCliente %d:\n", numCliente);
    printf("Nome: %s\n", cliente->nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n", cliente->dataNascimento->dia, cliente->dataNascimento->mes, cliente->dataNascimento->ano);
    printf("Código: %s\n", cliente->codigo);
    printf("Tipo de Contrato: %c\n", cliente->tipoContrato);
    printf("Quantidade de Placas: %d\n", cliente->quantidadePlacas);

    Carros *carroAtual = cliente->carros;
    int numCarro = 1;

    while (carroAtual != NULL) {
        printf("Carro %d:\n", numCarro);
        printf("  Placa: %s\n", carroAtual->placa);
        printf("  Código Sequencial: %s\n", carroAtual->codigoSequencial);
        printf("  Marca/Modelo: %s\n", carroAtual->marcaModelo);
        printf("  Ano: %d\n", carroAtual->ano);
        carroAtual = carroAtual->proximo;
        numCarro++;
    }
}

Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente) {
    Clientes *atual = inicio;
    while (atual != NULL && strcmp(atual->codigo, codigoCliente) != 0) {
        atual = atual->proximo;
    }
    return atual;
}

Carros* buscarCarroPorCodigo(Clientes *inicio, char *placaCarro, Carros **anterior) {
    Clientes *clienteAtual = inicio;
    while (clienteAtual != NULL) {
        Carros *carroAtual = clienteAtual->carros;
        *anterior = NULL;

        while (carroAtual != NULL) {
            if (strcmp(carroAtual->placa, placaCarro) == 0) {
                return carroAtual;
            }
            *anterior = carroAtual;
            carroAtual = carroAtual->proximo;
        }
        clienteAtual = clienteAtual->proximo;
    }
    return NULL;
}

char* buscarCodigo(char* mensagem) {
    static char codigo[MAX_CODIGO];
    printf("%s", mensagem);
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';  // Remover a quebra de linha
    return codigo;
}

void listarTodosClientes(Clientes *inicio) {
    if (inicio == NULL) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    Clientes *atual = inicio;
    int contador = 1;

    while (atual != NULL) {
        imprimeCliente(atual, contador);
        atual = atual->proximo;
        contador++;
    }
}

void listarClientePorCodigo(Clientes *inicio) {
    char *codigoCliente = buscarCodigo("Insira o código do cliente que deseja listar: ");
    Clientes *cliente = buscarClientePorCodigo(inicio, codigoCliente);

    if (cliente != NULL) {
        imprimeCliente(cliente, 1);
    } else {
        printf("Cliente não encontrado!\n");
    }
}

void listarClientesPorContrato(Clientes *inicio) {
    char tipoContrato;
    printf("Insira o tipo de contrato que deseja listar: ");
    scanf(" %c", &tipoContrato);

    Clientes *atual = inicio;
    int contador = 1;

    while (atual != NULL) {
        if (atual->tipoContrato == tipoContrato) {
            imprimeCliente(atual, contador);
            contador++;
        }
        atual = atual->proximo;
    }

    if (contador == 1) {
        printf("Nenhum cliente com esse tipo de contrato foi encontrado!\n");
    }
}

void excluirCliente(Clientes **inicio) {
    char *codigoCliente = buscarCodigo("Insira o código do cliente que deseja excluir: ");
    Clientes *cliente = buscarClientePorCodigo(*inicio, codigoCliente);

    if (cliente != NULL) {
        if (cliente->anterior != NULL) {
            cliente->anterior->proximo = cliente->proximo;
        } else {
            *inicio = cliente->proximo;
        }
        if (cliente->proximo != NULL) {
            cliente->proximo->anterior = cliente->anterior;
        }

        Carros *carroAtual = cliente->carros;
        while (carroAtual != NULL) {
            Carros *carroTemp = carroAtual;
            carroAtual = carroAtual->proximo;
            free(carroTemp);
        }
        free(cliente->dataNascimento);
        free(cliente);

        printf("Cliente excluído com sucesso!\n");
    } else {
        printf("Cliente não encontrado!\n");
    }
}

void excluirPlaca(Clientes **inicio) {
    char *placaCarro = buscarCodigo("Insira a placa do carro que deseja excluir: ");
    Carros *anterior = NULL;
    Carros *carro = buscarCarroPorCodigo(*inicio, placaCarro, &anterior);

    if (carro != NULL) {
        Clientes *cliente = *inicio;

        while (cliente != NULL) {
            if (cliente->carros == carro) {
                cliente->carros = carro->proximo;
                cliente->quantidadePlacas--;
                free(carro);
                printf("Carro excluído com sucesso!\n");
                return;
            }
            cliente = cliente->proximo;
        }

        if (anterior != NULL) {
            anterior->proximo = carro->proximo;
        }
        free(carro);
        printf("Carro excluído com sucesso!\n");
    } else {
        printf("Carro não encontrado!\n");
    }
}

void receberPlacaPreenchida(Carros *carro) {
    printf("Insira a placa do carro (AAA0A00 ou AAA0000): ");
    fgets(carro->placa, sizeof(carro->placa), stdin);
    carro->placa[strcspn(carro->placa, "\n")] = '\0';  // Remover a quebra de linha

    while (!validarPlaca(carro->placa)) {
        printf("Placa inválida. Insira a placa do carro (AAA0A00 ou AAA0000): ");
        fgets(carro->placa, sizeof(carro->placa), stdin);
        carro->placa[strcspn(carro->placa, "\n")] = '\0';  // Remover a quebra de linha
    }
    getchar();
}

int validarPlaca(char *placa) {
    int len = strlen(placa);

    if (len == 7) {
        // Validar formato AAA0000
        if (placa[0] >= 'A' && placa[0] <= 'Z' &&
            placa[1] >= 'A' && placa[1] <= 'Z' &&
            placa[2] >= 'A' && placa[2] <= 'Z' &&
            placa[3] >= '0' && placa[3] <= '9' &&
            placa[4] >= '0' && placa[4] <= '9' &&
            placa[5] >= '0' && placa[5] <= '9' &&
            placa[6] >= '0' && placa[6] <= '9') {
            return 1;
        }

        // Validar formato AAA0A00
        if (placa[0] >= 'A' && placa[0] <= 'Z' &&
            placa[1] >= 'A' && placa[1] <= 'Z' &&
            placa[2] >= 'A' && placa[2] <= 'Z' &&
            placa[3] >= '0' && placa[3] <= '9' &&
            placa[4] >= 'A' && placa[4] <= 'Z' &&
            placa[5] >= '0' && placa[5] <= '9' &&
            placa[6] >= '0' && placa[6] <= '9') {
            return 1;
        }
    }

    return 0;
}

void receberNomePreenchido(Clientes *cliente) {
    printf("Insira o nome completo: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';  // Remover a quebra de linha
    formatarNomeRecursiva(cliente->nome, 0, 1);
}

void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego) {
    if (nome[indice] == '\0') {
        return;
    }

    if (caractereDeveSerPego) {
        if (nome[indice] >= 'a' && nome[indice] <= 'z') {
            nome[indice] -= 'a' - 'A';
        }
    } else {
        if (nome[indice] >= 'A' && nome[indice] <= 'Z') {
            nome[indice] += 'a' - 'A';
        }
    }

    caractereDeveSerPego = (nome[indice] == ' ');
    formatarNomeRecursiva(nome, indice + 1, caractereDeveSerPego);
}

void solicitarDataDeNascimento(Clientes *cliente) {
    char data_string[11];
    printf("Insira a data de nascimento (DD/MM/AAAA): ");
    fgets(data_string, sizeof(data_string), stdin);
    data_string[strcspn(data_string, "\n")] = '\0';  // Remover a quebra de linha

    DataNascimento data = converterData(data_string);
    while (!isDataValida(data.dia, data.mes, data.ano) || verificarIdade(data.ano) < 18) {
        printf("Data de nascimento inválida ou idade inferior a 18 anos. Insira novamente (DD/MM/AAAA): ");
        fgets(data_string, sizeof(data_string), stdin);
        data_string[strcspn(data_string, "\n")] = '\0';  // Remover a quebra de linha
        data = converterData(data_string);
    }

    cliente->dataNascimento = (DataNascimento *)malloc(sizeof(DataNascimento));
    if (cliente->dataNascimento == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    *(cliente->dataNascimento) = data;
}

DataNascimento converterData(char *data_string) {
    DataNascimento data;
    sscanf(data_string, "%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

int verificarIdade(int ano) {
    int ano_atual = 2024;
    return ano_atual - ano;
}

int isDataValida(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2024) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > 31) return 0;

    if (mes == 2) {
        int isBissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > 28 + isBissexto) return 0;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return 0;
    }

    return 1;
}

void receberCodigoPreenchido(Clientes *cliente, int *numeroSequencial) {
    char sequencial[7];
    snprintf(sequencial, sizeof(sequencial), "%06d", (*numeroSequencial)++);
    strcpy(cliente->codigo, "CLI");
    strcat(cliente->codigo, sequencial);
}

void receberTipoDeContrato(Clientes *cliente) {
    printf("Insira o tipo de contrato (A, B, C ou D): ");
    scanf(" %c", &cliente->tipoContrato);
    while (cliente->tipoContrato < 'A' || cliente->tipoContrato > 'D') {
        printf("Tipo de contrato inválido. Insira o tipo de contrato (A, B, C ou D): ");
        scanf(" %c", &cliente->tipoContrato);
    }
}

//void receberCodigoSequencialCarro(Carros *carro, int *numeroSequencial) {
//    char sequencial[7];
//    snprintf(sequencial, sizeof(sequencial), "%06d", (*numeroSequencial)++);
//    strcpy(carro->codigoSequencial, "CAR");
//    strcat(carro->codigoSequencial, sequencial);
//}

void receberMarcaModeloCarro(Carros *carro) {
    printf("Insira a marca/modelo do carro: ");
    fgets(carro->marcaModelo, sizeof(carro->marcaModelo), stdin);
    carro->marcaModelo[strcspn(carro->marcaModelo, "\n")] = '\0';  // Remover a quebra de linha
}

void receberAnoCarro(Carros *carro) {
    printf("Insira o ano do carro: ");
    scanf("%d", &carro->ano);
    while (carro->ano < 1950 || carro->ano > 2024) {
        printf("Ano inválido. Insira o ano do carro: ");
        scanf("%d", &carro->ano);
    }
}













