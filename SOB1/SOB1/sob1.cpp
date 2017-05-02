//#define NDEBUG
#include <iostream>
#include "GenerateFile.h"
#include "ReadFile.h"
#include "Queue.h"
#include "QueueElement.h"
using namespace std;

//boundary of the number generation
int randomMin = -50;
int randomMax = 100;
//count of generated numbers
int numbersCount = 20;

string fileName = "inputFile.txt";
string typ = "int";

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

template <typename Type>
void mainFunc(Args<Type> args) {
	qu::Queue<Type> queue;

	GenerateFile<Type> gf(args.fileName, args.randomMin, args.randomMax, args.numbersCount);
	gf.generateFile(args.fileName);

	ReadFile<Type> rf(args.fileName);
	rf.readFile(fileName, queue, -99, 100);

	queue.remove();
}


int main(int argc, char * argv[]) {	
	cout << "Arguments: randMin, randMax, boundmin, boundmax, count, fileName" << endl;
	
	assert(strcmp(argv[1], "float\n") || strcmp(argv[1], "int\n"));

	if (argc == 7 && strcmp(argv[1], "float\n")) {
		Args<float> args(stringToValue<float>(argv[1]), stringToValue<float>(argv[2]), stringToValue<float>(argv[3]), stringToValue<float>(argv[4]), stringToValue<float>(argv[5]), argv[6]);
		mainFunc<float>(args);
	}
	else if (argc == 7 && strcmp(argv[1], "int\n"))	{
		Args<int> args(stringToValue<int>(argv[1]), stringToValue<int>(argv[2]), stringToValue<int>(argv[3]), stringToValue<float>(argv[4]), stringToValue<float>(argv[5]), argv[6]);
		mainFunc<int>(args);
	}	

	cin.ignore();
	cout << "END." << endl;
	return 0;
}


