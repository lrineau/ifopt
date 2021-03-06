/******************************************************************************
Copyright (c) 2017, Alexander W. Winkler, ETH Zurich. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of ETH ZURICH nor the names of its contributors may be
      used to endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#ifndef IFOPT_SRC_IFOPT_IPOPT_INCLUDE_IFOPT_IPOPT_H_
#define IFOPT_SRC_IFOPT_IPOPT_INCLUDE_IFOPT_IPOPT_H_

#include <ifopt/problem.h>
#include <ifopt/solver.h>

namespace ifopt {

// this is the only class users should interact with
class Ipopt : public Solver {
public:
  using Ptr = std::shared_ptr<Ipopt>;

  /** @brief  Creates an IpoptAdapter and solves the NLP.
    * @param [in/out]  nlp  The specific problem.
    *
    * This function creates the actual solver, sets the solver specific
    * options (see SetOptions()) and passes the IpoptAdapter problem to it
    * to be modified.
    */
  void Solve(Problem& nlp);

  /**
  * These settings include which QP solver to use, if gradients should
  * be approximated or the provided analytical ones used, when the iterations
  * should be terminated,...
  *
  * A complete list of options can be found at:
  * https://www.coin-or.org/Ipopt/documentation/node40.html
  */

  // these are the options
  // Download and use additional solvers here: http://www.hsl.rl.ac.uk/ipopt/
  std::string linear_solver_ = "ma27"; ///< ma27, ma57, ma77, ma86, ma97
  std::string hessian_approximation_ = "limited-memory";
  double tol_ = 0.001;
  double max_cpu_time_ = 40.0; //s
  int print_level_ = 3;
  std::string print_user_options_ = "no";
  std::string print_timing_statistics_ = "no";

  // whether to use provided analytical derivatives or approximate by
  // finite differences.
  bool use_jacobian_approximation_ = false;



};

} /* namespace ifopt */

#endif /* IFOPT_SRC_IFOPT_IPOPT_INCLUDE_IFOPT_IPOPT_H_ */
