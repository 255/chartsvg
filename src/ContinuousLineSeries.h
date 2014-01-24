#ifndef CONTINUOUSLINESERIES_H
#define CONTINUOUSLINESERIES_H

#include "Series.h"

#include <map>
#include <iostream>

/**
    A series with an x-axis of sorted real numbers. Each value in its domain 
    maps to a single value in the range.
*/
class ContinuousLineSeries : public Series {
private:
    std::map<double, double> data;

public:
    ContinuousLineSeries(const std::string& n) : Series(n) {
        
    }

    void addDatum(double x, double y) {
        data[x] = y;
    }

    void printSVGData(std::ostream& os) const;

    // For debugging
    friend std::ostream& operator<< (std::ostream& os, const ContinuousLineSeries& series);
};

/**
    Print the data in this series. This is for debugging.
*/
std::ostream& operator<< (std::ostream& os, const ContinuousLineSeries& series);

#endif