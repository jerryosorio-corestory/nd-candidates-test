#include "counter.h"
#include <iostream>

void Counter::tally() {
    for (auto entry : counts_) {
        std::cout << entry.first << "=" << entry.second << "\n";
    }
}
