/*
 * Title:			C MAndelbrot example for Agon Light
 * Author:			James Higgs (Jum Hig)
 * Created:			2023
 * Last Updated:		2023-03-06
 *
 * Modinfo:
 */
 
#include <stdio.h>
#include <ctype.h>
#include "mos-interface.h"
#include "vdp.h"

#define MAX_ITERATION	20
#define SCREEN_WIDTH		320
#define SCREEN_HEIGHT	200

/// @param[in] argc			Argument count
/// @param[in] argv			Pointer to the argument string - zero terminated, parameters separated by spaces
int main(int argc, char * argv[]) {
	int	x, y;
	float x0, y0;
	UINT8 iteration;
	float a, b, xtemp;
	UINT8 shade;
	UINT8 keycode;
	
	// Set to 320 x 200 mode
	vdp_mode(2);
	vdp_cursorDisable();
	vdp_cls();
	
/* 	printf("Hello World\n\r");
	printf("Arguments:\n\r");
	printf("- argc: %d\n\r", argc);
	
	for(i = 0; i < argc; i++) {
		printf("- argv[%d]: %s\n\r", i, argv[i]);
	} */

	for (y = 0; y < SCREEN_HEIGHT; y++)
		{
		// Scale y coord to mandel set { -1.12, +1.12)
		y0 = (y - (SCREEN_HEIGHT / 2)) / 89.2857;				// 200 / 2 / 1.12
		for (x = 0; x < SCREEN_WIDTH; x++)
			{
			// Scale x coord to mandel set { -2.00, 0.47 } 
			x0 = (x - (SCREEN_WIDTH / 2)) / 89.2857;			// TODO - Fix!

			// Do mandel iteration
			iteration = 0;
			a = 0;
			b = 0;
			while ((a * a + b * b) <= (2 * 2) && iteration < MAX_ITERATION)
				{
				xtemp = a * a - b * b + x0;
				b = 2 * a * b + y0;
				a = xtemp;
				iteration++;
				}

			shade = iteration * 10;
			vdp_plotColour(shade, shade, shade);
			vdp_plotPoint(x, y);
				
			keycode = getsysvar8bit(sysvar_keycode);
			//keycode = getch();
			//printf("%d\n\r", keycode);
			if (27 == keycode)
				break;
			}
		}
	
	vdp_cursorEnable();
	
	vdp_mode(0);
	vdp_cls();
	
	return 0;
}