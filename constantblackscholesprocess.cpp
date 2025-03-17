// ConstantBlackScholesProcess.cpp

#include "constantblackscholesprocess.hpp"

namespace QuantLib {

    // Constructor with constant parameters for r (rate), sigma (volatility), d (dividend yield) and x0 (initial value)
    ConstantBlackScholesProcess::ConstantBlackScholesProcess(Real r, Real sigma, Real d, Real x0)
        : rate_(r), volatility_(sigma), dividendYield_(d), x0_(x0) {}

    // Drift function: adjusted for the dividend yield
    Real ConstantBlackScholesProcess::drift(Time t, Real x) const {
        return (rate_ - dividendYield_) * x; // Drift = (r - q) * x
    }

    // Diffusion function: returns the diffusion term (constant volatility)
    Real ConstantBlackScholesProcess::diffusion(Time t, Real x) const {
        return volatility_ * x; // Diffusion = sigma * x
    }

    // Method to return the initial value of the process
    Real ConstantBlackScholesProcess::x0() const {
        return x0_; // Initial value of the process
    }

}