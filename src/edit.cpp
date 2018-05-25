#include "sdafx.hpp"
#include "edit.hpp"
void Clean(Note *Notes,int n)
{
	for (int i = 0; i < n; i++) {
		Notes[i].n_data.tm_hour = 0;
		Notes[i].n_data.tm_min = 0;
		Notes[i].n_data.tm_mon = 0;
		Notes[i].n_data.tm_year = 0;
		Notes[i].n_data.tm_mday = 0;
		for (int j = 0; j < 10; j++) {
			Notes[i].n_text[j].t_metadata = 0;
			Notes[i].n_text[j].t_text[0] = '\0';
		}
	}
}
void Transfer(Note *NotesMonth, Note *NotesDay)
{
	int i = 0;
	while(NotesDay[i].n_text[0].t_metadata!=0) {
		NotesMonth[NotesDay[i].n_metadata] = NotesDay[i];
		i++;
	}
}
void DeleteNote(Note *Notes,Note Note1,int mtask)
{
	Notes[Note1.n_metadata] = Notes[mtask-1];
	Notes[mtask-1].n_text[0].t_metadata = 0;
	Notes[mtask-1].n_text[0].t_text[0] = '\0';
}
void CreateMatriksDay(int arr[7][8],int maxday, int day)
{
	for (int i=0; i<7; i++)
		for (int j = 1; j < 8; j++) {
			if (((i * 7 + j) > day) && ((i * 7 + j) < maxday+day+1)) {
				arr[i][j] = (i * 7 + j)-day;
			} else {
				arr[i][j] = 0;
			}
		}
}
