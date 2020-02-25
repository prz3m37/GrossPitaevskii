#include "GrossPitaevski.h"
#include <complex.h>
typedef std::complex<double> cdoub;


void GrossPitaevski::applySafeWindow(cdoub PsiC[], cdoub PsiX[])
{
    int xsize;
    int ysize;
    int sx;
    int xmin;
    int wb; 
#pragma omp parallel for schedule(static)
    for (int i = 0; i < xsize; ++i) {
        const double x = i * sx + xmin;
        const double cx = exp(-pow(x / wb, 20));
        for (int j = 0; j < ysize; ++j) {
            const int q = i * ysize + j;
            PsiC[q] *= cx;
            PsiX[q] *= cx;
        }
    }
}

cdoub GrossPitaevski::F(double x, double t)
{
    double Fp;
    double deltaomega;
    double kp;
    double w;
    cdoub F = Fp * exp(i * (kp * x - deltaomega * t))
        * exp(-utils.rsquare(x) / (2 * utils.rsquare(w)));
    return F;
}

cdoub *GrossPitaevski::getPsiCSubstep(cdoub PsiC[], cdoub PsiX[], double t)
{
    int xsize;
    int ysize;
    double OmegaR;
    double mc;
    double mConstX;
    double mConstY;
    double GammaC;
    double hbar;

    cdoub *GPEquation = new cdoub[xsize * ysize];
    #pragma omp parallel for schedule(static)
    for (int x=0; x < xsize; x++)
    {
        for (int y=0; y < ysize; y++)
        {
            const int q = x * ysize + y;
            const cdoub PsiCxm1 = x > 0 ? PsiC[(x - 1) * ysize + y] : 0;
            const cdoub PsiCxp1 = (x < xsize - 1) ? PsiC[(x + 1) * ysize + y] : 0;
            const cdoub PsiCym1 = (y > 0) ? PsiC[q - 1] : PsiC[x * ysize + ysize - 1];
            const cdoub PsiCyp1 = y < ysize - 1 ? PsiC[q + 1] : PsiC[x * ysize];

            GPEquation[q] = 
            (-i * F(x,t) -i * OmegaR / hbar * PsiX[q] 
                    + (i * hbar / (2 * mc) / utils.rsquare(mConstX) 
                    * (PsiCxm1 - 2.0 * PsiC[q] + PsiCxp1))
                    + (i * hbar / (2 * mc) / utils.rsquare(mConstY)
                    * (PsiCym1 - 2.0 * PsiC[q] + PsiCyp1)) - (GammaC / 2 * PsiC[q]));
        }
    }
    return GPEquation;
}

cdoub *GrossPitaevski::getPsiXSubstep(cdoub PsiC[], cdoub PsiX[], double t)
{
    int xsize;
    int ysize;
    double OmegaR; // for now 
    double hbar;
    double g;
    double GammaX;

    cdoub *GPEquation = new cdoub[xsize * ysize];
    #pragma omp parallel for schedule(static)
    for (int x=0; x<xsize; x++)
    {
        for(int y; y< ysize; y++)
        {
            const int q = x * ysize + y;
            GPEquation[q] = (-i * OmegaR / hbar * PsiC[q]
                    - (GammaX / 2 * PsiX[q])
                    - (i * g / hbar * utils.csquare(abs(PsiX[q])) * PsiX[q]));
        }
    }
    return GPEquation;
}; 

cdoub *GrossPitaevski::incerementTimestep(cdoub PsiC[], cdoub PsiX[], double t)
{
    int xsize;
    int ysize;
    cdoub *rungeKuttaComponent = new cdoub[xsize * ysize];
    for (int q = 0; q < (xsize * ysize); q++)
    {
        rungeKuttaComponent[q] = PsiC[q] + PsiC[q] * t;
    }
    return rungeKuttaComponent;
}

void GrossPitaevski::getRungeKutta(cdoub PsiC[], cdoub PsiX[], double t, double dt)
{
    int xsize;
    int ysize;

    cdoub *k1c = getPsiCSubstep(PsiC, PsiX, t);
    cdoub *k1x = getPsiXSubstep(PsiX, PsiC, t);

    cdoub *Psi2C = incerementTimestep(PsiC, k1c, dt * 0.5);
    cdoub *Psi2X = incerementTimestep(PsiX, k1x, dt * 0.5);

    cdoub *k2c = getPsiCSubstep(Psi2C, Psi2X, t + dt * 0.5);
    cdoub *k2x = getPsiXSubstep(Psi2X, Psi2C, t + dt * 0.5);

    cdoub *Psi3C = incerementTimestep(PsiC, k2c, dt * 0.5);
    cdoub *Psi3X = incerementTimestep(PsiX, k2x, dt * 0.5);

    cdoub *k3c = getPsiCSubstep(Psi3C, Psi3X, t + dt * 0.5);
    cdoub *k3x = getPsiXSubstep(Psi3X, Psi3C, t + dt * 0.5);

    cdoub *Psi4C = incerementTimestep(PsiC, k3c, dt);
    cdoub *Psi4X = incerementTimestep(PsiX, k3x, dt);

    cdoub *k4c = getPsiCSubstep(Psi4C, Psi4X, t + dt);
    cdoub *k4x = getPsiXSubstep(Psi4X, Psi4C, t + dt);

#pragma omp parallel for schedule(static)
    for (int q = 0; q < (xsize * ysize); q++)
    {
        PsiC[q] += (k1c[q] + 2.0 * k2c[q] + 2.0 * k3c[q] + k4c[q]) * (dt / 6);
        PsiX[q] += (k1x[q] + 2.0 * k2x[q] + 2.0 * k3x[q] + k4x[q]) * (dt / 6);
    }

    delete[] k1c;
    delete[] k2c; 
    delete[] k3c; 
    delete[] k4c;
    delete[] k1x; 
    delete[] k2x; 
    delete[] k3x; 
    delete[] k4x;
    delete[] Psi2C; 
    delete[] Psi3C; 
    delete[] Psi4C;
    delete[] Psi2X; 
    delete[] Psi3X; 
    delete[] Psi4X;
}
