#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

/*
    Alloue dynamiquemennt et initialise un perceptron avce des poids et un biais a 0
    Paramètres: dimin (dimension d'entrée) taux (taux d'apprentissage)
    Retourne un pointeur vers perceptron ou NULL 
*/
perceptron *creaPerceptron(int dimin, double taux){

    if(dimin<= 0){
        return NULL;
    }
    /*Initialisation*/
    perceptron *p = malloc(sizeof(perceptron));
    if(p == NULL){
        return NULL;
    }
    
    p->vectPoids = malloc(dimin*sizeof(double));
    if(p->vectPoids == NULL){
        free(p);
        return NULL;
    }

    p->dimEntree = dimin;
    p->tauxAppren = taux;
    p->biais = 0.0;

    for(int i = 0; i < dimin; i++){
        p->vectPoids[i] = 0.0;
    }
    return p;
}

void libePerceptron(perceptron *p){
    if(p == NULL){
        return;
    }
    else{
        if(p->vectPoids != NULL){
            free(p->vectPoids);
        }
    }
    free(p);
}