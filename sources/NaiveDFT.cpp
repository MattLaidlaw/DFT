#include <DFT/NaiveDFT.hpp>

DFT::Status NaiveDFT::Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const {
    const bool inputIsNull = timeSeriesIn == nullptr;
    const bool outputIsNull = dftOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    for (auto k = 0; k < N; k++) {
        auto sum = complex(0.0, 0.0);
        for (auto n = 0; n < N; n++) {
            double exponential = 2 * PI / N * k * n;
            double real = cos(exponential);
            double imag = -sin(exponential);
            sum += (timeSeriesIn[n] * complex(real, imag));
        }
        dftOut[k] = sum;
    }
    return Status::Success;
}

DFT::Status NaiveDFT::Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const {
    const bool inputIsNull = dftIn == nullptr;
    const bool outputIsNull = timeSeriesOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    for (auto n = 0; n < N; n++) {
        auto s = complex(0.0, 0.0);
        for (auto k = 0; k < N; k++) {
            double exponent = ((2 * PI) / N) * k * n;
            double lhs = cos(exponent);
            double rhs = sin(exponent);
            s += (dftIn[k] * complex(lhs, rhs));
        }
        s = s / complex(N, 0.0);
        timeSeriesOut[n] = s;
    }
    return Status::Success;
}
