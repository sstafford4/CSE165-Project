#include <GLFW/glfw3.h>
#include "npc.h"
#include "player.h"
#include<iostream> 


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Player* player = static_cast<Player*>(glfwGetWindowUserPointer(window));

    // Move the player based on key presses
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_W:
            player->moveUp();
            break;
        case GLFW_KEY_S:
            player->moveDown();
            break;
        case GLFW_KEY_A:
            player->moveLeft();
            break;
        case GLFW_KEY_D:
            player->moveRight();
            break;
        }
    }
}

// this checks if the player and the npc are touching. 
bool collide(Player& player, NPC& npc) {
    return (player.getPlayerX() < npc.getNpcX() + 0.2f && player.getPlayerX() + 0.2f > npc.getNpcX() && player.getPlayerY() < npc.getNpcY() + 0.2f && player.getPlayerY() + 0.2f > npc.getNpcY());
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Demo 1", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Create a Player object and set it as user pointer for the window
    Player player(0.0f, 0.0f, 0.01f);
    glfwSetWindowUserPointer(window, &player);
    glfwSetKeyCallback(window, key_callback);

    NPC npc(0.0f, 0.0f, 0.00005f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        npc.display();
        npc.side_movement(); 
        // Draw the player rectangle
        player.player_display();

        // this loop uses collide() to check if the two objects are touching and if
        // they are, it uses death_reset in player.h to send the player back to the start. 
        if (collide(player, npc)) {
            player.death_reset(); 
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
