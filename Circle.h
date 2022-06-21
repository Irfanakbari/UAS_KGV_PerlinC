#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Circle : public Shape
{
    public:
        static unsigned int vertexArray;
        static unsigned int vertexBuffer;
        static unsigned int indexBuffer;

        Circle();
        void draw();

    private:
        float pi = 3.14159;
        int j = 2;

        float vertices[130] = {};

        unsigned int indexArr[130 * 3] = {};
};
