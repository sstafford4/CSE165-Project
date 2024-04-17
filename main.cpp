#include <GLFW/glfw3.h>
#include "npc.h"

int main(void)
{
    NPC npc; // npc object of type NPC
    //NPC npc2; 
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    //window = glfwCreateWindow(640, 480, "Demo 1", NULL, NULL);
    window = glfwCreateWindow(800, 600, "Demo 1", NULL, NULL); 
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        npc.display(); //npc.h display function
         

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        npc.movement(); //npc.h movement function
    }

    glfwTerminate();
    return 0;
}
