#include "NKLogger/NkSink.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkTime.h"
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

#include "NKEvent/NkKeyboardEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "Ma fenetre";

    cfg.width = 400;
    cfg.height = 200;
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;

    NkWindow window(cfg);
    bool captureSouris = true;
    bool documentModifie = false;

    auto mettreAJourTitre = [&]()
    {
        auto taille = window.GetSize();

        NkString titre = cfg.title;

        if (documentModifie)
            titre += "*";

        titre += " - ";
        titre += NkString::Fmtf("%u x %u", taille.x, taille.y);

        window.SetTitle(titre);
    };

    mettreAJourTitre();

    auto size = window.GetSize();
    auto displaySize = window.GetDisplaySize();
    float32 scale = window.GetDpiScale();

    logger.Info("=== TEST NkString::Fmt ===");

    logger.Info("w=8 avec 42 : [{}]",
                NkString::Fmt("{0:w=8}", 42));

    logger.Info("w=8 avec 1234567890 : [{}]",
                NkString::Fmt("{0:w=8}", 1234567890));

    logger.Info("alignement > : [{}]",
                NkString::Fmt("{0:w=8 >}", 42));

    logger.Info("alignement < : [{}]",
                NkString::Fmt("{0:w=8 <}", 42));

    logger.Info("alignement ^ : [{}]",
                NkString::Fmt("{0:w=8 ^}", 42));

    logger.Info("precision .3 sur entier : [{}]",
                NkString::Fmt("{0:.3}", 42));

    logger.Info("exemple documentation : [{}]",
                NkString::Fmt("{0:w=8 >} = {1:.3}", 42, 3.14159));

    try
    {
        logger.Info("index inexistant : [{}]",
                    NkString::Fmt("{5:w=8}", 42, 123));
    }
    catch (const std::out_of_range &e)
    {
        logger.Error("index inexistant : {}", e.what());
    }

    if (!window.IsOpen())
    {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    NkString texte = window.GetClipboardText();
    logger.Info("Texte du presse-papiers avant : {}", texte);
    texte = texte.ToUpper();
    window.SetClipboardText(texte);
    logger.Info("Texte remis dans le presse-papiers : {}", texte);
    logger.Info("Image présente : {}", window.HasClipboardImage());
    NkClipboardImage imageTest;
    imageTest.width = 2;
    imageTest.height = 2;
    imageTest.pixels.Resize(16);
    imageTest.pixels[0] = 255;
    imageTest.pixels[1] = 0;
    imageTest.pixels[2] = 0;
    imageTest.pixels[3] = 255;
    bool imageEcrite = window.SetClipboardImage(imageTest); // pour demander a NKWindow de metttre notre image dans le presse papier.
    logger.Info("Image ecrite : {}", imageEcrite);
    NkClipboardImage image;
    bool imageLue = window.GetClipboardImage(image);
    logger.Info("Image lue : {}", imageLue);
    logger.Info("Image : {} x {} | 32 bits par pixel", image.width, image.height);
    for (usize i = 0; i + 3 < image.pixels.Size(); i += 4)
    {
        image.pixels[i] = 255 - image.pixels[i];
        image.pixels[i + 1] = 255 - image.pixels[i + 1];
        image.pixels[i + 2] = 255 - image.pixels[i + 2];
    }
    bool imageRemise = window.SetClipboardImage(image);
    logger.Info("Image remise dans le presse-papiers : {}", imageRemise);
    NkClipboardImage imageFinale;
    bool imageFinaleLue = window.GetClipboardImage(imageFinale);
    logger.Info("Image finale relue : {}", imageFinaleLue);
    while (window.IsOpen())
    {
        math::NkVec2u size = window.GetSize();

        while (window.IsOpen())
        {
            while (NkEvent *e = NkEvents().PollEvent())
            {
                if (e->Is<NkWindowCloseEvent>())
                {
                    window.Close();
                }

                if (e->Is<NkWindowResizeEvent>())
                {
                    mettreAJourTitre();
                }

                if (e->Is<NkKeyPressEvent>())
                {
                    documentModifie = true;
                    mettreAJourTitre();
                }

                if (e->Is<NkMouseMoveEvent>())
                {
                    auto *mouse = e->As<NkMouseMoveEvent>();

                    int x = mouse->GetX();
                    int y = mouse->GetY();

                    // Zone 1 : bande supérieure
                    if (y < 120)
                    {
                        window.SetCursor(NkWindow::NkCursorType::Arrow);
                    }
                    // Zone 2 : bas gauche
                    else if (x < 426 && y < 320)
                    {
                        window.SetCursor(NkWindow::NkCursorType::TextInput);
                    }
                    // Zone 3 : bas centre
                    else if (x < 853 && y < 320)
                    {
                        window.SetCursor(NkWindow::NkCursorType::Hand);
                    }
                    // Zone 4 : bas droite
                    else if (y < 320)
                    {
                        window.SetCursor(NkWindow::NkCursorType::ResizeNS);
                    }
                    // Zone 5
                    else if (x < 426)
                    {
                        window.SetCursor(NkWindow::NkCursorType::ResizeWE);
                    }
                    // Zone 6
                    else if (x < 853)
                    {
                        window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
                    }
                    // Zone 7
                    else
                    {
                        window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
                    }
                }
                if (auto *event = dynamic_cast<NkMouseButtonPressEvent *>(e))
                {
                    if (event->IsLeft())
                    {
                        if (captureSouris)
                        {
                            window.CaptureMouse(true);
                            logger.Info("Capture souris activee");
                        }
                    }
                }

                if (auto *event = dynamic_cast<NkMouseButtonReleaseEvent *>(e))
                {
                    if (event->IsLeft())
                    {
                        if (captureSouris)
                        {
                            window.CaptureMouse(false);
                            logger.Info("Capture souris liberee");
                        }
                    }
                }
            }
        }

    }
    return 0;
}    
