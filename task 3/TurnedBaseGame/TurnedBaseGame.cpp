// TurnedBaseGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

class Player {
    std::string name;
    int health;
public:
    Player()
    {
        this->name = "Player";
        this->health = 100;
    }
    Player(std::string name, int health)
    {
        this->name = name;
        this->health = health;
    }
    std::string GetName() const 
    { 
        return name; 
    }
    int GetHealth() const 
    { 
        return health; 
    }
    void TakeDamage(int damage) 
    { 
        health -= damage; 
    }
    bool IsDead() const 
    { 
        return health <= 0; 
    }
};

class Enemy {
    int health;
    int damage;
public:
    Enemy()
    {
        this->health = 100;
        this->damage = 10;
    }
    Enemy(int health, int damage)
    {
        this->health = health;
        this->damage = damage;
    }
    int GetHealth() const 
    { 
        return health; 
    }
    int GetDamage() const 
    { 
        return damage; 
    }
    void TakeDamage(int damage) 
    { 
        health -= damage; 
    }
    bool IsDead() const 
    { 
        return health <= 0; 
    }
};

int main() {
    srand(time(0));

    Player player("Player", 100);
    Enemy enemy(50, 10);

    std::cout << "Welcome to the game!" << std::endl;

    while (!player.IsDead() && !enemy.IsDead()) 
    {
        int player_damage = rand() % 10 + 1; 
        int enemy_damage = rand() % enemy.GetDamage() + 1; 

        std::cout << player.GetName() << " hits enemy for " << player_damage << " damage!" << std::endl;
        enemy.TakeDamage(player_damage);
        std::cout << "Enemy has " << enemy.GetHealth() << " health left." << std::endl;

        if (enemy.IsDead()) {
            std::cout << "Congratulations, you have defeated the enemy!" << std::endl;
            break;
        }

        std::cout << "Enemy hits " << player.GetName() << " for " << enemy_damage << " damage!" << std::endl;
        player.TakeDamage(enemy_damage);
        std::cout << player.GetName() << " has " << player.GetHealth() << " health left." << std::endl;

        if (player.IsDead()) {
            std::cout << "Game over, the enemy has defeated you." << std::endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}

//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//
//class Player {
//public:
//    Player(std::string name, int health, int attack) : m_name(name), m_health(health), m_attack(attack) {}
//    void attack(Player& other) {
//        other.m_health -= m_attack;
//    }
//    bool isAlive() const {
//        return m_health > 0;
//    }
//    std::string getName() const {
//        return m_name;
//    }
//private:
//    std::string m_name;
//    int m_health;
//    int m_attack;
//};
//
//class Game {
//public:
//    Game() : m_player("Player", 100, 10), m_enemy("Enemy", 50, 5) {}
//    void play() {
//        std::srand(std::time(nullptr));
//        std::cout << "Welcome to the game!" << std::endl;
//        std::cout << "You are " << m_player.getName() << ", and your enemy is " << m_enemy.getName() << "." << std::endl;
//        while (m_player.isAlive() && m_enemy.isAlive()) {
//            std::cout << "It's your turn to attack!" << std::endl;
//            m_player.attack(m_enemy);
//            std::cout << m_player.getName() << " attacks " << m_enemy.getName() << " for " << m_player.getName() << " damage." << std::endl;
//            if (!m_enemy.isAlive()) {
//                break;
//            }
//            std::cout << "It's " << m_enemy.getName() << "'s turn to attack!" << std::endl;
//            m_enemy.attack(m_player);
//            std::cout << m_enemy.getName() << " attacks " << m_player.getName() << " for " << m_enemy.getName() << " damage." << std::endl;
//        }
//        if (m_player.isAlive()) {
//            std::cout << "Congratulations, you won!" << std::endl;
//        }
//        else {
//            std::cout << "Game over, you lost." << std::endl;
//        }
//    }
//private:
//    Player m_player;
//    Player m_enemy;
//};
//
//int main() {
//    Game game;
//    game.play();
//    return 0;
//}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
