#include "NKLogger/NkSink.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkTime.h"
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

#include "NKEvent/NkKeyboardEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "Ma fenetre";
   
    cfg.width = 1280;
    cfg.height = 720;
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;

    NkWindow window(cfg);
    bool documentModifie = false;
    auto mettreAJourTitre = [&]() {
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

    logger.Info(
        "Window: {}x{} | Display: {}x{} | DPI Scale: {}",
        size.x, size.y,
        displaySize.x, displaySize.y,
        scale);

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
        }
      
    }
    return 0;
}    
