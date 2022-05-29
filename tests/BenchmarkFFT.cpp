#include <benchmark/benchmark.h>
#include <DFT/FFT.hpp>
#include "Utils.hpp"

static void Benchmark_FFT_Forward(benchmark::State& state) {
    const auto dft = FFT();
    const auto signal = CreateCompositeSignal(state.range(0), {{1, 1}});

    for (auto _ : state) {
        const auto frequencySeries = dft.Forward(signal);
    }

    state.SetBytesProcessed(state.iterations() * state.range(0));
    state.SetComplexityN(state.range(0));
}

BENCHMARK(Benchmark_FFT_Forward)->RangeMultiplier(2)->Range(1024, 32768)->Complexity();
