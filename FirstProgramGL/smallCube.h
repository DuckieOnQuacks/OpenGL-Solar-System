#ifndef SMALLCUBE_H
#define SMALLCUBE_H

#include <vector>
#include "graphics_headers.h"

class smallCube
{
  public:
    smallCube();
    ~smallCube();
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    void createVertices();

    glm::mat4 GetModel();

    void setSpeed(glm::vec3 spd)
    { 
        m_speed = spd;
    }

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    GLuint vao; //Vertex array object
    GLuint VB; //Vertex buffer
    GLuint IB; //Vertex buffer

    glm::vec3 m_speed = glm::vec3(0., 0., 0.);

    float angle;
};

#endif
