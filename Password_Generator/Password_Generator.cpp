// Password_Generator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;
int main()
{
	setlocale (LC_ALL, "RUS");

	//read symbols from the file
	std::ifstream Stream;
	Stream.open ("C:\\Users\\kiraz\\Desktop\\Symbols.txt");
	string anInputLine;
	getline (Stream, anInputLine, '\0');
	Stream.close();

	//make a random generator
	std::random_device rd;
	std::mt19937 g (rd());

	//shuffle symbols and create a password
	std::shuffle (anInputLine.begin(), anInputLine.end(), g);
	string password = "";
	for (int i = 0; i < 13; ++i) {
		password += anInputLine [i];
	}

	std::cout << "Ваш пароль: " << password << endl;
	system ("pause");

	return 0;
}


