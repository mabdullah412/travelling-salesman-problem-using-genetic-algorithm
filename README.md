# travelling-salesman-problem-using-genetic-algorithm

The Traveling Salesman Problem (TSP) is a well-known optimization problem that involves finding the 
shortest possible route that visits every city exactly once and returns to the starting city. In this 
assignment, you will use a Genetic Algorithm (GA) to solve a TSP instance.


Your task is to implement a GA that can solve a given TSP instance. You should use the following steps:
- Generate an initial population of solutions. Each solution should represent a possible route 
through the cities, i.e., a permutation of the city indices.
- Evaluate the fitness of each solution. The fitness should be the total distance traveled by the 
route.
- Select the fittest individuals from the population. You should use a selection method that favors 
the fittest individuals, such as tournament selection or roulette wheel selection.
- Create new offspring by applying crossover and mutation operations to the selected individuals. 
You should use a crossover method that preserves the order of the cities, such as order 
crossover (OX) or partially mapped crossover (PMX). You should also apply mutation to the 
offspring, to introduce new variations.
- Evaluate the fitness of the new offspring.
- Replace the weakest individuals in the population with the new offspring.
- Repeat steps 3-6 until a termination condition is met, such as a maximum number of 
generations or a convergence criterion.
