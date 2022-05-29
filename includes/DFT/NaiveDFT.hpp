#ifndef DFT_NAIVEDFT_HPP
#define DFT_NAIVEDFT_HPP

#include "DFT.hpp"

/** @brief Implements the DFT interface using the definition of the DFT algorithm.
 *         Completes in O(n^2) time. */
class NaiveDFT : public DFT {
public:
    Series Forward(const Series& timeSeries) const final;
    Series Backward(const Series& frequencySeries) const final;
};

#endif //DFT_NAIVEDFT_HPP
