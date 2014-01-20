#include "Color.h"

std::ostream& operator<< (std::ostream& os, const Color& color) {
    os << '#';

    if (color.rgbRepeatedHexDigits()) {
        os << Color::lowerHexDigit(color.r)
           << Color::lowerHexDigit(color.g)
           << Color::lowerHexDigit(color.b);
    } else {
        os << std::hex << std::setfill('0') << std::setw(2) << (unsigned short)color.r
           << std::setw(2) << (unsigned short)color.g
           << std::setw(2) << (unsigned short)color.b;
    }

    return os;
 }