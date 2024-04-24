#include <GLFW/glfw3.h>
#include "npc.h"
#include "bullet.h"
#include "player.h"
#include<iostream> 

using namespace std;

// accessing the private variables
// -------------------------------------------------
float NPC::getNpcX() {
    return square_pos_x;
}
float NPC::getNpcY() {
    return square_pos_y;
}
float Player::getPlayerX() const {
    return pos_x;
}
float Player::getPlayerY() const {
    return pos_y;
}
float Bullet::getBulletX() const {
    return bul_x;
}
float Bullet::getBulletY() const {
    return bul_y;
}

Bullet b(0.0f, 0.0f, 0.0002f);

// -------------------------------------------------

// keyboard interaction for movement
// -------------------------------------------------
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
        case GLFW_KEY_ESCAPE:
            glfwDestroyWindow(window);
            break;
        case GLFW_KEY_SPACE:
            if (action == GLFW_PRESS) {
                // Set bullet's position to player's position
                b.setBulletPosition(player->getPlayerX(), player->getPlayerY());
            }
            break;
        }
    }
}
// -------------------------------------------------

// this checks if the player and the npc are touching.
// -------------------------------------------------
bool static collide(Player& player, NPC& npc) {
    return (player.getPlayerX() < npc.getNpcX() + 0.2f && player.getPlayerX() + 0.2f > npc.getNpcX() && player.getPlayerY() < npc.getNpcY() + 0.2f && player.getPlayerY() + 0.2f > npc.getNpcY());
}

bool static collideBullet(Bullet& bull, NPC& npc) {
    return (bull.getBulletX() < npc.getNpcX() + 0.2f && bull.getBulletX() + 0.2f > npc.getNpcX() && bull.getBulletY() < npc.getNpcY() + 0.2f && bull.getBulletY() + 0.2f > npc.getNpcY());
}
// -------------------------------------------------

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Demo 1", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Create a Player object and set it as user pointer for the window
    Player player(0.0f, 0.0f, 0.025f);
    glfwSetWindowUserPointer(window, &player);
    glfwSetKeyCallback(window, key_callback);

    NPC npc(0.0f, 0.0f, 0.00005f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        npc.display();
        npc.side_movement();
        // Draw the player rectangle
        player.player_display();

        if (b.isActive()) {
            b.fired();  // Move the bullet
            b.display();  // Render the bullet
        }


        // this loop uses collide() to check if the two objects are touching and if
        // they are, it uses death_reset in player.h to send the player back to the start. 
        if (collide(player, npc)) {
            player.death_reset();
        }

        if (collideBullet(b, npc)) {
            //isnt made yet, but it'll destroy the enemy object
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
