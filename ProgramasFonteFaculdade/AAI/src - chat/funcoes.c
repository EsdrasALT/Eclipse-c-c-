#include "biblioteca.h"

// Funções de formatação de nomes
void formatarNomeRecursiva(char *nome, int indice, int caractereDeveSerPego) {
    if (nome[indice] == '\0') {
        return;
    }
    if (caractereDeveSerPego && isalpha(nome[indice])) {
        nome[indice] = toupper(nome[indice]);
        caractereDeveSerPego = 0;
    } else {
        nome[indice] = tolower(nome[indice]);
    }
    if (nome[indice] == ' ') {
        caractereDeveSerPego = 1;
    }
    formatarNomeRecursiva(nome, indice + 1, caractereDeveSerPego);
}

void receberNomePreenchido(Clientes *cliente) {
    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, 50, stdin);
    getchar();
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
    formatarNomeRecursiva(cliente->nome, 0, 1);
}

// Funções de data
DataNascimento converterData(char *data_str) {
    DataNascimento data;
    sscanf(data_str, "%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

int isAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int isDataValida(int dia, int mes, int ano) {
    if (ano < 1924 || ano > 2006) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1) return 0;

    int dias_no_mes[] = { 31, isAnoBissexto(ano) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (dia > dias_no_mes[mes - 1]) return 0;
    return 1;
}

void solicitarDataDeNascimento(Clientes *cliente) {
    char data_str[11];
    DataNascimento data;
    do {
        printf("Digite a data de nascimento (dd/mm/yyyy): ");
        fgets(data_str, 11, stdin);
        getchar();
        data_str[strcspn(data_str, "\n")] = '\0';
        data = converterData(data_str);
    } while (!isDataValida(data.dia, data.mes, data.ano));
    cliente->dataNascimento = data;
}

// Função para gerar código sequencial do cliente
void gerarCodigoSequencial(Clientes *cliente, int numeroSequencial) {
    snprintf(cliente->codigo, 10, "%c%d%02d", cliente->nome[0], cliente->dataNascimento.ano, numeroSequencial);
}

// Função para verificar tipo de contrato
void verificarTipoContrato(Clientes *cliente) {
    char tipo;
    do {
        printf("Digite o tipo de contrato (D - Diária, P - Parcial, M - Mensal): ");
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        getchar();
    } while (tipo != 'D' && tipo != 'P' && tipo != 'M');
    cliente->tipoContrato = tipo;
}

// Função para quantidade de placas
void quantidadePlacas(Clientes *cliente) {
    int qtde;
    do {
        printf("Digite a quantidade de placas (1 a %d): ", MAX_PLACAS);
        scanf("%d", &qtde);
    } while (qtde < 1 || qtde > MAX_PLACAS);
    cliente->qtdePlacas = qtde;
}

// Funções de criação de cliente e carro
Clientes* criarCliente(Clientes **inicio, Clientes **fim, int *codigo) {
    Clientes *novo = (Clientes *)malloc(sizeof(Clientes));
    if (novo == NULL) {
        printf("Erro ao alocar memória para novo cliente.\n");
        exit(1);
    }

    receberNomePreenchido(novo);
    solicitarDataDeNascimento(novo);
    verificarTipoContrato(novo);
    quantidadePlacas(novo);
    gerarCodigoSequencial(novo, *codigo);
    (*codigo)++;

    novo->carros = NULL;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*fim == NULL) {
        *inicio = novo;
    } else {
        (*fim)->prox = novo;
        novo->ant = *fim;
    }
    *fim = novo;

    return novo;
}

Carros* criaCarro(Clientes *cliente, int *codigo) {
    if (cliente->qtdePlacas >= MAX_PLACAS) {
        printf("Número máximo de placas atingido.\n");
        return NULL;
    }

    Carros *novo = (Carros *)malloc(sizeof(Carros));
    if (novo == NULL) {
        printf("Erro ao alocar memória para novo carro.\n");
        exit(1);
    }

    // Solicitar e armazenar dados do carro
    printf("Digite a placa do carro: ");
    scanf("%s", novo->placa);
    snprintf(novo->codigo, 10, "%s%02d", cliente->codigo, cliente->qtdePlacas);
    printf("Digite a marca e modelo do carro: ");
    scanf("%s", novo->marcaModelo);
    printf("Digite o ano do carro: ");
    scanf("%d", &novo->ano);

    novo->prox = cliente->carros;
    cliente->carros = novo;
    cliente->qtdePlacas++;

    return novo;
}

// Funções de inserção
void inserirCliente(Clientes **inicio, Clientes **fim, int *numeroSequencial) {
    criarCliente(inicio, fim, numeroSequencial);
}

void inserirPlaca(Clientes **inicio, int *numeroSequencial) {
    char codigoCliente[10];
    printf("Digite o código do cliente para adicionar a placa: ");
    scanf("%s", codigoCliente);

    Clientes *cliente = buscarClientePorCodigo(*inicio, codigoCliente);
    if (cliente != NULL) {
        criaCarro(cliente, numeroSequencial);
    } else {
        printf("Cliente não encontrado.\n");
    }
}

// Funções de busca
Clientes* buscarClientePorCodigo(Clientes *inicio, char *codigoCliente) {
    Clientes *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigoCliente) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Carros* buscarCarroPorCodigo(Clientes *inicio, char *placaCarro, Clientes **anterior) {
    Clientes *atualCliente = inicio;
    while (atualCliente != NULL) {
        Carros *atualCarro = atualCliente->carros;
        while (atualCarro != NULL) {
            if (strcmp(atualCarro->placa, placaCarro) == 0) {
                if (anterior != NULL) {
                    *anterior = atualCliente;
                }
                return atualCarro;
            }
            atualCarro = atualCarro->prox;
        }
        atualCliente = atualCliente->prox;
    }
    return NULL;
}

// Funções de listagem
void listarTodosClientes(Clientes *inicio) {
    Clientes *atual = inicio;
    while (atual != NULL) {
        imprimeCliente(atual, 1);
        atual = atual->prox;
    }
}

void imprimeCliente(Clientes *cliente, int numCliente) {
    printf("Cliente %d:\n", numCliente);
    printf("Nome: %s\n", cliente->nome);
    printf("Código: %s\n", cliente->codigo);
    printf("Data de Nascimento: %02d/%02d/%04d\n", cliente->dataNascimento.dia, cliente->dataNascimento.mes, cliente->dataNascimento.ano);
    printf("Tipo de Contrato: %c\n", cliente->tipoContrato);
    printf("Quantidade de Placas: %d\n", cliente->qtdePlacas);

    Carros *carro = cliente->carros;
    while (carro != NULL) {
        printf("\tPlaca: %s\n", carro->placa);
        printf("\tCódigo: %s\n", carro->codigo);
        printf("\tMarca/Modelo: %s\n", carro->marcaModelo);
        printf("\tAno: %d\n", carro->ano);
        carro = carro->prox;
    }
}

// Funções de exclusão
void excluirCliente(Clientes **inicio) {
    char codigoCliente[10];
    printf("Digite o código do cliente para excluir: ");
    scanf("%s", codigoCliente);

    Clientes *atual = *inicio;
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigoCliente) == 0) {
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            } else {
                *inicio = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            }

            Carros *carro = atual->carros;
            while (carro != NULL) {
                Carros *tempCarro = carro;
                carro = carro->prox;
                free(tempCarro);
            }
            free(atual);
            printf("Cliente excluído com sucesso.\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Cliente não encontrado.\n");
}

void excluirPlaca(Clientes **inicio) {
    char placaCarro[8];
    printf("Digite a placa do carro para excluir: ");
    scanf("%s", placaCarro);

    Clientes *anterior = NULL;
    Carros *carro = buscarCarroPorCodigo(*inicio, placaCarro, &anterior);

    if (carro != NULL) {
        if (anterior->carros == carro) {
            anterior->carros = carro->prox;
        } else {
            Carros *temp = anterior->carros;
            while (temp->prox != carro) {
                temp = temp->prox;
            }
            temp->prox = carro->prox;
        }
        free(carro);
        anterior->qtdePlacas--;
        printf("Carro excluído com sucesso.\n");
    } else {
        printf("Carro não encontrado.\n");
    }
}

// Funções de relatórios
void listarClientePorCodigo(Clientes *inicio) {
    char codigoCliente[10];
    printf("Digite o código do cliente: ");
    scanf("%s", codigoCliente);

    Clientes *cliente = buscarClientePorCodigo(inicio, codigoCliente);
    if (cliente != NULL) {
        imprimeCliente(cliente, 1);
    } else {
        printf("Cliente não encontrado.\n");
    }
}

void listarClientesPorContrato(Clientes *inicio) {
    char tipo;
    printf("Digite o tipo de contrato (D - Diária, P - Parcial, M - Mensal): ");
    scanf(" %c", &tipo);

    Clientes *atual = inicio;
    while (atual != NULL) {
        if (atual->tipoContrato == toupper(tipo)) {
            imprimeCliente(atual, 1);
        }
        atual = atual->prox;
    }
}

// Função principal
void menuPrincipal() {
    Clientes *inicio = NULL;
    Clientes *fim = NULL;
    int codigoSequencial = 1;
    int opcao;

    do {
        printf("\nMenu Principal\n");
        printf("1. Inserir Cliente\n");
        printf("2. Inserir Placa\n");
        printf("3. Excluir Cliente\n");
        printf("4. Excluir Placa\n");
        printf("5. Relatórios\n");
        printf("6. Finalizar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirCliente(&inicio, &fim, &codigoSequencial);
                break;
            case 2:
                inserirPlaca(&inicio, &codigoSequencial);
                break;
            case 3:
                excluirCliente(&inicio);
                break;
            case 4:
                excluirPlaca(&inicio);
                break;
            case 5:
                menuRelatorios();
                break;
            case 6:
                printf("Finalizando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 6);
}

void menuRelatorios() {
    int opcao;
    Clientes *inicio = NULL;

    printf("\nMenu de Relatórios\n");
    printf("1. Listar todos os clientes cadastrados\n");
    printf("2. Listar dados do cliente por código\n");
    printf("3. Listar clientes por tipo de contrato\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
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
            printf("Opção inválida.\n");
    }
}
