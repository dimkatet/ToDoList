#include "sdafx.hpp"
#include "read.hpp"
void Openfile (int mon, int year, FILE **list0)
{
	char p[17] = "data/00.2000.txt";
	p[5] = mon/10+48;
	p[6] = mon%10+49;
	p[10] = (year-2000)/10+48;
	p[11] = year%10 + 48;
	p[16] = '\0';
	*list0 = fopen(p,"r");
	printf("%s\n",p);
}