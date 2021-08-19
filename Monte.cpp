#include "Monte.hpp"

Monte::Monte(string file) {
	gen.newFile(file);
	gen.makeFiles();
	caught = 0;

}

void Monte::newFile(string file) {
	gen.newFile(file);
	gen.makeFiles();
	caught = 0;
}

void Monte::readItems() {
	results = "";
	results = "\nANALYZING DATA SETS: \n";
	bool iscaught = false;
	for(int i = 0; i < gen.getBatches() - 1; i++) {
		fstream myfile("./Datasets/ds" + to_string(i+1) + ".txt");
		iscaught = false;
		for(int j = 0; j < gen.getSampled() - 1; j++) {
			string chip;
			getline(myfile, chip);
			
			if((chip == "b") && (iscaught == false)) {
				caught++;
				//cout << caught;
				iscaught = true;
				results += "batch #" + to_string(i+1) + " is bad\n";
			}
		}
	}


}

string Monte::getReview() {
	string temp = "";


	double bad =  ((double) caught / gen.getBadFiles());
	double num1 = (100.0 - gen.getBadItems()) / 100.0;
	double num2 = 0.0 + gen.getSampled();
	
	temp += "\nBase = " + to_string(num1) + " exponent = " + to_string(num2);
	temp += "\nP(failure to detect bad batch = " + to_string(pow(num1,num2 ) );
	temp += "\nPercentage of bad batches actually detected = " + to_string(bad * 100) + "%\n";

	return temp;
}

string Monte::printResults() {
	string output = "";
	
	output += gen.getResults();
	
	output += results;

	output += getReview();
	
	return output;
}
