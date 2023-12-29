/*
 * Title:			C MAndelbrot example for Agon Light
 * Author:			James Higgs (Jum Hig)
 * Created:			2023
 * Last Updated:		2023-12-21
 *
 * Revisions:
 * 2023-04-21 - Updated to MOS 1.03
 * 2023-12-21 - Updated to MOS 1.04
 */
 
#include <stdio.h>
#include <ctype.h>
#include "mos-interface.h"
#include "vdp.h"

#define MAX_ITERATION	16		//20
#define SCREEN_WIDTH		640		//1024
#define SCREEN_HEIGHT	480		//1024

/// @param[in] argc			Argument count
/// @param[in] argv			Pointer to the argument string - zero terminated, parameters separated by spaces
int main(int argc, char * argv[]) {
	int	x, y;
	float x0, y0;
	float x2, y2;
	float w;
	UINT8 iteration;
	float a, b, xtemp;
	UINT8 shade;
	UINT8 keycode;
	
	// Set video mode
	vdp_mode(VDPMODE_640x480_16C);	//1); was 512 x 384 in MOS 1.03
	vdp_cursorDisable();
	vdp_cls();
	vdp_setLogicalCoords(0);				// turn off BBC illogical coords
	
/* 	printf("Hello World\n\r");
	printf("Arguments:\n\r");
	printf("- argc: %d\n\r", argc);
	
	for(i = 0; i < argc; i++) {
		printf("- argv[%d]: %s\n\r", i, argv[i]);
	} */
	
	printf("Screen width: %d\n\r", SCREEN_WIDTH);
	printf("Screen height: %d\n\r", SCREEN_HEIGHT);

	// Wait for key release
	while (getsysvar_vkeydown() != 0) { };

	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
		{
		// Scale y coord to mandel set { -1.12 ... +1.12)
		y0 = (y - (SCREEN_HEIGHT / 2)) / 300.0;				// 200 / 2 / 1.12
		for (x = 0; x < SCREEN_WIDTH; x++)
			{
			// Scale x coord to mandel set { -2.50 ... 0.0 } 
			x0 = (x - (SCREEN_WIDTH / 2)) / 300.0 - 0.5;			// TODO - Fix!

			// Do mandel iteration
			iteration = 0;
			a = 0;
			b = 0;
/* unoptimised version
			while ((a * a + b * b) <= (2 * 2) && iteration < MAX_ITERATION)
				{
				xtemp = a * a - b * b + x0;
				b = 2 * a * b + y0;
				a = xtemp;
				iteration++;
				}
*/
			// optimised version
			x2 = y2 = w = 0;
			while ((x2 + y2 < 4) && iteration < MAX_ITERATION)
				{
				a = x2 - y2 + x0;
				b = w - x2 - y2 + y0;
				x2 = a * a;
				y2 = b * b;
				w = (a + b) * (a + b);
				iteration++;
				}
			shade = (iteration & 0x07);
			vdp_plotColour(shade);			// palette colour index
			vdp_plotPoint(x, y);
			vdp_plotPoint(x, SCREEN_HEIGHT - y - 1);
				
			keycode = getsysvar_keyascii();
			//printf("%d\n\r", keycode);
			if (27 == keycode)
				{
				printf("Esc key pressed!\n\r");
				y = SCREEN_HEIGHT;
				break;
				}
			}
		}
	
	vdp_cursorEnable();
	
	return 0;
}