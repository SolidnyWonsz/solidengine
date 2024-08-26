#pragma once

#include <string>

namespace Common {
    class Tokenizer {
        public:
            Tokenizer(const std::string &str, const char delimiter) : input(str), delim(delimiter), start(0), end(0) {}
            std::string next();
            bool isEnd();

        private:
            std::string input;
            char delim;
            size_t start, end;
    };
}