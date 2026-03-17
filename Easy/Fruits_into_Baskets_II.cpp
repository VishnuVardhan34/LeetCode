int numOfUnplacedFruits(const std::vector<int>& fruits, const std::vector<int>& baskets) {
    std::vector<bool> used(baskets.size(), false);

    int unplaced = 0;

    for (int fruit : fruits) {
        bool found = false;

        for (size_t j = 0; j < baskets.size(); j++) {
            if (!used[j] && baskets[j] >= fruit) {
                used[j] = true;
                found = true;
                break;
            }
        }

        if (!found) {
            unplaced++;
        }
    }

    return unplaced;
}
