#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Hexagram : public Shape
{
    public:
        static unsigned int vertexArray;
        static unsigned int vertexBuffer;
        static unsigned int indexBuffer;

        Hexagram();
        void draw();

    private:
        float vertices[24] = {
             0.0f,  1.0f, 0.5f,  0.0f,
             0.9f,  0.5f, 0.95f, 0.25f,
             0.9f, -0.5f, 0.95f, 0.25f,
             0.0f, -1.0f, 0.0f,  0.0f,
            -0.9f, -0.5f, 0.95f, 0.25f,
            -0.9f,  0.5f, 0.95f, 0.25f,
        };

        unsigned int indexArr[6] = {
            0, 2, 4,
            1, 3, 5
        };
};
