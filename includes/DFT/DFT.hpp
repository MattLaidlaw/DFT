#ifndef DFT_DFT_HPP
#define DFT_DFT_HPP

#include <complex>
#include <vector>

const double M_PI = 3.14159265358979323846;

/** @brief A single complex number. */
typedef std::complex<double> Sample;

/** @brief A list of complex numbers. */
typedef std::vector<Sample> Series;

/** @brief An interface for calculating Discrete Fourier Transforms. */
class DFT {
public:

    /** @brief Converts a list of samples from the time-domain to the frequency-domain.
     *  @param timeSeries A list of time-series samples. */
    virtual Series Forward(const Series& timeSeries) const = 0;

    /** @brief Converts a list of samples from the frequency-domain to the time-domain.
     *  @param frequencySeries A list of frequency-series samples. */
    virtual Series Backward(const Series& frequencySeries) const = 0;

};

#endif // DFT_DFT_HPP
