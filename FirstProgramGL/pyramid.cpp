#include "pyramid.h"

//Default constructor for Cube class
Pyramid::Pyramid()
{
	createVertices();
}
//Create the verices for the Cube
void Pyramid::createVertices()
{
	//Setting up vertices for the cube.
	Vertices =
	{
		{{0.0f, 2.0f, 0.0f}, {1, 1, 1}},

		{{1.0f, 0.0f, 1.0f}, {0, 1, 0}},

		{{-1.0f, 0.0f, 1.0f}, {0, 0, 1}},

		{{-1.0f, 0.0f, -1.0f}, {1, 0, 0}},

		{{1.0f, 0.0f, -1.0f}, {0, 0, 1}},

	};

	Indices = 
	{
		0, 1, 2,	// Front Triangle
		0, 2, 3,	// Right Side triangle
		0, 3, 4,	// Back triangle
		0, 4, 1,	// Left back side triangle
		1, 2, 3,	// Bottom Triangle
		3, 4, 1		// Bottom triangle
	};
}

void Pyramid::Initialize(GLint posAttribLoc, GLint colAttribLoc) 
{
	// Set up your VOA
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// setting the Vertex VBO
	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(posAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	// Setting the Index VBO
	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);

}

//Cube class destructor.
Pyramid::~Pyramid()
{
	Vertices.clear();
	Indices.clear();
}


//Function that returns the model of this class
glm::mat4 Pyramid::GetModel()
{
	return model;
}

//Rendering the model at the afformented positions
void Pyramid::Render(GLint posAttribLoc, GLint colAttribLoc)
{
	// Bind VAO
	glBindVertexArray(vao);

	// Bind VBO(s)
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

	// enable the vertex attribute arrays 
	// this is the poistion attrib in the vertex shader
	glEnableVertexAttribArray(posAttribLoc);
	// this is the color attribe in the vertex shader
	glEnableVertexAttribArray(colAttribLoc);

	// Draw call to OpenGL
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

	// disable the vertex attributes
	glDisableVertexAttribArray(posAttribLoc);
	glDisableVertexAttribArray(colAttribLoc);

	// unbind VBO(s) and ElementBuffer(s)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

