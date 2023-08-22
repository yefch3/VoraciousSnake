#ifndef VORACIOUS_SNAKE
#define VORACIOUS_SNAKE

#define BLOCK_SIZE 20

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <random>
#include <Windows.h>


class voraciousSnake {
private:
	int width;
	int height;
	std::deque<std::pair<int, int>> pos;
	std::pair<int, int> food;
	char direction;
	int score;
	int speed;
	bool dead;

public:
	voraciousSnake(int width=40, int height=30) {
		this->width = width;
		this->height = height;
		this->score = 0;
		this->pos.push_back(std::make_pair(2, 0));
		this->pos.push_back(std::make_pair(1, 0));
		this->pos.push_back(std::make_pair(0, 0));
		this->food = std::make_pair(rand() % this->width, rand() % this->height);
		this->direction = 'R';
		this->speed = 1;
		this->dead = false;
	}

	~voraciousSnake() {}

	void setSpeed(int speed) {
		this->speed = speed;
	}

	void setDirection(char direction) {
		this->direction = direction;
	}

	void setFood() {
		this->food = std::make_pair<int, int>(rand() % this->width, rand() % this->height);
	}

	void setScore(int score) {
		this->score = score;
	}

	int getLength() {
		return this->pos.size();
	}

	int getScore() {
		return this->score;
	}

	std::pair<int, int> getFood() {
		return this->food;
	}

	int getFoodX() {
		return this->food.first;
	}

	int getFoodY() {
		return this->food.second;
	}

	std::deque<std::pair<int, int>> getPos() {
		return this->pos;
	}

	char getDirection() {
		return this->direction;
	}

	int getWidth() {
		return this->width;
	}

	int getHeight() {
		return this->height;
	}

	int getSpeed() {
		return this->speed;
	}

	bool isDead() {
		// collision with itself
		for (auto it = this->pos.begin() + 1; it != this->pos.end(); ++it) {
			if (this->pos.front() == *it) {
				return true;
			}
		}

		// collision with wall
		if (this->pos.front().first < 0 || this->pos.front().first >= this->width || this->pos.front().second < 0 || this->pos.front().second > this->height) {
			return true;
		}

		return false;
	}

	bool getDead() {
		return this->dead;
	}

	void moveUp() {
		int cur_headX = this->pos.front().first;
		int cur_headY = this->pos.front().second;
		pos.push_front(std::make_pair(cur_headX, cur_headY - 1));
		if (pos.front().first != this->food.first || pos.front().second != this->food.second) {
			pos.pop_back();
		}
		else {
			this->score++;
			refreshFood();
		}
	}

	void moveLeft() {
		int cur_headX = this->pos.front().first;
		int cur_headY = this->pos.front().second;
		pos.push_front(std::make_pair(cur_headX - 1, cur_headY));
		if (pos.front().first != this->food.first || pos.front().second != this->food.second) {
			pos.pop_back();
		}
		else {
			this->score++;
			refreshFood();
		}
	}

	void moveDown() {
		int cur_headX = this->pos.front().first;
		int cur_headY = this->pos.front().second;
		pos.push_front(std::make_pair(cur_headX, cur_headY + 1));
		if (pos.front().first != this->food.first || pos.front().second != this->food.second) {
			pos.pop_back();
		}
		else {
			this->score++;
			refreshFood();
		}
	}

	void moveRight() {
		int cur_headX = this->pos.front().first;
		int cur_headY = this->pos.front().second;
		pos.push_front(std::make_pair(cur_headX + 1, cur_headY));
		if (pos.front().first != this->food.first || pos.front().second != this->food.second) {
			pos.pop_back();
		}
		else {
			this->score++;
			refreshFood();
		}
	}

	void setDead(bool dead) {
		this->dead = dead;
	}

	void refreshFood() {
		this->food = std::make_pair(rand() % this->width, rand() % this->height);
	}
};


#endif // !VORACIOUS_SNAKE

