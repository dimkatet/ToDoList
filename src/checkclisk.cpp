#include"sdafx.hpp"
#include"checkclisk.hpp"
int checkstart(float x, float y)
{
	if ((y > 100) && (y < 150))
	{
		if ((x > 130) && (x < 180)) return 1;
		if ((x > 525) && (x < 572)) return 2;
	}
	if ((y > 275) && (y < 575)&& (x > 105) && (x < 595))
		return 3;
	if((y > 75) && (y < 100)&& (x > 1200) && (x < 1225)) return 4;
	if((y > 125) && (y < 575) && (x > 775) && (x < 1200)) return 5;
	if((y > 125) && (y < 575) && (x > 750) && (x < 770)) return 6;
	return 0;
}
int checkday(int x, int y,int day)
{
	x -= 105;
	y -= 275;
	x = x / 70;
	y = y / 50;
	return (y * 7 + x - day+1);
}
int checktask(int y)
{
	y -= 125;
	y = y / 20;
	return y;
}
int checkstart2(float x, float y)
{
	if ((y > 25) && (y < 75))
	{
		if ((x > 330) && (x < 380)) return 1;
		if ((x > 920) && (x < 970)) return 2;
	}
	if ((y > 25) && (y < 75) && (x > 405) && (x < 895)) return 4;
	if ((y > 0) && (y < 25) && (x > 1275) && (x < 1300)) return 3;
	if ((y > 150) && (y < 600) && (x > 125) && (x < 550)) return 5;
	if ((y > 150) && (y < 600) && (x > 660) && (x < 680)) return 6;
	if((y > 600) && (y < 650) && (x > 600) && (x < 650)) return 7;
	if ((y > 600) && (y < 650) && (x > 1200) && (x < 1250)) return 8;
	if ((y > 150) && (y < 600) && (x > 685) && (x < 1200)) return 9;
	return 0;
}
void nowdate(int *nowday, int *xmonth)
{
	time_t t;
	struct tm *t_m;
	t=time(NULL);
	t_m=localtime(&t);
	*nowday = t_m->tm_mday;
	*xmonth = t_m->tm_mon; 
}
int nday(int month,int *maxday)
{
	switch (month)
	{
	case 0: *maxday = 31;	return 0;
	case 1: *maxday = 28;	return 3;
	case 2:	*maxday = 31;	return 3;
	case 3: *maxday = 30;	return 6;
	case 4: *maxday = 31;	return 1;
	case 5: *maxday = 30;	return 4;
	case 6: *maxday = 31;	return 6;
	case 7: *maxday = 31;	return 2;
	case 8: *maxday = 30;	return 5;
	case 9: *maxday = 31;	return 0;
	case 10: *maxday = 30;	return 3;
	case 11: *maxday = 31;	return 5;
	default:	return 0;
	}
	return 0;
} 
int counterp(Note p) 
{ 
int i = 0; 
while (p.n_text[i].t_metadata != 0) 
{ 
i++; 
} 
return i; 
}
