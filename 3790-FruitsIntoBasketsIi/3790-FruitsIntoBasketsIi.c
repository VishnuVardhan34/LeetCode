// Last updated: 8/4/2026, 12:22:12 PM
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int used[100] = {0};

    int unplaced = 0;

    for (int i = 0; i < fruitsSize; i++) {
        int found = 0;

        for (int j = 0; j < basketsSize; j++) {
            if (used[j] == 0 && baskets[j] >= fruits[i]) {
                used[j] = 1;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            unplaced++;
        }
    }

    return unplaced;
}