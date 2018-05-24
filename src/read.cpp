#include "sdafx.hpp"
#include "read.hpp"
void Read(FILE *of, Note *Notes)
{
	char **AllData = new char *[100],ch,*StringData;
	int j = 0, i = 0, q = 0;
	while ((ch=fgetc(of))!=EOF) {
		if(j==0) {
			AllData[i] = new char [617];
			q++;
		}
		AllData[i][j]=ch;
		j++;
		if(ch=='\n') {
			j=0;
			i++;
		}
	}
	for (int i = 0, y = 0, o = 0; i<q; i++) {
		j = 12;
		y = 0;
		o = 0;
		Notes[i].n_metadata = i;
		StringData = new char[617];
		StringData = AllData[i];
		Notes[i].n_data.tm_min = (StringData[2]-48)*10 + StringData[3] - 48;
		Notes[i].n_data.tm_hour = (StringData[0]-48)*10 + StringData[1] - 48;
		Notes[i].n_data.tm_mday =  (StringData[4]-48)*10 + StringData[5] - 48;
		Notes[i].n_data.tm_mon =  (StringData[6]-48)*10 + StringData[7] - 48;
		Notes[i].n_data.tm_year = (StringData[8]-48)*1000 + (StringData[9]-48)*100 + (StringData[10] - 48)*10 + StringData[11] - 48;
		while(StringData[j]!='\0') {
			if(StringData[j]=='/') {
				j++;
				Notes[i].n_text[y].t_metadata = StringData[j] - 48;
				Notes[i].n_text[y].t_text[o] = '\0';
				j++;
				if (StringData[j]!='\n')
					y++;
				else break;
				o=0;
			}
			Notes[i].n_text[y].t_text[o] = StringData[j];
			o++;
			j++;
		}
		delete(StringData);
	}
}