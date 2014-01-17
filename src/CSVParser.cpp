#include "CSVParser.h"

CSVParser::CSVParser(const std::string& filename, char field_delim)
    : inputFile(filename) {

    hasHeaderLine = isalpha(inputFile.peek());

    if (hasHeaderLine)
        parseHeader();
    else
        countColumns();

    skipNewlines();
}

void CSVParser::parseHeader() { 
    size_t delimiters = 0;

    // TODO: check seek location?
    char c;
    std::string cur;
    while (!isNewline(inputFile.peek())) {
        c = inputFile.get();

        if (c == DELIMETER) {
            delimiters++;
            header.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    header.push_back(cur); // the final word

    columnsCount = delimiters+1;
}

void CSVParser::countColumns() {
    // TODO: Change this?
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

    columnsCount = delimiters+1;
}

double CSVParser::nextDouble() {
    char c;
    std::string token;
    do {
        c = inputFile.get();
        token.push_back(c);
    } while (isdigit(c) || c == DECIMAL_MARK);

    skipNewlines();
    return strtod(token.c_str(), nullptr);
}
