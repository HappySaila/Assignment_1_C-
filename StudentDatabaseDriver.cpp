//Driver of the student database program
//WLSGRA012
#include <iostream>
#include "PrintManager.h"

using namespace std;

int main()
{
	char answer = 0;
	int i;
	
	PrintManager::PrintHelloMessage();
	
	while (answer != 'q'){
		//prints out the users unteractive options
		PrintManager::PrintUI();

		//get user input
		PrintManager::PrintPrompt();
		cin >> answer;
		
		//print stub message
		PrintManager::PrintStubMessage(answer);
	}
		
	return 0;
}