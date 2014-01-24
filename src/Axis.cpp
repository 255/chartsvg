#include "Axis.h"

double Axis::translateCoordinate(double val) {
    return starting_pos + (max - val) * scaling_factor;
}

void Axis::printSVG(std::ostream& os) const {
    static const char COORD_SEPARATOR = ',';

    double dx, dy;
    double tick_dx, tick_dy;
    if (orientation == VERTICAL) {
        dx = 0;
        dy = tick_spacing;
        tick_dx = tick_length;
        tick_dy = 0;
    } else { // HORIZONTAL
        dx = tick_spacing;
        dy = 0;
        tick_dx = 0;
        tick_dy = tick_length;
    }

    // TODO: Very, very preliminary, of course
    // Maybe I will draw ticks separately so I can use a simple line element
    // and have different styles for the ticks
    os << "<g";
    axis_style.printSVG(os);
    os << ">";

    os << "<path d=\"M" << pos_x << ' ' << pos_y;
    for (size_t i = 0; i < tick_count; ++i) {
        os << 'l' << dx << COORD_SEPARATOR << dy;
        // draw the tick 
        // TODO: adapt for different styles
        os << 'l' << tick_dx << COORD_SEPARATOR << tick_dy;
        os << 'm' << -tick_dx << COORD_SEPARATOR << -tick_dy;
    }
    os << "\"/>\n";
    os << "</g>";
}