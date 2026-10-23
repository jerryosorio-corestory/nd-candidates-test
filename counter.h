#pragma once
#include <unordered_map>
#include <string>

// COR-4076 repro: a hash-container member declared only in this header.
// The method that iterates it is defined out-of-line in counter.cc, so
// resolving its type needs the project-wide rebuild, not per-file extraction.
class Counter {
public:
    void tally();
private:
    std::unordered_map<std::string, int> counts_;
};
