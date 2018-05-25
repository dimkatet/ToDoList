#define CTEST_MAIN
#include "sdafx.hpp"
#include "write.hpp"
#include "read.hpp"
#include "testing.hpp"

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
