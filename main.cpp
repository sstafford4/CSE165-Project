#include <GLFW/glfw3.h>
#include "player.h"
#include "NPCVirt.h"
#include"bullet.h"
#include "enemy.h"
#include<vector>
#include<iostream> 

using namespace std;

// accessing the private variables
// -------------------------------------------------

float Player::getPlayerX() const {
    return pos_x;
}

float Player::getPlayerY() const {
    return pos_y;
}

float Bullet::returnBulletY() const{
    return bullet_y;
}

float Bullet::returnBulletX() const {
    return bullet_x; 
}

float Enemy::enemyX() {
    return x; 
}

float Enemy::enemyY() {
    return y; 
}
// -------------------------------------------------

// keyboard interaction for movement
// -------------------------------------------------
Bullet b(0.0f, 0.0f, 0.004f);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Player* player = static_cast<Player*>(glfwGetWindowUserPointer(window)); // for player movement keys
  
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
        case GLFW_KEY_SPACE:
            if (action == GLFW_PRESS) {
                b.setBulletPosition(player->getPlayerX(), player->getPlayerY());

            }
        }
    }
 }
// -------------------------------------------------


// this checks if the player and the npc are touching.
// -------------------------------------------------
bool static collide(Player& player, Enemy& npc) {
    return (player.getPlayerX() < npc.enemyX() + 0.2f && player.getPlayerX() + 0.2f > npc.enemyX() && player.getPlayerY() < npc.enemyY() + 0.2f && player.getPlayerY() + 0.2f > npc.enemyY());
}

bool static enemy_death(Bullet& bull, Enemy& npc) {
    return (bull.returnBulletX() < npc.enemyX() + 0.2f && bull.returnBulletX() + 0.2f > npc.enemyX() && bull.returnBulletY() < npc.enemyY() + 0.2f && bull.returnBulletY() + 0.2f > npc.enemyY());

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
    // player() takes in x_pos, y_pos, and initial speed.
    Player player(-0.1f, -0.8f, 0.025f);

    // Enabling the key callbacks
    // -------------------------------------------------
    glfwSetWindowUserPointer(window, &player); 
    glfwSetKeyCallback(window, key_callback);
    // -------------------------------------------------

    // taking in initial xy pos and initial speed. 
    Enemy npc(-0.1f, -0.4f, 0.00009f);
    Enemy npc2(0.3f, 0.1f, 0.00025f);

    // upcasting to create bullet bill enemy type
    NPCVirt *ptr;
    Enemy a(-0.1f, 0.7f, 0.0005f);
    ptr = &a;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        npc.display(0.0f, 1.0f, 1.0f); // generates teal color
        npc.side_movement(); 

        npc2.display(1.0f, 0.5f, 0.5f); // generates a salmon colored square
        npc2.side_movement();

        // draws the bullet bill npc 
        ptr->display();
        ptr->scroll_movement();  

        // Draw the player rectangle
        player.player_display();

        if (b.isActive()) {
            b.fire();
            b.bullet_display(); 
        }

        // this loop uses collide() to check if the two objects are touching and if
        // they are, it uses death_reset in player.h to send the player back to the start. 
       if (collide(player, npc) || collide(player, npc2) || collide(player, a)){
         player.death_reset(); 
       }

        if (enemy_death(b, a)){
            ptr->npc_death();
        }

        if (enemy_death(b, npc)) {
            npc.npc_death(); 
        }

        if (enemy_death(b, npc2)) {
            npc2.npc_death();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
