#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <iostream>
#include <iomanip>

/**
    A color
*/
class Color {
private:
    uint8_t r, g, b, a;

    /*
        Check if an 8-bit number has repeated nibbles so it can be abbreviated
        as 0xabc --> 0xaabbcc
    */
    static bool repeatedHex(uint8_t i) {
        return (0x0F & i) == (i >> 4);
    }

    bool rgbRepeatedHexDigits() const {
        return repeatedHex(r) && repeatedHex(g) && repeatedHex(b);
    }

    // Truncates the number and converts it to a char
    static char lowerHexDigit(uint8_t num) {
        uint8_t nibble = num & 0xF;
        if (nibble < 0xA)
            return '0' + nibble;
        else
            return 'a' + (nibble - 0xA);
    }
    
public:
    Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 0)
        : r(red), g(green), b(blue), a(alpha) {}

    /*
        Destructor
    */
    virtual ~Color() {}

    /**
        Get/set the red value
    */
    uint8_t& red() { return r; }

    /**
        Get/set the green value
    */
    uint8_t& green() { return g; }

    /**
        Get/set the blue value
    */
    uint8_t& blue() { return b; }

    /**
        Get/set the alpha value
    */
    uint8_t& alpha() { return a; }

    /**
        Get the alpha as double.
    */
    double opacity() const { return (double)a / 255.0; }

    // TODO: Maybe, if would be useful, have let colors be set/printed by name

    /**
        Get the XML-style string for the color.
        Returns three digit version (e.g. #fff) if possible.
    */
    friend std::ostream& operator<< (std::ostream& os, const Color& color);
};

std::ostream& operator<< (std::ostream& os, const Color& color);

#endif