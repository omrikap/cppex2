#include "Manager.h"
#include <iostream>

using namespace std;

int main() {
    Manager theManager = Manager();
	theManager.readParametersFromFile("/media/sf_labcpp/ex2/school_sol/test_examples/parameters_2"
			                                  ".in");
	theManager.readSongsFromFile("/media/sf_labcpp/ex2/school_sol/test_examples/songs_2.in");
	theManager.giveScores();
    return 0;
}