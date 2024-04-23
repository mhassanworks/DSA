// C++ program to demonstrate Pointer to Structure
#include <iostream>

using namespace std;

struct point {
	int value;
};

int main()
{

	struct point g;
	// Initialization of the structure pointer
	struct point* ptr = &g;

	return 0;
}
