#ifndef SCATTERPLOTSERIES_H
#define SCATTERPLOTSERIES_H

#include "Series.h"

#include <map>
#include <iostream>

/**
    
*/
class ScatterPlotSeries : public Series, std::map<double, double> {
private:
    std::map<double, double> data;

public:
    void addDatum(double x, double y) {
        data[x] = y;
    }

    // TODO: ROUGH MOCKUP! THIS IS JUST THE BASIC IDEA
    void print(std::ostream& os) {
        for (auto datum : data)
            os << "<circle cx=\"" << datum.first << "\" cy=\"" << datum.second << "\" r=\"10\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />\n";
    }

    friend std::ostream& operator<< (std::ostream& os, const ScatterPlotSeries& series);
};

/**
    Print the data in this series.
*/
std::ostream& operator<< (std::ostream& os, const ScatterPlotSeries& series);

#endif