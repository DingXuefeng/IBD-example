/*****************************************************************************/
// Author: Xuefeng Ding <dingxf@ihep.ac.cn> @ IHEP-CAS
// 
// Date: 2023 March 25
// Version: v1.0
// Description: Unoscillated reactor visible energy spectrum
//
// All rights reserved. 2023 copyrighted.
/*****************************************************************************/
double Pee_vac(double E) {
  constexpr double sin2_th12 =  0.307;
  constexpr double sin2_th13 = 2.18e-2;
  constexpr double Dm2_21 = 7.53e-5;
  constexpr double Dm2_32 = 2.453e-3;
  constexpr double Dm2_31 = Dm2_32+Dm2_21;
  //constexpr double DeltaM32Sq_InvertedHierarchy = -2.546e-3;
  constexpr double cos2_th12 = 1. - sin2_th12;
  constexpr double sin2_2th12 = 4.*sin2_th12*cos2_th12;
  constexpr double cos2_th13 = 1. - sin2_th13;
  constexpr double sin2_2th13 = 4.*sin2_th13*cos2_th13;
  constexpr double cos4_th13 = cos2_th13*cos2_th13;
  constexpr double L = 52.5e3;
  // 1.267 -> DM2 in eV^2, L in m, E in MeV
  const double t1 = sin2_2th12 * cos4_th13 * pow(sin(1.267 * Dm2_21 * L / E), 2);
  const double t2 = sin2_2th13 * cos2_th12 * pow(sin(1.267 * Dm2_31 * L / E), 2);
  const double t3 = sin2_2th13 * sin2_th12 * pow(sin(1.267 * Dm2_32 * L / E), 2);
  const double ndProb = 1. - t1 - t2 - t3;
  return ndProb;


}
