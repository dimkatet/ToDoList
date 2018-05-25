#define CTEST_MAIN
#include "sdafx.hpp"
#include "read.hpp"
#include "testing.hpp"
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
REGISTER_TEST(test_read_corr, "Open file correct");