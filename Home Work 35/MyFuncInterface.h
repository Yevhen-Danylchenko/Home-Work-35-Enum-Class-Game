#pragma once

#include <iostream>
#include <string>

#include "MyGameCharacter.h"

namespace MyFunctionInterface 
{
	namespace MyAlias = MyGame;

	void MyFunc() {
		char choice = 'y';
		MyAlias::GameCharacter hero;
		while (tolower(choice) == 'y')
		{
			std::string action;
			
			std::cout << "����i�� �� ����� �� �������." << std::endl;
			std::cout << "�i�: 'print', 'idle', 'walk', 'run', 'jump', 'attack', 'heal', 'damage'." << std::endl;
			std::cin >> action;

			if (action == "print") {
				hero.printState();
			} 
			else if (action == "idle") {
				hero.moveTo(MyAlias::State::Idle);
			} 
			else if (action == "walk") {
				hero.moveTo(MyAlias::State::Walking);
			} 
			else if (action == "run") {
				hero.run();
			} 
			else if (action == "jump") {
				hero.jump();
			} 
			else if (action == "attack") {
				hero.attack();
			} 
			else if (action == "heal") {
				int amount;
				std::cout << "�� ��i���� ��i���� �����? ";
				std::cin >> amount;
				hero.heal(amount);
			} 
			else if (action == "damage") {
				int dmg;
				std::cout << "��i���� ����� ������� �����? ";
				std::cin >> dmg;
				hero.takeDamage(dmg);
			}
			else {
				std::cout << "���i���� �i�!" << std::endl;
			}
			std::cout << "������ ����������? (y/n): ";
			std::cin >> choice;
		}
	}	
} 
