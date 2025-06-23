// Your code here
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define STANDARD_DECK { \
    {"Ac", 'H'}, {"2", 'H'}, {"3", 'H'}, {"4", 'H'}, {"5", 'H'}, {"6", 'H'}, {"7", 'H'}, \
    {"8", 'H'}, {"9", 'H'}, {"T", 'H'}, {"J", 'H'}, {"Qu", 'H'}, {"Ki", 'H'},\
    {"Ac", 'D'}, {"2", 'D'}, {"3", 'D'}, {"4", 'D'}, {"5", 'D'}, {"6", 'D'}, {"7", 'D'}, \
    {"8", 'D'}, {"9", 'D'}, {"T", 'D'}, {"J", 'D'}, {"Qu", 'D'}, {"Ki", 'D'},\
    {"Ac", 'C'}, {"2", 'C'}, {"3", 'C'}, {"4", 'C'}, {"5", 'C'}, {"6", 'C'}, {"7", 'C'}, \
    {"8", 'C'}, {"9", 'C'}, {"T", 'C'}, {"J", 'C'}, {"Qu", 'C'}, {"Ki", 'C'},\
    {"Ac", 'S'}, {"2", 'S'}, {"3", 'S'}, {"4", 'S'}, {"5", 'S'}, {"6", 'S'}, {"7", 'S'}, \
    {"8", 'S'}, {"9", 'S'}, {"T", 'S'}, {"J", 'S'}, {"Qu", 'S'}, {"Ki", 'S'}\
}
typedef struct {
    char rank[3];
    char suit; 
} card_t; 
/* Functions prototypes*/
void swap_card_t(card_t *a, card_t *b);
card_t** deal_cards(int n_players, int card_per_hand); 
void print_hands(card_t **players_hands, int n, int card_per_hand); 

int main(int arc, char *argv[]) {
    srand(time(NULL));
    int n_players = 4; 
    int card_per_hand = 5; 
    card_t **players_hands = deal_cards(n_players, card_per_hand); 
    if (players_hands == NULL) {
        return 0; 
    }
    print_hands(players_hands, n_players, card_per_hand); 
    return 0; 
}

/* Functions declarations */
void swap_card_t(card_t *a, card_t *b) {
    card_t temp = *a; 
    *a = *b; 
    *b = temp; 
}
card_t** deal_cards(int n_players, int card_per_hand) {
    card_t **players_hands = malloc(sizeof(card_t*) * n_players); 
    assert(players_hands != NULL); 
    if (n_players * card_per_hand > 52) {
        fprintf(stderr, "Not enough cards to dealt to all!\n"); 
        return NULL; 
    }
    card_t deck[52] = STANDARD_DECK;
    int deck_size = 52;
    for (int i = 0; i < n_players; i++) {
        card_t *player_hand = malloc(sizeof(card_t) * card_per_hand);
        assert(player_hand != NULL); 
        for (int j = 0; j < card_per_hand; j++) {
            int choose_idx = rand() % deck_size; 
            player_hand[j] = deck[choose_idx]; 
            swap_card_t(&deck[choose_idx], &deck[deck_size - 1]);
            deck_size--; 
        }
        players_hands[i] = player_hand; 
    }
    return players_hands; 
}
void print_hands(card_t **players_hands, int n, int card_per_hand) {
    for (int i = 0; i < n; i++) {
        printf("player %d: ", i + 1); 
        for (int j = 0; j < card_per_hand; j++) {
            card_t current_card = players_hands[i][j]; 
            printf("%s-%c, ", current_card.rank, current_card.suit); 
        }
    printf("\n"); 
    }
}
