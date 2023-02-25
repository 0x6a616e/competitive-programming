#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        long SR, SC, DR, DC, DH, DV, D, aux;

        while (cin >> SR >> SC >> DR >> DC && !(SR == 0 && SC == 0 && DR == 0 && DC == 0)) {
                if (DR > SR) {
                        aux = DR;
                        DR = SR;
                        SR = aux;

                        aux = DC;
                        DC = SC;
                        SC = aux;
                }

                DH = abs(DC - SC);
                DV = abs(DR - SR);

                if (DH >= DV) {
                        D = DH + DV;
                } else {
                        D = DH * 2;
                        DV -= DH;
                        if (DV % 2 == 0) {
                                D += (DV / 2) * 4;
                        } else {
                                SC = DC;
                                SR = DR + DV;
                                if ((SR + SC) % 2 == 0) {
                                        D += ((DV + 1) / 2) * 3 + DV / 2;
                                } else {
                                        D += ((DV) / 2) * 3 + (DV + 1) / 2;
                                }
                        }
                }

                cout << D << '\n';
        }
        
        return 0;
}
