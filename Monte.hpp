#ifndef MONTE_HPP
#define MONTE_HPP	

#include "Generator.hpp"
#include <math.h>

class Monte{
	private:
		Generator gen;
		string results;
		int caught;


	public:
		Monte(string file);
		void newFile(string file);
		void readItems();
		string getReview();
		string printResults();
};

#endif
