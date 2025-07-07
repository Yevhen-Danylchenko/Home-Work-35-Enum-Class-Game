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
                std::cout << "����� �������. ��i�� ����� ���������.\n";
                return;
            }

            // Jump �������� ���� � Walking ��� Running
            if (newState == State::Jumping &&
                !(currentState == State::Running || currentState == State::Walking)) {
                std::cout << "�� ����� �������� � ��������� �����: " << stateToString(currentState) << "\n";
                return;
            }

            previousState = currentState;
            currentState = newState;
            std::cout << "���� ��i���� ��: " << stateToString(currentState) << "\n";
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
                std::cout << "����� �i� ��� �������!\n";
                std::cout << "����: Attacking\n";
                currentState = previousState; // ���������� �� Jumping
                std::cout << "���������� �� �����: " << stateToString(currentState) << "\n";
            }
            else {
                changeState(State::Attacking);
            }
        }

        void takeDamage(int dmg) {
            if (currentState == State::Dead) {
                std::cout << "����� ��� �������.\n";
                return;
            }

            health -= dmg;
            std::cout << "�������� �����: " << dmg << ", ������� ������'�: " << health << "\n";

            if (health <= 0) {
                health = 0;
                changeState(State::Dead);
            }
        }

        void printState() const {
            std::cout << "�������� ����: " << stateToString(currentState) << "\n";
        }

        void heal(int amount) {
            if (currentState != State::Dead) {
                health += amount;
                std::cout << "����� ��i����� �� " << amount << ", ����� ������'�: " << health << "\n";
            }
            else {
                std::cout << "�� ����� ��i���� �������� �����.\n";
            }
        }
    };

}
