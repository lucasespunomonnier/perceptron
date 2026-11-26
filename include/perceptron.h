typedef struct perceptron_s{
    int dim;
    int *vectPoids;
    double biais;
    int dimEntree;
    double tauxAppren;
}perceptron;

perceptron *creaPerceptron(int dimin, double taux);
void libePerceptron(perceptron *p);