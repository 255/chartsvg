#ifndef CONTINUOUSSERIES_H
#define CONTINUOUSSERIES_H

#include "Series.h"

/**
    Data with a continuous (floating point) independent variable.
    TODO: Subclasses (will) include series for line charts and for scatter plots
*/
class ContinuousSeries : public Series {
private:
    

public:
    virtual void addDatum(double x, double y) = 0;
};

#endif