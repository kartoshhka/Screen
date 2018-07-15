#include "stdio.h"
#include "stdint.h"
#include "conio.h"
#include <stdlib.h>

using namespace std;

#define SCREENSIZE 20
#define SYMSIZE 8
#define SYMSINROW 16
#define SYMSINCOL 18

/*uint8_t Screen[8][8] =
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};*/

const uint8_t Colours[8] = 
{
	0x10, 0x32, 0x54, 0x76, 0x98, 0xBA, 0xDC, 0xFE,
}; 

uint8_t Screen[SCREENSIZE][SCREENSIZE] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const uint8_t sym_A[SYMSIZE][SYMSIZE] =
{ 
	0, 0, 1, 1, 1, 1, 0, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0 
};

const uint8_t sym_B[SYMSIZE][SYMSIZE] =
{
	0, 1, 1, 1, 1, 1, 0, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0, 0,
};

const uint8_t sym_C[SYMSIZE][SYMSIZE] =
{
	0, 1, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 0,
}; 

const uint8_t sym_D[SYMSIZE][SYMSIZE] =
{
	0, 1, 1, 1, 1, 1, 0, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0, 0,
};// etc.

const uint8_t sym_STR[SYMSIZE][SYMSIZE] =
{
	1, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 1,
};


const uint8_t(*A)[SYMSIZE] = sym_A;
const uint8_t(*B)[SYMSIZE] = sym_B;
const uint8_t(*C)[SYMSIZE] = sym_C;
const uint8_t(*D)[SYMSIZE] = sym_D;
const uint8_t(*STR)[SYMSIZE] = sym_STR;
//etc.

void clrscr()
{
	system("@cls||clear");
}

void clear_Screen()
{
	clrscr();
	for (uint8_t i = 0; i < SCREENSIZE; i++)
	{
		for (uint8_t j = 0; j < SCREENSIZE; j++)
		{
			Screen[i][j] = 0;
		}
	}
}

void view_Screen()
{
	for (uint8_t i = 0; i < SCREENSIZE; i++)
	{
		for (uint8_t j = 0; j < SCREENSIZE; j++)
		{
			printf("%d", Screen[i][j]);
		}
		printf("\n");
	}
}

void draw_Dot(uint8_t x, uint8_t y, uint8_t color)
{
	if (Screen[x][y] == 0)
		Screen[x][y] = color;
}



void draw_verticalLine(uint8_t x, uint8_t y_right, uint8_t y_left, uint8_t color)
{
	for (uint8_t j = y_left + 1; j < y_right; j++)
	{
		draw_Dot(x, j, color);
	}
}

void draw_hotisontalLine(uint8_t x_right, uint8_t x_left, uint8_t y, uint8_t color)
{
	for (uint8_t i = x_left; i <= x_right; i++)
	{
		draw_Dot(i, y, color);
	}
}