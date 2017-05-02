/*
Main function is used to testing the list (named queue here, but it's a wrong name of this structure :)
*/

//#define NDEBUG ///if included, assertions are avoiding in comilation 
#include <iostream>
#include "GenerateFile.h"
#include "ReadFile.h"
#include "Queue.h"
#include "QueueElement.h"
using namespace std;

string fileName = "inputFile.txt";
string typ = "int";

/*
ARGS is class for to keep main function argumens in variables with appropriate types of data. 
*/
template <typename Type>
class Args
{
public:
	Type randomMin;
	Type randomMax;
	Type boundMin;
	Type boundMax;
	Type numbersCount; 
	string fileName; 

	Args(Type randMin, Type randMax, Type boundmin, Type boundmax, Type count, string file) {
		randomMin = randMin;
		randomMax = randMax;
		boundMin = boundmin;
		boundMax = boundmax;
		numbersCount = count;
		fileName = file;
	}
};

/*
A core of main function. Separated, because we need to test the list for two types of data (int or float), so we need to the template function.
*/
template <typename Type>
void mainFunc(Args<Type> args) {
	//make list
	qu::Queue<Type> queue;

	//generate pseudo-random input data and save they to the file
	GenerateFile<Type> gf(args.fileName, args.randomMin, args.randomMax, args.numbersCount);
	gf.generateFile(args.fileName);

	//read input data with boundary of values
	ReadFile<Type> rf(args.fileName);
	rf.readFile(fileName, queue, -99, 100);

	queue.remove();
}


int main(int argc, char * argv[]) {	
	//cout << "Arguments: randMin, randMax, boundmin, boundmax, count, fileName" << endl;
	
	///if count of arguments is wrong, the program will be working with default arguments
	if (argc == 7) {
		if (strcmp(argv[1], "float\n")) {
			Args<float> args(stringToValue<float>(argv[1]), stringToValue<float>(argv[2]), stringToValue<float>(argv[3]), stringToValue<float>(argv[4]), stringToValue<float>(argv[5]), argv[6]);
			mainFunc<float>(args);
		}
		else if (strcmp(argv[1], "int\n")) {
			Args<int> args(stringToValue<int>(argv[1]), stringToValue<int>(argv[2]), stringToValue<int>(argv[3]), stringToValue<float>(argv[4]), stringToValue<float>(argv[5]), argv[6]);
			mainFunc<int>(args);
		}
		else {
			assert(strcmp(argv[1], "float\n") || strcmp(argv[1], "int\n"));
		}
	}
	else {
		Args<int> args(-50, 50, -49, 49, 20, fileName);
		mainFunc<int>(args);
	}
	
	cin.ignore();
	cout << "END." << endl;
	return 0;
}


