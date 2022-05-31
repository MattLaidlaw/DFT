#include <gtest/gtest.h>
#include <DFT/FFT.hpp>
#include "Utils.hpp"

TEST(FFT, NullInputInvalidParameter) {
    const auto dft = FFT();

    const size_t numberOfSamples = 8;

    const complex* in = nullptr;
    auto* out = new complex[numberOfSamples];

    auto result = dft.Forward(in, out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::InvalidParameter);

    delete[] out;
}

TEST(FFT, NullOutputInvalidParameter) {
    const auto dft = FFT();

    const size_t numberOfSamples = 8;

    const auto* in = new complex[numberOfSamples];
    complex* out = nullptr;

    auto result = dft.Forward(in, out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::InvalidParameter);

    delete[] in;
}

TEST(FFT, SmokeTest) {
    const auto dft = FFT();

    const int numberOfSamples = 4;

    const auto* in = new complex[numberOfSamples] {{1, 0}, {2, -1}, {0, -1}, {-1, 2}};
    auto* out = new complex[numberOfSamples];

    auto result = dft.Forward(in, out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    EXPECT_NEAR(out[0].real(), 2.0, 0.0001);
    EXPECT_NEAR(out[0].imag(), 0.0, 0.0001);

    EXPECT_NEAR(out[1].real(), -2.0, 0.0001);
    EXPECT_NEAR(out[1].imag(), -2.0, 0.0001);

    EXPECT_NEAR(out[2].real(), 0.0, 0.0001);
    EXPECT_NEAR(out[2].imag(), -2.0, 0.0001);

    EXPECT_NEAR(out[3].real(), 4.0, 0.0001);
    EXPECT_NEAR(out[3].imag(), 4.0, 0.0001);

    delete[] in;
    delete[] out;
}

TEST(FFT, Zeros) {
    const auto dft = FFT();

    const int numberOfSamples = 8;
    const int frequency = 0.0;
    const int amplitude = 0.0;

    const auto in = CreateCompositeSignal(numberOfSamples, {{frequency, amplitude}});
    auto* out = new complex[numberOfSamples];

    auto result = dft.Forward(in.data(), out, numberOfSamples);
    EXPECT_EQ(result, DFT::Status::Success);

    for (auto i = 0; i < numberOfSamples; i++) {
        EXPECT_NEAR(out[i].real(), 0.0, 0.0001);
        EXPECT_NEAR(out[i].imag(), 0.0, 0.0001);
    }

    delete[] out;
}

TEST(FFT, SimpleSignal) {
    const auto dft = FFT();

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

TEST(FFT, CompositeSignal) {
    const auto dft = FFT();

    const int numberOfSamples = 32;
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

TEST(FFT, InverseTransform) {
    const auto dft = FFT();

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
