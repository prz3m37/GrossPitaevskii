#include "GrossPitaevski.h"
#include <complex.h>

//typedef std::complex<double> cdoub;

std::complex<double>* GrossPitaevski::getPsiCSubstep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t)
{
    int xsize;
    int ysize;
    double OmegaR;
    double mc;
    double mConstX;
    double mConstY;
    double Gammac;
    double hbar;

    std::complex<double> *GPEquation = new std::complex<double>[xsize * ysize];
    for (int x=0; x < xsize; x++)
    {
        for (int y=0; y < ysize; y++)
        {
            const int q= x * ysize + y;
            const std::complex<double> PsiCxm1 = x > 0 ? PsiC[(x - 1) * ysize + y] : 0;
            const std::complex<double> PsiCxp1 = (x < xsize - 1) ? PsiC[(x + 1) * ysize + y] : 0;
            const std::complex<double> PsiCym1 = (y > 0) ? PsiC[q - 1] : PsiC[x * ysize + ysize - 1];
            const std::complex<double> PsiCyp1 = y < ysize - 1 ? PsiC[q + 1] : PsiC[x * ysize];

            GPEquation[q] = 
            (-i * OmegaR / hbar * PsiX[q] + (i * hbar / (2 * mc) / utils.rsqrt(mConstX)
                       * (PsiCxm1 - 2.0 * PsiC[q] + PsiCxp1))
                       + (i * hbar / (2 * mc) / utils.rsqrt(mConstY)
                       * (PsiCym1 - 2.0 * PsiC[q] + PsiCyp1)) - (Gammac / 2 * PsiC[q]));
        }
    }

    return GPEquation;
};


std::complex<double> GrossPitaevski::getRungeKutta()
{
};