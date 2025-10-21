#include <bits/stdc++.h>
using namespace std;

struct Item {
    string id;
    string name;
    double cost;    // weight
    double impact;  // value
};

// Comparator to sort items by value-to-weight ratio
bool cmp(Item a, Item b) {
    double r1 = a.impact / a.cost;
    double r2 = b.impact / b.cost;
    return r1 > r2;  // descending order
}

int main() {
    double budget = 500000.0; // capacity of knapsack

    vector<Item> items = {
        {"P1", "Food Rations", 300000, 40},
        {"P2", "Water Purification Kits", 100000, 25},
        {"P3", "Temporary Shelters", 350000, 50},
        {"P4", "Medical Supplies", 100000, 18},
        {"P5", "Communication Equipment", 50000, 12}
    };

    // Sort by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalCost = 0, totalImpact = 0;
    vector<Item> selected;

    cout << fixed << setprecision(2);
    cout << "Sorted by Value-to-Cost Ratio (Descending):\n";
    for (auto &it : items) {
        cout << it.id << " (" << it.name << ") -> Ratio = " 
             << it.impact / it.cost << endl;
    }
    cout << "\nSelecting items based on greedy strategy:\n";

    for (auto &it : items) {
        if (totalCost + it.cost <= budget) {
            selected.push_back(it);
            totalCost += it.cost;
            totalImpact += it.impact;
            cout << "✅ Selected: " << it.id << " (" << it.name << ")\n";
        } else {
            cout << "❌ Skipped: " << it.id << " (" << it.name << ") [Over budget]\n";
        }
    }

    cout << "\n-------------------------------------------\n";
    cout << "Selected Items:\n";
    for (auto &it : selected) {
        cout << it.id << " - " << it.name << endl;
    }
    cout << "-------------------------------------------\n";
    cout << "Total Cost: " << totalCost << " BDT\n";
    cout << "Total Impact Score: " << totalImpact << endl;

    return 0;
}
