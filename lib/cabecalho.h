#ifndef cabecalho
#define cabecalho
#include "structs.h"

int string_to_int(char str[]);
long string_to_long(char str[]);
void inserir_paciente(Doente doentes[]);
void insert(list_doentes_t *list, int contador);
void search(list_doentes_t *list,int ID, l_node_doentes_t **prev, l_node_doentes_t **cur);
void remove_doente(list_doentes_t *list, int ID);
#endif 