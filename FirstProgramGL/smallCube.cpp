#include "smallCube.h"

//Default constructor for Cube class
smallCube::smallCube()
{
	createVertices();
}
//Create the verices for the Cube
void smallCube::createVertices()
{
	//Setting up vertices for the cube.
	Vertices =
	{
		{{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},

		{{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},

		{{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},

		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},


		{{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},

		{{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},

		{{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},

		{{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
	};


	Indices = {
	//Top
	2, 3, 4,
	8, 7, 6,

	//Bottom
	1, 5, 6,
	2, 6, 7,

	//Left
	7, 8, 4,
	1, 4, 8,

	//Right
	1, 2, 4,
	5, 8, 6,

	//Front
	2, 1, 6,
	3, 2, 7,

	//Back
	3, 7, 4,
	5, 1, 8
	};

	//Start the index at one instead of zero
	for (unsigned int i = 0; i < Indices.size(); i++)
	{
		Indices[i] = Indices[i] - 1;
	}
}

void smallCube::Initialize(GLint posAttribLoc, GLint colAttribLoc) 
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
smallCube::~smallCube()
{
	Vertices.clear();
	Indices.clear();
}


//Function that returns the model of this class
glm::mat4 smallCube::GetModel()
{
	return model;
}

//Rendering the model at the afformented positions
void smallCube::Render(GLint posAttribLoc, GLint colAttribLoc)
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

