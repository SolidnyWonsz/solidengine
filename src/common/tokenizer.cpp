#include <common/tokenizer.h>

using namespace Common;

std::string Tokenizer::next() {
    start = input.find_first_not_of(delim, end);

    if (start == std::string::npos) {
        return "";
    }

    end = input.find_first_of(delim, start);
    return input.substr(start, end - start);
}

bool Tokenizer::isEnd() {
    return (start != std::string::npos);
}