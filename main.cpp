#include "functions.h"

int main() {
	startUp();
	while (true) {
		updateDirectionAndMove();
	}
	return 0;
}