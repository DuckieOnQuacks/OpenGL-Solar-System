#ifndef PYRAMID_H
#define PYRAMID_H

#include <vector>
#include "graphics_headers.h"

class Pyramid
{
  public:
    Pyramid();
    ~Pyramid();
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    void createVertices();
    glm::mat4 GetModel();
    void setSpeed(glm::vec3 spd) { m_speed = spd; }

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    GLuint vao; //Vertex array object
    GLuint VB; //Vertex bufferhmm
    GLuint IB; //Vertex buffer

    glm::vec3 m_speed = glm::vec3(0., 0., 0.);

    float angle;
};

#endif
