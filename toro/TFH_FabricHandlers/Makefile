######################################################################
#
# Toro VPR interface library
#
# Note: This make file is dependent on the platform-specific ISM 
#       environment variable.  ISM is platform-specific and is used 
#       to determine various build switches and directories.
#
#       This make file currently supports (csh/tcsh shells):
#       - setenv ISM linux_x86_64
#       - setenv ISM linux_i686
#       - setenv ISM sun8
#
#       This make file currently supports (ksh/sh shells):
#       - export ISM=linux_x86_64
#       - export ISM=linux_i686
#       - export ISM=sun8
#
######################################################################

######################################################################
# Compiler options
######################################################################

pC++linux_x86_64 = /usr/bin/gcc
pC++linux_i686 = /usr/bin/gcc
pC++sun8 = /apps/SUNWspro_6.0-U2/bin/CC
pC++ = $(pC++$(ISM))

PIClinux_x86_64 = -shared
PIClinux_i686 = -shared
PICsun8 = -G -KPIC
PIC = $(PIC$(ISM))

CFLAGSlinux_x86_64 = -Wall -Wpointer-arith -Wcast-qual -static -fPIC -DLINUX_X86_64
CFLAGSlinux_i686 = -Wall -Wpointer-arith -Wcast-qual -static -fPIC -DLINUX_I686
CFLAGSsun8 = +w -xarch=v9 -library=iostream,Cstd -DLP64 -DSUN8
CFLAGS = $(CFLAGS$(ISM)) \
	-DTORO_FABRIC_GRID_VALID_ENABLE \
	-DTORO_FABRIC_CHANNEL_WIDTHS_ENABLE \
	-I. \
	-I../TGO_GeometricObjects \
	-I../TIO_InputOutputHandlers \
	-I../TC_Common \
	-I../../libcommon_c/pcre/SRC \
	-I../../vpr/SRC/base -I../../vpr/SRC/util -I../../vpr/SRC/place \
	-I../../libarchfpga/include

######################################################################
# Linker options
######################################################################

LINKERlinux_x86_64 = /usr/bin/ld
LINKERlinux_i686 = /usr/bin/ld
LINKERsun8 = /usr/ccs/bin/ld
LINKER = $(LINKER$(ISM))

LFLAGSlinux_x86_64 = -shared
LFLAGSlinux_i686 = -shared
LFLAGSsun8 = -G -library=iostream -xarch=v9
LFLAGS = $(LFLAGS$(ISM))

######################################################################
# Program files
######################################################################

SOLlinux_x86_64 = so
SOLlinux_i686 = so
SOLsun8 = so
SOL = $(SOL$(ISM))

LIBSOlinux_x86_64 = ../linux_x86_64/$(PROG).$(SOL)
LIBSOlinux_i686 = ../linux_i686/$(PROG).$(SOL)
LIBSOsun8 = ../sun8/$(PROG).$(SOL)
LIBSO = $(LIBSO$(ISM))

OBJSlinux_x86_64 = linux_x86_64/TFH_FabricGridHandler.o \
                   linux_x86_64/TFH_FabricBlockHandler.o \
                   linux_x86_64/TFH_FabricSwitchBoxHandler.o \
                   linux_x86_64/TFH_FabricConnectionBlockHandler.o \
                   linux_x86_64/TFH_FabricChannelHandler.o \
                   linux_x86_64/TFH_GridBlock.o \
                   linux_x86_64/TFH_SwitchBox.o \
                   linux_x86_64/TFH_ConnectionBlock.o \
                   linux_x86_64/TFH_ConnectionMap.o \
                   linux_x86_64/TFH_StringUtils.o
OBJSlinux_i686 = linux_i686/TFH_FabricGridHandler.o \
                 linux_i686/TFH_FabricBlockHandler.o \
                 linux_i686/TFH_FabricSwitchBoxHandler.o \
                 linux_i686/TFH_FabricConnectionBlockHandler.o \
                 linux_i686/TFH_FabricChannelHandler.o \
                 linux_i686/TFH_GridBlock.o \
                 linux_i686/TFH_SwitchBox.o \
                 linux_i686/TFH_ConnectionBlock.o \
                 linux_i686/TFH_ConnectionMap.o \
                 linux_i686/TFH_StringUtils.o
OBJSsun8 = sun8/TFH_FabricGridHandler.o \
           sun8/TFH_FabricBlockHandler.o \
           sun8/TFH_FabricSwitchBoxHandler.o \
           sun8/TFH_FabricConnectionBlockHandler.o \
           sun8/TFH_FabricChannelHandler.o \
           sun8/TFH_GridBlock.o \
           sun8/TFH_SwitchBox.o \
           sun8/TFH_ConnectionBlock.o \
           sun8/TFH_ConnectionMap.o \
           sun8/TFH_StringUtils.o
OBJECTS = $(OBJS$(ISM))

PROG = libTFH_FabricHandlers
EXE = ../$(ISM)/$(PROG).a

######################################################################
# Target rules
######################################################################

BUILD_TARGET =

all:
	make Debug
Optimized:
	make $(EXE) CFLAGS="-O2 $(CFLAGS)" BUILD_TARGET=Optimized
Debug:
	make $(EXE) CFLAGS="-g -DDEBUG $(CFLAGS)" BUILD_TARGET=Debug
Gprof:
	make $(EXE) CFLAGS="-pg -g -DDEBUG $(CFLAGS)" BUILD_TARGET=Debug
clean:
	rm -f $(EXE) $(ISM)/*.o

.cxx.o:;
.cxx.a:;

######################################################################
# Program rules
######################################################################

ARCMDlinux_x86_64 = $(LINKER) -r -o $(ISM)/$(PROG).a $(OBJECTS) ; \
	mv $(ISM)/$(PROG).a $(EXE)
ARCMDlinux_i686 = $(LINKER) -r -o $(ISM)/$(PROG).a $(OBJECTS) ; \
	mv $(ISM)/$(PROG).a $(EXE)
ARCMDsun8 = $(pC++) -xar -xarch=v9 -library=iostream -o $(ISM)/$(PROG).a $(OBJECTS) ; \
	mv $(ISM)/$(PROG).a $(EXE)
ARCMD = $(ARCMD$(ISM))
$(EXE): $(LIBSO)
	$(ARCMD)

$(LIBSOlinux_x86_64): $(OBJECTS) Makefile
	$(pC++) $(LFLAGS) -o $(ISM)/$(PROG).$(SOL) $(OBJECTS) ; \
	mv $(ISM)/$(PROG).$(SOL) $@
$(LIBSOlinux_i686): $(OBJECTS) Makefile
	$(pC++) $(LFLAGS) -o $(ISM)/$(PROG).$(SOL) $(OBJECTS) ; \
	mv $(ISM)/$(PROG).$(SOL) $@
$(LIBSOsun8): $(OBJECTS) Makefile
	$(pC++) $(LFLAGS) -o $(ISM)/$(PROG).$(SOL) $(OBJECTS) ; \
	mv $(ISM)/$(PROG).$(SOL) $@

$(OBJECTS): $(ISM)/%.o:%.cxx
	$(pC++) -o $@ -c $(@F:.o=.cxx) $(PIC) $(CFLAGS)

######################################################################
# Library rules
######################################################################

../$(ISM)/libTGO_GeometricObjects.a:
	cd ../TGO_GeometricObjects ; $(MAKE) $(BUILD_TARGET)

../$(ISM)/libTIO_InputOutputHandlers.a:
	cd ../TIO_InputOutputHandlers ; $(MAKE) $(BUILD_TARGET)

../$(ISM)/libTC_Common.a:
	cd ../TC_Common ; $(MAKE) $(BUILD_TARGET)
