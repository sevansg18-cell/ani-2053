#include "NKImage/Core/NkImage.h"
#include <NKLogger/NkLog.h>
#include <iostream>

int main()
{
    nkentseu::NkLog::Initialize("MesureImages");
    nkentseu::NkImage capture;
    nkentseu::NkImage dessin;
    nkentseu::NkImage icone;
    nkentseu::NkImage photo1;
    nkentseu::NkImage photo2;

    capture.Load("capture.png");
    dessin.Load("dessin.png");
    icone.Load("icone.png");
    photo1.Load("photo1.jpg");
    photo2.Load("photo2.jpg");

    auto calculCapture = capture.Width() * capture.Height() * capture.BytesPP();
    auto calculDessin = dessin.Width() * dessin.Height() * dessin.BytesPP();
    auto calculIcone = icone.Width() * icone.Height() * icone.BytesPP();
    auto calculPhoto1 = photo1.Width() * photo1.Height() * photo1.BytesPP();
    auto calculPhoto2 = photo2.Width() * photo2.Height() * photo2.BytesPP();

    logger.Info("capture.png : {0} x {1}, BytesPP : {2}, calcul : {3}", capture.Width(), capture.Height(),
                capture.BytesPP(), calculCapture);

    std::cout << "Image chargee. Relevez la memoire, puis appuyez sur Entree." << std::endl;
    std::cin.get();
    logger.Info("dessin.png : {0} x {1}, BytesPP : {2}, calcul : {3}", dessin.Width(), dessin.Height(),
                dessin.BytesPP(), calculDessin);
    std::cout << "Image chargee. Relevez la memoire, puis appuyez sur Entree." << std::endl;
    std::cin.get();

    logger.Info("icone.png : {0} x {1}, BytesPP : {2}, calcul : {3}", icone.Width(), icone.Height(), icone.BytesPP(),
                calculIcone);
    std::cout << "Image chargee. Relevez la memoire, puis appuyez sur Entree." << std::endl;
    std::cin.get();

    logger.Info("photo1.jpg : {0} x {1}, BytesPP : {2}, calcul : {3}", photo1.Width(), photo1.Height(),
                photo1.BytesPP(), calculPhoto1);
    std::cout << "Image chargee. Relevez la memoire, puis appuyez sur Entree." << std::endl;
    std::cin.get();

    logger.Info("photo2.jpg : {0} x {1}, BytesPP : {2}, calcul : {3}", photo2.Width(), photo2.Height(),
                photo2.BytesPP(), calculPhoto2);
    std::cout << "Image chargee. Relevez la memoire, puis appuyez sur Entree." << std::endl;
    std::cin.get();
    
    nkentseu::NkLog::Shutdown();

    return 0;
}
