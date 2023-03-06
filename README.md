# Agon Light C code Mandelbrot example

A simple example of a 24-bit ADL application in C, for the Agon Light.

This example generates a plot of the Mandelbrot set on the Agon Light.

Uses the floating-point library in the Zilog ZDS.

Use hex2bin to convert the Mandelbrot.hex file in the Debug output folder to a .bin that can be loaded and executed on the AGon Light.

Altenativley, use hexload to load Mandelbrot.hex to the Agon Light, then RUN it.

NB:
- The paths in the link files (Debug.linkcmd and Release.linkcmd) need to be modified to reflect where the tools are located on your hard drive before this will compile.