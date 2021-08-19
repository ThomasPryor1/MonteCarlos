#include "Monte.hpp"

int main() {
	
	for (int i = 1; i <= 4; i++) {
		Monte monte("t" + to_string(i) + ".txt");
		monte.readItems();
		cout << "SIMULATION " + to_string(i) << endl;
		cout << monte.printResults() << endl;


	}

	
		

	return 0;
}
