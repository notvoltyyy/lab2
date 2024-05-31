#include "Myheader1.h"

int main() {
	int choice;
	Line* top = nullptr;
	int stackSize = 0;
	char userinput[30];
	bool programIsOpen = true;
	while (programIsOpen) {
		cout << "\n\nMENU\n\n1.Load file\n2.Print Stack\n3.Print File\n4.Purge Stack\n5.Renumber Stack\n6.Reverse Stack\n7.Quit.\n\nYour choice: \n";
		cin >> choice;
		if (!cin) {
			cout << "An integer is expected!\n";
			return -1;
		}
		Menu menu = Menu(choice);
		switch (menu) {
		case choice_LoadToStack:
			showFiles();
			cout << "Enter filename : ";
			cin >> userinput;
			LoadFileToStack(top, userinput, stackSize);
			break;
		case choice_PrintStack:
			PrintStack(top);
			break;
		case choice_PrintFile:
			showFiles();
			cout << "Enter filename : ";
			cin >> userinput;
			PrintFile(top, userinput);
			break;
		case choice_Purge:
			PurgeStack(top);
			break;
		case choice_Renumber:
			RenumberStack(top, stackSize);
			break;
		case choice_Reverse:
			ReverseStack(top);
			break;
		case choice_Quit:
			programIsOpen = false;
			break;
		}
	}
	PurgeStack(top);
}