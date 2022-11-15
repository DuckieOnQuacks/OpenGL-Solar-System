#include <iostream>
#include "engine.h"

//Input: command line argument.
//Output: 0
//Purpose: Main code that is run first. Made to Start an engine and run it then cleanup after.
int main(int argc, char** argv)
{
	//Create the engine
	Engine* engine = new Engine("Tutorial Window Name", 800, 600); //Initilize window of size 800x600 called "Tutorial Window Name"

	// Engine initialization
	//Check to see if engine was successfully initialized
	if (!engine->Initialize()) 
	{
		printf("The engine failed to start.\n");
		delete engine;
		engine = NULL;
		return 1;
	}
	
	// Run the engine as long as it exists
	engine->Run();

	// Destroy the engine after it has run.
	delete engine;
	engine = NULL;

	return 0;
}
