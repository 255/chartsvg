#include <iostream>
#include <regex>
#include <string>


#include "Color.h"

#include "ContinuousLineChart.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 3) {
        ContinuousLineChart plot("Test Plot!", 1280, 768);

        plot.parseData(argv[1]);

        cout << "The parser found:" << endl;
        cout << plot;

        plot.printSVG(cout);

        ofstream out(argv[2]);
        plot.printSVG(out);
        out.close();
    }
    else {
        int red, green, blue;
        cin >> red >> green >> blue;

        Color col(red, green, blue);
        std::cout << col << endl;

    }

    return 0;
}