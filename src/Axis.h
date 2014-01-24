#ifndef AXIS_H
#define AXIS_H

#include "SVGProperties.h"

// TODO: I will create a new coordinate system for the chart using a transform
/*
    An axis is a labeled number line. It is 1-dimensional.
*/
class Axis {
public:
    enum Orientation {
        VERTICAL,
        HORIZONTAL
    };

    enum TickType {
        NONE,
        CROSS,
        INNER,
        OUTER
    };

private:
    Orientation orientation;
    double min, max; // the end values of the axis
    SVGProperties axis_style; // defines stroke color, width, and opacity
    
    // Starting position and length in the SVG coordinate system
    double pos_x, pos_y;
    double starting_pos; // either pos_x or pos_y, determined by orientation
    double length;
    double scaling_factor; // (length in pixels) / (length in data)

    // the tick properties
    SVGProperties tick_style;
    TickType tick_type;
    double tick_length;
    double tick_spacing;
    double tick_count; // TODO: tick spacing should be related to tick_count

public:
    /**
        Construct a new axis. Uses various default values.
    */
    Axis(Orientation orient, double from, double to, double x_pos, double y_pos,
         double len, const SVGProperties& style)
         : axis_style(style), tick_style(style) {
        // initialize the axis
        orientation = orient;
        min = from;
        max = to;
        pos_x = x_pos;
        pos_y = y_pos;
        length = len;
        scaling_factor = length / (max - min);
        starting_pos = (orientation == VERTICAL ? pos_y : pos_x);

        // initialize the ticks TODO: using defaults for now
        tick_type = CROSS;
        tick_length = 6;
        tick_count = 11;
        tick_spacing = length / 10;

        // TODO: More testing defaults here
        axis_style.setStroke(Color(0,0,0));
        axis_style.setProperty("stroke-width", "2");
        axis_style.setProperty("fill-opacity", "0");

    }

    // TODO: This is fine and dandy, but I should do this instead:
    //   <g transform="translate(x,y)">
    //   <g transform="scale(scale, like_this)">
    // so that the data points themselves do not have to be scaled!
    // This will make editing/adding by hand very, very easy.
    /**
       Get the coordinate in the SVG coordinate system that corresponds with 
       the specified value.
    */
    double translateCoordinate(double val);

    /**
        Print the SVG representation of this axis.
    */
    void printSVG(std::ostream& os) const;
};

#endif