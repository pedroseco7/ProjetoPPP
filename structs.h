#ifndef STRUCT
#define STRUCT


typedef struct{
    int ten_min;
    int ten_max;
    int peso;
    double altura;
    int ID;
}Registo;

typedef struct{
    char nome[30];
    char data[11];
    char cc[13];
    int telemovel;
    char email[30];
    int ID;
    Registo registo;
}Doente;

#endif