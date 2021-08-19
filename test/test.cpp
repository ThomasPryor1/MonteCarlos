#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Generator.hpp"


TEST_CASE("class Generator")
{
	Generator gen("t1.txt");
	
	REQUIRE(gen.getBatches() == 200);
	REQUIRE(gen.getItems() == 1000);
	REQUIRE(gen.getBadBatches() == 25);
	REQUIRE(gen.getBadItems() == 15);
	REQUIRE(gen.getSampled() == 50);
	gen.makeFiles();


}

//TEST_CASE("class Brute")
//{


//}

//TEST_CASE("class NodeController")
//{
  
//  REQUIRE(NodeController.Delete() == "INSERT CHECK FOR DELETION HERE");

//  REQUIRE(NodeController.Add() == "INSERT CHECK FOR INSERTION HERE");
  
//}

