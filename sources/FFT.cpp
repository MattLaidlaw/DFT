#include <DFT/FFT.hpp>
#include <vector>
#include <DFT/NaiveDFT.hpp>

void _Forward(const complex* const in, complex* const out, const size_t N) {
    if (N == 1) {
        out[0] = in[0];
    } else {
        complex* X = new complex[N];
        for (auto i = 0; i < (N / 2); i++) {
            X[i] = in[2 * i];
            X[i + (N / 2)] = in[2 * i + 1];
        }

        _Forward(X, X, N / 2);
        _Forward(X + (N / 2), X + (N / 2), N / 2);

        for (auto k = 0; k < (N / 2); k++) {
            auto p = X[k];
            double exponential = 2 * PI / N * k;
            double real = cos(exponential);
            double imag = -sin(exponential);
            auto q = complex(real, imag) * X[k + (N / 2)];
            X[k] = p + q;
            X[k + (N / 2)] = p - q;
        }

        std::copy(X, X + N, out);
        delete[] X;
    }
}

void _Backward(const complex* const in, complex* const out, const size_t N, const int D) {
    if (N == 1) {
        out[0] = in[0] / complex(D, 0.0);
    } else {
        complex* X = new complex[N];
        for (auto i = 0; i < (N / 2); i++) {
            X[i] = in[2 * i];
            X[i + (N / 2)] = in[2 * i + 1];
        }

        _Backward(X, X, N / 2, D);
        _Backward(X + (N / 2), X + (N / 2), N / 2, D);

        for (auto k = 0; k < (N / 2); k++) {
            auto p = X[k];
            double exponential = 2 * PI / N * k;
            double real = cos(exponential);
            double imag = sin(exponential);
            auto q = complex(real, imag) * X[k + (N / 2)];
            X[k] = p + q;
            X[k + (N / 2)] = p - q;
        }

        std::copy(X, X + N, out);
        delete[] X;
    }
}

DFT::Status FFT::Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const {
    const bool inputIsNull = timeSeriesIn == nullptr;
    const bool outputIsNull = dftOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    _Forward(timeSeriesIn, dftOut, N);

    return Status::Success;
}

DFT::Status FFT::Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const {
    const bool inputIsNull = dftIn == nullptr;
    const bool outputIsNull = timeSeriesOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    _Backward(dftIn, timeSeriesOut, N, N);

    return Status::Success;
}
