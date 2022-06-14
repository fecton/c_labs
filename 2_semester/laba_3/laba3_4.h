#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int is_in_list(char already_set_cards[52][2], int suit, int rank) {
	for (int i = 0; i < 52; ++i) {
		if (already_set_cards[i][0] == rank && already_set_cards[i][1] == suit) {
			return 1;
		}
	}
	return 0;
}