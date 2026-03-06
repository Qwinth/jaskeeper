#include <iostream>
#include <fstream>
#include <sstream>
#include <jaskeeper/compiller/lexer.hpp>

int main() {
    std::ifstream file("/home/nullnore/projects/cpp/jaskeeper/tests/testclass.js");

    std::stringstream ss;
    ss << file.rdbuf();

    LexicalAnalyzer lexer;
    lexer.setCode(ss.str());
    lexer.split();
    lexer.preprocess();
    lexer.tokenize();
    lexer.classify({{"class", TokenTypeEnum::KEYWORD}, {"new", TokenTypeEnum::KEYWORD}, {"this", TokenTypeEnum::KEYWORD}, {"let", TokenTypeEnum::KEYWORD}});

    auto tokens = lexer.getTokens();

    for (auto token : tokens) {
        std::cout << token.value << "\t|\t" << getTokenTypeName(token.type) << std::endl;
    }
}