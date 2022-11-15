#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "pyramid.h"
#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "cube.h"
#include "smallCube.h"
#include <stack>


//Graphics class
class Graphics
{
  public:
    Graphics(); //Default Constructor
    ~Graphics(); //Destructor
    bool Initialize(int width, int height); //Initializes the window elements
    void UpdateRender(float dt, glm::vec3 speed); //Sets the speed that the an object updates at
    
    Object* getTriangle() { return m_triangle; } //Returns pointer to triangle object
    Cube* getCube() { return m_cube; } //Returns pointer to triangle object
    Pyramid* getPyramid() { return m_pyramid; } //Returns pointer to triangle object
    smallCube* getsmallCube() { return m_smallCube; } //Returns pointer to triangle object


  private:
    //Private class variables/pointers
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;
    //GLint is always 32 bits in length
    GLint m_projectionMatrix; 
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_vertPos;
    GLint m_vertCol;

    stack<glm::mat4> mvStack;

    float cameraX;
    float cameraY;
    float cameraZ;
    float cubeLocX;
    float cubeLocY;
    float cubeLocZ;

    Object* m_triangle;
    Cube* m_cube;
    Pyramid* m_pyramid;
    smallCube* m_smallCube;

    glm::mat4 vMat;
    glm::vec3 m_vectRotate = glm::vec3(0., 0., 0.);
};

#endif /* GRAPHICS_H */
