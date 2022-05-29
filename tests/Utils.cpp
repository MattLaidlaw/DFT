#include "Utils.hpp"

#include <algorithm>
#include <iomanip>
#include <numeric>

Series CreateCompositeSignal(int numberOfSamples, const SignalList& composingSignals) {
    Series series(numberOfSamples);
    auto indices = std::vector<int>(series.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::transform(indices.begin(), indices.end(), series.begin(), [&](const int& i) -> Sample {
        double real = 0.0;
        double imag = 0.0;
        for (const auto& [frequency, amplitude] : composingSignals) {
            double radians = frequency * i * 2 * PI / numberOfSamples;
            real += amplitude * cos(radians);
            imag += amplitude * sin(radians);
        }
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
