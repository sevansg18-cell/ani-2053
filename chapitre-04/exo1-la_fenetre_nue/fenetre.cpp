#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"

class Fenetre : public nkentseu::renderer::NkCanvasApp
{
public:
    Fenetre()
    {
        Config().title = "Fenetre nue";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = nkentseu::renderer::NkColor2D{18, 18, 24, 255};
    }
};

int nkmain(const nkentseu::NkEntryState &state)
{
    return nkentseu::renderer::NkCanvasApp::Run<Fenetre>(state);
}
