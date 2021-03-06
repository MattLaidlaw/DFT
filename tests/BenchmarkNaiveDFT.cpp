#include <benchmark/benchmark.h>
#include <DFT/NaiveDFT.hpp>
#include "Utils.hpp"

static void Benchmark_NaiveDFT_Forward(benchmark::State& state) {
    const auto dft = NaiveDFT();
    const auto signal = CreateCompositeSignal(state.range(0), {{1, 1}});
    auto* out = new complex[state.range(0)];

    for (auto _ : state) {
        dft.Forward(signal.data(), out, state.range(0));
    }

    delete[] out;

    state.SetBytesProcessed(state.iterations() * state.range(0));
    state.SetComplexityN(state.range(0));
}

BENCHMARK(Benchmark_NaiveDFT_Forward)->RangeMultiplier(2)->Range(1024, 32768)->Complexity();
