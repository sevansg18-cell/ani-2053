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

    cfg.width = 800;
    cfg.height = 600;
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

    return 0;
}
