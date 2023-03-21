#pragma once

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void cls() {
	system("cls");
}

void print(string txt, short spd) {
	short x = 0;
	// Prints out the words letter-by-letter until the end character '\0'. 
	while (txt[x] != '\0') {
		cout << txt[x];
		sleep_for(milliseconds(spd)); // spd default is '1'.
		x++;
	}
}

void opMenu() {

}