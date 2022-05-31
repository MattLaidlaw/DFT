#ifndef DFT_FFT_HPP
#define DFT_FFT_HPP

#include "DFT.hpp"

/** @brief Implements the DFT interface using the Cooley-Tukey FFT algorithm.
 *         Completes in O(n * log(n)) time. */
class FFT : public DFT {
public:
    Status Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const final;
    Status Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const final;
};

#endif //DFT_FFT_HPP
