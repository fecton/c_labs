#include "laba3_4.h"

int main(int argc, const char* argv[]) {
	int in_hand[NUM_SUITS][NUM_RANKS] = { 0 };
	int num_cards = 52, rank, suit;

	char already_set_cards[52][2] = { {0,}, };

	const char
		rank_code[] = {
			'2', '3', '4', '5', '6', '7', '8', '9',
			't', 'j', 'q', 'k', 'a'
		},
		suit_code[] = {
			'\x03', '\x04', '\x05', '\x06'
		};

	// ♥ \x03
	// ♦ \x04
	// ♣ \x05
	// ♠ \x06

	char players[3][6][2] = {
		{0,}, // player's 1 cards
		{0,}, // 2..
		{0,}, // 3..
	};

	srand(time(0));
	printf("Cards:\n");

	int
		i = 0,
		j = 0,
		separator = 1;

	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;
		rank = rand() % NUM_RANKS;
		if (!in_hand[suit][rank]) {
			if (!is_in_list(already_set_cards, suit, rank)) {
				already_set_cards[i][0] = rank;
				already_set_cards[i][1] = suit;
			}
			else {
				continue;
			}

			in_hand[suit][rank] = 1;
			num_cards--;

			if (i == 3) {
				break;
			}
			else
				if (j == 5) {
					j = 0;
					i++;
				}
				else {
					players[i][j][0] = rank_code[rank];
					players[i][j][1] = suit_code[suit];
					j++;
				}

			printf(" %c%c", rank_code[rank], suit_code[suit]);
			if (separator % 6 == 0) {
				printf("\n");
			}
			separator++;
		}
	}

	printf("\n");

	int
		flash_combo = 0,
		combo_count = 0;

	// 0 - none
	// 1 - first player
	// 2 - second
	// 3 - third

	for (int i = 0; i < 3; ++i) {
		if (combo_count == 5 || flash_combo) {
			flash_combo = i;
			break;
		}
		combo_count = 0;
		for (int j = 0; j < 6; ++j) {
			if (!flash_combo) {
				if (players[i][j][1] == '\x06') {
					combo_count++;
				}
			}
		}
	}

	printf("\n");

	if (flash_combo) {
		printf("Flash found! Player %d has it!!\n", flash_combo);
	}
	else {
		printf("Oh no! Does somebody have it? :(\n");
	}

	return 0;
}
