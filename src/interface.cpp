#include"checkclisk.hpp"
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<sstream>

using namespace sf;
int main()
{
	struct Note *NotesDay = new Note [10], *NotesMonth = new Note [300];
	int nowMonth = 0, year = 2018, day, maxday, nowday; 
	FILE *data = 0;
	int x0=0,y0=0,flag=0,pole = 0,namdertask = 1, help1,ntask,ntaskp,i = 1, k,help, help1;
	float x, y, x1, y1;
	RenderWindow window(VideoMode(1300, 700), "To-do");
	
	Image fon;
	fon.loadFromFile("../image/fon.jpg");
	Texture fontexture;
	fontexture.loadFromImage(fon);
	Sprite fonsprite;
	fonsprite.setTexture(fontexture);
	
	Image fon2;
	fon2.loadFromFile("../image/fon2.jpg");
	Texture fon2texture;
	fon2texture.loadFromImage(fon2);
	Sprite fon2sprite;
	fon2sprite.setTexture(fon2texture);

	Image mes;
	mes.loadFromFile("../image/mes.png");
	Texture mestexture;
	mestexture.loadFromImage(mes);
	Sprite messprite;
	messprite.setTexture(mestexture);
	messprite.setTextureRect(IntRect(nowMonth *300+300, 0, 300, 60));
	messprite.setPosition(200, 95);
	
	Image textfon;
	textfon.loadFromFile("../image/textfondop.jpg");
	Texture textfontexture;
	textfontexture.loadFromImage(textfon);
	Sprite textfonsprite;
	textfonsprite.setTexture(textfontexture);
	textfonsprite.setPosition(700, 50);
	
	Image galka;
	galka.loadFromFile("../image/galka.jpg");
	Texture galkatexture;
	galkatexture.loadFromImage(galka);
	Sprite galkasprite;
	galkasprite.setTexture(galkatexture);

	Image galka1;
	galka1.loadFromFile("../image/galka1.jpg");
	Texture galka1texture;
	galka1texture.loadFromImage(galka1);
	Sprite galka1sprite;
	galka1sprite.setTexture(galka1texture);

	Image zaplat;
	zaplat.loadFromFile("../image/zaplat.png");
	Texture zaplattexture;
	zaplattexture.loadFromImage(zaplat);
	Sprite zaplatsprite;
	zaplatsprite.setTexture(zaplattexture);
	zaplatsprite.setTextureRect(IntRect(0, 0,70,50));
	
	Font font;
	font.loadFromFile("font.ttf");

	while (window.isOpen())
	{	flag = 0; x0 = 0; y0 = 0; help = 0;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (event.type == Event::MouseButtonPressed)
			if (event.key.code == Mouse::Left)
			{
				Vector2i pikspos = Mouse::getPosition(window);
				x0 = (float)pikspos.x;
				y0 = (float)pikspos.y;
			}
			if (!pole)
		{
			x = (float)((nowday + day - 1) % 7), y = (float)((nowday + day - 1) / 7);
			zaplatsprite.setPosition(110 + x * 70, 275 + y * 50);
			flag = checkstart(x0, y0);
			if (flag == 1)
			{
				Transfer(NotesMonth,NotesDay);
				Print(data,NotesMonth,nowMonth,year);
				if (nowMonth == 0) { nowMonth = 11;	year--; }
				else  nowMonth--;
				for (int i = 0; i < 301; i += 3)
				{
					messprite.setTextureRect(IntRect(nowMonth * 300 + 600 - i, 0, 300, 60));
					window.draw(messprite);
					window.display();
					Sleep(1);
				}
				day = nday(nowMonth, &maxday);
				nowday = checkday((int)x1, (int)y1, day);
				if ((nowday < 1) || (nowday > maxday))
				{
					help1 = nowday = 1;
					x1 = (float)((nowday + day - 1) % 7), y1 = (float)((nowday + day - 1) / 7);
					zaplatsprite.setPosition(110 + x1 * 70, 275 + y1 * 50);
					x1 = 110 + x1 * 70; y1 = 275 + y1 * 50;
				}
				Openfile(nowMonth,year,&data);
				Clean(NotesMonth,100);
				Clean(NotesDay,10);
				Read(data, NotesMonth);
				ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
				if (ntask==0) Clean(NotesDay,10);
			}
			if (flag == 2)
			{
				Transfer(NotesMonth,NotesDay);
				Print(data,NotesMonth,nowMonth,year);
				nowMonth++;
				year += nowMonth / 12;
				nowMonth = nowMonth % 12;
				for (int i = 0; i < 301; i += 3)
				{
					messprite.setTextureRect(IntRect(nowMonth * 300 + i, 0, 300, 60));
					window.draw(messprite);
					window.display();
					Sleep(1);
				}
				day = nday(nowMonth, &maxday);
				nowday = checkday((int)x1, (int)y1, day);
				if ((nowday < 1) || (nowday > maxday))
				{
					help1 = nowday = 1;
					x1 = (float)((nowday + day - 1) % 7), y1 = (float)((nowday + day - 1) / 7);
					zaplatsprite.setPosition(110 + x1 * 70, 275 + y1 * 50);
					x1 = 110 + x1 * 70; y1 = 275 + y1 * 50;
				}
				Openfile(nowMonth,year,&data);
				Clean(NotesMonth,100);
				Clean(NotesDay,10);
				Read(data, NotesMonth);
				ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
				if(ntask==0) Clean(NotesDay,10);
			}
			if (flag == 3)
			{
				nowday = checkday((int)x0, (int)y0, day);
				if ((nowday < 1) || (nowday > maxday)) nowday = checkday((int)x1, (int)y1, day);
				else
				{
					x0 = (float)((nowday + day - 1) % 7), y0 = (float)((nowday + day - 1) / 7);
					zaplatsprite.setPosition(110 + x0 * 70, 275 + y0 * 50);
					x1 = 110 + x0 * 70; y1 = 275 + y0 * 50;
					if (help1 == nowday)
					{
						pole = 1;
					}
					else
					{
						help1 = nowday;
					}
				}
				ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
				if (ntask==0) Clean(NotesDay,10);
			}
			window.clear();
			window.draw(fonsprite);
			window.draw(zaplatsprite);
			i = 1, k = day;
			x = (float)day, y = 0;
			Text text("", font, 30);
			text.setFillColor(sf::Color(225, 104, 57));
			while (i <= maxday)
			{
				int u1 = i / 10;
				int u2 = i % 10;
				char u3[3];
				u3[2] = '\0';
				if (u1 == 0)
				{
					u3[1] = '\0';
					u3[0] = u2 + 48;
				}
				else
				{
					u3[1] = u2 + 48;
					u3[0] = u1 + 48;
				}
				text.setString(u3);
				text.setPosition(115 + x * 70, 275 + y * 50);
				k++;
				x = (float)(k % 7);
				y = (float)(k / 7);
				window.draw(text);
				i++;
			}
			Text textstr("", font, 14);
			textstr.setFillColor(sf::Color(225, 104, 57));
			if (flag == 4)
				flagtext = 0;
			if (flagtext) 
			{
				window.draw(textfonsprite);
				ntaskp = counterp(NotesDay[namdertask]);
				for (int i = 0; i < ntaskp; i++)
				{
					if (NotesDay[namdertask].n_text[i].t_metadata != 0)
					{
						if (flag == 6)
						{
							help = checktask(y0);
							if (NotesDay[namdertask].n_text[help].t_metadata != 0)
								if (help < ntaskp)
								{
									if (NotesDay[namdertask].n_text[help].t_metadata == 2)
									{
										NotesDay[namdertask].n_text[help].t_metadata = 1;
									}
									else
									{
										if((NotesDay[namdertask].n_text[help].t_metadata == 1)||(NotesDay[namdertask].n_text[help].t_metadata == 2))
										NotesDay[namdertask].n_text[help].t_metadata = 2;
									}
								}
						}
						if (NotesDay[namdertask].n_text[i].t_metadata != 2)
						{
							textstr.setString(NotesDay[namdertask].n_text[i].t_text);
							textstr.setFillColor(sf::Color(225, 104, 57));
							if (i == 0)
								textstr.setPosition(775, 125);
							else
								textstr.setPosition(790, 125 + i * 20);
							galkasprite.setPosition(750, 125 + i * 20);
							window.draw(textstr);
							window.draw(galkasprite);
						}
						else
						{
							textstr.setString(NotesDay[namdertask].n_text[i].t_text);
							textstr.setFillColor(sf::Color(129, 129, 129));
							if (i == 0)
								textstr.setPosition(775, 125);
							else
								textstr.setPosition(790, 125 + i * 20);
							galka1sprite.setPosition(750, 125 + i * 20);
							window.draw(textstr);
							window.draw(galka1sprite);
						}

					}
				}
			}
			else
			{
				for (int i = 0; i < ntask; i++)
					if (NotesDay[i].n_text[0].t_metadata != 0)
					{
						if (NotesDay[i].n_text[0].t_metadata != 2)
						{
							textstr.setString(NotesDay[i].n_text[0].t_text);
							textstr.setFillColor(sf::Color(225, 104, 57));
							textstr.setPosition(775, 125 + i * 20);
							galkasprite.setPosition(750, 125 + i * 20);
							window.draw(textstr);
							window.draw(galkasprite);
						}
						else
						{
							textstr.setString(NotesDay[i].n_text[0].t_text);
							textstr.setFillColor(sf::Color(129, 129, 129));
							textstr.setPosition(775, 125 + i * 20);
							galka1sprite.setPosition(750, 125 + i * 20);
							window.draw(textstr);
							window.draw(galka1sprite);
						}

						if (flag == 5)
						{
							if (checktask(y0) < ntask)
							{
								namdertask = checktask(y0);
								flagtext = 1;
							}
						}
					}
			}
			Sleep(100);
			window.draw(messprite);
			window.display();
		}
		}
	}
	return 0;
}

