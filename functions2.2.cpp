#include "MyHeader1.h"
void PushStack(Line*& top, char text[BUFSIZ]) {
	Line* newNode = new Line;
	int len = strlen(text);
	if (len > 0 && text[len - 1] == '\n') {
		text[len - 1] = '\0';
	}
	strcpy(newNode->value, text);
	newNode->next = top;
	top = newNode;
}

Line* PopStack(Line*& top) {
	if (top == nullptr) {
		return nullptr;
	}
	Line* removedElement = top;
	top = top->next;
	return removedElement;
}

int LoadFileToStack(Line*& top, char filename[30], int& stackSize) {
	ifstream document;
	document.open(filename);
	if (!document) {
		cout << "Cannot open the file!\n";
		return -1;
	}
	cout << "File loaded succesfully!\n";
	char text[BUFSIZ];

	while (document.getline(text, BUFSIZ)) {
		PushStack(top, text);
		stackSize++;
	}
	document.close();
	return 0;
}

void PrintStack(Line*& top) {
	if (!top) {
		cout << "\nStack is empty!\n";
	}
	Line* current = top;
	cout << "\nInfo from stack : \n";
	while (current) {
		cout << current->value << "\n";
		current = current->next;
	}
}

void PurgeStack(Line*& top) {
	if (!top) {
		cout << "\nStack is empty!\n";
	}
	cout << "\nInfo from stack : \n";
	while (top) {
		Line* removedElement = PopStack(top);
		cout << removedElement->value << endl;
		delete removedElement;
	}
}
void RenumberStack(Line*& top, int stackSize) {
	if (!top) {
		cout << "\nStack is empty!\n";
		return;
	}
	Line* current = top;
	cout << "\nStack was renumbered!\n";
	while (current) {
		char temp[BUFSIZ];
		sprintf(temp, "%d:", stackSize);
		strcat(temp, current->value);
		strcpy(current->value, temp);
		stackSize--;
		current = current->next;
	}
}

void ReverseStack(Line*& top) {
	if (!top) {
		cout << "\nStack is empty!\n";
	}
	Line* reversedStack = nullptr;
	cout << "\nStack was reversed! \n";
	while (top) {
		Line* temp = top->next;
		top->next = reversedStack;
		reversedStack = top;
		top = temp;
	}
	top = reversedStack;
}

int PrintFile(Line*& top, char filename[30]) {
	ifstream document;
	document.open(filename);
	if (!document) {
		cout << "Cannot open the file!\n";
		return -1;
	}
	char text[BUFSIZ];
	cout << "\nInfo from file : \n";
	while (document.getline(text, BUFSIZ)) {
		cout << text << "\n";
	}
	document.close();
	return 0;
}

void showFiles() {
	WIN32_FIND_DATAA findfiledata;
	HANDLE handle;

	handle = FindFirstFileA("*.txt", &findfiledata);
	if (handle != INVALID_HANDLE_VALUE) {
		cout << "\nFiles from directory: \n";
		do {
			cout << findfiledata.cFileName << endl;
		} while (FindNextFileA(handle, &findfiledata));
	}

}