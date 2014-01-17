#include "CSVParser.h"

CSVParser::CSVParser(const std::string& filename, char field_delim)
    : inputFile(filename) {
    skipWhitespace();
    start = inputFile.tellg();
}

double CSVParser::nextDouble() {
    // find the next digit
    while (!isdigit(inputFile.peek())) {
        inputFile.ignore(1);

        if (!inputFile.good())
            return strtod("NAN", nullptr);
    }

    char c;
    std::string token;
    do {
        c = inputFile.get();
        token.push_back(c);
    } while (isdigit(c) || c == DECIMAL_MARK);

    return strtod(token.c_str(), nullptr);
}

size_t CSVParser::getColumnsCount() {
    // TODO: This is stupid. Fix this.
    std::streampos curPos(inputFile.tellg());
    size_t delimiters = 0;

    char c;
    do {
        c = inputFile.get();
        if (c == DELIMETER)
            delimiters++;
    } while (!isNewline(c) && inputFile.good());

    // restore seek location
    inputFile.seekg(curPos);

    return delimiters+1;
}

