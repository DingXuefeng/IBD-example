/*****************************************************************************/
// Author: Xuefeng Ding <dingxf@ihep.ac.cn> @ IHEP-CAS
// 
// Date: 2023 March 25
// Version: v1.0
// Description: Unoscillated reactor visible energy spectrum
//
// All rights reserved. 2023 copyrighted.
/*****************************************************************************/
#include <cmath>
#include <iostream>
// An, Fengpeng, Guangpeng An, Qi An, Vito Antonelli, Eric Baussan, John Beacom, Leonid Bezrukov, et al. 
// “Neutrino Physics with JUNO.” 
// Journal of Physics G: Nuclear and Particle Physics 43, no. 3 (2016): 030401. 
// https://doi.org/10.1088/0954-3899/43/3/030401.
// See page 118
constexpr double fractions[] =  {0.58,0.07,0.3,0.05};
constexpr double E_per_fission[] =  {202.36,205.99,211.12,214.26};
// @ 1 km = 1e5 cm
// 1 GW = 6.24e21 MeV/s
//      = 3e19 fission / s
constexpr double E_avg = E_per_fission[0]*fractions[0]+E_per_fission[1]*fractions[1]
+E_per_fission[2]*fractions[2]+E_per_fission[3]*fractions[3];
constexpr double fission_rate = 27*6.24e21/*GW->MeV/s*/*86400/E_avg; // MeV/day @ 27 GW
// 20k ton -> 1e6 g, or 0.5e6 mol proton
constexpr double Ntarget = 2e10*0.1201*6.02e23;
constexpr double dist = 52.5e5; // in cm
constexpr double s0 = Ntarget*fission_rate/(4*M_PI*dist*dist);

double dNdEvis(double Evis) {
  if(Evis<=1.022) return 0;
  double Te = Evis-1.022;
  double Ev = Te+1.806;
  double f = 0;
  for(int i = 0;i<4;++i) {
    f += fractions[i]*dNdEv(i,Ev);
  }
  return s0*f*IBDxsec(Ev)*Pee_vac(Ev);;
}
