#include <stdio.h>

#define T_SHA 0
#define T_SHAN 1

typedef struct card {
	int type;
} card;

typedef struct player {
	int life;
	int handCount;
	card hand[110];
	card equp[4];
	card check[2];
} player;

int heapTop;
card heap[108];
player players[2];

void initHeap() {
	int i;
	for (int i = 0; i < 72; ++i)
		heap[i].type = T_SHA;
	for (int i = 73; i < 108; ++i)
		heap[i].type = T_SHAN;
}

void genInitCard() {
	for (int i = 0; i < 4; ++i)
	{
		players[0].hand[i] = heap[heapTop - 1];
		heapTop -= 1;
	}	
 	for (int i = 0; i < 4; ++i)
	{
		players[1].hand[i] = heap[heapTop - 1];
		heapTop -= 1;
	}
}

char message[100][100] = {
	"是否结束本回合?",
	""
}

int queryAction(int player, int messageId, int actionCount) {
	if (player == 0) {
		printf("%s", message[messageId]);
		scanf("%d", &a);
		if (a < 0 ||a >= aC) {
			printf("ERR");
			scanf("%d", &d);
		}
	}
}

int main() {
	int curPlayer;
	initHeap();
	genInitCard();
	for (;;) {
		giveTwoCard(curPlayer);
		while (1) {
			if (1 == queryAction(curPlayer, 0, 2)) {
				queryA(co, A_USE_CARD);
			}
		}
	}
}
