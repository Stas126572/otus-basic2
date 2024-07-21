#include "check_value.h"


int play_game(int target_value){
	int current_value = 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	int i=0;

	for (;;)
	{
		std::cin >> current_value;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}
		i++;
	}

	return i;
}