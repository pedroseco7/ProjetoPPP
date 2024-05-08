#include <stdio.h>
#include <stdlib.h>
#include <structs.h>
#include <cabecalho.h>
#include <string.h>

void init(list_doentes_t *list){

    list -> num_elems = 0;
    list -> front = NULL;

}

int empty(list_doentes_t *list){
    return list -> front == NULL;
}

void clear(list_doentes_t *list){
    l_node_doentes_t *node;
    while(list->front != NULL){
        node = list->front;
        list -> front = list -> front -> next;
        free(node);
    }
    init(list);
}

void search(list_doentes_t *list,int ID, l_node_doentes_t **prev, l_node_doentes_t **cur){

    *prev = NULL;
    *cur = list -> front;
    while(*cur != NULL && (*cur)->doente.ID < ID){
        *prev = *cur;
        *cur = (*cur)->next;
    }
}

void search_nome(list_doentes_t *list, char nome[], l_node_doentes_t **prev, l_node_doentes_t **cur){

    *prev = NULL;
    *cur = list -> front;
    while(*cur != NULL && strcmp((*cur)->doente.nome,nome) < 0){
        *prev = *cur;
        *cur = (*cur)->next;
    }

}

void escreve_ficheiro(int ID, char nome[], int dia, int mes, int ano, char cc[], long telemovel, char email[]){
    FILE *f = fopen("docs/doentes.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo doentes.txt.\n");
        return;
    }
    fprintf(f,"%d\n",ID);
    fputs(nome,f);
    fputs("\n",f);
    fprintf(f,"%d/",dia);
    fprintf(f,"%d/",mes);
    fprintf(f,"%d\n",ano);
    fputs(cc,f);
    fputs("\n",f);
    fprintf(f,"%ld\n",telemovel);
    fputs(email,f);
    fputs("\n", f);

    
    fclose(f);

}

void insere_ordenado(list_doentes_t *list, Doente doente) {
    l_node_doentes_t *novo = malloc(sizeof(l_node_doentes_t));
    novo->doente = doente;
    novo->next = NULL;

    if (list->front == NULL || list->front->doente.ID >= doente.ID) {
        novo->next = list->front;
        list->front = novo;
    } else {
        l_node_doentes_t *atual = list->front;
        while (atual->next != NULL && atual->next->doente.ID < doente.ID) {
            atual = atual->next;
        }
        novo->next = atual->next;
        atual->next = novo;
    }
}


void insert(list_doentes_t *list, int contador){
    l_node_doentes_t *node = (l_node_doentes_t *)malloc(sizeof(l_node_doentes_t));
    l_node_doentes_t *prev, *cur;
    if(node != NULL){

        char var[50];



        node->doente.registos = (list_registo_t *)malloc(sizeof(list_registo_t));
        node->doente.registos->num_elem = 0;
        node->doente.registos->front = NULL;

        // ID

        node->doente.ID = contador;

        // NOME

        printf("Introduza o nome do doente:\n");
        fgets(var, 30, stdin);

        if(var[strlen(var) - 1] == '\n'){
            var[strlen(var) - 1] = '\0';
        }
        
        strcpy(node->doente.nome,var);

        // DIA - Nascimento

        printf("Introduza o dia de nascimento do doente:\n");
        fgets(var, 50, stdin);

        if(var[strlen(var) - 1] == '\n'){
            var[strlen(var) - 1] = '\0';
        }

        while(string_to_int(var) == 0 || string_to_int(var) > 31){
            printf("Dia inválido, introduza novamente:\n");
            fgets(var, 50, stdin);
            if(var[strlen(var) - 1] == '\n'){
                var[strlen(var) - 1] = '\0';
            }
        }
        node->doente.dia = string_to_int(var);

        // MES - Nascimento

        printf("Introduza o mês de nascimento do doente:\n");
        fgets(var, 50, stdin);
        if(var[strlen(var) - 1] == '\n'){
            var[strlen(var) - 1] = '\0';
        }
        while(string_to_int(var) == 0 || string_to_int(var) > 12){
            printf("Mês inválido, introduza novamente:\n");
            fgets(var, 50, stdin);
            if(var[strlen(var) - 1] == '\n'){
                var[strlen(var) - 1] = '\0';
            }
        }
        node->doente.mes = string_to_int(var);

        // ANO - Nascimento

        printf("Introduza o ano de nascimento do doente:\n");
        fgets(var, 50, stdin);
        if(var[strlen(var) - 1] == '\n'){
            var[strlen(var) - 1] = '\0';
        }
        while(string_to_int(var) == 0 || string_to_int(var) > 2024){
            printf("Ano inválido, introduza novamente:\n");
            fgets(var, 50, stdin);
            if(var[strlen(var) - 1] == '\n'){
                var[strlen(var) - 1] = '\0';
            }
        }
        node->doente.ano = string_to_int(var);

        // CC

        int verifica = 1;
        printf("Introduza um número de Cartão de Cidadão válido, com o seguinte formato XXXXXXXX-X-XXX:\n");
        while(verifica == 1) {
            fgets(var, 50, stdin);
            if(var[strlen(var) - 1] == '\n'){
                var[strlen(var) - 1] = '\0';
            }
            verifica = 0;
            for (int i = 0; i < 14; i++) {
                if(var[8] != '-' || var[10] != '-'){
                    printf("CC inválido, introduza novamente:\n");
                    verifica = 1;
                    break;
                }
                if(i != 8 && i != 10 && i != 11 && i != 12 && (var[i] < '0' || var[i] > '9')){
                    printf("CC inválido, introduza novamente:\n");
                    verifica = 1;
                    break;
                }
                if(var[11] < 'A' || var[11] > 'Z' || var[12] < 'A' || var[12] > 'Z'){
                    printf("CC inválido, introduza novamente:\n");
                    verifica = 1;
                    break;
                }
            }
        }

        strcpy(node->doente.cc, var);
        // Telemóvel

        printf("Introduza o número de telemóvel do doente:\n");
        fgets(var, 50, stdin);
        if(var[strlen(var) - 1] == '\n'){
            var[strlen(var) - 1] = '\0';
        }
        while(string_to_long(var) == 0){
            printf("Número de telemóvel inválido, introduza novamente:\n");
            fgets(var, 50, stdin);
            if(var[strlen(var) - 1] == '\n'){
                var[strlen(var) - 1] = '\0';
            }
        }
        node->doente.telemovel = string_to_long(var);

        // Email

        printf("Introduza o email do doente:\n");
        int arroba_counter = 0;

        while(arroba_counter == 0) {
            fgets(var, 50, stdin);
            for (size_t i = 0; i < strlen(var); i++) {
                if (var[i] == '@') {
                    arroba_counter++;
                    break;
                }
            }
            if(arroba_counter != 1) {
                printf("Email inválido, introduza novamente:\n");
            }
        }
        strcpy(node->doente.email, var);

        printf("ID do novo doente: %d\n", node->doente.ID); // Adicionado para debug
        escreve_ficheiro(node->doente.ID,node->doente.nome,node->doente.dia,node->doente.mes,node->doente.ano,node->doente.cc,node->doente.telemovel,node->doente.email);

        
    }

    search_nome(list, node->doente.nome, &prev, &cur);

    if(prev != NULL){
        prev->next = node;
        node->next = cur;
    }
    else{
        list->front = node;
        node->next = cur;
    }
    list->num_elems++;
}

void remove_doente(list_doentes_t *list, int ID){
    // Procura pelo doente com o ID especificado
    l_node_doentes_t *prev, *cur;
    search(list, ID, &prev, &cur);

    // Se o doente for encontrado
    if(cur != NULL && cur->doente.ID == ID){

        if(prev != NULL){
            prev -> next = cur -> next;
        }

        else{
            list->front = cur->next;
        }
        free(cur);
        list->num_elems--;
    }
    else{
        printf("ID não encontrado.\n");
    }
}

void ordem_alfabetica(list_doentes_t *list){

    l_node_doentes_t *cur = NULL;
    cur = list->front;
    printf("Ordem Alfabética dos Doentes:\n");
    while(cur != NULL){
        printf("%s\n", (cur)->doente.nome);
        cur = (cur)->next;
    }
}


void recolhe_info_fich(list_doentes_t *list){
    FILE *file = fopen("docs/doentes.txt", "r");

    if(file != NULL) {

        l_node_doentes_t *node;
        l_node_doentes_t *prev, *cur;
        char *ler_linha = (char *)malloc(256*sizeof(char));
        int linha = 0;

        while (fgets(ler_linha, 256*sizeof(char), file) != NULL) {

            linha++;
            if (ler_linha[strlen(ler_linha) - 1] == '\n') {
                ler_linha[strlen(ler_linha) - 1] = '\0';
            }
            if (linha % 7 == 1) {
                node = (l_node_doentes_t *)malloc(sizeof(l_node_doentes_t));
                if(node == NULL){
                    break;
                }
                node->doente.ID = string_to_int(ler_linha);
            }
            else if (linha % 7 == 2){
                strcpy(node->doente.nome, ler_linha);
            }
            else if (linha % 7 == 3){
                char *token;
                token = strtok(ler_linha, "/");
                node->doente.dia = string_to_int(token);
                token = strtok(NULL, "/");
                node->doente.mes = string_to_int(token);
                token = strtok(NULL, "/");
                if(token[strlen(token) - 1] == '\n'){
                    token[strlen(token) - 1] = '\0';
                }
                node->doente.ano = string_to_int(token);
            }
            else if(linha % 7 == 4){
                strcpy(node->doente.cc, ler_linha);
            }
            else if(linha % 7 == 5){
                node->doente.telemovel = string_to_long(ler_linha);
            }
            else if(linha % 7 == 6){
                strcpy(node->doente.email, ler_linha);
                search_nome(list, node->doente.nome, &prev, &cur);
                if(prev != NULL){
                    prev->next = node;
                    node->next = cur;
                }
                else{
                    list->front = node;
                    node->next = cur;
                }
                list->num_elems++;
                linha = 0;
            }
        }
        free(ler_linha);
    }

    fclose(file);

}

//ver a segurança no email -> está valido quando é p.e pedro@@gmail.com

void inserir_registos(list_doentes_t *list, int dia, int mes, int ano, int ID, int ten_max, int ten_min, float peso, float alt) {

    l_node_doentes_t *atual = list->front;

    printf("\n%d\n",atual->doente.ID);

    while (atual != NULL && atual->doente.ID != ID) {
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Não foi encontrado nenhum paciente com esse ID\n");
        return;
    }

    printf("\n%d\n",atual->doente.ID); 

    if (atual->doente.registos == NULL) {
        atual->doente.registos = (list_registo_t *)malloc(sizeof(list_registo_t));
        if (atual->doente.registos == NULL) {
            printf("Ocorreu um erro ao alocar memória\n");
            return;
        }
        atual->doente.registos->num_elem = 0;
        atual->doente.registos->front = NULL;
    }

    registo_t novo_registo;

    novo_registo.dia = dia;
    novo_registo.mes = mes;
    novo_registo.ano = ano;
    novo_registo.altura = alt;
    novo_registo.peso = peso;
    novo_registo.ten_max = ten_max;
    novo_registo.ten_min = ten_min;
    novo_registo.ID = ID;
    
    l_node_registos_t *novo_lista_registo = (l_node_registos_t *)malloc(sizeof(l_node_registos_t));
    if (novo_lista_registo == NULL) {
        printf("Ocorreu um erro ao alocar memória\n");
        return;
    }

    // Preencher o novo nó com o registro e definir next como NULL
    novo_lista_registo->registo = novo_registo;
    novo_lista_registo->next = NULL;

    // Se a lista de registros estiver vazia, definir o novo registro como o primeiro
    if (atual->doente.registos->front == NULL) {
        atual->doente.registos->front = novo_lista_registo;
    } else {
        // Encontrar o último nó da lista de registros
        l_node_registos_t *ultimo = atual->doente.registos->front;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }

        // Atualizar o ponteiro next do último nó para apontar para o novo registro
        ultimo->next = novo_lista_registo;
    }

    
    atual->doente.registos->num_elem++;
    printf("Registo adicionado com sucesso para o doente com ID %d.\n", ID);
}

void mostra_nome_id(list_doentes_t *list){

    l_node_doentes_t *cur;
    cur = list->front;
    printf("Nome - ID\n");
    while(cur != NULL){
        printf("%s - %d\n", cur->doente.nome, cur->doente.ID);
        cur = cur->next;
    }
}

void teste(list_doentes_t *list){

    l_node_doentes_t *cur;
    cur = list->front;
    while(cur != NULL){
        escreve_ficheiro(cur->doente.ID, cur->doente.nome, cur->doente.dia, cur->doente.mes, cur->doente.ano, cur->doente.cc, cur->doente.telemovel, cur->doente.email);
        cur = cur->next;
    }
}
    



