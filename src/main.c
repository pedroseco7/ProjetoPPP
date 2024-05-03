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
        if (str[i] >= '0' && str[i] <= '9') {
            resultado = resultado * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return resultado;
}

long string_to_long(char str[]) {
    int resultado = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            resultado = resultado * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return resultado;
}

int main(){


    char opcao[20];
    int num_opcao;
    list_doentes_t listDoentes;

    FILE *file = fopen("docs/doentes.txt","r");
    int contador_ID = 0;

    if(file == NULL){ //se nao existir
        printf("A criar o ficheiro dos doentes...\n");
        file = fopen("docs/doentes.txt","w");
        fclose(file);
    }
    else{ //se ja existir, temos de percorrer o ficheiro, encontrar o ID de maior valor para que seja retomado com o valor do ID

        char ler_linha[100];
        int linha = 0;

        while(fgets(ler_linha,sizeof(ler_linha),file) != NULL){
            linha++;
            if(ler_linha[strlen(ler_linha)-1] == '\n'){
                ler_linha[strlen(ler_linha)-1] = '\0';
            }
            if(linha%6 == 1){ //Os ID's estão nas posições 1,7,13,...
                int id = string_to_int(ler_linha);
                if(id>contador_ID){
                    contador_ID = id;
                }
            }   
        }

        fclose(file);
    }
    recolhe_info_fich(&listDoentes);
    do{
        
        printf("\n=== Menu ===\n");
        printf("1. Adicionar Doente\n");
        printf("2. Eliminar Doente\n");
        printf("3. Listar Doente por Ordem Alfabética\n");
        printf("4. Listar os Doentes com Tensões Máximas acima de um determinado valor\n");
        printf("5. Apresentar a informação de um doente\n");
        printf("6. Registar a informação de um doente num determinado dia \n");
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
                contador_ID++;
                insert(&listDoentes, contador_ID);
                break;
            case 2:
                //Eliminar um doente existente
                char var[50];


                printf("Para remover, introduza o ID do doente:\n");
                fgets(var, 50, stdin);

                if(var[strlen(var) - 1] == '\n'){
                    var[strlen(var) - 1] = '\0';
                }

                while(string_to_int(var) == 0){
                    printf("ID inválido, introduza novamente:\n");
                    fgets(var, 50, stdin);
                    if(var[strlen(var) - 1] == '\n'){
                        var[strlen(var) - 1] = '\0';
                    }
                }

                remove_doente(&listDoentes,string_to_int(var));

                break;
            
            case 3:
                ordem_alfabetica(&listDoentes);
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
    } while (num_opcao != 7);

    return 0;
}

//para implementar uma forma para proteger o codigo ao inserir, podiamos usar switch e do-while