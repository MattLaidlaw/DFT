#include <gtest/gtest.h>
#include <DFT/FFT.hpp>
#include "Utils.hpp"

TEST(FFT, Zeros) {
    const auto dft = FFT();

    const int numberOfSamples = 8;
    const int frequency = 0.0;
    const int amplitude = 0.0;

    const auto signal = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    const auto frequencySeries = dft.Forward(signal);
    for (auto i = 0; i < signal.size(); i++) {
        EXPECT_NEAR(frequencySeries[i].real(), 0.0, 0.0001);
        EXPECT_NEAR(frequencySeries[i].imag(), 0.0, 0.0001);
    }
}

TEST(FFT, SimpleSignal) {
    const auto dft = FFT();

    const int numberOfSamples = 8;
    const int frequency = 1.0;
    const int amplitude = 1.0;

    const auto signal = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    const auto frequencySeries = dft.Forward(signal);
    for (auto i = 0; i < signal.size(); i++) {
        if (i == frequency) {
            EXPECT_NEAR(frequencySeries[i].real(), double(numberOfSamples), 0.0001);
        } else {
            EXPECT_NEAR(frequencySeries[i].real(), 0.0, 0.0001);
        }
        EXPECT_NEAR(frequencySeries[i].imag(), 0.0, 0.0001);
    }
}

TEST(FFT, CompositeSignal) {
    const auto dft = FFT();

    const int numberOfSamples = 8;
    const auto signals = SignalList{{1, 5}, {3, 3}, {5, 1}};

    const auto signal = CreateCompositeSignal(numberOfSamples, signals);
    const auto frequencySeries = dft.Forward(signal);
    for (auto i = 0; i < signal.size(); i++) {
        if (i == 1) {
            EXPECT_NEAR(frequencySeries[i].real(), double(numberOfSamples * 5), 0.0001);
        } else if (i == 3) {
            EXPECT_NEAR(frequencySeries[i].real(), double(numberOfSamples * 3), 0.0001);
        } else if (i == 5) {
            EXPECT_NEAR(frequencySeries[i].real(), double(numberOfSamples * 1), 0.0001);
        } else {
            EXPECT_NEAR(frequencySeries[i].real(), 0.0, 0.0001);
        }
        EXPECT_NEAR(frequencySeries[i].imag(), 0.0, 0.0001);
    }
}

TEST(FFT, InverseTransform) {
    const auto dft = FFT();

    const int numberOfSamples = 8;
    const int frequency = 1.0;
    const int amplitude = 1.0;

    const auto expectedSignal = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    const auto frequencySeries = dft.Forward(expectedSignal);
    const auto actualSignal = dft.Backward(frequencySeries);
    for (auto i = 0; i < expectedSignal.size(); i++) {
        EXPECT_NEAR(expectedSignal[i].real(), actualSignal[i].real(), 0.0001);
        EXPECT_NEAR(expectedSignal[i].imag(), actualSignal[i].imag(), 0.0001);
    }
}
