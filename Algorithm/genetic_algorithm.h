#pragma once
#define GENETIC_ALGORITHM_H

#define POPULATION_SIZE 10
#define GENE_LENGTH 5
#define MAX_GENERATIONS 100
#define MUTATION_RATE 0.1

typedef struct {
    int genes[GENE_LENGTH];
    int fitness;
} Individual;

void initializePopulation(Individual population[]);
void calculateFitness(Individual population[]);
void crossover(Individual parent1, Individual parent2, Individual* child1, Individual* child2);
void mutate(Individual* individual);
void printPopulation(Individual population[]);
int compareFitness(const void* a, const void* b);