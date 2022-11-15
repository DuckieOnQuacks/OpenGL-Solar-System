#include "engine.h"

//Engine class default constructor
Engine::Engine(const char* name, int width, int height)
{
  m_WINDOW_NAME = name; //Setting window name
  m_WINDOW_WIDTH = width; //Setting window width
  m_WINDOW_HEIGHT = height; //Setting window height
}

//Engine class destructor
Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}


bool Engine::Initialize()
{
  //Start a window and check to make sure it is successfully initialized
  m_window = new Window(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT);
  if(!m_window->Initialize())
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics and check to make sure it is successfully initialized
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // No errors
  return true;
}

//While the window exists, this function opens that window and displays the triangle
void Engine::Run()
{
  m_running = true;
  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
      //ProcessInput();
      Display(m_window->getWindow(), glfwGetTime());
      glfwPollEvents();
  }
  m_running = false;
}

//Helper function that returns the deltaTime
unsigned int Engine::getDT()
{
  //long long TimeNowMillis = GetCurrentTimeMillis();
  //assert(TimeNowMillis >= m_currentTimeMillis);
  //unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  //m_currentTimeMillis = TimeNowMillis;
  //return DeltaTimeMillis;
    return glfwGetTime();
}

//Helper function that returns the time in milliseconds
long long Engine::GetCurrentTimeMillis()
{
  //timeval t;
  //gettimeofday(&t, NULL);
  //long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  //return ret;
    return (long long) glfwGetTime();
}

//Helper function to display a passed in window. As well as how often you want the triangle to update.
void Engine::Display(GLFWwindow* window, double time) 
{
    m_window->Swap();
    m_graphics->UpdateRender(time*2, speed);
}
