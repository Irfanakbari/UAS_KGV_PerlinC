#include "Circle.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int Circle::vertexArray = 0;
unsigned int Circle::vertexBuffer = 0;
unsigned int Circle::indexBuffer = 0;

Circle::Circle()
{
    for (float i = 0; i <= pi * 2.04; i += 0.1)
    {
        vertices[j] = sin(i); j++;
        vertices[j] = cos(i); j++;
    }

    j = 0;
    for (int i = 1; i <= pi * 2.04 / 0.1; i++)
    {
        indexArr[j] = 0; j++;
        indexArr[j] = i; j++;
        indexArr[j] = (i == pi * 2.04 / 0.1) ? 1 : i + 1; j++;
    }
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2.04 * (pi * 2.04 / 0.1) + 2, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * (3 * (pi * 2.04 / 0.1)), indexArr, GL_STATIC_DRAW);

    // Pointer Data Posisi
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
}

void Circle::draw()
{
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glDrawElements(GL_TRIANGLES, (3 * (pi * 2.04 / 0.1)), GL_UNSIGNED_INT, nullptr);
}
