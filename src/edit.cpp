#include "sdafx.hpp"
#include "edit.hpp"
void Clean(Note *Notes,int n)
{
	for (int i = 0; i < n; i++)
	{
		Notes[i].n_data.tm_hour = 0;
		Notes[i].n_data.tm_min = 0;
		Notes[i].n_data.tm_mon = 0;
		Notes[i].n_data.tm_year = 0;
		Notes[i].n_data.tm_mday = 0;
		for (int j = 0; j < 10; j++)
		{
			Notes[i].n_text[j].t_metadata = 0;
			Notes[i].n_text[j].t_text[0] = '\0';
		}
	}
}
void Transfer(Note *NotesMonth, Note *NotesDay)
{
	int i = 0;
	while(NotesDay[i].n_text[0].t_metadata!=0)
	{
		NotesMonth[NotesDay[i].n_metadata] = NotesDay[i];
		i++;
	}
}