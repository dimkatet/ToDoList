#ifndef EDIT_H
#define EDIT_H
void Clean(Note *Notes,int n);
void Transfer(Note *NotesMonth, Note *NotesDay);
void DeleteNote(Note *Notes,Note Note1,int mtask);
void CreateMatriksDay(int arr[7][8],int maxday, int day);
#endif