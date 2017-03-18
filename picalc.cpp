#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cmath>
#include <cfloat>
#include <random>

/*****************************************************************************************/
// Wrapper for random number generator (RNG)
/*****************************************************************************************/
typedef std::uint_fast32_t random_num_type;

std::random_device seed_generator;
std::mt19937 gen(seed_generator());

random_num_type generate_number()
{
	return gen();
}

/*****************************************************************************************/
// GCD Calculator (Euclid's Devision Algorithm)
/*****************************************************************************************/
random_num_type gcd(random_num_type a, random_num_type b)
{
	while (b != 0)
	{
		a %= b;
		if (a == 0) return b;
		b %= a;
	}
	return a;
}

/*****************************************************************************************/
// GCD Calculator (Euclid's Devision Lemma/Algorithm)
/*****************************************************************************************/
int main()
{
	int count_coprime = 0, trials;

	std::cout << "Enter the number of number pairs/number of trials to use: ";
	std::cin >> trials;
	while(trials < 1000)
	{
		std::cout << "The number of trials must be greater than 1000." << std::endl;
		std::cout << "Enter the number of number pairs/number of trials to use: ";
		std::cin >> trials;
	}
	std::cout << std::endl;

	int trials_per_percent = trials / 100;
	for (int i = trials; i > 0; i--)
	{
		random_num_type a = generate_number();
		random_num_type b = generate_number();
		if (gcd(a, b) == 1) count_coprime++;

		if (i%trials_per_percent == 0) std::cout << ".";
	}
	std::cout << std::endl;

	if (count_coprime == 0)
	{
		std::cout << "The experiment was not successful.";
		std::cin >> trials;
		return 0;
	}

	double pi = std::sqrt(static_cast<double>(6*trials)/count_coprime);
	std::cout << std::endl << "Out of " << trials << " pairs of random numbers, " <<count_coprime<< " pairs of numbers were coprime." << std::endl;
	std::cout << std::setprecision(DBL_DIG)<< "Approximate value of pi is: " << pi;
	std::cin >> trials;
	return 0;
}
