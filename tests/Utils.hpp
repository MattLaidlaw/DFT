#ifndef DFT_UTILS_HPP
#define DFT_UTILS_HPP

#include <DFT/DFT.hpp>

#include <iostream>
#include <vector>

/** @brief A pair of frequency and amplitude values defining a signal.
 *  Signal::first => frequency
 *  Signal::second => amplitude */
typedef std::pair<int, int> Signal;

/** @brief A list of signals, each with its own frequency and amplitude. */
typedef std::vector<Signal> SignalList;

/** @brief Create a time-series sampling of a composite signal.
 *  @param numberOfSamples The number of samples to generate.
 *  @param composingSignals The list of signals that will be summed into a single composite. */
Series CreateCompositeSignal(int numberOfSamples, const SignalList& composingSignals);

/** @brief Prints each sample from a series.
 *  @param series The series to print.
 *  @param os The output stream to write to, defaults to stdout. */
void PrintSeries(const Series& series, std::ostream& os = std::cout);

#endif //DFT_UTILS_HPP
