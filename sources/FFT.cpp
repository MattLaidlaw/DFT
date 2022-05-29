#include <DFT/FFT.hpp>

//Series TrivialForward(const Series& timeSeries) {
//    auto N = timeSeries.size();
//    auto frequencySeries = Series(N);
//
//    for (auto k = 0; k < N; k++) {
//        auto sum = Sample(0.0, 0.0);
//        for (auto n = 0; n < N; n++) {
//            double exponential = 2 * PI / N * k * n;
//            double real = cos(exponential);
//            double imag = -sin(exponential);
//            sum += (timeSeries[n] * Sample(real, imag));
//        }
//        frequencySeries[k] = sum;
//    }
//
//    return frequencySeries;
//}
//
//Series _Forward(const Series& timeSeries) {
//    const int N = timeSeries.size();
//
//    if (N == 1) {
//        return TrivialForward(timeSeries);
//    } else {
//        auto lhs = Series(N / 2);
//        auto rhs = Series(N / 2);
//        for (auto i = 0; i < (N / 2); i++) {
//            lhs[i] = timeSeries[2 * i];
//            rhs[i] = timeSeries[2 * i + 1];
//        }
//
//        lhs = _Forward(lhs);
//        rhs = _Forward(rhs);
//
//        auto X = Series(N);
//        for (auto i = 0; i < (N / 2); i++) {
//            X[i] = lhs[i];
//            X[i + (N / 2)] = rhs[i];
//        }
//
//        for (auto k = 0; k < (N / 2); k++) {
//            auto p = X[k];
//
//            double exponential = 2 * PI / N * k;
//            double real = cos(exponential);
//            double imag = -sin(exponential);
//            auto q = Sample(real, imag) * X[k + (N / 2)];
//            X[k] = p + q;
//            X[k + (N / 2)] = p - q;
//        }
//
//        return X;
//    }
//}

DFT::Status FFT::Forward(const complex* const timeSeriesIn, complex* const dftOut, const size_t N) const {
    const bool inputIsNull = timeSeriesIn == nullptr;
    const bool outputIsNull = dftOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    return Status::Success;
}

DFT::Status FFT::Backward(const complex* const dftIn, complex* const timeSeriesOut, const size_t N) const {
    const bool inputIsNull = timeSeriesIn == nullptr;
    const bool outputIsNull = dftOut == nullptr;
    if (inputIsNull || outputIsNull) {
        return Status::InvalidParameter;
    }

    return Status::Success;
}
