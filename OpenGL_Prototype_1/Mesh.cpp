#include "Mesh.h"
#include <iostream>


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    m_drawCount = numVertices;

    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult)
    {
        printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
        exit(EXIT_FAILURE);
    }

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, m_vertexArrayBuffers);
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}
