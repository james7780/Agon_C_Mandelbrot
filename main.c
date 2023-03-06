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

#define MAX_ITERATION	16	//20
#define SCREEN_WIDTH	512
#define SCREEN_HEIGHT	384

struct RGB_t
{
	UINT8 r;
	UINT8 g;
	UINT8 b;
};

// Colours for the mandlebrot shading
struct RGB_t colours[8] = {
	 { 0,   0,   0   },
	 { 0,   0,   255 },
	 { 0,   255, 0   },
	 { 0,   255, 255 },
	 { 255, 0,   0   },
	 { 255, 0,   255 },
	 { 255, 255, 0   },
	 { 255, 0,   255 }	
};

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
	
	// Set to 512x384 mode
	vdp_mode(1);
	vdp_cursorDisable();
	vdp_cls();
	
/* 	printf("Hello World\n\r");
	printf("Arguments:\n\r");
	printf("- argc: %d\n\r", argc);
	
	for(i = 0; i < argc; i++) {
		printf("- argv[%d]: %s\n\r", i, argv[i]);
	} */

	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
		{
		// Scale y coord to mandel set { -1.12 ... +1.12)
		y0 = (y - (SCREEN_HEIGHT / 2)) / 150.0;				// 200 / 2 / 1.12
		for (x = 0; x < SCREEN_WIDTH; x++)
			{
			// Scale x coord to mandel set { -2.50 ... 0.0 } 
			x0 = (x - (SCREEN_WIDTH / 2)) / 150.0 - 0.5;			// TODO - Fix!

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
			vdp_plotColour(colours[shade].r, colours[shade].g, colours[shade].b);
			vdp_plotPoint(x, y);
			vdp_plotPoint(x, 383 - y);
				
			//keycode = getsysvar8bit(sysvar_keycode);
			//keycode = getch();
			//printf("%d\n\r", keycode);
			//if (27 == keycode)
			//	break;
			keycode = getkeycode();
			//printf("%d\n\r", k);
			//if (27 == k)
			if (keycode != 0)
				{
				y = SCREEN_HEIGHT;
				break;
				}
			}
		}
	
	vdp_cursorEnable();
	
	//vdp_mode(0);
	//vdp_cls();
	
	return 0;
}