#include "sdafx.hpp"
#include "write.hpp"
#include "read.hpp"
int main()
{
	Note *NotesDay = new Note [10]; 
	int nowMonth = 0, year = 2018;
	FILE *data = 0;
	Openfile(nowMonth,year,&data);
 	Print(data,NotesDay,nowMonth,year);
 	return 0;
}
