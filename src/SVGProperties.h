#ifndef SVGPROPERTIES_H
#define SVGPROPERTIES_H

#include <map>
#include <iostream>
#include <string>

#include "Color.h"

/**
    A generic collection of SVG attributes, basically for a <g>.
*/
class SVGProperties {
private:
    // Classes to allow for property polymorphism. This allows me to handle
    // color properties with colors, etc.
    struct PropertyValue {
        virtual void printValue(std::ostream& os) const = 0;

        virtual ~PropertyValue() {}
    };

    class ColorValue : public PropertyValue {
        Color color;
        
    public:
        ColorValue(const Color& c)
            : color(c) {}

        void printValue(std::ostream& os) const {
            os << color;
        }
    };

    class StringValue : public PropertyValue {
        std::string value;

    public:
        StringValue(const std::string& str)
            : value(str) {}

        void printValue(std::ostream& os) const {
            os << value;
        }
    };

    std::map<std::string, PropertyValue*> properties;

public:
    SVGProperties() {}

    SVGProperties(const SVGProperties& other) {
        // TODO : I don't want to deal with this (deep copy on polymorphic array...)
        // ITERATE OVER CONTAINERS BY REFERENCE TO AVOID MAKING COPIES!!!!
        std::cerr << " COPY CONSTRUCTING AN SVG PROPERTIES. DON'T DO THIS! ";
    }

    // TODO: create a fill object to handle different fill styles. Also, fill opacity
    /**
        Set the fill color property.
    */
    void setFill(const Color& color) {
        properties["fill"] = new ColorValue(color);
    }

    /**
        Set the stroke property to the specified color.
    */
    void setStroke(const Color& color) {
        properties["stroke"] = new ColorValue(color);
    }

    /**
        Set any property to the specified string.
        TODO: This is a little dangerous.
    */
    void setProperty(const std::string& property, const std::string& value) {
        properties[property] = new StringValue(value);
    }

    /**
        Print these properties in SVG style. Begins with a space.
    */
    void printSVG(std::ostream& os) const {
        for (auto& property : properties) {
            os << ' ' << property.first << "=\"";
            property.second->printValue(os);
            os << "\"";
        }
    }

    /*
        Destructor
    */
    ~SVGProperties() {
        
        for (auto& val : properties) {
            delete val.second;
        }
    }
};

#endif