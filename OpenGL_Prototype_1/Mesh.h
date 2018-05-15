#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }
    glm::vec3 pos;
    glm::vec2 texCoord;
protected:
private:
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    
    void Draw();

    virtual ~Mesh();
private:
    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

