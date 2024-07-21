#include "high_scores.h"

int AppendHightScore(const std::string high_scores_filename, int attempts_count, const std::string user_name)
{
	std::ofstream out_file{high_scores_filename, std::ios_base::app};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;
	out_file.close();
		return 0;
};

int InputHightScore(const std::string high_scores_filename)
{
	std::fstream file_source;
	file_source.open(high_scores_filename);
	if (!file_source.is_open())
	{
		
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string name_user;
	int score_max = 0;

	int length = 0;
//GetDatas
//---------------------------------------------------------------------------------------------------------------

	for (length=0;!file_source.fail();length++)
	{
		file_source >> name_user;
		file_source >> score_max;
		file_source.ignore();
	}

	std::string* massive_name_user = new std::string[length];
	int* massive_score_max = new int[length];
	
	file_source.clear();
	file_source.seekg(0);
	for (int i=0;!file_source.fail();i++)
	{
		file_source >> name_user;
		file_source >> score_max;
		massive_name_user[i] = name_user;
		massive_score_max[i] = score_max;
		file_source.ignore();
	}

	file_source.close();

//Data processing
//---------------------------------------------------------------------------------------------------------------


	std::string* lot_unique_name_user = new std::string[length];

	std::string name_current;
	bool is_unique;

	int num_unique_elements = 0;
	for (int i = 0; i<length; i++)
	{
		name_current = massive_name_user[i];
		is_unique = true;
		for (int j = 0; j<num_unique_elements; j++)
		{
			if (lot_unique_name_user[j] == name_current)
			{
				is_unique = false;
				break;
			}
		}
		if (is_unique)
		{
			lot_unique_name_user[num_unique_elements] = name_current;
			num_unique_elements++;
		}
	}

	int** dict_score_users = new int*[num_unique_elements];
	int* indexes = new int[num_unique_elements];

	for (int i = 0; i<num_unique_elements; i++)
	{
		dict_score_users[i] = new int[length];
		indexes[i] = 0;
		for (int j = 0; j<length; j++)
		{
			dict_score_users[i][j] = -1;
		}
	}

	for (int i = 0; i<length; i++)
	{
		for (int j = 0; j<num_unique_elements; j++)
		{
			if (massive_name_user[i]==lot_unique_name_user[j])
			{
				dict_score_users[j][indexes[j]] = massive_score_max[i];
				indexes[j]+=1;
			}
		}
	}

	int* best_score_player = new int[num_unique_elements];

	for (int i=0; i<num_unique_elements; i++)
	{
		best_score_player[i] = -1;
	}
	
	for (int i = 0; i<num_unique_elements; i++)
	{
		for (int j = 0; j<length; j++)
		{
			int a = dict_score_users[i][j];
			if (a!=-1)
			{
				if (best_score_player[i] == -1 || best_score_player[i] > a)
				{
					best_score_player[i] = a;
				}
			}
		}
	}	


//Input Text
//---------------------------------------------------------------------------------------------------------------

	for (int i = 0; i<num_unique_elements; i++)
	{
		std::cout << lot_unique_name_user[i] << " " << best_score_player[i] << std::endl;
	}

	std::cout << std::endl;
	return 0;
}