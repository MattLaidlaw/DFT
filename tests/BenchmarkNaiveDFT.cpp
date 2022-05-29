#include <benchmark/benchmark.h>
#include <DFT/NaiveDFT.hpp>
#include "Utils.hpp"

static void Benchmark_NaiveDFT_Forward(benchmark::State& state) {
    const auto dft = NaiveDFT();
    const auto signal = CreateCompositeSignal(state.range(0), {{1, 1}});

    for (auto _ : state) {
        const auto frequencySeries = dft.Forward(signal);
    }

    state.SetBytesProcessed(state.iterations() * state.range(0));
    state.SetComplexityN(state.range(0));
}

BENCHMARK(Benchmark_NaiveDFT_Forward)->Range(8, 8<<10)->Complexity();
