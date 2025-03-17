// ConstantBlackScholesProcess.hpp

#ifndef CONSTANTBLACKSCHOLESPROCESS_HPP
#define CONSTANTBLACKSCHOLESPROCESS_HPP

#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {
    public:
        // Constructor with constant parameters for r (rate), sigma (volatility), d (dividend yield) and x0 (initial value)
        ConstantBlackScholesProcess(Real r, Real sigma, Real d, Real x0);

        // Overriding the pure virtual functions from StochasticProcess1D
        Real x0() const override;
        Real drift(Time t, Real x) const override;
        Real diffusion(Time t, Real x) const override;

    private:
        Real rate_;          // Constant risk-free rate
        Real volatility_;    // Constant volatility
        Real dividendYield_; // Constant dividend yield
        Real x0_;            // Initial asset value
    };
}

#endif // CONSTANTBLACKSCHOLESPROCESS_HPP