#ifndef PERCEPTRON_H
#define PERCEPTRON_H
typedef struct perceptron_s{
    int dim;
    double *vectPoids;
    double biais;
    int dimEntree;
    double tauxAppren;
}perceptron;

perceptron *creaPerceptron(int dimin, double taux);
void libePerceptron(perceptron *p);
#endif