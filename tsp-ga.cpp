#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// number of cities
#define CITIES 8
// starting city
#define START_CITY 0
// genetic algorithm population
#define POPULATION 10
// threshold
#define THRESHOLD 10
// represents no connection
#define NO_CONNECTION 9999

// map that contains distance between cities. it is initialzed in main function
int map[CITIES][CITIES];

// class that holds an individual chromosome data
class Chromosome
{
private:
    string chromosome;
    int fitness;

public:
    Chromosome(string chromosome)
    {
        this->chromosome = chromosome;
        this->fitness = calculate_fitness();
    }

    // return chromosome
    string get_chromosome() { return chromosome; }
    // return fitness
    int get_fitness() { return fitness; }

    // the fitness represents the total distance travelled by the route
    int calculate_fitness()
    {
        int temp_fitness = 0;
        for (int i = 0; i < chromosome.size() - 1; i++)
        {
            if (map[int(chromosome[i])][int(chromosome[i + 1])] == NO_CONNECTION)
                return NO_CONNECTION;

            temp_fitness += map[chromosome[i] - 48][chromosome[i + 1] - 48];
        }
        return temp_fitness;
    };

};

Chromosome mutate(Chromosome chromosome)
{
    string new_chromosome = chromosome.get_chromosome();

    while (true)
    {
        int a = 1 + rand() % (CITIES - 1);
        int b = 1 + rand() % (CITIES - 1);
        if (a != b)
        {
            char temp = new_chromosome[a];
            new_chromosome[a] = new_chromosome[b];
            new_chromosome[b] = temp;
            break;
        }
    }

    return Chromosome(new_chromosome);
};

bool repeated(string s, char ch)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch)
            return true;
    }
    return false;
}

string create_chromosome()
{
    string chromosome = to_string(START_CITY);

    while (chromosome.size() < CITIES)
    {
        int temp = 1 + rand() % (CITIES - 1);
        if (!repeated(chromosome, to_string(temp)[0]))
        {
            chromosome += to_string(temp);
        }
    }
    chromosome += to_string(START_CITY);

    return chromosome;
}

bool lessthan(Chromosome a, Chromosome b)
{
	return a.get_fitness() < b.get_fitness();
}

void travelling_salesman_problem()
{
    vector<Chromosome> population;
    int generation = 0;

    // populating initial chromosomes
    for (int i = 0; i < POPULATION; i++)
    {
        Chromosome chromosome = Chromosome(create_chromosome());
        population.push_back(chromosome);
    }
    
    // printing initial population
    cout << "Initial Population:\n";
    cout << "Generation: " << generation << "\n";
    cout << "CHROMOSOME\tFITNESS\n";
    for (int i = 0; i < POPULATION; i++)
    {
        cout << population[i].get_chromosome() << "\t\t" << population[i].get_fitness() << "\n";
    }
    
    // 
    while (generation <= THRESHOLD)
    {
        sort(population.begin(), population.end(), lessthan);
        vector<Chromosome> new_population;

        for (int i = 0; i < POPULATION; i++)
        {
            Chromosome new_chromosome = mutate(population[i]); 
            if (new_chromosome.get_fitness() <= population[i].get_fitness())
            {
                new_population.push_back(new_chromosome);
            } else {
                new_population.push_back(population[i]);
            }
        }

        population = new_population;

        cout << "\nGeneration: " << generation << "\n";
        cout << "CHROMOSOME\tFITNESS\n";
        for (int i = 0; i < POPULATION; i++)
        {
            cout << population[i].get_chromosome() << "\t\t" << population[i].get_fitness() << "\n";
        }

        generation++;
    }
    
}

int main()
{
    srand((unsigned)(time(0)));

    // creating a new graph/map of cities with random weights.
    for (int i = 0; i < CITIES; i++)
    {
        for (int j = i; j < CITIES; j++)
        {
            int temp_dist = 1 + rand() % 10;
            map[i][j] = temp_dist;
            map[j][i] = temp_dist;
        }
    }

    // printing the graph and its values
    cout << "------------------ MAP ------------------\n";
    char characters[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for (int i = 0; i < CITIES; i++)
    {
        cout << "\t" << characters[i];
    }
    cout << "\n\n";
    for (int i = 0; i < CITIES; i++)
    {
        cout << characters[i];
        for (int j = 0; j < CITIES; j++)
        {
            cout << "\t" << map[i][j];
        }
        cout << "\n";
    }
    cout << "-----------------------------------------\n\n";

    travelling_salesman_problem();

    return 0;
}