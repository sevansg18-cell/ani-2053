# Fenetre_nue

Pour faire cet exercice J'ai d'abord genere le kit dans un dossier sur mon bureau appele: ***Mon workspace***, avec la commande `jenga kit --target NKWindows --outpout "C:\Users\cloth\OneDrive\Bureau\Mon workspace" --platform windows --config Debug`.

```
___Mon workspace
|
|______include
|      |
|      |____NKContainer
|      |
|      |___.....
|
|
|______lib
|       |
|       |___Debug-Windows
|
|
|______KIT.txt
|
|______Monworkspace
```
puis j'ai cree dans document un dossier ***workspace*** et j'ai cree le dossier FirstWindows qui contient mon projet.

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow

Dans ce dossier nous avons les dossier :
-.jenga
-.jenga-typing
-Build
-Mon workspace
-Window
-.gitignore
-FirstWindow.jenga
-pyrightconfig.json
```
A l'interieur de Window dans le `main.cpp`. J'ai ecrit le plus petit programme:

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKLogger/NkSink.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"

#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```
Et le resultat avec `jenga build` et `jenga run` j'obtiens ***une fentetre***


# Comparaison

Comme mon code en haut le montre j'ai 25 lignes de codes

Le code du chapitre est celui ci dessous et il contient 20 lignes :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

NKENTSEU_DEFINE_APP_DATA([]() {
    NkAppData d{};
    d.appName = "MaFenetre";
    d.appVersion = "1.0.0";
    return d;
}());

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Ma fenetre";
    cfg.width = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    while (window.IsOpen()) {
        // les evenements arrivent ici (chapitre 4)
    }
    return 0;
}
```
Les deux codes sont pratiquement identiques. Les seules lignes qui different sont:

```
#include "NKLogger/NkSink.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"
```
## NB: Mon code est legerement plus long que celui du chapitre.
