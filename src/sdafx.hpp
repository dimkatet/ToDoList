#ifndef SDAFX_H
#define SDAFX_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <tchar.h> 
#include <sstream> 
#include <conio.h> 
#include <string.h>
#include <windows.h>
#include "read.hpp"
#include ""
struct text{
	char t_text[60];
	int t_metadata;
};
struct Note{
	tm n_data;
	text n_text[10];
	int n_metadata;
};
#endif