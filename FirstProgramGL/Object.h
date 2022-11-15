#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object(); //Deafult Constructor
    ~Object(); //Destructor
    void Initialize(GLint posAttribLoc, GLint colAttribLoc); //Initialize the object vertices
    void Update(unsigned int dt); //Set how often the object updates
    void Render(GLint posAttribLoc, GLint colAttribLoc); //Render the object into the view space
    void createVertices();

    glm::mat4 GetModel(); //Get the current model

    //Helper function to set the private variable speed
    void setSpeed(glm::vec3 spd) 
    { 
        m_speed = spd; 
    }

  private:
    //Private variable declarations
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint vao; //Vertex array object
    GLuint VB; //Vertex buffer
    GLuint IB; //Vertex buffer

    glm::vec3 m_speed = glm::vec3(0., 0., 0.);

    float angle;
};

#endif /* OBJECT_H */
