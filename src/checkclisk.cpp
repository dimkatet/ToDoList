#include"stdafx.hpp"
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
