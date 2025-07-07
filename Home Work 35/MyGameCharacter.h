#pragma once

#include <iostream>
#include <string>

namespace MyGame
{
	enum class State {
		Idle,
		Walking,
		Running,
		Jumping,
		Attacking,
		Dead
	};

	std::string stateToString(State s) {
		switch (s) {
		case State::Idle: return "Idle";
		case State::Walking: return "Walking";
		case State::Running: return "Running";
		case State::Jumping: return "Jumping";
		case State::Attacking: return "Attacking";
		case State::Dead: return "Dead";
		default: return "Unknown";
		}
	}


    class GameCharacter {
    private:
        State currentState;
        State previousState;
        int health;

        void changeState(State newState) {
            if (currentState == State::Dead) {
                std::cout << "Герой мертвий. Змiна стану неможлива.\n";
                return;
            }

            // Jump можливий лише з Walking або Running
            if (newState == State::Jumping &&
                !(currentState == State::Running || currentState == State::Walking)) {
                std::cout << "Не можна стрибати з поточного стану: " << stateToString(currentState) << "\n";
                return;
            }

            previousState = currentState;
            currentState = newState;
            std::cout << "Стан змiнено на: " << stateToString(currentState) << "\n";
        }

    public:
        GameCharacter() : currentState(State::Idle), previousState(State::Idle), health(100) {}

        void moveTo(State newState) {
            changeState(newState);
        }

        void jump() {
            changeState(State::Jumping);
        }

        void run() {
            changeState(State::Running);
		}

        void attack() {
            if (currentState == State::Jumping) {
                previousState = currentState;
                currentState = State::Attacking;
                std::cout << "Атака пiд час стрибка!\n";
                std::cout << "Стан: Attacking\n";
                currentState = previousState; // Повернення до Jumping
                std::cout << "Повернення до стану: " << stateToString(currentState) << "\n";
            }
            else {
                changeState(State::Attacking);
            }
        }

        void takeDamage(int dmg) {
            if (currentState == State::Dead) {
                std::cout << "Герой вже мертвий.\n";
                return;
            }

            health -= dmg;
            std::cout << "Отримано шкоди: " << dmg << ", поточне здоров'я: " << health << "\n";

            if (health <= 0) {
                health = 0;
                changeState(State::Dead);
            }
        }

        void printState() const {
            std::cout << "Поточний стан: " << stateToString(currentState) << "\n";
        }

        void heal(int amount) {
            if (currentState != State::Dead) {
                health += amount;
                std::cout << "Герой зцiлений на " << amount << ", тепер здоров'я: " << health << "\n";
            }
            else {
                std::cout << "Не можна зцiлити мертвого героя.\n";
            }
        }
    };

}
