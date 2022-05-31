#ifndef DFT_DFT_HPP
#define DFT_DFT_HPP

#include <complex>

const double PI = 3.14159265358979323846;

/** @brief A single complex number. */
typedef std::complex<double> complex;

/** @brief An interface for calculating Discrete Fourier Transforms. */
class DFT {
public:

    enum class Status {
        Success = 0,
        InvalidParameter
    };

    /** @brief Converts a time-series sampling to the frequency-domain.
     *  @param timeSeriesIn A list of time-series samples.
     *  @param dftOut The time-series sampling represented in the frequency-domain.
     *  @param N the number of samples. */
    virtual Status Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const = 0;

    /** @brief Converts a list of frequency-amplitude bins to a time-domain sampling.
     *  @param dftIn A list of frequency-amplitude bins.
     *  @param timeSeriesOut A time-series sampling representing the frequency-domain input.
     *  @param N the number of samples. */
    virtual Status Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const = 0;

};

#endif // DFT_DFT_HPP
