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
                printf("i");
                break;
            case 2:
                printf("i");
                break;
            
            case 3:
                printf("i");
                break;
            
            case 4:
                printf("i");
                break;

            case 5:
                printf("i");
                break;

            case 6:
                printf("i");
                break;
            
            case 7:
                printf("A sair...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (num_opcao < 1 || num_opcao > 7);
    

    

    

    
    



    
    



    return 0;
}

//para implementar uma forma para proteger o codigo ao inserir, podiamos usar switch e do-while