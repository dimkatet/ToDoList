#define CTEST_MAIN
#include "sdafx.hpp"
#include "write.hpp"
#include "read.hpp"
#include "testing.hpp"
#include "edit.hpp"
struct test_write: TestCase{
	void run(){
		Note *Notes = new Note [2];
		char arr1[] = "TestCheck1",arr2[11],ch;
		int i = 0;
		while(arr1[i]!='\0'){
			Notes[0].n_text[0].t_text[i] = arr1[i];
			i++;
		}
		Notes[0].n_text[0].t_metadata = 1;
		FILE *data = fopen("./data/05.2018.txt","w");
		Print(data,Notes,4,2018);
		fclose(data);
		data = fopen("./data/05.2018.txt","r");
		i = 0;
		arr2[10]='\0';
		while ((ch=fgetc(data))!=EOF&&ch!='/'){
			if(i>11) arr2[i-12]=ch;
			i++;
		}
		ASSERT_STRINGS_EQUAL(arr1, arr2);
	}
};
REGISTER_TEST(test_write, "Write in file correct");

struct test_open_corr: TestCase{
	void run(){
		FILE *data0 = fopen("./data/01.2018.txt","w");
		fclose(data0);
		int mon = 0, year = 2018, real, exp = 1;
		Openfile(mon,year,&data0);
		if (data0 == NULL) real = 0;
		else real = 1;
		ASSERT_EQUAL(exp, real);
	}
};
REGISTER_TEST(test_open_corr, "Open file correct");

struct test_open_incorr: TestCase{
	void run(){
		FILE *data0 = fopen("./data/01.2018.txt","w");
		fclose(data0);
		int mon = 1, year = 2018, real, exp = 0;
		Openfile(mon,year,&data0);
		if (data0 == NULL) real = 0;
		else real = 1;
		ASSERT_EQUAL(exp, real);
	}
};
REGISTER_TEST(test_open_incorr, "Open file incorrect");

struct test_read_corr: TestCase{
	void run(){
		Note *Notes = new Note;
		char p[] = "000000002018Text1/2", expCh[] = "Text1";
		FILE *data0 = fopen("./data/01.2018.txt","w");
		int i = 0;
		while(p[i]!='\0'){
			fputc(p[i],data0);
			i++;
		}
		fclose(data0);
		data0 = fopen("./data/01.2018.txt","r");
		Read(data0,Notes);
		ASSERT_EQUAL(0, Notes[0].n_data.tm_mday);
		ASSERT_EQUAL(0, Notes[0].n_data.tm_mon);
		ASSERT_EQUAL(2018, Notes[0].n_data.tm_year);
		ASSERT_STRINGS_EQUAL(expCh, Notes[0].n_text[0].t_text);
		ASSERT_EQUAL(2, Notes[0].n_text[0].t_metadata);
	}
};
REGISTER_TEST(test_read_corr, "Read file correct");

struct test_clean: TestCase{
	void run(){
		Note *Notes = new Note [10];
		Clean(Notes,10);
		for(int i = 0; i < 10; i++)
		ASSERT_EQUAL(0, Notes[i].n_text[0].t_metadata);
	}
};
REGISTER_TEST(test_clean, "clean data");

struct test_transfer: TestCase{
	void run(){
		Note *NotesM = new Note [10], *NotesD = new Note [6];
		for(int i = 0; i < 5; i++){
		NotesD[i].n_metadata = i+2;
		NotesD[i].n_text[0].t_metadata = i+3;
		}
		Transfer(NotesM,NotesD);
		for(int i = 0; i < 5; i++)
		ASSERT_EQUAL(NotesM[i+2].n_text[0].t_metadata, NotesD[i].n_text[0].t_metadata);
	}
};
REGISTER_TEST(test_transfer, "trasder data");

struct test_delete: TestCase{
	void run(){
		Note *NotesM = new Note [10], NotesD;
		for(int i = 0; i < 10; i++){
		NotesM[i].n_metadata = i;
		NotesM[i].n_text[0].t_metadata = i+3;
		}
		NotesD.n_metadata = 4;
		DeleteNote(NotesM,NotesD,10);
		ASSERT_EQUAL(12, NotesM[4].n_text[0].t_metadata);
	}
};
REGISTER_TEST(test_delete, "delete note");

