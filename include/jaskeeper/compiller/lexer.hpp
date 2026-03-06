#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "token.hpp"

class LexicalAnalyzer {
    std::string codeString;

    std::string whiteSpaces = " \t\n\r";
    std::string operators = "~|!%^&*/?-+=";
    std::string delimiters = ",.`@#$()[]{}<>:;'\"\\";

    std::string splitChars = whiteSpaces + operators + delimiters;

    std::vector<std::string> splitStrings;
    std::vector<std::string> stringTokens;
    std::vector<Token> tokens;

    bool checkNextIndexStringToken(size_t index) {
        return index + 1 < stringTokens.size();
    }

    bool checkPrevIndexStringToken(size_t index) {
        return index > 0;
    }

    bool checkInteger(size_t index) {
        if (!std::all_of(stringTokens.at(index).begin(), stringTokens.at(index).end(), ::isdigit)) return false;
        if (!checkNextIndexStringToken(index) || stringTokens.at(index + 1) == ".") return false;

        return true;
    }

    bool checkFloat(size_t index) {
        if (!std::all_of(stringTokens.at(index).begin(), stringTokens.at(index).end(), ::isdigit)) return false;
        if (!checkNextIndexStringToken(index) || stringTokens.at(index + 1) != ".") return false;
        if (!checkNextIndexStringToken(index + 1) || !std::all_of(stringTokens.at(index + 2).begin(), stringTokens.at(index + 2).end(), ::isdigit)) return false;

        return true;
    }

    bool checkString(size_t index) {
        if (!checkNextIndexStringToken(index) || !checkNextIndexStringToken(index + 1)) return false;
        if (stringTokens.at(index) != "\"" || stringTokens.at(index + 2) != "\"") return false;

        return true;
    }

    bool checkChar(size_t index) {
        if (!checkNextIndexStringToken(index) || !checkNextIndexStringToken(index + 1)) return false;
        if (stringTokens.at(index) != "'" || stringTokens.at(index + 2) != "'") return false;

        return true;
    }

    bool checkDelimiter(size_t index) {
        if (delimiters.find(stringTokens.at(index)) != std::string::npos) return true;
        
        return false;
    }

    bool checkOperator(size_t index) {
        if (operators.find(stringTokens.at(index)) != std::string::npos) return true;
        
        return false;
    }

    bool isAlphaNumeric(std::string str) {
        for (auto i : str) if (!::isalnum(i)) return false;

        return true;
    }
public:
    void setCode(std::string code) {
        codeString = code;
    }

    void split() {
        size_t start = 0;
        size_t end = 0;

        while ((end = codeString.find_first_of(splitChars, start)) != std::string::npos) {
            if (start < end) splitStrings.push_back(codeString.substr(start, end - start));
            splitStrings.push_back(codeString.substr(end, 1));
            
            start = end + 1;
        }
    }

    void preprocess() {
        std::string quotes;
        bool escaped_next = false;

        std::string stringToken;

        for (size_t i = 0; i < splitStrings.size(); i++) {
            std::string& tempString = splitStrings.at(i);

            if (splitChars.find(tempString) != std::string::npos) {
                if (quotes.size()) {
                    if (escaped_next) {
                        stringToken += tempString;
                        escaped_next = false;
                    }

                    else {
                        if (tempString == "\\") escaped_next = true;

                        else if (tempString == quotes) {
                            stringTokens.push_back(stringToken);
                            stringTokens.push_back(tempString);
                            stringToken.clear();
                            quotes.clear();
                        }

                        else stringToken += tempString;
                    }
                }

                else {
                    if (tempString == "\"" || tempString == "'") quotes = tempString;
                    
                    if (stringToken.size()) stringTokens.push_back(stringToken);
                    if (whiteSpaces.find(tempString) == std::string::npos) stringTokens.push_back(tempString);
                    stringToken.clear();
                }
            }

            else stringToken += tempString;
        }
    }

    void tokenize() {
        for (size_t i = 0;  i < stringTokens.size(); i++) {
            std::string stringData = stringTokens.at(i);

            if (checkInteger(i)) tokens.push_back({TokenTypeEnum::INTEGER_LITERAL, stringData});

            else if (checkFloat(i)) {
                tokens.push_back({TokenTypeEnum::FLOAT_LITERAL, stringData + "." + stringTokens.at(i + 2)});
                i += 2;
            }

            else if (checkString(i)) {
                tokens.push_back({TokenTypeEnum::STRING, stringTokens.at(i + 1)});
                i += 2;
            }

            else if (checkChar(i)) {
                tokens.push_back({TokenTypeEnum::CHARACTER, stringTokens.at(i + 1).substr(0, 1)});
                i += 2;
            }

            else if (checkDelimiter(i)) tokens.push_back({TokenTypeEnum::DELIMITER, stringData});
            else if (checkOperator(i)) tokens.push_back({TokenTypeEnum::OPERATOR, stringData});
            else tokens.push_back({TokenTypeEnum::UNKNOWN, stringData});
        }
    }

    void classify(std::map<std::string, TokenTypeEnum> type_map) {
        for (auto& i : tokens) if (i.type == TokenTypeEnum::UNKNOWN) if (type_map.find(i.value) != type_map.end()) i.type = type_map.at(i.value);
    }

    std::vector<std::string>& getSplitStrings() {
        return splitStrings;
    }

    std::vector<Token>& getTokens() {
        return tokens;
    }
};
