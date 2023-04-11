#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include <array>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void cls() {
	system("cls");
}

void cinFlush() {
	cin.clear(); // Clears any error flags in the input stream.
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores all characters up until the newline character.
}

void pause() {
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << endl;
}

bool charComp(string badChars, char temp) {
	unsigned short x = 0;
	while (badChars[x] != '\0') {
		if (badChars[x] == temp) {
			return false; // Character already exists.
		}
		else {
			x++;
		}
	}
	return true;
}

void print(string txt, short spd = 1, bool divider = false, bool modified = false, bool noSpace = false, bool neither = false, string badChars = "") {
	short x = 0;
	// Prints out the words letter-by-letter until the end character '\0' with or without the modifiers.

	// Prints without spaces.
	if (noSpace) {
		while (txt[x] != '\0') {
			if (txt[x] == ' ') {
				x++;
			}
			else {
				cout << txt[x];
				sleep_for(milliseconds(spd));
				x++;
			}
		}
		return;
	}

	// Prints with a divider.
	if (divider) {
		while (txt[x] != '\0') {
			if (txt[x + 1] == '\0') {
				cout << txt[x] << ".";
				sleep_for(milliseconds(spd));
				x++;
			}
			else {
				cout << txt[x] << ", ";
				sleep_for(milliseconds(spd));
				x++;
			}
		}
		return;
	}

	if (neither) {
		while (txt[x] != '\0') {
			if (charComp(badChars, txt[x]) && txt[x] != ' ') {
				cout << txt[x];
				sleep_for(milliseconds(spd));
			}
			x++;
		}
		return;
	}

	if (!modified) {
		while (txt[x] != '\0') {
			cout << txt[x];
			sleep_for(milliseconds(spd));
			x++;
		}
		return;
	}
	// Prints without the characters in the list.
	else if (modified) {
		while (txt[x] != '\0') {
			if (charComp(badChars, txt[x])) {
				cout << txt[x];
				sleep_for(milliseconds(spd));
			}
		x++;
		}
		return;
	}
}

void border(short spd, bool isBottom = false) { // Maybe remove this (isnt being used anywhere?
	if (isBottom) {
		cout << "\n";
	}
	print("*****************************************************************", spd);
	if (isBottom) {
		// Add stuff here...
	}
	else if (!isBottom) {
		cout << "\n";
	}
}

short cCounter(string txt, bool withoutSpaces = false, bool withoutBadChars = false, bool withoutBoth = false, string badChars = "") {
	short x = 0, y = 0, z = 0, yz = 0;
	while (txt[x] != '\0') {
		if (txt[x] == ' ') {
			y++;
		}
		if (!charComp(badChars, txt[x])) {
			z++;
		}
		x++;
	}
	if (withoutSpaces) {
		return (x - y);
	}
	else if (withoutBadChars) {
		return (x - z);
	}
	else if (withoutBoth) {
		yz = y + z;
		return (x - yz);
	}
	else {
		return x;
	}
}

void cll(short spd, string badChars = "", unsigned short overide = 0) { // Find out a way to count the number of characters in a given line so that it can be more optimal.
	unsigned short arrSize;
	if (overide == 0) {
		arrSize = cCounter(badChars);
	}
	else {
		for (short i = 0; i < overide; i++) {
			cout << " ";
			sleep_for(milliseconds(spd));
		}
		return;
	}
	if (arrSize > 0) {
		arrSize = (arrSize * 3) + 14;
		for (short i = 0; i < arrSize; i++) {
			cout << " ";
			sleep_for(milliseconds(spd));
		}
	}
	else if (arrSize == 0) {
		for (short i = 0; i < 22; i++) {
			cout << " ";
			sleep_for(milliseconds(spd));
		}
	}
}

void charStat(string badChars, short spd) {
	if (badChars[0] == '\0') {
		print("Empty...", spd);
	}
	else {
		print(badChars, spd, true);
	}
}

void charCount(string txt, string badChars, short spd) {
	cls();
	print("Original input: \"", spd); print(txt, spd); cout << "\"";
	print("\nNo bad characters: \"", spd); print(txt, spd, false, true, false, false, badChars); cout << "\"";
	print("\nNo spaces: \"", spd); print(txt, spd, false, false, true); cout << "\"";
	print("\nNeither: \"", spd); print(txt, spd, false, false, false, true, badChars); cout << "\"";
	print("\n\nThe total number of characters was: ", spd); print(to_string(cCounter(txt)), spd);
	print("\nThe total number of characters without the ones on the list was: ", spd); print(to_string(cCounter(txt, false, true, false, badChars)), spd);
	print("\nThe total number of characters without spaces was: ", spd); print(to_string(cCounter(txt, true)), spd);
	print("\nThe total number of non-space, non-list characters was: ", spd); print(to_string(cCounter(txt, false, false, true, badChars)), spd);
	print("\nIgnored character list: ", spd); charStat(badChars, spd);
}

bool isGud(short num) {
	if (cin.fail()) {
		// Input could not be interpreted as a short.
		return false;
	}
	else {
		// Input is a valid short.
		return true;
	}
}

void questChar(string& termKey, short spd) {
start:
	cls();
	string temp = "", choice = "";
	print("What keyword would you like to use to terminate this function?\n~> ", spd);
	cin >> temp;
	cls();
	if (temp[1] == '\0') {
		print("Warning: Single letter keywords may lead to undesired outcomes", spd); pause();
	}
	print("Your keyword is: ", spd); print(temp, spd); print("\nAccept? (y/n)\n~> ", spd);
	cin >> choice;
	// The following code is horrific but i do not care...
	if (choice[1] != '\0') {
		print("Input either Y or N", spd); pause();
		goto start;
	}
	if (choice[0] == 'y' || choice[0] == 'Y') {
		termKey = temp;
		return;
	}
	else if (choice[0] == 'n' || choice[0] == 'N') {
		goto start;
	}
	else {
		print("Input either y/Y or n/N", spd); pause();
		goto start;
	}
}

void addChar(string& badChars, string termKey, short spd) {
start:
	cls();
	string temp = "";
	print("Write which character you want to be ignored", spd); print(" (Termination key is: ", spd); print(termKey, spd); cout << ")\n\n";
	print("Current list: ", spd); charStat(badChars, spd);
	cout << "\033[1A \r"; cout << "~> "; cin >> temp;
	if (temp == termKey) {
		return;
	}
	if (temp[1] != '\0') {
		cll(spd, badChars); cout << "\r";
		print("Please only enter only ONE character", spd); pause();
	}
	else if (temp[0] == ' ') {
		print("The counter already has a seperate output with the number of characters excluding spaces", spd); pause();
		goto start;
	}
	else {
		if (charComp(badChars, temp[0])) {
			badChars += temp;
		}
		else {
			cll(spd, badChars); cout << "\r";
			print("Sorry, that character is already on the list", spd); pause();
		}
	}
	goto start;
}

void remChar(string& badChars, string termKey, short spd) {
	string newList = badChars;
start:
	short x = 0, y = 0;
	cls();
	string temp = "";
	print("Write which character you want to remove from the list", spd); print(" (Termination key is: ", spd); print(termKey, spd); cout << ")\n";
	print("\nCurrent list: ", spd); charStat(newList, spd);
	cout << "\033[1A \r"; cout << "~> "; cin >> temp;
	if (temp == termKey) {
		badChars = newList;
		return;
	}
	if (temp[1] != '\0') {
		cll(spd, badChars); cout << "\r";
		print("Please only enter only ONE character", spd); pause();
	}
	else {
		if (!charComp(badChars, temp[0])) {
			/*
			// This function takes a string and a character to remove as input.
			// It uses a loop to find all occurrences of the character in the string,
			// and erases them one by one using the erase() function of the std::string class.
			*/
			size_t pos = newList.find(temp[0]);
			while (pos != std::string::npos) {
				newList.erase(pos, 1);
				pos = newList.find(temp[0]);
			}
		}
		else {
			cll(spd, badChars); cout << "\r";
			print("Sorry, that character is not on the list", spd); pause();
		}
	}
	goto start;
}

void clearChar(string& badChars, short spd) {
start:
	cls();
	string temp = "";
	print("Clear all characters in list? (y/n)\n\n", spd);
	print("Current list: ", spd); charStat(badChars, spd);
	cout << "\033[1A \r"; cout << "~> "; cin >> temp;
	if (temp[1] != '\0') {
		cll(spd, badChars); cout << "\r";
		print("Please only enter only ONE character", spd); pause();
	}
	else if (temp[0] == 'y' || temp[0] == 'Y') {
		if (badChars[0] == '\0') {
			cls();
			print("List is already empty", spd); pause();
		}
		badChars = "";
		return;
	}
	else if (temp[0] == 'n' || temp[0] == 'N') {
		return;
	}
	else {
		cll(spd, badChars); cout << "\r";
		print("Please enter either 'y' or 'n'", spd); pause();
	}
	goto start;
}

void spdChange(short& spd) {
start:
	string choice;
	cls();
	print("Use Print Scrolling?\n", spd);
	if (spd) {
		print("Currently set to: TRUE.", spd);
	}
	else {
		print("Currently set to: FALSE.", spd);
	}
	print("\nChange? (y/n)\n~> ", spd);
	cin >> choice;

	if (choice[1] != '\0') {
		print("Sorry that input is invalid, try again", spd); cinFlush(); pause();
		goto start;
	}

	if ((choice[0] == 'y' || choice[0] == 'Y') && spd) {
		spd = 0;
	}
	else if ((choice[0] == 'y' || choice[0] == 'Y') && !spd) {
		spd = 1;
	}
	else if (choice[0] == 'n' || choice[0] == 'N') {
		return;
	}
	goto start;
}

string sortString(string txt) {
	std::sort(txt.begin(), txt.end());
	return txt;
}

void alphabetise(string& txt, short spd) {
start:
	cls();
	string choice;
	print("Do you want to alphabetise the list (y/n)?\n", spd);
	if (txt[0] == '\0') {
		print("\nCurrent list: Empty...", spd);
		cout << "\033[2A \r"; print("\n~> ", spd);
	}
	else if (txt[0] != '\0') {
		print("\nCurrent list: ", spd); print(txt, spd, true);
		print("\nAlphabetised: ", spd); print(sortString(txt), spd, true);
		cout << "\033[3A \r"; print("\n~> ", spd);
	}
	cin >> choice;

	if (choice[1] != '\0') {
		cll(spd, txt); cout << "\r";
		print("Sorry that input is invalid, try again", spd); cinFlush(); pause();
		goto start;
	}
	if (choice[0] == 'y' || choice[0] == 'Y') {
		txt = sortString(txt);
		return;
	}
	else if (choice[0] == 'n' || choice[0] == 'N') {
		return;
	}
	goto start;
}

void colorStat(short spd, short colour) {
	print("Current colour is: ", spd);
	switch (colour) {
	case 1:
		print("Light Red.\n", spd);
		break;

	case 2:
		print("Light Purple.\n", spd);
		break;

	case 3:
		print("Light Yellow.\n", spd);
		break;

	case 4:
		print("Light Green.\n", spd);
		break;

	case 5:
		print("Bright White.\n", spd);
		break;

	default:
		print("ERROR!\n", spd);
		cout << "\033[1A \r";
		print("~> ", spd);
		return;
	}
	cout << "\033[2A \r";
	print("~> ", spd);
	return;
}

void colorChoice(short spd, short& colour, short autoChoice = 0) { // autochoice here for when i finally implement the config file...
start:
	cls();
	short choice = 0;

	if ((autoChoice > 0) && (autoChoice <= 5)) {
		choice = autoChoice;
		goto skip;
	}

	//cout << "Enter which colour you would like to set the program to:\n";
	print("Enter which colour you would like to have the program use:\n", spd);
	print("1) Light Red.\n", spd);
	print("2) Light Purple.\n", spd);
	print("3) Light Yellow.\n", spd);
	print("4) Light Green.\n", spd);
	print("5) Bright White.\n", spd);
	print("0) Return.\n\n", spd);
	colorStat(spd, colour);
	cin >> choice;

	if (!isGud(choice)) {
		goto def;
	}

skip:
	switch (choice) {
	case 1:
		colour = choice;
		system("color c");
		break;

	case 2:
		colour = choice;
		system("color d");
		break;

	case 3:
		colour = choice;
		system("color e");
		break;

	case 4:
		colour = choice;
		system("color a");
		break;

	case 5:
		colour = choice;
		system("color f");
		break;

	case 0:
		return;

	default:
	def:
		cll(spd, "", 31); cout << "\r";
		print("Sorry that input is invalid, try again", spd); cinFlush(); pause();
		break;
	}
	if (autoChoice > 0) {
		return;
	}
	goto start;
}

void setMenu(string& badChars, short& spd, short& colour) {
start:
	cls();
	short choice = 0;
	string termKey;
	print("Settings Menu:\n", spd);
	print("1) Add characters to ignore list.\n", spd);
	print("2) Remove characters from ignore list.\n", spd);
	print("3) Clear the ignore list.\n", spd);
	print("4) Alphabetise list.\n", spd);
	print("5) Scrolling effect.\n", spd);
	print("6) System Colours.\n", spd);
	print("0) Return.\n\n", spd);
	print("Current list: ", spd); charStat(badChars, spd);
	cout << "\033[1A \r"; print("~> ", spd);
	cin >> choice;

	if (!isGud(choice)) {
		goto def;
	}

	switch (choice){
	case 1:
		questChar(termKey, spd);
		addChar(badChars, termKey, spd);
		break;

	case 2:
		questChar(termKey, spd);
		remChar(badChars, termKey, spd);
		break;
		
	case 3:
		clearChar(badChars, spd);
		break;

	case 4:
		alphabetise(badChars, spd);
		break;

	case 5:
		spdChange(spd);
		break;

	case 6:
		colorChoice(spd, colour);
		break;

	case 0:
		return;

	default:
	def:
		cll(spd, badChars); cout << "\r";
		print("Sorry that input is invalid, try again", spd); cinFlush(); pause();
		break;
	}
	goto start;
}

void opMenu(short& spd, string& badChars, short& colour) {
start:
	cls();
	short choice = 0, zero = 0;
	string txt;

	print("Main Menu:\n", spd);
	print("1) Character Counter.\n", spd);
	print("2) Settings.\n");
	print("0) Exit.\n", spd);
	print("~> ", spd);
	cin >> choice;
	cls();

	if (!isGud(choice)) {
		goto def;
	}

	switch (choice){
	case 0:
		cls();
		print("Thank you for using my program", spd); pause();
		print("\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003\003", spd); //33 Hearts cuz why not?
		return;
	case 1:
		print("Input (Max 4094 for some reason, maybe its my terminal):\n~> ", spd);
		cin.ignore();
		getline(cin, txt);
		cout << endl;
		charCount(txt, badChars, spd);
		cout << endl;
		system("pause");
		break;

	case 2:
		setMenu(badChars, spd, colour);
		break;

	default:
	def:
		print("Sorry that input is invalid, try again", spd); cinFlush(); pause();
		break;
	}
	goto start;
}