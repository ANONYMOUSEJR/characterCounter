#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    short spd = 1, colour;
    string badChars = "";

    colorChoice(spd, colour, 4);
    opMenu(spd, badChars, colour);
}

// TODO:
// - Contemplate removing border function.
// - Maybe add a config file functionality to the program like with my other project...
// 
// ~ Don't forget to push and upload the file to releases when you're done <3
// 
// * Create a scheduler, one similar to the one i have made for my midterms.
// 


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
