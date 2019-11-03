#include "random.h"



RandomNumbers::RandomNumbers(unsigned long int seed) {
    if (seed == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper) {
	std::uniform_real_distribution<> uniform(lower, upper);
	for (auto V = vec.begin(); V != vec.end(); V++) *V = uniform(rng);
	}

double RandomNumbers::uniform_double(double lower, double upper) {
	std::uniform_real_distribution<> uniform(lower, upper);
	return uniform(rng);
	}

void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd) {
	std::normal_distribution<> normal(mean, sd);
    for (auto V = vec.begin(); V != vec.end(); V++) *V = normal(rng);
	}

double RandomNumbers::normal(double mean, double sd) {
	std::normal_distribution<> normal(mean, sd);
	return normal(rng);
	}
	
void RandomNumbers::poisson(std::vector<int>& vec, double mean) {
    std::poisson_distribution<int> poisson(mean);
    for (auto V = vec.begin(); V != vec.end(); V++) *V = poisson(rng);
	}
    
int RandomNumbers::poisson(double mean) {
	std::poisson_distribution<int> poisson(mean);
	return poisson(rng);
	}
