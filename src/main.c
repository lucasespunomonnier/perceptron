#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"
#include "dataset.h"

int main() {
    printf("Début du main\n");
    
    perceptron *p = creaPerceptron(2, 0.1);
    if (p == NULL) {
        fprintf(stderr, "Erreur d'allocation du perceptron.\n");
        return EXIT_FAILURE;
    }
    printf("Perceptron créé avec succès.\n");

    dataset *ds = chargerDataset("data/champignons.csv");
    printf("n = %d | dim = %d \n", ds->n, ds->dim);
    for(int i =0; i<(ds->n); i++){
        for(int j =0; j<(ds->dim); j++){
            printf("%g ", ds->caracteristique[i][j]);
        }
        printf("-> label %d \n", ds->labels[i]);
    }
    libeDataset(ds);


    libePerceptron(p);
    
    printf("%f", activationsigmoide(5));

    printf("Fin du main, mémoire libérée.\n");
    return EXIT_SUCCESS;
}