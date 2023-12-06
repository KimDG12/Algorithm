#include "genetic_algorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializePopulation(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        for (int j = 0; j < GENE_LENGTH; ++j) {
            population[i].genes[j] = rand() % 2; // Binary genes for simplicity
        }
        population[i].fitness = 0;
    }
}

void calculateFitness(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        // Dummy fitness function: Sum of genes
        population[i].fitness = 0;
        for (int j = 0; j < GENE_LENGTH; ++j) {
            population[i].fitness += population[i].genes[j];
        }
    }

    // Sort population based on fitness
    qsort(population, POPULATION_SIZE, sizeof(Individual), compareFitness);
}

void crossover(Individual parent1, Individual parent2, Individual* child1, Individual* child2) {
    int crossoverPoint = rand() % GENE_LENGTH;

    for (int i = 0; i < crossoverPoint; ++i) {
        child1->genes[i] = parent1.genes[i];
        child2->genes[i] = parent2.genes[i];
    }

    for (int i = crossoverPoint; i < GENE_LENGTH; ++i) {
        child1->genes[i] = parent2.genes[i];
        child2->genes[i] = parent1.genes[i];
    }
}

void mutate(Individual* individual) {
    for (int i = 0; i < GENE_LENGTH; ++i) {
        if ((rand() / (double)RAND_MAX) < MUTATION_RATE) {
            individual->genes[i] = 1 - individual->genes[i]; // Flip the bit
        }
    }
}

void printPopulation(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        printf("Individual %d - Genes: ", i);
        for (int j = 0; j < GENE_LENGTH; ++j) {
            printf("%d", population[i].genes[j]);
        }
        printf(" | Fitness: %d\n", population[i].fitness);
    }
}

int compareFitness(const void* a, const void* b) {
    return ((const Individual*)b)->fitness - ((const Individual*)a)->fitness;
}