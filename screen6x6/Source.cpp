#include "Header.h"

void draw_Rectangle(uint8_t x_right, uint8_t y_right, uint8_t x_left, uint8_t y_left, uint8_t color)
{
	draw_hotisontalLine(x_right, x_left, y_right, color);
	draw_hotisontalLine(x_right, x_left, y_left, color);
	draw_verticalLine(x_right, y_right, y_left, color);
	draw_verticalLine(x_left, y_right, y_left, color);
	//view_Screen();
}

void draw_Symbol(const uint8_t symbol[SYMSIZE][SYMSIZE], uint8_t color, uint8_t x, uint8_t y)
{
	for (uint8_t i = 0; i < SYMSIZE; i++)
	{
		for (uint8_t j = 0; j < SYMSIZE; j++)
		{
			if (symbol[i][j] != 0) // Если элемент массива = 1
			{
				draw_Dot(x+i, y+j, color);
			}
		}
	}
	//view_Screen();
}

void draw_Text(const uint8_t symbol[SYMSIZE][SYMSIZE], uint8_t color)
{
	static uint8_t x, y;
	if (y >= SYMSINCOL || symbol == STR) // достигли конца экрана или вводим новый текст
	{
		x = 0;
		y = 0;
		clear_Screen();
	}
	if (x < (SYMSINROW) && y < (SYMSINCOL) && symbol != STR)
	{
		draw_Symbol(symbol, color, y, x);
		x += SYMSIZE;
	}
	
	if (x >= (SYMSINROW) && (y == 0 || (y%(SYMSIZE+1) == 0))) // достигли конца строки
	{
		x = 0;
		y += (SYMSIZE+1);
	}
}

int main()
{
	draw_Rectangle(5, 5, 2, 2, (Colours[0]>>4));
	view_Screen();
	_getch();
	clear_Screen();

	draw_Rectangle(17, 17, 3, 3, 1);
	view_Screen();
	_getch();
	clear_Screen();

	draw_Text(STR, 1); //начало строки
	draw_Text(A, (Colours[2] >> 4));
	draw_Text(B, 1);
	draw_Text(C, (Colours[1] % 16 ));
	draw_Text(D, (Colours[4] % 16 ));
	//при выходе за границу экрана текст будет выводиться заново
	draw_Text(D, 1);
	draw_Text(B, 1);
	draw_Text(A, (Colours[2] >> 4));
	view_Screen();
	_getch();
	clear_Screen();

	draw_Symbol(D, 1, 4, 5);
	view_Screen();
	_getch();
	clear_Screen();

	draw_Text(STR, 1); // начало строки
	draw_Text(A, 1);
	view_Screen();
	_getch();

	return 0;
}
