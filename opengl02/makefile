#Space invaders makefile
CC=g++
cc=gcc

OPT = -g -Wall
#OPT += -O3

UNAME := $(shell uname)

#-LIBRARIES AND INCLUDES
FRAMEWORK = -framework GLUT -framework OpenGL
LIBS = -lGL -lGLU -lm -lstdc++ -lfreetype -lftgl
INCS = -I.
INCS += -I./include

#Mac specific includes
ifeq ($(UNAME), Darwin)

  #x11/opengl
LIBS += -L"/usr/X11/lib"
INCS += -I"/usr/X11/include/GL"

  #FreeType GL: fonts
LIBS += -L"/usr/local/Cellar/ftgl/2.1.3-rc5/lib"
INCS += -I"/usr/local/Cellar/ftgl/2.1.3-rc5/include"
INCS += -I"/usr/X11/include/freetype2"

  #Eigen: linear algebra
INCS += -I"/usr/local/Cellar/eigen/3.0.5/include/eigen3"

endif


#FLAGS
CCOPTS = $(OPT) $(INCS) -c
LDOPTS = $(OPT) $(INCS) $(LIBS)

#USEFUL INFORMATION
SOURCES=main.cpp si_game.cpp state.cpp renderable.cpp render.cpp viewport.cpp quits.cpp si_states.cpp scene.cpp physics.cpp entity.cpp util.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

#RULES
all: $(SOURCES) $(EXECUTABLE)

clean:
	/bin/rm -f *.o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FRAMEWORK) $(OBJECTS) $(LDOPTS) -o $@

.cpp.o:
	$(CC) $(CCOPTS) $< -o $@
