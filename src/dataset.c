#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataset.h"

dataset *creaDataset(int n, int dim) {
    dataset *d = malloc(sizeof(dataset));
    if (d == NULL) return NULL;

    d->n = n;
    d->dim = dim;

    /* Allocation du tableau de labels */
    d->labels = malloc(n * sizeof(int));
    if (d->labels == NULL){
        free(d);
        return NULL;
    }

    /* Allocation du tableau 2D de caractéristiques */
    d->caracteristique = malloc(n * sizeof(double *));
    if (d->caracteristique == NULL) {
        free(d->labels);
        free(d);
        return NULL;
    }

    /* Allocation de chaque ligne et initialisation à zéro */
    for (int i = 0; i < n; i++) {
        d->caracteristique[i] = malloc(dim * sizeof(double));
        if (d->caracteristique[i] == NULL) {
            /* En cas d'échec, libérer tout ce qui a été alloué précédemment */
            for (int j = 0; j < i; j++) {
                free(d->caracteristique[j]);
            }
            free(d->caracteristique);
            free(d->labels);
            free(d);
            return NULL;
        }
        for (int j = 0; j < dim; j++) {
            d->caracteristique[i][j] = 0.0;
        }
        d->labels[i] = 0;
    }
    return d;
}

void libeDataset(dataset *d) {
    if (d == NULL) return;
    
    if (d->caracteristique != NULL) {
        for (int i = 0; i < d->n; i++) {
            free(d->caracteristique[i]);
        }
        free(d->caracteristique);
    }
    
    if (d->labels != NULL) {
        free(d->labels);
    }
    
    free(d);
}

dataset *chargerDataset(char *path){
    // Compter les lignes et colonnes 
    FILE *fd = fopen(path, "r");
    if(fd == NULL){
        fprintf(stderr, "Une erreur lors de l'ouverture d'un fichier\n");
        exit(EXIT_FAILURE);
    }

    char ligne[1024];
    int n = 0;
    int nb_col = 0;

    while(fgets(ligne, sizeof(ligne), fd) != NULL){
        if(ligne[0] == '\n' || ligne[0] == '\r'){
            continue;
        }

        if(n == 0){
            nb_col = 1;
            for(int i = 0; ligne[i] != '\0'; i++){
                if(ligne[i] == ','){
                    nb_col ++;
                }
            }
        }
        n++;
    }

    int dim  = nb_col - 1;

    dataset *d = creaDataset(n, dim);
    if(d == NULL){
        fprintf(stderr, "Erreur d'allocation du dataset\n");
        fclose(fd);
        exit(EXIT_FAILURE);
    }

    // Remplir le dataset 
    rewind(fd);
    int i = 0;

    while(i < n && fgets(ligne, sizeof(ligne), fd) != NULL){
        if(ligne[0] == '\n' || ligne[0] == '\r'){
            continue;
        }
        char *tok = strtok(ligne, ",\r\n");
        for(int j =0; j<dim; j++){
            d->caracteristique[i][j] = atof(tok);
            tok = strtok(NULL, ",\r\n");
        }
        d->labels[i] = atoi(tok);
        i++;
    }
    fclose(fd);
    return d;
}
