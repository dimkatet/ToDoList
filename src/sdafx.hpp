#ifndef SDAFX_H 
#define SDAFX_H
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<sstream>
#include<conio.h>
#include<string.h>

struct text {
	char t_text[80];
	int t_metadata;
};
struct Note {
	tm n_data;
	text n_text[10];
	int n_metadata;
};
#endif
