#include <proeikon>
#include <imgpv>

namespace CirateG {

//<<<<<<<<<<<<<<<<<<<< setparam <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Parametros
double adesv=infinito;
double qdesv=infinito;

int    nesc=maxint;
double escinic=infinito;
double escfim=infinito;

int    nang=maxint;

double t1=infinito;
bool otimiza1;
int qtd_cand_1f=maxint;
double pct_cand_1f=infinito;
double dist_pixel_1f=infinito;

double t2=infinito;
bool otimiza2;
int qtd_cand_2f=maxint;
double pct_cand_2f=infinito;
double dist_pixel_2f=infinito;

double t3=infinito;
bool otimiza3;
int qtd_cand_3f=maxint;
double dist_pixel_3f=infinito;

double ssalpha=infinito;
double ssbeta=infinito;
double ssgama=infinito;

bool   absoluto=true;

int    ncirc=maxint;
double rinic=infinito;
double rfim=infinito;

int    tol=maxint;

string analyze;
string query;

bool   gauss_exec=true;
string gaussa;
string gaussq;
string actualq;

bool   cissa_exec=true;
string cissa_out;
string cissa_verbose;

bool   cissq_exec=true;
string cissq_out;
string cissq_verbose;

bool   cifi_exec=true;
string cifi_param;
string cifi_match;

bool   rassq_exec=true;
string rassq_out;
string rassq_verbose;

bool   rafi_exec=true;
string rafi_param;
string rafi_match;

bool   tefi_exec=true;
string tefi_param;
string tefi_match;
string tefi_verbose;

bool   circ_exec=true;
string circ_out;
string circ_modo="l";
// int    circ_nmaiores=0;
// double circ_dist=0.0;

bool   txt_exec=true;
string txt_out;

// Variaveis globais
double dcirc;
double passoesc;
double dangrad; // em radianos
double dangdeg; // em radianos
IMGGRY an,qu,ga,gq,anori;
vector<BOX> v; // acrescentado
double rqunit; // raio de q na escala unitaria

//<<<<<<<<<<<<<<<<<<<<<<<
void setparam(char* nomearq)
{ FILE* cfg;
  cfg=fopen(nomearq,"rt");
  if (cfg==NULL) erro("Error: Configuration file not found ",nomearq);

  string st=LeStr(cfg);
  while (st!="eof") {
    if      (st=="adesv")    LeNum(cfg,adesv);
    else if (st=="qdesv")    LeNum(cfg,qdesv);
    else if (st=="nesc")     LeNum(cfg,nesc);
    else if (st=="escinic")  LeNum(cfg,escinic);
    else if (st=="escfim")   LeNum(cfg,escfim);

    else if (st=="nang")     LeNum(cfg,nang);

    else if (st=="otimiza1") LeNum(cfg,otimiza1);
    else if (st=="t1")       LeNum(cfg,t1);
    else if (st=="qtd_cand_1f")  LeNum(cfg,qtd_cand_1f);
    else if (st=="pct_cand_1f")  LeNum(cfg,pct_cand_1f);
    else if (st=="dist_pixel_1f")  LeNum(cfg,dist_pixel_1f);

    else if (st=="otimiza2") LeNum(cfg,otimiza2);
    else if (st=="t2")       LeNum(cfg,t2);
    else if (st=="qtd_cand_2f")  LeNum(cfg,qtd_cand_2f);
    else if (st=="pct_cand_2f")  LeNum(cfg,pct_cand_2f);
    else if (st=="dist_pixel_2f")  LeNum(cfg,dist_pixel_2f);

    else if (st=="otimiza3") LeNum(cfg,otimiza3);
    else if (st=="t3")       LeNum(cfg,t3);
    else if (st=="qtd_cand_3f")  LeNum(cfg,qtd_cand_3f);
    else if (st=="dist_pixel_3f")  LeNum(cfg,dist_pixel_3f);
    else if (st=="ssalpha")  LeNum(cfg,ssalpha);
    else if (st=="ssbeta")   LeNum(cfg,ssbeta);
    else if (st=="ssgama")   LeNum(cfg,ssgama);

    else if (st=="absoluto") LeNum(cfg,absoluto);

    else if (st=="ncirc")    LeNum(cfg,ncirc);
    else if (st=="rinic")    LeNum(cfg,rinic);
    else if (st=="rfim")     LeNum(cfg,rfim);

    else if (st=="tol")      LeNum(cfg,tol);

    else if (st=="analyze")  analyze=LeFileName(cfg);
    else if (st=="query")    query=LeFileName(cfg);

    else if (st=="gauss_exec") LeNum(cfg,gauss_exec);
    else if (st=="gaussa")     gaussa=LeFileName(cfg);
    else if (st=="gaussq")     gaussq=LeFileName(cfg);
    else if (st=="actualq")       actualq=LeFileName(cfg);

    else if (st=="cissa_exec")    LeNum(cfg,cissa_exec);
    else if (st=="cissa_out")     cissa_out=LeFileName(cfg);
    else if (st=="cissa_verbose") cissa_verbose=LeFileName(cfg);

    else if (st=="cissq_exec")    LeNum(cfg,cissq_exec);
    else if (st=="cissq_out")     cissq_out=LeFileName(cfg);
    else if (st=="cissq_verbose") cissq_verbose=LeFileName(cfg);

    else if (st=="cifi_exec")     LeNum(cfg,cifi_exec);
    else if (st=="cifi_param")    cifi_param=LeFileName(cfg);
    else if (st=="cifi_match")    cifi_match=LeFileName(cfg);

    else if (st=="rassq_exec")    LeNum(cfg,rassq_exec);
    else if (st=="rassq_out")     rassq_out=LeFileName(cfg);
    else if (st=="rassq_verbose") rassq_verbose=LeFileName(cfg);

    else if (st=="rafi_exec")     LeNum(cfg,rafi_exec);
    else if (st=="rafi_param")    rafi_param=LeFileName(cfg);
    else if (st=="rafi_match")    rafi_match=LeFileName(cfg);

    else if (st=="tefi_exec")     LeNum(cfg,tefi_exec);
    else if (st=="tefi_param")    tefi_param=LeFileName(cfg);
    else if (st=="tefi_match")    tefi_match=LeFileName(cfg);
    else if (st=="tefi_verbose")  tefi_verbose=LeFileName(cfg);

    else if (st=="circ_exec")     LeNum(cfg,circ_exec);
    else if (st=="circ_out")      circ_out=LeFileName(cfg);
    else if (st=="circ_modo")     circ_modo=LeStr(cfg);

    else if (st=="txt_exec")     LeNum(cfg,txt_exec);
    else if (st=="txt_out")      txt_out=LeFileName(cfg);

    else erro("Error: Unknown token ",st.c_str());
    st=LeStr(cfg);
  }
  fclose(cfg);
}

void verifyparam()
{
  if (adesv<0.0) erro("Error: adesv<0.0");
  if (qdesv<0.0) erro("Error: qdesv<0.0");

  if (nesc<=0) erro("Error: nesc<=0");
  if (escinic<0.0) erro("Error: escinic<0.0");
  if (escfim<escinic) erro("Error: escfim<escinic");
  //if (nesc>1) desc=(escfim-escinic)/(nesc-1); else desc=0.0;
  if (nesc>1) passoesc=exp(log(escfim/escinic)/nesc); else passoesc=1.0;

  if (nang<=1) erro("Error: nang<=1");
  dangdeg=360.0/nang;
  dangrad=deg2rad(dangdeg);

  if (otimiza1) {
    if (qtd_cand_1f==maxint) erro("Error: qtd_cand_1f");
    if (dist_pixel_1f==infinito || dist_pixel_1f<0) erro("Error: dist_pixel_1f");
  } else {
    if (t1<0.0 || 1.0<t1) erro("Error: t1 out of range");
  }

  if (otimiza2) {
    if (qtd_cand_2f==maxint) erro("Error: qtd_cand_2f");
    if (dist_pixel_2f==infinito || dist_pixel_2f<0) erro("Error: dist_pixel_2f");
  } else {
    if (t2<0.0 || 1.0<t2) erro("Error: t2 out of range");
  }

  if (otimiza3) {
    if (qtd_cand_3f==maxint) erro("Error: qtd_cand_3f");
    if (dist_pixel_3f==infinito || dist_pixel_3f<0) erro("Error: dist_pixel_3f");
  } else {
    if (t3<0.0 || 1.0<t3) erro("Error: t3 out of range");
  }

  if (ssalpha<0.0) erro("Error: ssalpha out of range");
  if (ssbeta<0.0) erro("Error: ssbeta out of range");
  if (ssgama<0.0) erro("Error: ssgama out of range");

  if (ncirc<=0) erro("Error: ncirc<=0");
  if (rinic<0.0) erro("Error: rinic<0.0");
  //if (rfim<rinic) erro("Error: rfim<rinic");
  if (ncirc>1) dcirc=(rfim-rinic)/(ncirc-1); else dcirc=0.0;

  if (tol<0) erro("Error: tol<0");

  if (analyze=="") erro("Error: analyze without name");
  if (query=="") erro("Error: query without name");

  if (gaussa=="") erro("Error: gaussa without name");
  if (gaussq=="") erro("Error: gaussq without name");

  if (cissa_out=="") erro("Error: cissa_out without name");
  //cout << "cissa_out " << cissa_out << endl;
  if (cissa_verbose=="") erro("Error: cissa_verbose without name");

  if (cissq_out=="") erro("Error: cissq_out without name");
  if (cissq_verbose=="") erro("Error: cissq_verbose without name");

  if (cifi_param=="") erro("Error: cifi_param without name");
  if (cifi_match=="") erro("Error: cifi_match without name");

  if (rassq_out=="") erro("Error: rassq_out without name");
  if (rassq_verbose=="") erro("Error: rassq_verbose without name");

  if (rafi_param=="") erro("Error: rafi_param without name");
  if (rafi_match=="") erro("Error: rafi_match without name");

  if (tefi_param=="") erro("Error: tefi_param without name");
  if (tefi_match=="") erro("Error: tefi_match without name");
  if (tefi_verbose=="") erro("Error: tefi_verbose without name");

  if (circ_out=="") erro("Error: circ_out without name");
  if (circ_modo!="c" && circ_modo!="l") erro("Error: invalid circ_modo (must be c or l)");

  if (txt_out=="") erro("Error: txt_out without name");
}

IMGGRY pintapreto(IMGGRY a)
{ IMGGRY d=a;
  int raio=d.nl()/2;
  for (int x=d.minx(); x<=d.maxx(); x++)
    for (int y=d.miny(); y<=d.maxy(); y++) {
      if (d.atC(x,y)==0) d.atC(x,y)=1;
      if (arredonda(sqrt(double(elev2(x)+elev2(y))))>arredonda(sqrt(double(elev2(raio))))) {
        d.atC(x,y)=0;
      }
    }
  return d;
}

double scale(int s)
{ return escinic*pow(passoesc,s); }

void autoparam()
{ if (rfim<rinic) rfim=scale(nesc-1)*(qu.nl()/2);
  rqunit=qu.nl()/2;
  if (ncirc>1) dcirc=(rfim-rinic)/(ncirc-1); else dcirc=0.0;
  if (qtd_cand_1f<=0) qtd_cand_1f=arredonda(an.n()*pct_cand_1f/100.0);
  if (qtd_cand_2f<=0) qtd_cand_2f=arredonda(an.n()*pct_cand_2f/100.0);
}

void pintabordabranca(IMGCOR& cp)
{ int raio=teto(scale(0)*gq.nl())/2;
  for (unsigned i=0; i<v.size(); i++) {
    for (int l=v[i].l1; l<=v[i].l2; l++) {
      for (int c=v[i].c1; c<=min(v[i].c1+raio,v[i].c2); c++) cp(l,c)=COR(255,255,255);
      for (int c=v[i].c2; c>=max(v[i].c2-raio,v[i].c1); c--) cp(l,c)=COR(255,255,255);
    }
    for (int c=v[i].c1; c<=v[i].c2; c++) {
      for (int l=v[i].l1; l<=min(v[i].l1+raio,v[i].l2); l++) cp(l,c)=COR(255,255,255);
      for (int l=v[i].l2; l>=max(v[i].l2-raio,v[i].l1); l--) cp(l,c)=COR(255,255,255);
    }
  }
}

void pintabordazero(IMGFLT& f)
{ int raio=teto(scale(0)*gq.nl())/2;
  for (unsigned i=0; i<v.size(); i++) {
    for (int l=v[i].l1; l<=v[i].l2; l++) {
      for (int c=v[i].c1; c<=min(v[i].c1+raio,v[i].c2); c++) f(l,c)=0.0;
      for (int c=v[i].c2; c>=max(v[i].c2-raio,v[i].c1); c--) f(l,c)=0.0;
    }
    for (int c=v[i].c1; c<=v[i].c2; c++) {
      for (int l=v[i].l1; l<=min(v[i].l1+raio,v[i].l2); l++) f(l,c)=0.0;
      for (int l=v[i].l2; l>=max(v[i].l2-raio,v[i].l1); l--) f(l,c)=0.0;
    }
  }
}

//<<<<<<<<<<<<<<<<<<<< Gauss <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void gauss()
{ fprintf(stderr,"<<Gauss>>\n");
  if (adesv>0.0) ga=ConvGaussHV(IMGFLT(an),adesv); else ga=an;
  if (gaussa!="nul") imp(ga,gaussa);
  if (qdesv>0.0) gq=ConvGaussHV(IMGFLT(qu),qdesv); else gq=qu;
  if (gaussq!="nul") imp(gq,gaussq);
  if (actualq!="" && actualq!="nul") {
    IMGGRY qupintado=pintapreto(qu);
    imp(qupintado,actualq);
  }
}

//<<<<<<<<<<<<<<<<<<<< CissA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
BYTE csample(IMGGRY& a, int l, int c, int r)
{ int l2=0; int c2=r; int soma=0; int conta=0;
  while (c2>0) {

    soma=soma+a.atx(l+l2,c+c2)+a.atx(l-l2,c-c2)+a.atx(l+c2,c-l2)+a.atx(l-c2,c+l2);
    conta=conta+4;

    int mh=abs(elev2(l2+1)+elev2(c2)-elev2(r));
    int md=abs(elev2(l2+1)+elev2(c2-1)-elev2(r));
    int mv=abs(elev2(l2)+elev2(c2-1)-elev2(r));
    int m=min3(mh,md,mv);
    if (m==mh) l2++;
    else if (m==md) { l2++; c2--; }
    else c2--;
  }
  if (conta>0) return int2G((soma+conta/2)/conta);
  else return a.atx(l,c);
}

void cissa()
{ fprintf(stderr,"<<Circular projections of A>>\n");
  ga.backg()=255;
  I3DGRY b(ncirc,ga.nl(),ga.nc());
  for (int s=b.ns()-1; s>=0; s--) {
    fprintf(stderr,"Processing slice %-5d\r",s);

    int raio=arredonda(dcirc*s+rinic);
    for (int l=0; l<ga.nl(); l++)
      for (int c=0; c<ga.nc(); c++) {
        b(s,l,c)=csample(ga,l,c,raio);
      }
  }
  fprintf(stderr,"\n");
  imp(b,cissa_out);

  if (cissa_verbose!="nul") {
    IMGCOR _ca=an;
    for (int s=b.ns()-1; s>=0; s--) {
      int raio=arredonda(dcirc*s+rinic);
      circulo(_ca,_ca.lc(),_ca.cc(),raio,COR(255,0,0));
    }
    imp(_ca,cissa_verbose);
  }
}

//<<<<<<<<<<<<<<<<<<<< CissQ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
IMGGRY quadradaimpar(IMGGRY ei)
{ int minn=min(ei.nl(),ei.nc());
  if (minn%2==0) minn--;
  IMGGRY e(minn,minn); e.backg()=255;
  for (int x=e.minx(); x<=e.maxx(); x++)
    for (int y=e.miny(); y<=e.maxy(); y++)
      e.atX(x,y)=ei.atX(x,y);
  return e;
}

void cissq()
{ fprintf(stderr,"<<Circular projections of Q>>\n");

  IMGDBL m(nesc,ncirc,0.0);
  for (int f=0; f<nesc; f++) {
    //double escala=f*desc+escinic;
    double escala=scale(f);

    int n=teto(escala*gq.nl());
    IMGGRY t(n,n); t.backg()=gq.backg();
    zoomfat(gq, t, escala, escala);
    int ncirc2=min(chao(escala/scale(nesc-1)*ncirc),ncirc); // Consertei! 13/08/2010
    for (int c=0; c<ncirc2; c++) m(f,c)=G2D(csample(t,t.lc(),t.cc(),arredonda(c*dcirc+rinic)));
    for (int c=ncirc2; c<ncirc; c++) m(f,c)=1.0;

    if (cissq_verbose!="nul") {
      string formato=cissq_verbose+"%02d.tga";
      char st[256];
      sprintf(st,formato.c_str(),f);
      IMGCOR b=t;
      for (int c=0; c<ncirc2; c++) {
        int raio=arredonda(c*dcirc+rinic);
        circulo(b,b.lc(),b.cc(),raio,COR(255,0,0));
      }
      imp(b,st);
    }
  }
  imp(m,cissq_out);
}

//<<<<<<<<<<<<<<<<<<<< Cifi <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void cissmatch(I3DGRY& a, int l, int c, VETOR<double>& X, double mX, double& coef)
{ VETOR<double> Y(X.n());
  for (int k=0; k<Y.n(); k++) Y(k)=a(k,l,c);

  //coefcorr(Y,X,thbeta,coef,beta,gama);

  double mY=dcrejectcommedia(Y);
  double x2=X*X;
  double y2=Y*Y;
  coef=ssimgry(Y,y2,mY,X,x2,mX,ssalpha,ssbeta,ssgama); 
}

void cifi()
{ fprintf(stderr,"<<Cifi>>\n");
  I3DGRY a; le(a,cissa_out);
  IMGDBL q; le(q,cissq_out);
  if (a.ns()<q.nc()) erro("Error: #analyze.avi slices < #query.mat columns");

  VETOR< VETOR<double> > qm(q.nl());
  VETOR<double> mqm(q.nl());
  for (int l=0; l<q.nl(); l++) {
    int nc=q.nc()-1;
    while (q(l,nc)==1.0 && 0<=nc) nc--;
    nc++;
    if (nc<3) erro("Error: Query.mat has a row with less than 3 columns");
    qm(l).resize(nc);
    for (int c=0; c<nc; c++) qm(l)(c)=255.0*q(l,c);
    mqm(l)=dcrejectcommedia(qm(l));
  }

  IMGCOR cm=anori;
  IMGCOR cp=anori;
  if (!otimiza1) {
    for (int l=0; l<a.nl(); l++) {
      if (l%10==0 || l==a.nl()-1) fprintf(stderr,"Processing row %5d/%d\r",l,a.nl());
      for (int c=0; c<a.nc(); c++) {
        if (anori(l,c)<255) {
          double maxcoef=-infinito;
          int maxesc=0;
          for (int e=0; e<qm.n(); e++) {
            double coef;
            cissmatch(a,l,c,qm(e),mqm(e),coef);
            if (absoluto) coef=abs(coef);
            if (coef>maxcoef) {
              maxcoef=coef;
              maxesc=e;
            }
            if (maxcoef>t1) {
              cp(l,c).r()=255;
              cp(l,c).g()=maxesc;
              cp(l,c).b()=double2G(255.0*maxcoef);
              cm(l,c).r()=255;
              cm(l,c).g()=maxesc;
              cm(l,c).b()=double2G(255.0*maxcoef);
            }
          }
        }
      }
    }
    fprintf(stderr,"\n");
    pintabordabranca(cp);
  } else {
    IMGCOR cpo=cp;
    IMGCOR cmo=cm;
    IMGFLT co(an.nl(),an.nc(),0.0);
    for (int l=0; l<a.nl(); l++) {
      if (l%10==0 || l==a.nl()-1) fprintf(stderr,"Processing row %5d/%d\r",l,a.nl());
      for (int c=0; c<a.nc(); c++) {
        if (anori(l,c)<255) {
          double maxcoef=-infinito;
          int maxesc=0;
          for (int e=0; e<qm.n(); e++) {
            double coef;
            cissmatch(a,l,c,qm(e),mqm(e),coef);
            if (absoluto) coef=abs(coef);
            if (coef>maxcoef) {
              maxcoef=coef;
              maxesc=e;
            }
            co(l,c)=maxcoef;
            cpo(l,c).r()=255;
            cpo(l,c).g()=maxesc;
            cpo(l,c).b()=double2G(255.0*maxcoef);
            cmo(l,c).r()=255;
            cmo(l,c).g()=maxesc;
            cmo(l,c).b()=double2G(255.0*maxcoef);
          }
        }
      }
    }
    fprintf(stderr,"\n");
    pintabordazero(co);
    vector<PONTOI2> v=kmax(co,qtd_cand_1f,dist_pixel_1f);
    for (unsigned i=0; i<v.size(); i++) {
      int l=v[i].l(); int c=v[i].c();
      cp(l,c)=cpo(l,c);
      cm(l,c)=cmo(l,c);
    }
    pintabordabranca(cp);
  }
  imp(cp,cifi_param);
  imp(cm,cifi_match);
}

//<<<<<<<<<<<<<<<<<<<< RassQ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
BYTE rsample(IMGGRY& g, int l, int c, double ang, double rfim2)
{ int soma=0; int conta=0;
  int x,y,dx,dy,a,err,dx2,dy2,sobe;
  int x1=c; int x2=c+arredonda(cos(ang)*rfim2);
  int y1=l; int y2=l-arredonda(sin(ang)*rfim2);
  dx=x2-x1; dy=y2-y1;
  if (abs(dx)>=abs(dy)) { // octante 1, 4, 5 ou 8
    if (dx<0) { swap(x1,x2); swap(y1,y2); dx=-dx; dy=-dy; }
    a=abs(2*dy); err=0; dx2=dx*2;
    sobe=sign(dy); y=y1;
    for (x=x1; x<=x2; x++) {
      soma+=g.atx(y,x); conta++; err=err+a;
      if (err>=dx) { y=y+sobe; err=err-dx2; }
    }
  } else {
    if (dy<0) { swap(x1,x2); swap(y1,y2); dx=-dx; dy=-dy; }
    a=abs(2*dx); err=0; dy2=dy*2;
    sobe=sign(dx); x=x1;
    for (y=y1; y<=y2; y++) {
      soma+=g.atx(y,x); conta++; err=err+a;
      if (err>=dy) { x=x+sobe; err=err-dy2; }
    }
  }
  if (conta>0) return int2G((soma+conta/2)/conta);
  else return g.atx(l,c);
}

void rassq()
{ fprintf(stderr,"<<Radial projections of Q>>\n");

  IMGDBL m(1,nang,0.0);
  for (int c=0; c<nang; c++)
    m(0,c)=G2D(rsample(gq,gq.lc(),gq.cc(),dangrad*c,rqunit));
  imp(m,rassq_out);

  if (rassq_verbose!="nul") {
    IMGCOR b=qu;
    for (int c=0; c<nang; c++) {
      reta(b, b.lc(),b.cc(), b.lc()-arredonda(sin(dangrad*c)*rqunit), b.cc()+arredonda(cos(dangrad*c)*rqunit), COR(0,0,255));
    }
    imp(b,rassq_verbose);

    // Acrescentei depois, para imprimir projecoes radiais
    /*
    VETOR<double> f(nang);
    IMGBIN d(240,320,branco);
    for (int c=0; c<nang; c++) {
      f(c)=G2D(rsample(gq,gq.lc(),gq.cc(),dangrad*c,rqunit));
    }
    funcao2imgbin(f,d,preto,true,-infinito,infinito,1.0);
    imp(d,"ras.bmp");
    */
  }
}

//<<<<<<<<<<<<<<<<<<<< Rafi <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void rassmatch(IMGGRY& a, int l, int c, VETOR<double>& X, double mX, double rfim2,
                      double& coef, int& ang)
{ VETOR<double> Y(X.n());
  double passo=2.0*M_PI/X.n();
  for (int s=0; s<Y.n(); s++)
    Y(s)=rsample(a,l,c,s*passo,rfim2);
  double mY=dcrejectcommedia(Y);

  double x2=X*X;
  double y2=Y*Y;
  coef=-infinito; ang=0;
  for (int i=0; i<X.n(); i++) {
    double coef2;
    coef2=ssimgry(Y,y2,mY,X,x2,mX,ssalpha,ssbeta,ssgama); 
    if (absoluto) coef2=abs(coef2);
    if (coef2>coef) {
      coef=coef2; ang=i;
    }
    X=cshift(X,1);
  }
}

void rafi()
{ fprintf(stderr,"<<Rafi>>\n");

  IMGDBL rq; le(rq,rassq_out);
  int nang=rq.n();
  VETOR<double> X(nang);
  for (int k=0; k<X.n(); k++) X(k)=255.0*rq(0,k);
  double mX=dcrejectcommedia(X);

  IMGCOR cp; le(cp,cifi_param);
  if (ga.nl()!=cp.nl() || ga.nc()!=cp.nc()) erro("Error: Different dimensions");

  IMGCOR rp=anori;
  IMGCOR rm=anori;
  if (!otimiza2) {
    for (int l=0; l<ga.nl(); l++) {
      if (l%10==0 || l==ga.nl()-1) fprintf(stderr,"Processing row %5d/%d\r",l,ga.nl());
      for (int c=0; c<ga.nc(); c++) {
        if (cp(l,c).r()==255 && cp(l,c)!=COR(255,255,255)) {
          //double escala=cp(l,c).g()*desc+escinic;
          double escala=scale(cp(l,c).g());
          double coef; int ang;
          rassmatch(ga,l,c,X,mX,rqunit*escala,coef,ang);
          if (coef>t2) {
            rp(l,c).r()=255;
            rp(l,c).g()=cp(l,c).g();
            rp(l,c).b()=ang;
            rm(l,c).g()=double2G(255.0*coef);
          }
        }
      }
    }
    fprintf(stderr,"\n");
    pintabordabranca(rp);
  } else {
    IMGCOR rpo=rp;
    IMGCOR rmo=rm;
    IMGFLT ro(an.nl(),an.nc(),0.0);
    for (int l=0; l<ga.nl(); l++) {
      if (l%10==0 || l==ga.nl()-1) fprintf(stderr,"Processing row %5d/%d\r",l,ga.nl());
      for (int c=0; c<ga.nc(); c++) {
        if (cp(l,c).r()==255 && cp(l,c)!=COR(255,255,255)) {
          //double escala=cp(l,c).g()*desc+escinic;
          double escala=scale(cp(l,c).g());
          double coef; int ang;
          rassmatch(ga,l,c,X,mX,rqunit*escala,coef,ang);
          ro(l,c)=coef;
          rpo(l,c).r()=255;
          rpo(l,c).g()=cp(l,c).g();
          rpo(l,c).b()=ang;
          rmo(l,c).g()=double2G(255.0*coef);
        }
      }
    }
    fprintf(stderr,"\n");  
    pintabordazero(ro);
    vector<PONTOI2> v=kmax(ro,qtd_cand_2f,dist_pixel_2f);
    for (unsigned i=0; i<v.size(); i++) {
      int l=v[i].l(); int c=v[i].c();
      rp(l,c)=rpo(l,c);
      rm(l,c)=rmo(l,c);
    }
    pintabordabranca(rp);
  }
  imp(rp,rafi_param);
  imp(rm,rafi_match);
}

//<<<<<<<<<<<<<<<<<<<< Tefi <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void tefimatch(IMGGRY& a, int ax, int ay, IMGGRY& qm, int naopreto, double& coef)
{ //int conta=0;
  //for (int x=qm.minx(); x<=qm.maxx(); x++)
  //  for (int y=qm.miny(); y<=qm.maxy(); y++)
  //    if (qm.atX(x,y)>0) conta++;
  //if (conta!=naopreto) erro("Erro: conta!=naopreto");

  VETOR<double> Y(naopreto);
  VETOR<double> X(naopreto);
  int i=0;
  for (int x=qm.minx(); x<=qm.maxx(); x++)
    for (int y=qm.miny(); y<=qm.maxy(); y++)
      if (qm.atX(x,y)>0) {
        Y(i)=a.atX(ax+x,ay+y);
        X(i)=qm.atX(x,y);
        i++;
      }
  double mX=dcrejectcommedia(X);
  double mY=dcrejectcommedia(Y);
  double x2=X*X;
  double y2=Y*Y;
  coef=ssimgry(Y,y2,mY,X,x2,mX,ssalpha,ssbeta,ssgama); 
}

void tefi()
{ fprintf(stderr,"<<Tefi>>\n");
  IMGCOR mas; le(mas,rafi_param);

  MATRIZ<IMGGRY> qm(nesc,nang);
  MATRIZ<int> naopreto(nesc,nang);
  for (int l=0; l<nesc; l++) {
    for (int c=0; c<nang; c++) {
      //double escala=l*desc+escinic;
      double escala=scale(l);
      double angulo=c*dangdeg;
      int n=arredonda(escala*gq.nl());
      qm(l,c).resize(n,n);
      rotzoom(gq, qm(l,c), angulo, escala, 'X');
    }
  }

  // Enche de preto pixels fora do dominio.
  for (int l=0; l<nesc; l++)
    for (int c=0; c<nang; c++) {
      int raio=arredonda(rqunit*scale(l));
      naopreto(l,c)=qm(l,c).n();
      for (int x=qm(l,c).minx(); x<=qm(l,c).maxx(); x++)
        for (int y=qm(l,c).miny(); y<=qm(l,c).maxy(); y++) {
          if (qm(l,c).atC(x,y)==0) qm(l,c).atC(x,y)=1;
          if (arredonda(sqrt(double(elev2(x)+elev2(y))))>arredonda(sqrt(double(elev2(raio))))) {
            qm(l,c).atC(x,y)=0;
            naopreto(l,c)--;
          }
        }
    }

  if (tefi_verbose!="nul") {
    string formato=tefi_verbose+"%02d%02d.tga";
    for (int l=0; l<nesc; l++)
      for (int c=0; c<nang; c++) {
        char st[256];
        sprintf(st,formato.c_str(),l,c);
        imp(qm(l,c),st);
      }
  }

  IMGCOR tp=anori; 
  IMGCOR tm=anori;
  if (!otimiza3) {
    for (int ax=ga.minx(); ax<=ga.maxx(); ax++) {
      if (modulo(ax,10)==0 || ax==ga.maxx()) fprintf(stderr,"Processing column %5d/%d\r",ax,ga.maxx());
      for (int ay=ga.miny(); ay<=ga.maxy(); ay++) {
        if (mas.atC(ax,ay).r()==255 && mas.atC(ax,ay)!=COR(255,255,255)) {
  
          double maxcoef=-infinito;
          int inil=mas.atC(ax,ay).g()-tol; if (inil<0) inil=0;
          int fiml=mas.atC(ax,ay).g()+tol; if (fiml>=nesc) fiml=nesc-1;
          int inic=mas.atC(ax,ay).b()-tol;
          int fimc=mas.atC(ax,ay).b()+tol;
          //printf("inil=%d fiml=%d inic=%d fimc=%d\n",inil,fiml,inic,fimc);
          int minl=0,minc=0;
          for (int l=inil; l<=fiml; l++)
            for (int c=inic; c<=fimc; c++) {
              int c2=modulo(c,nang);
              double coef;
              tefimatch(ga,ax,ay,qm(l,c2),naopreto(l,c2),coef);
              if (absoluto) coef=abs(coef);
              if (coef>maxcoef) {
                maxcoef=coef;
                minl=l;
                minc=c2;
              }
            }
          if (maxcoef>t3) {
            tp.atC(ax,ay).r()=255;
            tp.atC(ax,ay).g()=minl;
            tp.atC(ax,ay).b()=minc;
            tm.atC(ax,ay).g()=double2G(255.0*maxcoef);
          }
        }
      }
    }
    fprintf(stderr,"\n");
    pintabordabranca(tp);
  } else {
    IMGCOR tpo=tp;
    IMGCOR tmo=tm;
    IMGFLT to(an.nl(),an.nc(),0.0);
    for (int ax=ga.minx(); ax<=ga.maxx(); ax++) {
      if (modulo(ax,10)==0 || ax==ga.maxx()) fprintf(stderr,"Processing column %5d/%d\r",ax,ga.maxx());
      for (int ay=ga.miny(); ay<=ga.maxy(); ay++) {
        if (mas.atC(ax,ay).r()==255 && mas.atC(ax,ay)!=COR(255,255,255)) {
          double maxcoef=-infinito;
          int inil=mas.atC(ax,ay).g()-tol; if (inil<0) inil=0;
          int fiml=mas.atC(ax,ay).g()+tol; if (fiml>=nesc) fiml=nesc-1;
          int inic=mas.atC(ax,ay).b()-tol;
          int fimc=mas.atC(ax,ay).b()+tol;
          //printf("inil=%d fiml=%d inic=%d fimc=%d\n",inil,fiml,inic,fimc);
          int minl=0,minc=0;
          for (int l=inil; l<=fiml; l++)
            for (int c=inic; c<=fimc; c++) {
              int c2=modulo(c,nang);
              double coef;
              tefimatch(ga,ax,ay,qm(l,c2),naopreto(l,c2),coef);
              if (absoluto) coef=abs(coef);
              if (coef>maxcoef) {
                maxcoef=coef;
                minl=l;
                minc=c2;
              }
            }
          //printf("maxcoef=%f\n",maxcoef);
          to.atC(ax,ay)=maxcoef;
          tpo.atC(ax,ay).r()=255;
          tpo.atC(ax,ay).g()=minl;
          tpo.atC(ax,ay).b()=minc;
          tmo.atC(ax,ay).g()=double2G(255.0*maxcoef);
        }
      }
    }
    fprintf(stderr,"\n");
    pintabordazero(to);
    vector<PONTOI2> v=kmax(to,qtd_cand_3f,dist_pixel_3f);
    //printf("v.size=%d l=%d c=%d\n",v.size(),v[0].l(),v[0].c());
    for (unsigned i=0; i<v.size(); i++) {
      int l=v[i].l(); int c=v[i].c();
      tp(l,c)=tpo(l,c);
      tm(l,c)=tmo(l,c);
    }
    pintabordabranca(tp);
  }
  imp(tp,tefi_param);
  imp(tm,tefi_match);
}

//<<<<<<<<<<<<<<<<<<<< Circ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void circ()
{ fprintf(stderr,"<<Drawing circles with pointers>>\n");

  IMGCOR tp; le(tp,tefi_param);
  IMGCOR ci=anori;
  for (int l=0; l<tp.nl(); l++)
    for (int c=0; c<tp.nc(); c++) {
      COR cor=tp(l,c);
      if (cor.r()==255 && cor!=COR(255,255,255)) {
        int lj,cj,sj; bool dentro;
        p2i(v, l, c, lj, cj, sj, dentro);
        if (!dentro) continue;

        int iesc=cor.g();
        int iang=cor.b();
        int raiop=arredonda(rqunit*scale(iesc));
        int raioi=arredonda(pow(2.0,sj)*rqunit*scale(iesc));
        double angrad=iang*dangrad;

        if (circ_modo=="c") {
          circulo(ci,l,c,raiop,COR(255,0,0),2);
          reta(ci,l,c,l-arredonda(raiop*sin(angrad+M_PI_2)),c+arredonda(raiop*cos(angrad+M_PI_2)),COR(255,0,0),2);
          if (sj>0) {
            circulo(ci,lj,cj,raioi,COR(0,255,0),2);
            reta(ci,lj,cj,lj-arredonda(raioi*sin(angrad+M_PI_2)),cj+arredonda(raioi*cos(angrad+M_PI_2)),COR(0,255,0),2);
          }
        } else if (circ_modo=="l") {
          circulo(ci,l,c,raiop,COR(255,0,0),2);
          reta(ci,l,c,l-arredonda(raiop*sin(angrad+M_PI_2)),c+arredonda(raiop*cos(angrad+M_PI_2)),COR(255,0,0),2);
          if (sj>0) {
            circulo(ci,lj,cj,raioi,COR(0,255,0),2);
            reta(ci,lj,cj,lj-arredonda(raioi*sin(angrad+M_PI_2)),cj+arredonda(raioi*cos(angrad+M_PI_2)),COR(0,255,0),2);
          }
          puttxt(ci,lj,cj,semsufixo(query),COR(0,0,255));
        } else erro("Error: Unexpected");
      }
    }
  imp(ci,circ_out);
}

void txt()
{ fprintf(stderr,"<<Writing text file>>\n");
  if (txt_out=="nul") return;
  FILE* arq=fopen(txt_out.c_str(),"wt");
  fprintf(arq,"%6s %6s %6s %6s %6s %6s %6s %6s %6s\n",
              "row","col","scale","angDeg","simil","rowPyr","colPyr","scaleP","floorP");

  IMGCOR tp; le(tp,tefi_param);
  IMGCOR tm; le(tm,tefi_match);

  for (int l=0; l<tp.nl(); l++)
    for (int c=0; c<tp.nc(); c++) {
      COR cor=tp(l,c);
      if (cor.r()==255 && cor!=COR(255,255,255)) {
        COR ssim=tm(l,c);
        int lj,cj,sj; bool dentro;
        p2i(v, l, c, lj, cj, sj, dentro);
        if (!dentro) continue;

        int iesc=cor.g();
        int iang=cor.b();
        double scalep=scale(iesc);
        double scalei=pow(2.0,sj)*scale(iesc);
        double angrad=iang*dangrad;

        //          "row col scale angde simil rowp colp radip floor\n"
        fprintf(arq,"%6d %6d %6.1f %6.1f %6.3f %6d %6d %6.1f %6d\n",
                    lj,cj,scalei,rad2deg(angrad),ssim.g()/255.0,l,c,scalep,sj);
      }
    }
  fclose(arq);
}

}

//<<<<<<<<<<<<<<<<<<<< CirateG3 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main(int argc, char** argv)
{ using namespace CirateG;
  if (argc!=2 && argc!=5) {
    printf("CirateGS: Piramidal ciratefi for grayscale images v1.05\n");
    printf("CirateGS cirategs.cfg [a.pgm q.pgm ci.ppm]\n");
    printf("  If [a.pgm q.pgm ci.pgm] are specified, overrides cirategs.cfg\n");
    erro("Error: Invalid number of arguments");
  }

  int tempo1=centseg();

  setparam(argv[1]);

  if (argc==5) {
    analyze=argv[2];
    query=argv[3];
    circ_out=argv[4];
  }
  verifyparam();
  { IMGCOR ancor; 
    le(ancor,analyze);
    converte(ancor,anori); 
  }
  piramide(anori,anori,v); // acrescentado
  an=anori;

  { IMGCOR qucor; 
    le(qucor,query);
    converte(qucor,qu); 
  }
  qu=quadradaimpar(qu);
  autoparam();

  if (gauss_exec) gauss(); else { le(ga,gaussa); le(gq,gaussq); }
  if (cissa_exec) cissa();
  if (cissq_exec) cissq();
  if (cifi_exec)  cifi();
  if (rassq_exec) rassq();
  if (rafi_exec)  rafi();
  if (tefi_exec)  tefi();
  if (circ_exec)  circ();
  if (txt_exec)   txt();

  tempo1=centseg()-tempo1;
  printf("Processing time: %d.%02d seconds\n",tempo1/100,tempo1%100);
}

