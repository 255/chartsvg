#include "ContinuousLineSeries.h"

void ContinuousLineSeries::printSVGData(std::ostream& os) const {
    // TODO: This is still very temporary
    size_t radius = 6;
    for (const auto& datum : data)
        os << "<circle cx=\"" << datum.first << "\" cy=\"" << datum.second << "\" r=\"" << radius << "\"/>\n";
}

std::ostream& operator<< (std::ostream& os, const ContinuousLineSeries& series) {
	os << series.getName() << std::endl;

    for (const auto& datum : series.data) {
        os << '(' << datum.first << ',' << datum.second << ')' << std::endl;
    }

    return os;
}
