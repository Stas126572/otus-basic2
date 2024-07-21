#include "check_value.h"
#include "high_scores.h"
#include "random_value.h"

#include <iostream>


int main(int argc, char** argv) {

	int a;
	a = get_random_value();


	// To check - does use print some other argument we should check if the argc >= 2
	if (argc >= 2) {

		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max")
		{
			// We've detected the '-max' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value! Write --help to now what you can write." << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			a = get_random_value(std::stoi(argv[2]));
		}
		else if(arg1_value == "-tester")
		{
			AppendHightScore("scores.txt", 10, "Stat");
			InputHightScore("scores.txt");
			return 0;
		}
		else if(arg1_value == "-table" || arg1_value == "-tbl")
		{
			InputHightScore("scores.txt");
			return 0;
		}
		else if(arg1_value == "--help")
		{
			std::cout << "This is help. If you doesn't now rules, write --rules. If you want to set the maximum value to which you want to guess, enter --max.";
			return 0;
		}
		else if(arg1_value == "--rules")
		{		
			std::cout << "This is rules. If you need help, write --help. This is a guess the number game. Rules of the game: the computer guesses a number, the user tries to guess it. The user says the number. The computer compares the number with the correct one, and says more if the number is greater, less if the number is less, and you win if the number is equal. An effective way: binary search.";
			return 0;
		}
		else
		{
			std::cout << "This is invalid argument. To find out which arguments can be used, enter --help.";
			return -1;
		}
	}

	std::string n;
	std::cout << "You doesn't now what is this? Write --help" << std::endl;
	std::cout << "Hi! Enter your name, please: " << std::endl;
	std::cin >> n;

	a = play_game(a);

	std::cout << " " << "attempts" << " = " << a << std::endl;

	AppendHightScore("scores.txt", a, n);
	InputHightScore("scores.txt");
	return 0;
}