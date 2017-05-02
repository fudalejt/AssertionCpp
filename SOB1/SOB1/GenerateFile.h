#pragma once
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <cassert>
using namespace std;

template<typename Type>
class GenerateFile
{
public:
	GenerateFile(std::string path, int min, int max, int count);
	virtual ~GenerateFile();
	void generateFile(string path);
	void setMinMax(int min, int max);

private:
	std::string path;
	int min, max;
	int count;
};

template<typename Type>
GenerateFile<Type>::GenerateFile(std::string path, int min, int max, int count)
{
	assert(min < max);
	assert(count > 0);
	this->min = min;
	this->max = max;
	this->count = count;
}

template<typename Type>
GenerateFile<Type>::~GenerateFile()
{
}

template<typename Type>
void GenerateFile<Type>::generateFile(string path)
{
	srand(time(NULL));
	std::ofstream file(path);
	assert(file.good());
		
	if (is_integral<Type>::value) {
		for (int i = 0; i < count; i++) {
			file << rand() % (max - min) + min << endl;
		}
	}
	else if (is_floating_point<Type>::value) {
		for (int i = 0; i < count; i++) {
			file << (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * (max - min)  + min << endl;
		}
	}
	else 
		assert(false);	
	
	file.close();
}

template<typename Type>
void GenerateFile<Type>::setMinMax(int min, int max)
{
	assert(min < max);
	min = min;
	max = max;
}

