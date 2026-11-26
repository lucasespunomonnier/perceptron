#ifndef DATASET_H
#define DATASET_H 
typedef struct dataset_s{
    int n;
    int dim;
    double **caracteristique;
    int *labels;
}dataset;

dataset *creaDataset(int n, int dim);
void libeDataset(dataset *d);
dataset *chargerDataset(char *path);
#endif