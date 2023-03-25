/*****************************************************************************/
// Author: Xuefeng Ding <dingxf@ihep.ac.cn> @ IHEP-CAS
// 
// Date: 2023 March 25
// Version: v1.0
// Description: testing functions
//
// All rights reserved. 2023 copyrighted.
/*****************************************************************************/
//double dNdEv(int index,double Ev);
//#pragma cling load("HM_cxx.so")
void test() {
  gStyle->SetOptTitle(0);
  TCanvas *cc = new TCanvas;
  double sum = 0;
  for(int i = 0;i<4;++i) {
    TF1 *f = new TF1(Form("f%d",i),[=](double *x,double *) {
	return dNdEv(i,x[0])*fractions[i];
	},1.806,8.2,1);
    double integ,err;
    integ = f->IntegralOneDim(1.806,12,1e-8,1e-8,err);
    sum += integ*fractions[i];
    std::cout<<i<<" "<<integ<<" "<<err<<std::endl;
    f->Draw(i?"same":"");
    f->SetLineColor(i+1);
  }
  std::cout<<"total: "<<sum<<std::endl;
  std::cout<<"Avg fission E "<<E_avg<<std::endl;
  cc->SetLogy();

  cc = new TCanvas;
  TF1 *f = new TF1("reactor",[=](double *x,double *) {
      return dNdEvis(x[0]);
      },1.022,12,0);
  f->SetNpx(1000);

  f->Draw();

  double integ,err;
  integ = f->IntegralOneDim(1.022,12,1e-8,1e-8,err);
  std::cout<<"total number of events "<<integ<<" "<<err<<std::endl;
  TF1 *f2 = new TF1("neutrino",[=](double *x,double *) {
	double Ev = x[0];
	if(Ev<=1.806) return 0.;
	double f = 0;
	for(int i = 0;i<4;++i) {
	  f += fractions[i]*dNdEv(i,Ev);
	}
	return f;
      },1.806,12,0);
  double Nv = f2->IntegralOneDim(1.806,12,1e-8,1e-8,err);
  std::cout<<"s0 "<<s0<<std::endl;
  std::cout<<"total "<<Nv<<" "<<err<<std::endl;
  std::cout<<"Avg xsec: "<<integ/s0/Nv<<std::endl;
}
