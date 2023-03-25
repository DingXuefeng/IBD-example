/*****************************************************************************/
// Author: Xuefeng Ding <dingxf@ihep.ac.cn> @ IHEP-CAS
// 
// Date: 2023 March 25
// Version: v1.0
// Description: Huber Muller model
//
// All rights reserved. 2023 copyrighted.
/*****************************************************************************/
#include <cmath>
#include <iostream>
double dNdEv(int index,double Ev) {
  // based on Huber Muller model
  // Mueller, Th. A., D. Lhuillier, M. Fallot, A. Letourneau, S. Cormon, M. Fechner, L. Giot, et al. 
  // “Improved Predictions of Reactor Antineutrino Spectra.” 
  // Physical Review C 83, no. 5 (May 23, 2011): 054615. 
  // https://doi.org/10.1103/PhysRevC.83.054615.
  constexpr double alpha_pk [][6] = {
    { 3.217, -3.111,1.395,-3.690e-1,4.445e-2,-2.053e-3}, // U235
    { 4.833e-1,1.927e-1,-1.283e-1,-6.762e-3,2.233e-3,-1.536e-4}, // U238
    { 6.413,-7.432,3.535,-8.820e-1,1.025e-1,-4.550e-3}, // Pu239
    { 3.251,-3.204,1.428,-3.675e-1,4.254e-2,-1.896e-3}}; // Pu241
  double f = 0;
  for(int i = 0;i<6;++i) {
    f += alpha_pk[index][i]*pow(Ev,i);
  }
  return exp(f);
}
