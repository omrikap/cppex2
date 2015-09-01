#include "Manager.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Manager theManager = Manager();
	theManager.readSongsFromFile("/media/sf_labcpp/ex2/school_sol/test_examples/songs_1.in");
    return 0;
}