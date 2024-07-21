#include "random_value.h"

int get_random_value()
{
	return get_random_value(100);
}

int get_random_value(int max_value)
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	return random_value;
};