#include "sdafx.hpp"
void Openfile (tm *time, FILE **list0)
{
	char p[17] = "data/00.2000.txt";
	p[5] = time->tm_mon/10+48;
	p[6] = time->tm_mon%10+49;
	p[10] = time->tm_year/10+38;
	p[11] = time->tm_year%10 + 48;
	p[16] = '\0';
	*list0 = fopen(p,"r");
}