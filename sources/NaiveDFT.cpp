#include <DFT/NaiveDFT.hpp>

Series NaiveDFT::Forward(const Series &timeSeries) const {
    auto N = timeSeries.size();
    auto frequencySeries = Series(N);

    for (auto k = 0; k < N; k++) {
        auto sum = Sample(0.0, 0.0);
        for (auto n = 0; n < N; n++) {
            double exponential = 2 * PI / N * k * n;
            double real = cos(exponential);
            double imag = -sin(exponential);
            sum += (timeSeries[n] * Sample(real, imag));
        }
        frequencySeries[k] = sum;
    }

    return frequencySeries;
}

Series NaiveDFT::Backward(const Series &frequencySeries) const {
    auto N = frequencySeries.size();
    auto timeSeries = Series(N);

    for (auto n = 0; n < N; n++) {
        auto s = Sample(0.0, 0.0);
        for (auto k = 0; k < N; k++) {
            double exponent = ((2 * PI) / N) * k * n;
            double lhs = cos(exponent);
            double rhs = sin(exponent);
            s += (frequencySeries[k] * Sample(lhs, rhs));
        }
        s = s / Sample(N, 0.0);
        timeSeries[n] = s;
    }

    return timeSeries;
}
