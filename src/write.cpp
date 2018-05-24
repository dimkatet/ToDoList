#include "sdafx.hpp"
#include "write.hpp"
void Print(FILE *of, Note *Notes, int mon, int year)
{
	char p[17] = "data/00.2000.txt";
	p[5] = mon/10+48;
	p[6] = mon%10+49;
	p[10] = (year-2000)/10+48;
	p[11] = year%10 + 48;
	p[16] = '\0';
	of = fopen(p,"w");
	int a = 0;;
	while(Notes[a].n_text[0].t_metadata!=0)	{
		int i = 0, j = 0;
		fputc(Notes[a].n_data.tm_hour/10+48,of);
		fputc(Notes[a].n_data.tm_hour%10+48,of);
		fputc(Notes[a].n_data.tm_min/10+48,of);
		fputc(Notes[a].n_data.tm_min%10+48,of);
		fputc(Notes[a].n_data.tm_mday/10+48,of);
		fputc(Notes[a].n_data.tm_mday%10+48,of);
		fputc(Notes[a].n_data.tm_mon/10+48,of);
		fputc(Notes[a].n_data.tm_mon%10+48,of);
		fputc(Notes[a].n_data.tm_year/1000+48,of);
		fputc(Notes[a].n_data.tm_year%1000/100+48,of);
		fputc(Notes[a].n_data.tm_year%100/10+48,of);
		fputc(Notes[a].n_data.tm_year%10+48,of);
		while(Notes[a].n_text[j].t_text[1]!='\0') {
			i = 0;
			while(Notes[a].n_text[j].t_text[i]!='\0') {
				fputc(Notes[a].n_text[j].t_text[i],of);
				i++;
			}
			fputc('/',of);
			fputc(Notes[a].n_text[j].t_metadata+48,of);
			j++;
		}
		fputc('\n',of);
		a++;
	}
	fclose(of);
}