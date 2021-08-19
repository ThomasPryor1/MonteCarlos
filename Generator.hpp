#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Generator{
	private:
		fstream myfile;
		int items = 0;
		int batches = 0;
		int badBatches = 0;
		int badItems = 0;
		int sampled = 0;
		int count = 0;
		int badfiles = 0;
		string result = "";;
	public:
		Generator();
		Generator(string file);
		void newFile(string file);
		string getResults();
		void run();
		void makeFiles();
		int getItems();
		int getBatches();
		int getBadItems();
		int getSampled();
		int getBadBatches();
		int getBadFiles();
	
};

#endif
