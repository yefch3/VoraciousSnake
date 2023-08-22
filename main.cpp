#include "functions.h"

int main() {
	startUp();
	while (true) {
		move();
		updateDirection();
	}
	return 0;
}