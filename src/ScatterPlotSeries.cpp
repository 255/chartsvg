#include "ScatterPlotSeries.h"

std::ostream& operator<< (std::ostream& os, const ScatterPlotSeries& series) {
	os << series.getName() << std::endl;

    for (auto datum : series.data) {
        os << '(' << datum.first << ',' << datum.second << ')' << std::endl;
    }

    return os;
}
