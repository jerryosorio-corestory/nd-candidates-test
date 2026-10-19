#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

// A value-keyed hash container, declared in this same file (required for
// COR-4039's corroboration step to store a site for it).
std::unordered_map<std::string, int> wordCounts;

void simpleForm() {
    // Old form, already matched before this fix: plain "for (auto x : container)".
    for (auto entry : wordCounts) {
        std::cout << entry.first << "=" << entry.second << "\n";
    }
}

void structuredBindingForm() {
    // New form this fix adds: structured binding.
    for (auto& [word, count] : wordCounts) {
        count += 1;
    }
}

void constRefForm() {
    // New form this fix adds: "auto const&".
    for (auto const& entry : wordCounts) {
        std::cout << entry.first << "\n";
    }
}

void pointerForm() {
    // New form this fix adds: a pointer declarator over a container of pointers.
    std::vector<std::unordered_map<std::string, int>*> maps;
    for (auto* m : maps) {
        (void)m;
    }
}

int main() {
    wordCounts["a"] = 1;
    wordCounts["b"] = 2;
    simpleForm();
    structuredBindingForm();
    constRefForm();
    pointerForm();
    return 0;
}
