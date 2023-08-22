#include "functions.h"

voraciousSnake* snake = new voraciousSnake();

void startUp() {
	initgraph(snake->getWidth() * BLOCK_SIZE, snake->getHeight() * BLOCK_SIZE);
	setlinecolor(RGB(200, 200, 200));
	BeginBatchDraw();
}

void display() {
	cleardevice();

	// draw background
	setfillcolor(RGB(128, 128, 128));
	fillrectangle(0, 0, snake->getWidth() * BLOCK_SIZE, snake->getHeight() * BLOCK_SIZE);

	// draw food
	setfillcolor(RGB(0, 128, 0));
	fillrectangle(snake->getFoodX() * BLOCK_SIZE, snake->getFoodY() * BLOCK_SIZE, (snake->getFoodX() + 1) * BLOCK_SIZE, (snake->getFoodY() + 1) * BLOCK_SIZE);

	// draw snake
	setfillcolor(RGB(128, 0, 0));
	for (auto p : snake->getPos()) {
		fillrectangle(p.first * BLOCK_SIZE, p.second * BLOCK_SIZE, (p.first + 1) * BLOCK_SIZE, (p.second + 1) * BLOCK_SIZE);
	}

	// draw score
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 255, 255));
	settextstyle(20, 0, _T("Times New Roman"));
	TCHAR score[20];
	_stprintf_s(score, _T("Score: %d"), snake->getScore());
	outtextxy(0, 0, score);

	// draw game over
	if (snake->getDead() == true) {
		setbkmode(TRANSPARENT);
		settextcolor(RGB(255, 0, 0));
		settextstyle(80, 0, _T("Times New Roman"));
		outtextxy(240, 220, _T("Game Over"));
	}


	FlushBatchDraw();
}

void move() {
	display();
	if (snake->isDead() == true) {
		snake->setDead(true);
	}

	if (snake->getDead() == false) {
		if (snake->getDirection() == 'U') {
			snake->moveUp();
		} else if (snake->getDirection() == 'D') {
			snake->moveDown();
		} else if (snake->getDirection() == 'L') {
			snake->moveLeft();
		} else if (snake->getDirection() == 'R') {
			snake->moveRight();
		}
	}

	Sleep(500 / snake->getSpeed());
}

void updateDirectionAndMove() {
	snake->setSpeed(snake->getScore() / 10 + 1);


	move();

	
	if (_kbhit()) {
		char dir = _getch();
		if (dir == snake->getDirection()) {
			return;
		}
		if (dir == 'a' && snake->getDirection() != 'R') {
			snake->setDirection('L');
		}
		else if (dir == 'd' && snake->getDirection() != 'L') {
			snake->setDirection('R');
		}
		else if (dir == 'w' && snake->getDirection() != 'D') {
			snake->setDirection('U');
		}
		else if (dir == 's' && snake->getDirection() != 'U') {
			snake->setDirection('D');
		}
	}
}

