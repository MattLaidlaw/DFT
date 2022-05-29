#include "Utils.hpp"

#include <algorithm>
#include <iomanip>

Series CreateCompositeSignal(int numberOfSamples, const SignalList& composingSignals) {
    Series series(numberOfSamples);
    std::transform(series.begin(), series.end(), series.begin(),
                   [&, i = 0](const Sample& sample) mutable -> Sample {
        double real = 0.0;
        double imag = 0.0;
        for (const auto& [frequency, amplitude] : composingSignals) {
            double radians = frequency * i * 2 * M_PI / numberOfSamples;
            real += amplitude * cos(radians);
            imag += amplitude * sin(radians);
        }
        i++;
        return {real, imag};
    });
    return series;
}

void PrintSeries(const Series& series, std::ostream& os) {
    os << std::fixed;
    for (const auto& sample : series) {
        os << sample << std::endl;
    }
    os << std::endl;
}
