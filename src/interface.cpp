#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<sstream>

using namespace sf;
int main()
{
	int x0=0,y0=0;
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
	messprite.setTextureRect(IntRect(xmonth *300+300, 0, 300, 60));
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

	while (window.isOpen())
	{
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
	}
	return 0;
}

