#include <iostream>
#include <fstream>
#include <Windows.h>
#pragma warning(disable:4996)
using namespace std;
#pragma once

enum Menu {
	choice_LoadToStack = 1, choice_PrintStack, choice_PrintFile, choice_Purge, choice_Renumber, choice_Reverse, choice_Quit
};

struct Line {
	Line* next;
	char value[BUFSIZ];
};

void PushStack(Line*& top, char text[BUFSIZ]);
Line* PopStack(Line*& top);
int LoadFileToStack(Line*& top, char filename[30], int& stackSize);
void PrintStack(Line*& top);
void PurgeStack(Line*& top);
void RenumberStack(Line*& top, int stackSize);
void ReverseStack(Line*& top);
int PrintFile(Line*& top, char filename[30]);
void showFiles();
