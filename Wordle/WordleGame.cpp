#include<fstream>
#include<string>
#include<set>
#include <iostream> // just for debugging 
#include <algorithm> // to use find algorithm
#include "WordleGame.h"

using namespace std;

WordleGame::WordleGame(const string& filename) {
	ifstream myfile(filename);
	string word;
	myfile >> word;
	while (myfile) {
		dictionary.insert(word);
		myfile >> word;
	}
}

void WordleGame::select_key(int index) {
	set<string>::iterator s_iter;
	int to_find_i = 1;
	int f_index = index % dictionary.size();
	for (s_iter = dictionary.begin(); s_iter!= dictionary.end(); s_iter++) {
		if (to_find_i == f_index) {
			key = *s_iter;
			break;
		}
		to_find_i++;
	}
}

string WordleGame::score(const std::string& input) {
	string score = "-----";
	//bool multiple = false;
	// int num1;
	// int num2;

	int repetitions = 0;
	int allowed_repetitions;


	for (unsigned int i = 0; i < input.size(); i++) {
		allowed_repetitions = count(key.begin(), key.end(), input[i]);
		for (unsigned int j = 0; j < key.size(); j++) {
			if(i == j && key[j] == input[i]) {
				score[i] = '*';
			} else if (key[j] == input[i]){
				if(repetitions < allowed_repetitions) {
					score[j] = '*';
				}
				// num1 = count(input.begin(), input.end(), [](char c){return key[j] == c});
				// num2 = count(key.begin(), key.end(), [](char c){return input[i] == c});
				// if (num1 != num2) {score[i] = '-';} else {score[i] = '+';}
			}						
			 
		}
	}

	auto is_in_dic = find(dictionary.begin(),dictionary.end(),input);
	if (input.size() > 5 || is_in_dic == end(dictionary)) {
		score = "not in dictionary";
		return score;
	}

	if (input == key) {done = true;} else {done = false;};
	return score;
}

bool WordleGame::over(void) const {
	return done;
}