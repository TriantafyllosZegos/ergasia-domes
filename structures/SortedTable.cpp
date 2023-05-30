#include "SortedTable.h"

void SortedTable::addPair(const std::string& word1, const std::string& word2) {
    table.emplace_back(word1, word2);
}

void SortedTable::sortTable() {
    quicksort(0, table.size() - 1);
}

void SortedTable::printTable() {
    for (const auto& pair : table) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void SortedTable::quicksort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quicksort(low, pivotIndex - 1);
        quicksort(pivotIndex + 1, high);
    }
}

int SortedTable::partition(int low, int high) {
    std::pair<std::string, std::string>& pivot = table[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (table[j] < pivot) {
            i++;
            std::swap(table[i], table[j]);
        }
    }

    std::swap(table[i + 1], table[high]);
    return i + 1;
}
