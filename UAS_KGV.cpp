// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <math.h>
#define _USE_MATH_DEFINES

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Util.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"
#include "Triangle.h"
#include "Hexagram.h"
#include "Circle.h"

using namespace std;

float xHeli = 0;
float yHeli = 0;

float currentTime = 0;
float deltaTime = 0;
float lastTime = 0;
float rotation = 0;
float rot = 0;

vector<Square> square;
vector<Triangle> triangle;
vector<Hexagram> hexagram;
vector<Circle> circle;

float degrad(float d)
{
    return d * M_PI / 180;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Square s;
    Triangle t;
    Hexagram h;
    Circle c;

    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_LEFT)  xHeli -= 0.02f;
        if (key == GLFW_KEY_RIGHT) xHeli += 0.02f;
        if (key == GLFW_KEY_DOWN)  yHeli -= 0.02f;
        if (key == GLFW_KEY_UP)    yHeli += 0.02f;

        /* Badan */
        s = Square();
        s.setTranslation(-0.3f + xHeli, 0.0f + yHeli, 0.0f);
        s.setScale(0.2f, 0.12f, 1.0f);
        s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        square[0] = s;

        /* Badan Bawah */
        s = Square();
        s.setTranslation(-0.36f + xHeli, -0.15f + yHeli, 0.0f);
        s.setScale(0.26f, 0.03f, 1.0f);
        s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        square[1] = s;

        /* Badan Depan */
        t = Triangle();
        t.setTranslation(-0.5f + xHeli, 0.0f + yHeli, 0.0f);
        t.setScale(0.12f, 0.12f, 1.0f);
        t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        triangle[0] = t;

        /* Badan Belakang */
        t = Triangle();
        t.setTranslation(-0.1f + xHeli, -0.03f + yHeli, 0.0f);
        t.setScale(0.15f, 0.15f, 1.0f);
        t.setRotation(degrad(180), 0.0f, 0.0f, 1.0f);
        t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        triangle[1] = t;

        /* Jendela */
        s = Square();
        s.setTranslation(-0.37f + xHeli, 0.02f + yHeli, 0.0f);
        s.setScale(0.12f, 0.07f, 1.0f);
        s.setColor(0.0f, 0.9f, 0.9f, 1.0f);
        square[2] = s;

        /* Jendela */
        t = Triangle();
        t.setTranslation(-0.485f + xHeli, 0.02f + yHeli, 0.0f);
        t.setScale(0.07f, 0.07f, 1.0f);
        t.setColor(0.0f, 0.9f, 0.9f, 1.0f);
        triangle[2] = t;

        /* Tangkai Ekor */
        s = Square();
        s.setTranslation(0.27f + xHeli, 0.09f + yHeli, 0.0f);
        s.setScale(0.25f, 0.03f, 1.0f);
        s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        square[3] = s;

        /* Ekor */
        t = Triangle();
        t.setTranslation(0.44f + xHeli, 0.14f + yHeli, 0.0f);
        t.setScale(0.08f, 0.08f, 1.0f);
        t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        triangle[3] = t;

        /* Ekor */
        t = Triangle();
        t.setTranslation(0.52f + xHeli, 0.14f + yHeli, 0.0f);
        t.setScale(0.08f, 0.08f, 1.0f);
        t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        t.setRotation(degrad(180), 0.0f, 0.0f, 1.0f);
        triangle[4] = t;

        /* Baling-baling Belakang */
        c = Circle();
        c.setTranslation(0.48f + xHeli, 0.14f + yHeli, 0.0f);
        c.setScale(0.12f, 0.12f, 1.0f);
        c.setColor(0.9f, 0.9f, 0.9f, 0.5f);
        circle[0] = c;

        /* Mesin Atas */
        s = Square();
        s.setTranslation(-0.35f + xHeli, 0.135f + yHeli, 0.0f);
        s.setScale(0.05f, 0.015f, 1.0f);
        s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
        square[4] = s;

        /* Tangkai Baling-baling Atas */
        s = Square();
        s.setTranslation(-0.35f + xHeli, 0.165f + yHeli, 0.0f);
        s.setScale(0.01f, 0.015f, 1.0f);
        s.setColor(0.5f, 0.5f, 0.5f, 1.0f);
        square[5] = s;

        /* Baling-baling Atas */
        s = Square();
        s.setTranslation(-0.35f + xHeli, 0.17f + yHeli, 0.0f);
        s.setScale(0.4f, 0.008f, 1.0f);
        s.setColor(0.9f, 0.9f, 0.9f, 0.5f);
        square[6] = s;

        /* Kaki Depan Helikopter */
        s = Square();
        s.setTranslation(-0.5f + xHeli, -0.2f + yHeli, 0.0f);
        s.setScale(0.015f, 0.02f, 1.0f);
        s.setColor(0.7f, 0.7f, 0.7f, 1.0f);
        square[7] = s;

        /* Kaki Belakang Helikopter */
        s = Square();
        s.setTranslation(-0.22f + xHeli, -0.2f + yHeli, 0.0f);
        s.setScale(0.015f, 0.02f, 1.0f);
        s.setColor(0.7f, 0.7f, 0.7f, 1.0f);
        square[8] = s;

        /* Telapak Kaki Helikopter */
        s = Square();
        s.setTranslation(-0.36f + xHeli, -0.23f + yHeli, 0.0f);
        s.setScale(0.26f, 0.015f, 1.0f);
        s.setColor(0.5f, 0.5f, 0.5f, 1.0f);
        square[9] = s;
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "UAS KGV Perlin-C", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

    GLenum err = glewInit();

    Square s;
    Triangle t;
    Hexagram h;
    Circle c;

    /* Bintang 1 */
    h = Hexagram();
    h.setTranslation(-0.7f, 0.6f, 0.0f);
    h.setScale(0.03f, 0.03f, 1.0f);
    h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
    hexagram.push_back(h);

    /* Bintang 2 */
    h = Hexagram();
    h.setTranslation(-0.6f, 0.85f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
    hexagram.push_back(h);

    /* Bintang 3 */
    h = Hexagram();
    h.setTranslation(0.0f, 0.65f, 0.0f);
    h.setScale(0.02f, 0.02f, 1.0f);
    h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
    hexagram.push_back(h);

    /* Bintang 4 */
    h = Hexagram();
    h.setTranslation(0.35f, 0.8f, 0.0f);
    h.setScale(0.04f, 0.04f, 1.0f);
    h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
    hexagram.push_back(h);

    /* Bintang 5 */
    h = Hexagram();
    h.setTranslation(0.65f, 0.4f, 0.0f);
    h.setScale(0.025f, 0.025f, 1.0f);
    h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
    hexagram.push_back(h);

    /* Badan */
    s = Square();
    s.setTranslation(-0.3f, 0.0f, 0.0f);
    s.setScale(0.2f, 0.12f, 1.0f);
    s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    square.push_back(s);

    /* Badan Bawah */
    s = Square();
    s.setTranslation(-0.36f, -0.15f, 0.0f);
    s.setScale(0.26f, 0.03f, 1.0f);
    s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    square.push_back(s);

    /* Badan Depan */
    t = Triangle();
    t.setTranslation(-0.5f, 0.0f, 0.0f);
    t.setScale(0.12f, 0.12f, 1.0f);
    t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    triangle.push_back(t);

    /* Badan Belakang */
    t = Triangle();
    t.setTranslation(-0.1f, -0.03f, 0.0f);
    t.setScale(0.15f, 0.15f, 1.0f);
    t.setRotation(degrad(180), 0.0f, 0.0f, 1.0f);
    t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    triangle.push_back(t);

    /* Jendela */
    s = Square();
    s.setTranslation(-0.37f, 0.02f, 0.0f);
    s.setScale(0.12f, 0.07f, 1.0f);
    s.setColor(0.0f, 0.9f, 0.9f, 1.0f);
    square.push_back(s);

    /* Jendela */
    t = Triangle();
    t.setTranslation(-0.485f, 0.02f, 0.0f);
    t.setScale(0.07f, 0.07f, 1.0f);
    t.setColor(0.0f, 0.9f, 0.9f, 1.0f);
    triangle.push_back(t);

    /* Tangkai Ekor */
    s = Square();
    s.setTranslation(0.27f, 0.09f, 0.0f);
    s.setScale(0.25f, 0.03f, 1.0f);
    s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    square.push_back(s);

    /* Ekor */
    t = Triangle();
    t.setTranslation(0.44f, 0.14f, 0.0f);
    t.setScale(0.08f, 0.08f, 1.0f);
    t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    triangle.push_back(t);

    /* Ekor */
    t = Triangle();
    t.setTranslation(0.52f, 0.14f, 0.0f);
    t.setScale(0.08f, 0.08f, 1.0f);
    t.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    t.setRotation(degrad(180), 0.0f, 0.0f, 1.0f);
    triangle.push_back(t);

    /* Baling-baling Belakang */
    c = Circle();
    c.setTranslation(0.48f, 0.14f, 0.0f);
    c.setScale(0.12f, 0.12f, 1.0f);
    c.setColor(0.9f, 0.9f, 0.9f, 0.5f);
    circle.push_back(c);

    /* Mesin Atas */
    s = Square();
    s.setTranslation(-0.35f, 0.135f, 0.0f);
    s.setScale(0.05f, 0.015f, 1.0f);
    s.setColor(0.9f, 0.2f, 0.0f, 1.0f);
    square.push_back(s);

    /* Tangkai Baling-baling Atas */
    s = Square();
    s.setTranslation(-0.35f, 0.165f, 0.0f);
    s.setScale(0.01f, 0.015f, 1.0f);
    s.setColor(0.5f, 0.5f, 0.5f, 1.0f);
    square.push_back(s);

    /* Baling-baling Atas */
    s = Square();
    s.setTranslation(-0.35f, 0.17f, 0.0f);
    s.setScale(0.4f, 0.008f, 1.0f);
    s.setColor(0.9f, 0.9f, 0.9f, 0.5f);
    square.push_back(s);

    /* Kaki Depan Helikopter */
    s = Square();
    s.setTranslation(-0.5f, -0.2f, 0.0f);
    s.setScale(0.015f, 0.02f, 1.0f);
    s.setColor(0.7f, 0.7f, 0.7f, 1.0f);
    square.push_back(s);

    /* Kaki Belakang Helikopter */
    s = Square();
    s.setTranslation(-0.22f, -0.2f, 0.0f);
    s.setScale(0.015f, 0.02f, 1.0f);
    s.setColor(0.7f, 0.7f, 0.7f, 1.0f);
    square.push_back(s);

    /* Telapak Kaki Helikopter */
    s = Square();
    s.setTranslation(-0.36f, -0.23f, 0.0f);
    s.setScale(0.26f, 0.015f, 1.0f);
    s.setColor(0.5f, 0.5f, 0.5f, 1.0f);
    square.push_back(s);



    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");
    
    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Warna Alpha (Transparan)
        glClearColor(0.0f, 0.3f, 0.6f, 1.0f); // Background Langit

        glUseProgram(program);

        for (int i = 0; i < hexagram.size(); i++)
        {
            glUniform4fv(uColor, 1, &hexagram[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &hexagram[i].getTransformationMat4x4()[0][0]);
            hexagram[i].draw();
        }

        for (int i = 0; i < square.size(); i++)
        {
            glUniform4fv(uColor, 1, &square[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &square[i].getTransformationMat4x4()[0][0]);
            square[i].draw();
        }

        for (int i = 0; i < triangle.size(); i++)
        {
            glUniform4fv(uColor, 1, &triangle[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &triangle[i].getTransformationMat4x4()[0][0]);
            triangle[i].draw();
        }

        for (int i = 0; i < circle.size(); i++)
        {
            glUniform4fv(uColor, 1, &circle[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &circle[i].getTransformationMat4x4()[0][0]);
            circle[i].draw();
        }

        /* Timer */
        currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        
        rotation += deltaTime;
        if (rotation >= 0.2f) {
            rotation = 0.1f;

            rot++;

            /* Bintang 1 */
            h = Hexagram();
            h.setTranslation(-0.7f, 0.6f, 0.0f);
            h.setScale(0.03f, 0.03f, 1.0f);
            h.setRotation(degrad(2 * -rot), 0.0f, 0.0f, 1.0f);
            h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
            hexagram[0] = h;

            /* Bintang 4 */
            h = Hexagram();
            h = Hexagram();
            h.setTranslation(0.35f, 0.8f, 0.0f);
            h.setScale(0.04f, 0.04f, 1.0f);
            h.setRotation(degrad(2 * rot), 0.0f, 0.0f, 1.0f);
            h.setColor(0.9f, 0.9f, 0.0f, 1.0f);
            hexagram[3] = h;
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
