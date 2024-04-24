#include <GLFW/glfw3.h>
#include "npc.h"
#include "player.h"
#include "NPCVirt.h"
#include "b_npc.h"
#include"bullet.h"
#include<vector>
#include<iostream> 

using namespace std;

// this struct is for my attempts at getting the bullets to work.
// -------------------------------------------------
struct winData {
    Player* player;
    vector<Bullet>* bullets;
};
// -------------------------------------------------


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

float BNPC::getBX() {
    return x;
}

float BNPC::getBY() {
    return y;
}

//float Bullet::returnBulletY() const{
    //return bullet_y;
//}
// -------------------------------------------------

// keyboard interaction for movement
// -------------------------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    winData* windowData = static_cast<winData*>(glfwGetWindowUserPointer(window));
    Player* player = windowData->player;
    vector<Bullet>* bullet = windowData->bullets;
    //Player* player = static_cast<Player*>(glfwGetWindowUserPointer(window)); // for player movement keys
    //vector<Bullet>* bullet = static_cast<vector<Bullet>*>(glfwGetWindowUserPointer(window)); // for bullet fire key
  
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
        }
    }
    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        bullet->push_back(Bullet(player->getPlayerX(), player->getPlayerY(), 0.002f));
        }
    }
// -------------------------------------------------


// this checks if the player and the npc are touching.
// -------------------------------------------------
bool static collide(Player& player, NPC& npc) {
    return (player.getPlayerX() < npc.getNpcX() + 0.2f && player.getPlayerX() + 0.2f > npc.getNpcX() && player.getPlayerY() < npc.getNpcY() + 0.2f && player.getPlayerY() + 0.2f > npc.getNpcY());
}

bool static b_collide(Player& player, BNPC& b_npc) {
    return (player.getPlayerX() < b_npc.getBX() + 0.2f && player.getPlayerX() + 0.2f > b_npc.getBX() && player.getPlayerY() < b_npc.getBY() + 0.2f && player.getPlayerY() + 0.2f > b_npc.getBY());
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

    vector<Bullet> bullets;
    bullets.push_back(Bullet(player.getPlayerX(), player.getPlayerY(), 0.002f)); 

    // this makes it so that glfwSetWindowUserPointer can be set to both player movement and bullet movement. 
    winData windowData = { &player, &bullets };

    // Enabling the key callbacks
    // -------------------------------------------------
    glfwSetWindowUserPointer(window, &windowData);
    glfwSetKeyCallback(window, key_callback);
    //glfwSetWindowUserPointer(window, &player);
    // -------------------------------------------------

    // taking in initial xy pos and initial speed. 
    NPC npc(-0.1f, -0.4f, 0.000075f);
    NPC npc2(0.3f, 0.1f, 0.00025f);

    BNPC b_npc(-0.1f, 0.7f, 0.0005f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        npc.display();
        npc.side_movement(); 

        npc2.display(1.0f, 0.5f, 0.5f); // generates a salmon colored square
        npc2.side_movement();

        // draws the bullet bill npc 
        b_npc.b_display();
        b_npc.b_movement(); 

        // Draw the player rectangle
        player.player_display();

        for (auto& bullet : bullets) {
            //bullet.fire();
            bullet.bullet_display();
            bullet.fire(); 
        }

        // this loop uses collide() to check if the two objects are touching and if
        // they are, it uses death_reset in player.h to send the player back to the start. 
        if (collide(player, npc) || collide(player, npc2) || b_collide(player, b_npc)){
            player.death_reset(); 
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
