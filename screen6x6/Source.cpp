#include "Header.h"

void draw_Rectangle(uint8_t x_right, uint8_t y_right, uint8_t x_left, uint8_t y_left, uint8_t color)
{
	for (uint8_t j = y_left + 1; j < y_right; j++)
	{
		draw_Dot(x_left, j, color);
		draw_Dot(x_right, j, color);
	}

	for (uint8_t i = x_left; i <= x_right; i++)
	{
		draw_Dot(i, y_right, color);
		draw_Dot(i, y_left, color);
	}
}

void draw_Symbol(const uint8_t symbol[SYMSIZE][SYMSIZE], uint8_t color, uint8_t x, uint8_t y)
{
	for (uint8_t i = 0; i < SYMSIZE; i++)
	{
		for (uint8_t j = 0; j < SYMSIZE; j++)
		{
			if (symbol[i][j] != 0) // ���� ������� ������� = 1
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
	if (y >= SYMSINCOL || symbol == STR) // �������� ����� ������ ��� ������ ����� �����
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
	
	if (x >= (SYMSINROW) && (y == 0 || (y%(SYMSIZE+1) == 0))) // �������� ����� ������
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

	draw_Text(STR, 1); //������ ������
	draw_Text(A, (Colours[2] >> 4));
	draw_Text(B, 1);
	draw_Text(C, (Colours[1] % 16 ));
	draw_Text(D, (Colours[4] % 16 ));
	//��� ������ �� ������� ������ ����� ����� ���������� ������
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

	draw_Text(STR, 1); // ������ ������
	draw_Text(A, 1);
	view_Screen();
	_getch();

	return 0;
}
