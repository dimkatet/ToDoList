#include"sdafx.hpp"
#include"checkclisk.hpp"
#include"read.hpp"
#include"write.hpp"
#include"edit.hpp"
#include"score.hpp"

using namespace sf;
int interface()
{
	struct Note *NotesDay = new Note [10], *NotesMonth = new Note [300];
	int nowMonth = 0, year = 2018, day, maxday, nowday; 
	int matrday[7][8];
	char ch;
	FILE *data = 0;
	int x0=0,y0=0,flag=0,pole = 0,namdertask = 1, help1,ntask,ntaskp,i = 1, k,help, help1, m, flag3 = 0, flag4 = 0, flag5 = 0, helpi = 0, hp = 0, hpp = 0;
	float x, y, x1, y1;
	RenderWindow window(VideoMode(1300, 700), "To-do");
	nowdate(&nowday, &xmonth);
	day = nday(xmonth, &maxday);
	Openfile(xmonth,god,&data);
	Read(data, NotesMonth);
	ScoreTaskMonth(NotesMonth,&mtask);
	ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
	
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
	x = (float)((nowday+day-1)%7), y = (float)((nowday+day-1) / 7);
	zaplatsprite.setPosition(110 + x * 70, 275 + y * 50);
	x1 = 110 + x * 70; y1 = 275 + y * 50;
	
	Font font;
	font.loadFromFile("font.ttf");
	help1 = 0;
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
			else
			{
				flag = checkstart2(x0, y0);
				window.clear();
				window.draw(fon2sprite);
				if (flag == 3)
				{
					pole = 0;
				}
				m = (nowday + day - 1) / 7;
				CreateMatriksDay(matrday, maxday, day);
				for (int i = 0; i < 7; i++)
				{
					if (matrday[m][i + 1] == nowday)
						zaplatsprite.setPosition(405 + i * 70, 25);
				}
				window.draw(zaplatsprite);
				if (flag == 1)
				{
					if (m > 0)
					{
						m--;
						if (matrday[m][1] != 0)
							nowday = matrday[m][1];
						else nowday = matrday[m][7];
						Transfer(NotesMonth,NotesDay);
						ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
						if (ntask==0) Clean(NotesDay,10);
					}
				}
				if (flag == 2)
				{
					if (m < ((maxday + day - 1) / 7))
					{
						m++;
						if (matrday[m][1] != 0)
							nowday = matrday[m][1];
						else nowday = matrday[m][7];
						Transfer(NotesMonth,NotesDay);
						ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
						if (ntask==0) Clean(NotesDay,10);
					}
	
				}
				Text text("", font, 30);
				text.setFillColor(sf::Color(225, 104, 57));
				for (int i = 0; i < 7; i++)
				{
					if (matrday[m][i + 1] != 0)
					{
						int u1 = matrday[m][i + 1] / 10;
						int u2 = matrday[m][i + 1] % 10;
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
						text.setPosition(405 + i * 70, 25);
						window.draw(text);
					}
				}
				if (flag == 4)
				{
					Transfer(NotesMonth,NotesDay);
					if (matrday[m][((x0 - 405) / 70) + 1] != 0)
						nowday = matrday[m][((x0 - 405) / 70) + 1];
					ScoreTask(NotesMonth,NotesDay, &ntask, nowday);
					if (ntask==0) Clean(NotesDay,10);
				}
				Text textstr("", font, 14);
				textstr.setFillColor(sf::Color(225, 104, 57));
				ntaskp = counterp(NotesDay[namdertask]);
				for (int i = 0; i < ntaskp; i++)
				{
					if (NotesDay[namdertask].n_text[i].t_metadata != 0)
					{
						if (flag == 6)
						{
							help = (y0 - 150) / 20;
							if (NotesDay[namdertask].n_text[help].t_metadata != 0)
								if (help < ntaskp)
								{
									if (NotesDay[namdertask].n_text[help].t_metadata == 2)
									{
										NotesDay[namdertask].n_text[help].t_metadata = 1;
									}
									else
									if ((NotesDay[namdertask].n_text[help].t_metadata == 1)|| (NotesDay[namdertask].n_text[help].t_metadata == 3))
									{
										NotesDay[namdertask].n_text[help].t_metadata = 2;
									}
								}
						}
						if (flag == 10)
						{
							help = (y0 - 150) / 20;
							if (help < ntask)
								if (NotesDay[help].n_text[0].t_metadata != 0)
								{
									if (NotesDay[help].n_text[0].t_metadata == 3)
									{
										NotesDay[help].n_text[0].t_metadata = 1;
									}
									else
										if ((NotesDay[help].n_text[0].t_metadata == 1) || (NotesDay[help].n_text[0].t_metadata == 2))
										{
											NotesDay[help].n_text[0].t_metadata = 3;
										}
								}

						}
						if (NotesDay[namdertask].n_text[i].t_metadata != 2)
						{
							textstr.setString(NotesDay[namdertask].n_text[i].t_text);
							textstr.setFillColor(sf::Color(225, 104, 57));
							if (i == 0)
								textstr.setPosition(685, 150);
							else
								textstr.setPosition(700, 150 + i * 20);
							galkasprite.setPosition(660, 150 + i * 20);
							basketsprite.setPosition(1200, 150 + i * 20);
							window.draw(textstr);
							window.draw(basketsprite);
							window.draw(galkasprite);
						}
						else
						{
							textstr.setString(NotesDay[namdertask].n_text[i].t_text);
							textstr.setFillColor(sf::Color(129, 129, 129));
							if (i == 0)
								textstr.setPosition(685, 150);
							else
								textstr.setPosition(700, 150 + i * 20);
							galka1sprite.setPosition(660, 150 + i * 20);
							basketsprite.setPosition(1200, 150 + i * 20);
							window.draw(textstr);
							window.draw(basketsprite);
							window.draw(galka1sprite);
						}
					}
					for (int i = 0; i < ntask; i++)
					if (NotesDay[i].n_text[0].t_metadata != 0)
					{
						if (NotesDay[i].n_text[0].t_metadata != 2)
						{
							textstr.setString(NotesDay[i].n_text[0].t_text);
							textstr.setFillColor(sf::Color(225, 104, 57));
							textstr.setPosition(125, 150 + i * 20);
							galkasprite.setPosition(100, 150 + i * 20);
							if (NotesDay[i].n_text[0].t_metadata == 3)
							{
								exclaimsprite.setPosition(80, 150 + i * 20);
								window.draw(exclaimsprite);
							}
							else
							{
								notexclaimsprite.setPosition(80, 150 + i * 20);
								window.draw(notexclaimsprite);
							}
							window.draw(textstr);
							window.draw(galkasprite);
						}
						else
						{
							textstr.setString(NotesDay[i].n_text[0].t_text);
							textstr.setFillColor(sf::Color(129, 129, 129));
							textstr.setPosition(125, 150 + i * 20);
							notexclaimsprite.setPosition(80, 150 + i * 20);
							galka1sprite.setPosition(100, 150 + i * 20);
							window.draw(textstr);
							window.draw(galka1sprite);
							window.draw(notexclaimsprite);
						}
					}
					if (flag == 7)
					{
						Sleep(50);
						if (ntask < 10)
						{
							printf("%d\n",mtask);
							ntask++;
							NotesDay[ntask-1].n_text[0].t_metadata = 1;
							NotesDay[ntask-1].n_metadata = mtask;
							NotesDay[ntask-1].n_data.tm_mday = nowday;
							NotesDay[ntask-1].n_data.tm_mon = xmonth + 1;
							NotesDay[ntask-1].n_data.tm_year = god;
							mtask++;
							flag5 = 0;
							flag4 = 0;
							flag3 = 1;
							helpi = 0;
							namdertask = ntask - 1;
							ntaskp = counterp(NotesDay[namdertask]);
							Transfer(NotesMonth,NotesDay);
						}
		
					}
					if (flag == 8)
					{
						Sleep(50);
						if (ntaskp < 10)
						{
							ntaskp++;
							NotesDay[namdertask].n_text[ntaskp-1].t_metadata = 1;
							flag5 = 0;
							flag4 = 1;
							flag3 = 0;
							helpi = 0;
						}
					}
					if (flag4)
					{
						if (event.type == Event::TextEntered)
						{
		
							if ((int)event.key.code == 13)
							{
								flag4 = 0;
							}
							else
							{
								if ((int)event.key.code == 8)
								{
									helpi--;
									NotesDay[namdertask].n_text[ntaskp - 1].t_text[helpi] = '\0';
		
								}
								else
								{
									NotesDay[namdertask].n_text[ntaskp - 1].t_text[helpi] = event.key.code;
									NotesDay[namdertask].n_text[ntaskp - 1].t_text[helpi + 1] = '\0';
									helpi++;
								}
							}
							if (helpi > 40)
								flag4 = 0;
						}
					}
				if (flag3)
				{
					if (event.type == Event::TextEntered)
					{
		
						if ((int)event.key.code ==13)
						{
							flag3 = 0;
						}
						else
						{
							if ((int)event.key.code == 8)
							{
								helpi--;
								NotesDay[ntask - 1].n_text[0].t_text[helpi] = '\0';
		
							}
							else
							{
								NotesDay[ntask - 1].n_text[0].t_text[helpi] = event.key.code;
								NotesDay[ntask - 1].n_text[0].t_text[helpi + 1] = '\0';
								helpi++;
							}
						}
						if(helpi>40)
							flag3 = 0;
					}
				}
				if (flag == 9)
				{
					hpp = (y0 - 150) / 20;
					helpi = strlen(NotesDay[namdertask].n_text[hpp].t_text);
					flag5 = 1;
					flag4 = 0;
					flag3 = 0;
				}
				if (flag == 11)
				{
					help = (y0 - 150) / 20;
					DeleteNote(NotesMonth,NotesDay[namdertask],mtask);
					if(help<ntaskp)
						if (help == 0)
						{
							NotesDay[namdertask] = NotesDay[ntask - 1];
							for (int j = 0; j < 10; j++)
							{
								NotesDay[ntask - 1].n_text[j].t_metadata = 0;
								NotesDay[ntask - 1].n_text[j].t_text[0] = '\0';
							}
								ntask--;
								ntaskp = counterp(NotesDay[namdertask]);
						}
						else 
						{
							NotesDay[namdertask].n_text[help] = NotesDay[namdertask].n_text[ntaskp-1];
							NotesDay[namdertask].n_text[ntaskp-1].t_metadata = 0;
							NotesDay[namdertask].n_text[ntaskp-1].t_text[0] = '\0';
								ntaskp--;
						}
				}
				if (flag5)
				{
					if (event.type == Event::TextEntered)
					{

						if ((int)event.key.code == 13)
						{
							flag5 = 0;
						}
						else
						{						
							if ((int)event.key.code == 8)
							{
								helpi--;
								NotesDay[namdertask].n_text[hpp].t_text[helpi] = '\0';
							}
							else
							{
								NotesDay[namdertask].n_text[hpp].t_text[helpi] = event.key.code;
								NotesDay[namdertask].n_text[hpp].t_text[helpi + 1] = '\0';
								helpi++;
							}
						}
						if (helpi > 40)
							flag5 = 0;
					}
					Sleep(100);
					window.display();
				}
	}
	return 0;
}