#include "Generator.hpp"



Generator::Generator() {

}


Generator::Generator(string file) {
	myfile.open(file);
	
	myfile >> batches;
	myfile >> items;
	myfile >> badBatches;
	myfile >> badItems;
	myfile >> sampled;

	run();
		
}

void Generator::newFile(string file) {
	myfile.open(file);	
	
	myfile >> batches;
	myfile >> items;
	myfile >> badBatches;
	myfile >> badItems;
	myfile >> sampled;
	run();
}

void Generator::run() {
	result = "";

	result = "Number of batches of items: " + to_string(batches);
	result += "\nNumber of items in each batch: " + to_string(items);
	result += "\nPercentage of batches containing bad items: " + to_string(badBatches) + "%";
	result += "\nPercentage of items that are bad in a bad set: " + to_string(badItems) + "%";
	result += "\nItems sampled from each set: " + to_string(sampled);

	result += "\nGENERATING DATA SETS: \n";


}

string Generator::getResults() {
	return result;
}

void Generator::makeFiles() {
	badfiles = 0;
	for(int i = 0; i < batches; i++) { 
		fstream NewFile;
		NewFile.open("./Datasets/ds" + to_string(i + 1) + ".txt", fstream::out);
		count = 0;
		if(rand() % 100 < badBatches - 1) {
			badfiles++;
			for(int j = 0; j < items; j++) {
				if(rand() % 100 <= badItems - 1) {
				       NewFile << "b\n";
				       count++;
				}
		 		else {
					NewFile << "g\n";
				}		
			}
			result += "Create bad set batch # " + to_string(i+1) + ", Total Bad = " + to_string(count) + ", Total Items = " + to_string(items) + ", Bad Items Percent = " + to_string(badItems) + "\n"; 
	
		}

		else {
			for(int j = 0; j < items; j++) {
				NewFile << "g\n";
			}
		}
		NewFile.close();
	}

	result += "\n Total bad sets = " + to_string(badfiles) + "\n";
}

int Generator::getItems() {
	return items;
}

int Generator::getBatches() {
	return batches;
}

int Generator::getBadItems() {
	return badItems;
}

int Generator::getSampled() {
	return sampled;
}

int Generator::getBadBatches() {
	return badBatches;
}

int Generator::getBadFiles() {
	return badfiles;
}

