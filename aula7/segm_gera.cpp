//segm_gera.cpp
//gera elipses e retangulos para segmentacao
//imagens X estao normalizadas de 0 a 255
#include <cekeikon.h>

int main() {
  RNG rng(7);
  int n=100;
  int nl=32;
  int nc=32;
  int diferenca=32;
  double desvio=diferenca/2.0;
  
  for (int i=0; i<n; i++) {
    int tamx=nc/8+rng(nc/4);
    int tamy=nl/8+rng(nl/4);
    
    GRY corfundo=rng(256);
    GRY corelipse;
    if (corfundo>128) corelipse=corfundo-diferenca;
    else corelipse=corfundo+diferenca;

    Mat_<GRY> a(nl,nc,corfundo);
    ellipse(a,Point(a.cols/2,a.rows/2),Size(tamx,tamy),
            0,0,360,toScalar(corelipse),-1);
    for (unsigned j=0; j<a.total(); j++)
      a(j) = saturate_cast<GRY>(a(j) + rng.gaussian(desvio));
    a=normaliza(a);
    imp(a,format("%03dx.png",i));

    corfundo=0;
    corelipse=255;
    a.setTo(corfundo);
    ellipse(a,Point(a.cols/2,a.rows/2),Size(tamx,tamy),
            0,0,360,toScalar(corelipse),-1);
    imp(a,format("%03dy.png",i));
  }  

  for (int i=n; i<2*n; i++) {
    int tamx=nc/8+rng(nc/4);
    int tamy=nl/8+rng(nl/4);
    int centrox=nc/2;
    int centroy=nl/2;

    GRY corfundo=rng(256);
    GRY corret;
    if (corfundo>128) corret=corfundo-diferenca;
    else corret=corfundo+diferenca;

    Mat_<GRY> a(nl,nc,corfundo);
    rectangle(a,Point(centrox-tamx,centroy-tamy),Point(centrox+tamx,centroy+tamy),
              toScalar(corret),-1);
    for (unsigned j=0; j<a.total(); j++)
      a(j) = saturate_cast<GRY>(a(j) + rng.gaussian(desvio));
    a=normaliza(a);
    imp(a,format("%03dx.png",i));

    corfundo=0;
    corret=255;
    a.setTo(corfundo);
    rectangle(a,Point(centrox-tamx,centroy-tamy),Point(centrox+tamx,centroy+tamy),
              toScalar(corret),-1);
    imp(a,format("%03dy.png",i));
  }  
}
