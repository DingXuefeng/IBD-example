/*****************************************************************************/
// Author: Xuefeng Ding <dingxf@ihep.ac.cn> @ IHEP-CAS
// 
// Date: 2023 March 25
// Version: v1.0
// Description: Strumia-Vissani approximation of IBD cross-section
//
// All rights reserved. 2023 copyrighted.
/*****************************************************************************/
#include <cmath>
#include <iostream>
double IBDxsec(double Ev) {
  // based on Strumia-Vissani approximation
  // Strumia, Alessandro, and Francesco Vissani. 
  // “Precise Quasielastic Neutrino/Nucleon Cross-Section.” 
  // Physics Letters B 564, no. 1–2 (July 2003): 42–54. 
  // https://doi.org/10.1016/S0370-2693(03)00616-6.
  double Ee = Ev-1.806+0.511;
  double pe = sqrt(Ee*Ee-0.511*0.511);
  return 1e-43*pe*Ee*pow(Ev,-0.07056+0.02018*log(Ev)-0.001953*pow(log(Ev),3));
}
