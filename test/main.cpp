#define CTEST_MAIN
#include "sdafx.hpp"
#include "read.hpp"
#include "testing.hpp"

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