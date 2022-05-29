#ifndef DFT_NAIVEDFT_HPP
#define DFT_NAIVEDFT_HPP

#include "DFT.hpp"

/** @brief Implements the DFT interface using the definition of the DFT algorithm.
 *         Completes in O(n^2) time. */
class NaiveDFT : public DFT {
public:
    Status Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const final;
    Status Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const final;
};

#endif //DFT_NAIVEDFT_HPP
