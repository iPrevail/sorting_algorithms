#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Defines card suits.
 * @SPADE: Represents spades.
 * @HEART: Symbolizes hearts.
 * @CLUB: Embodies clubs.
 * @DIAMOND: Epitomizes diamonds.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card with a value and kind.
 *
 * @value: Ranges from "Ace" to "King"
 * @kind: Describes the type of the card (e.g., hearts, spades)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node in a card deck
 *
 * @card: Pointer to the associated card
 * @prev: Pointer to the preceding node
 * @next: Pointer to the succeeding node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
