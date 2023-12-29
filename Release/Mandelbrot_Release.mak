SHELL = cmd.exe

#
# ZDS II Make File - Mandelbrot project, Release configuration
#
# Generated by: ZDS II - eZ80Acclaim! 5.3.4 (Build 19112104)
#   IDE component: d:5.3.0:19052909
#   Install Path: C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\
#

RM = del

# ZDS base directory
ZDSDIR = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4
ZDSDIR_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4

# ZDS bin directory
BIN = $(ZDSDIR)\bin

# ZDS include base directory
INCLUDE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\include
INCLUDE_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\include

# ZTP base directory
ZTPDIR = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\ZTP2.5.1
ZTPDIR_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\ZTP2.5.1

# project directory
PRJDIR = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot
PRJDIR_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot

# intermediate files directory
WORKDIR = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot\Release
WORKDIR_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot\Release

# output files directory
OUTDIR = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot\Release\
OUTDIR_ESCSPACE = C:\ZiLOG\ZDSII_eZ80Acclaim!_5.3.4\Agon_Mandelbrot\Release\

# tools
CC = @"$(BIN)\eZ80cc"
AS = @"$(BIN)\eZ80asm"
LD = @"$(BIN)\eZ80link"
AR = @"$(BIN)\eZ80lib"
WEBTOC = @"$(BIN)\mkwebpage"

CFLAGS =  \
-define:NDEBUG -define:_EZ80F92 -define:_EZ80ACCLAIM! -genprintf  \
-NOkeepasm -keeplst -NOlist -NOlistinc -NOmodsect -optspeed  \
-promote -NOreduceopt  \
-stdinc:"\"..;..\..\include\std;..\..\include\zilog\""  \
-usrinc:"\"..;\"" -NOmultithread -NOpadbranch -NOdebug  \
-cpu:eZ80F92  \
-asmsw:"   \
	-define:_EZ80ACCLAIM!=1  \
	-include:\"..;..\..\include\std;..\..\include\zilog\" -list  \
	-NOlistmac -pagelen:0 -pagewidth:80 -quiet -sdiopt -warn -NOdebug  \
	-NOigcase -cpu:eZ80F92"

ASFLAGS =  \
-define:_EZ80ACCLAIM!=1  \
-include:"\"..;..\..\include\std;..\..\include\zilog\"" -list  \
-NOlistmac -name -pagelen:0 -pagewidth:80 -quiet -sdiopt -warn  \
-NOdebug -NOigcase -cpu:eZ80F92

LDFLAGS = @..\Release.linkcmd
build: Mandelbrot

buildall: clean Mandelbrot

relink: deltarget Mandelbrot

deltarget: 
	@if exist "$(WORKDIR)\Mandelbrot.lod"  \
            $(RM) "$(WORKDIR)\Mandelbrot.lod"
	@if exist "$(WORKDIR)\Mandelbrot.hex"  \
            $(RM) "$(WORKDIR)\Mandelbrot.hex"
	@if exist "$(WORKDIR)\Mandelbrot.map"  \
            $(RM) "$(WORKDIR)\Mandelbrot.map"

clean: 
	@if exist "$(WORKDIR)\Mandelbrot.lod"  \
            $(RM) "$(WORKDIR)\Mandelbrot.lod"
	@if exist "$(WORKDIR)\Mandelbrot.hex"  \
            $(RM) "$(WORKDIR)\Mandelbrot.hex"
	@if exist "$(WORKDIR)\Mandelbrot.map"  \
            $(RM) "$(WORKDIR)\Mandelbrot.map"
	@if exist "$(WORKDIR)\init.obj"  \
            $(RM) "$(WORKDIR)\init.obj"
	@if exist "$(WORKDIR)\init.lis"  \
            $(RM) "$(WORKDIR)\init.lis"
	@if exist "$(WORKDIR)\init.lst"  \
            $(RM) "$(WORKDIR)\init.lst"
	@if exist "$(WORKDIR)\main.obj"  \
            $(RM) "$(WORKDIR)\main.obj"
	@if exist "$(WORKDIR)\main.lis"  \
            $(RM) "$(WORKDIR)\main.lis"
	@if exist "$(WORKDIR)\main.lst"  \
            $(RM) "$(WORKDIR)\main.lst"
	@if exist "$(WORKDIR)\main.src"  \
            $(RM) "$(WORKDIR)\main.src"
	@if exist "$(WORKDIR)\mos-interface.obj"  \
            $(RM) "$(WORKDIR)\mos-interface.obj"
	@if exist "$(WORKDIR)\mos-interface.lis"  \
            $(RM) "$(WORKDIR)\mos-interface.lis"
	@if exist "$(WORKDIR)\mos-interface.lst"  \
            $(RM) "$(WORKDIR)\mos-interface.lst"
	@if exist "$(WORKDIR)\vdp.obj"  \
            $(RM) "$(WORKDIR)\vdp.obj"
	@if exist "$(WORKDIR)\vdp.lis"  \
            $(RM) "$(WORKDIR)\vdp.lis"
	@if exist "$(WORKDIR)\vdp.lst"  \
            $(RM) "$(WORKDIR)\vdp.lst"
	@if exist "$(WORKDIR)\vdp.src"  \
            $(RM) "$(WORKDIR)\vdp.src"

# pre-4.11.0 compatibility
rebuildall: buildall 

LIBS = 

OBJS =  \
            $(WORKDIR_ESCSPACE)\init.obj  \
            $(WORKDIR_ESCSPACE)\main.obj  \
            $(WORKDIR_ESCSPACE)\mos-interface.obj  \
            $(WORKDIR_ESCSPACE)\vdp.obj

Mandelbrot: $(OBJS)
	 $(LD) $(LDFLAGS)

$(WORKDIR_ESCSPACE)\init.obj :  \
            $(PRJDIR_ESCSPACE)\init.asm
	 $(AS) $(ASFLAGS) "$(PRJDIR)\init.asm"

$(WORKDIR_ESCSPACE)\main.obj :  \
            $(PRJDIR_ESCSPACE)\main.c  \
            $(PRJDIR_ESCSPACE)\mos-interface.h  \
            $(PRJDIR_ESCSPACE)\stdint.h  \
            $(PRJDIR_ESCSPACE)\vdp.h  \
            $(INCLUDE_ESCSPACE)\std\Format.h  \
            $(INCLUDE_ESCSPACE)\std\Stdarg.h  \
            $(INCLUDE_ESCSPACE)\std\CTYPE.H  \
            $(INCLUDE_ESCSPACE)\std\Stdio.h  \
            $(INCLUDE_ESCSPACE)\zilog\defines.h
	 $(CC) $(CFLAGS) "$(PRJDIR)\main.c"

$(WORKDIR_ESCSPACE)\mos-interface.obj :  \
            $(PRJDIR_ESCSPACE)\mos-interface.asm  \
            $(PRJDIR_ESCSPACE)\mos_api.inc
	 $(AS) $(ASFLAGS) "$(PRJDIR)\mos-interface.asm"

$(WORKDIR_ESCSPACE)\vdp.obj :  \
            $(PRJDIR_ESCSPACE)\vdp.c  \
            $(PRJDIR_ESCSPACE)\mos-interface.h  \
            $(PRJDIR_ESCSPACE)\stdint.h  \
            $(PRJDIR_ESCSPACE)\vdp.h  \
            $(INCLUDE_ESCSPACE)\zilog\defines.h
	 $(CC) $(CFLAGS) "$(PRJDIR)\vdp.c"

