#pragma once
#include <string>

enum class TokenTypeEnum {
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    STRING,
    CHARACTER,
    DELIMITER,
    OPERATOR,
    DATA_TYPE,
    KEYWORD,
    UNKNOWN
};

struct Token {
    TokenTypeEnum type;
    std::string value;
};

std::string getTokenTypeName(TokenTypeEnum type)
{
    switch (type) {
    case TokenTypeEnum::CHARACTER:
        return "CHARACTER";
    case TokenTypeEnum::STRING:
        return "STRING";
    case TokenTypeEnum::INTEGER_LITERAL:
        return "INTEGER_LITERAL";
    case TokenTypeEnum::FLOAT_LITERAL:
        return "FLOAT_LITERAL";
    case TokenTypeEnum::OPERATOR:
        return "OPERATOR";
    case TokenTypeEnum::DELIMITER:
        return "DELIMITER";
    case TokenTypeEnum::DATA_TYPE:
        return "DATA_TYPE";
    case TokenTypeEnum::KEYWORD:
        return "KEYWORD";
    case TokenTypeEnum::UNKNOWN:
        return "UNKNOWN";
    default:
        return "UNDEFINED";
    }
}