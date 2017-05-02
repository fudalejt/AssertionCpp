#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include<cassert>
#include "Queue.h"

template<class T>
T stringToValue(string str) {
	istringstream iss(str);
	T value;
	iss >> value;
	return value;
}


template <typename Type>
class ReadFile
{
public:
	ReadFile(std::string path);
	virtual ~ReadFile();
	void readFile(string path, qu::Queue<Type> &queue, const Type min, const Type max);

private:
	std::string path;
};


template <typename Type>
ReadFile<Type>::ReadFile(std::string path)
{
	path = path;
}

template <typename Type>
ReadFile<Type>::~ReadFile()
{
}

template <typename Type>
void ReadFile<Type>::readFile(string path, qu::Queue<Type> &queue, const Type min, const Type max)
{
	std::fstream file;
	file.open(path, std::ios::in);
	assert(file.good());
	string s;
	
	while (true)
	{
		file >> s;
		if (!file.eof()) {
			auto d = stringToValue<Type>(s);
			QueueElement<Type> *newEl = new QueueElement<Type>(d);
			assert(newEl);
			bool flag = queue.addWithBoundary(newEl, min, max);
			assert(flag);
		}
		else
			break;
	}
}



