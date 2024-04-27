#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "structs.h"
#include "cabecalho.h"

#define MAX_PAC 100

int string_to_int(char str[]) {
    int resultado = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '1' && str[i] <= '7') {
            resultado = resultado * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return resultado;
}

void search(list_registo_t *list, int ID, l_node_t **prev, l_node_t **cur){

    *prev = NULL;
    *cur = list->front;
    while(*cur != NULL && (*cur)->registo.ID < ID){
        *prev = *cur;
        *cur = (*cur)->next;
    }
}

void remove_doente(,int ID){

    l_node_t *node, *prev, *cur;

    search(,ID, &prev, &)


    
}



int main(){

    Doente doentes[MAX_PAC];

    char opcao[20];
    int num_opcao;

    do {
        
        printf("\n=== Menu ===\n");
        printf("1. Adicionar Doente\n");
        printf("2. Eliminar Doente\n");
        printf("3. Listar Doente por Ordem Alfabética\n");
        printf("4. Listar os Doentes com Tensões Máximas acima de um determinado valor\n");
        printf("5. Apresentar a informação de um doente\n");
        printf("6. Registar a informação de um determinado doente \n");
        printf("7. Sair\n");
        printf("Opção que quer selecionar: ");

        fgets(opcao,20,stdin);

        int len = strlen(opcao);

        if(opcao[len-1] == '\n'){
            opcao[len-1] = '\0';
        }

        num_opcao = string_to_int(opcao);   
        

        switch (num_opcao) {
            case 1:
                //Introduzir dados de um novo doente
                printf("i");
                break;
            case 2:
                //Eliminar um doente existente

                printf("i");
                break;
            
            case 3:
                //Listar todos os doentes por ordem alfabética
                printf("i");
                break;
            
            case 4:
                //Listar os doentes com tensões máximas acima de um determinado valor (por ordem decrescente das mesmas)
                printf("i");
                break;

            case 5:
                //Apresentar toda a informação de um determinado doente
                printf("i");
                break;

            case 6:
                //Registar as tensões, o peso e a altura de um determinado doente num determinado dia. 
                printf("i");
                break;
            
            case 7:
                //Sair
                printf("A sair...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (num_opcao < 1 || num_opcao > 7);
    

    

    

    
    



    
    



    return 0;
}

//para implementar uma forma para proteger o codigo ao inserir, podiamos usar switch e do-while