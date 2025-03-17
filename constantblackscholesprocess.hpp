
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {
        public:
            // Constructor with constant parameters for r (rate), sigma (volatility), d (dividend yield) and x0 (initial value)
            ConstantBlackScholesProcess(Real r, Real sigma, Real d, Real x0)
                : rate_(r), volatility_(sigma), dividendYield_(d), x0_(x0) {}
    
            // Overriding the pure virtual functions from StochasticProcess1D
            Real x0() const override {
                return x0_; // Initial value of the process
            }
    
            // Drift function: adjusted for the dividend yield
            Real drift(Time t, Real x) const override {
                return (rate_ - dividendYield_) * x; // Drift = (r - q) * x
            }
    
            // Diffusion function: returns the diffusion term (constant volatility)
            Real diffusion(Time t, Real x) const override {
                return volatility_ * x; // Diffusion = sigma * x
            }
    
            // We can optionally define any other methods, but for now, these are sufficient for a constant Black-Scholes process
        private:
            Real rate_;          // Constant risk-free rate
            Real volatility_;    // Constant volatility
            Real dividendYield_; // Constant dividend yield
            Real x0_;            // Initial asset value
        };
}