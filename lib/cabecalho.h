#ifndef cabecalho
#define cabecalho
#include "structs.h"

int string_to_int(char str[]);
long string_to_long(char str[]);
void inserir_paciente(Doente doentes[]);
void insert(list_doentes_t *list);
void search(list_doentes_t *list, l_node_doentes_t **prev, l_node_doentes_t **cur);

#endif 