#include <stdio.h>
#include <stdlib.h>
#include <structs.h>
#include <cabecalho.h>
#include <string.h>

void remove_doente(list_doentes_t *list, int ID);

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

void escreve_ficheiro(int ID, char nome[], int dia, int mes, int ano, char cc[], long telemovel, char email[]){
    FILE *f = fopen("doentes.txt", "a+");
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

    fclose(f);

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
            if(arroba_counter == 0) {
                printf("Email inválido, introduza novamente:\n");
            }
        }
        strcpy(node->doente.email, var);

        escreve_ficheiro(node->doente.ID,node->doente.nome,node->doente.dia,node->doente.mes,node->doente.ano,node->doente.cc,node->doente.telemovel,node->doente.email);

 
    }

    search(list, node->doente.ID, &prev, &cur);

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

    l_node_doentes_t *prev, *cur;

    search(list, ID, &prev, &cur);

    if(cur != NULL && cur->doente.ID == ID){

        l_node_registos_t *reg_prev = NULL;
        l_node_registos_t *reg_cur = cur->doente.registos->front;

        while(reg_cur != NULL){
            reg_prev = reg_cur;
            reg_cur = reg_cur->next;
            free(reg_prev);
        }

        free(cur->doente.registos); // Liberar a memória da lista de registos

        if(prev != NULL){
            prev->next = cur->next;
        }
        else{
            list->front = cur->next;
        }
        free(cur);

        printf("Doente removido com sucesso!\n");

        list->num_elems--;
    }
    else{
        printf("ID não encontrado.\n");
    }
}

//ver a segurança no email -> está valido quando é p.e pedro@@gmail.com