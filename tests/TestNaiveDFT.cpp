#include <gtest/gtest.h>
#include <DFT/NaiveDFT.hpp>
#include "Utils.hpp"

TEST(NaiveDFT, NullInputInvalidParameter) {
    const size_t numberOfSamples = 8;

    const complex* in = nullptr;
    auto* out = new complex[numberOfSamples];

    const auto dft = NaiveDFT();
    auto result = dft.Forward(in, out, numberOfSamples);

    EXPECT_EQ(result, DFT::Status::InvalidParameter);

    delete[] out;
}

TEST(NaiveDFT, NullOutputInvalidParameter) {
    const size_t numberOfSamples = 8;

    const auto* in = new complex[numberOfSamples];
    complex* out = nullptr;

    const auto dft = NaiveDFT();
    auto result = dft.Forward(in, out, numberOfSamples);

    EXPECT_EQ(result, DFT::Status::InvalidParameter);

    delete[] in;
}

TEST(NaiveDFT, Zeros) {
    const auto dft = NaiveDFT();

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

TEST(NaiveDFT, SimpleSignal) {
    const auto dft = NaiveDFT();

    const int numberOfSamples = 8;
    const int frequency = 1.0;
    const int amplitude = 1.0;

    const auto in = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    auto* out = new complex[numberOfSamples];

    auto result = dft.Forward(in.data(), out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    for (auto i = 0; i < numberOfSamples; i++) {
        if (i == frequency) {
            EXPECT_NEAR(out[i].real(), double(numberOfSamples), 0.0001);
        } else {
            EXPECT_NEAR(out[i].real(), 0.0, 0.0001);
        }
        EXPECT_NEAR(out[i].imag(), 0.0, 0.0001);
    }

    delete[] out;
}

TEST(NaiveDFT, CompositeSignal) {
    const auto dft = NaiveDFT();

    const int numberOfSamples = 8;
    const auto signals = SignalList{{1, 5}, {3, 3}, {5, 1}};

    const auto in = CreateCompositeSignal(numberOfSamples, signals);
    auto* out = new complex[numberOfSamples];

    auto result = dft.Forward(in.data(), out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    for (auto i = 0; i < numberOfSamples; i++) {
        if (i == 1) {
            EXPECT_NEAR(out[i].real(), double(numberOfSamples * 5), 0.0001);
        } else if (i == 3) {
            EXPECT_NEAR(out[i].real(), double(numberOfSamples * 3), 0.0001);
        } else if (i == 5) {
            EXPECT_NEAR(out[i].real(), double(numberOfSamples * 1), 0.0001);
        } else {
            EXPECT_NEAR(out[i].real(), 0.0, 0.0001);
        }
        EXPECT_NEAR(out[i].imag(), 0.0, 0.0001);
    }

    delete[] out;
}

TEST(NaiveDFT, InverseTransform) {
    const auto dft = NaiveDFT();

    const int numberOfSamples = 8;
    const int frequency = 1.0;
    const int amplitude = 1.0;

    const auto expected = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    auto* out = new complex[numberOfSamples];
    auto* actual = new complex[numberOfSamples];

    auto result = dft.Forward(expected.data(), out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    result = dft.Backward(out, actual, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    for (auto i = 0; i < numberOfSamples; i++) {
        EXPECT_NEAR(expected[i].real(), actual[i].real(), 0.0001);
        EXPECT_NEAR(expected[i].imag(), actual[i].imag(), 0.0001);
    }

    delete[] out;
}
