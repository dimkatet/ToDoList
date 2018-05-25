#include "sdafx.hpp"
#include "score.hpp"
void ScoreTask(Note *Notes, Note *NotesDay, int *num, int data)
{
	int i = 0;
	*num = 0;
	while (Notes[i].n_data.tm_mday != data && Notes[i].n_text[0].t_metadata!=0)
		i++;

	while (Notes[i].n_data.tm_mday == data) {
		NotesDay[*num] = Notes[i];
		*num=*num+1;
		i++;
	}
}

void ScoreTaskMonth(Note *Notes, int *num)
{
	*num = 0;
	while(Notes[*num].n_text[0].t_metadata!=0)
		*num=*num+1;
}