#ifndef ENGINE_H
#define ENGINE_H

#include <assert.h>
#include "window.h"
#include "graphics.h"


//Engine class responsible for dealing with the view window
class Engine
{
  public:
    //Default constructor for engine class
    Engine(const char*  name, int width, int height);
    
    ~Engine(); //Destructor
    //Window setup 
    bool Initialize();
    void Run();
    unsigned int getDT();
    long long GetCurrentTimeMillis(); 

    //Displays view window
    void Display(GLFWwindow*, double);

   //Helper function to set private variable speed
    void setSpeed(glm::vec3 spd) { speed = spd; };
  
  private:
    // Window related variables
    Window *m_window;    
    const char* m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;
    bool m_running;

    //Speed variable that is set by its helper function
    glm::vec3 speed = glm::vec3(0.f,0.f,0.f);

    //Create graphics object
    Graphics *m_graphics;
};

#endif // ENGINE_H
