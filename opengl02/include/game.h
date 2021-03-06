#pragma once

//GL STUFF
#include <glut.h>
#include <glu.h>

//STDLIB STUFF
#include <vector>
#include <iostream>
#include <string>

//TIME STUFF
#ifdef _WIN32
#	include <windows.h>
#else
#	include <sys/time.h>
#endif
#ifdef _WIN32
static DWORD lastTime;
#else
static struct timeval lastTime;
#endif

#include <Eigen/Core>
#include <FTGL/ftgl.h>
//GAME STUFF
#include "viewport.h"
#include "quits.h"
#include "state.h"
#include "input.h"
#include "renderable.h"
#include "renderer.h"

///Game: state manager, traffic director for input and GL callbacks
///Contains input, and rendering managers (plus others in future)
class Game : public StateManager {
public:
  virtual ~Game() {}
  virtual void run()=0;
  virtual void end()=0;
  virtual void draw()=0;
  virtual void reshapeViewport(int w, int h)=0;
  virtual void idle()=0;
  virtual void normalKeyDown(unsigned char key, int x, int y)=0;
  virtual void normalKeyUp(unsigned char key, int x, int y)=0;
  virtual void specialKeyDown(int key, int x, int y)=0;
  virtual void specialKeyUp(int key, int x, int y)=0;
  virtual Viewport* getViewport()=0;
protected:

};