# Ouverture des 7 fenetres

Pour cet exercice j'ai d'abord ajoute les 7 droits de l'utilisateur dans mon code:

```
1. droit de redimensionner la fenêtre.
2. droit de déplacer la fenêtre.
3. droit de fermer la fenêtre.
4. droit de minimiser la fenêtre.
5. droit de maximiser la fenêtre.
6. droit de passer en plein écran.
7. droit/comportement modal de la fenêtre, c'est-à-dire qu'elle peut bloquer les interactions avec les autres fenêtres.
```
En code ces 7 droits sont:

```
cfg.resizable 
cfg.movable 
cfg.closable
cfg.minimizable
cfg.maximizable
cfg.canFullscreen
cfg.modal

```

C'est la raison pour laquelle mon code donne:

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
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable =  true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```
Pour l'instant les 7 droits sont actives.

# Desactivation des droits
## resizable
J'ai mis `cfg.resizable` a false, la fenetre s'est ouverte normalement a `12080 x 720`.

Je pouvais toujours la deplacer, la minimiser et la maximiser mais je ne peux plus la modifier en largeur ou en hauteur.

## movable

J'ai desactive `cfg.movable`

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
    cfg.resizable = true;
    cfg.movable = false;
    cfg.closable =  true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```
**Mais lorsque j'execute j'arrive toujours a faire bouger la fenetre.**

## closable

j'ai annule ce droit pour empecher l'utilisateur de fermer la fenetre.

```
cfg.closable = false;
```
La fenetre s'ouvrait normalement la taille etait respecter, je pouvais maximiser et minimaliser mais le bouton rouge pour fermer la fenetre etait toujours actif. Je pouvais toujours fermer la fenetre.

## minimalize

Pour ca j'ai remis closable a `true` et mis minimalize a `false` 

```
 cfg.minimizable = false;
 ```
J'ai toujours reussi a minimaliser la fenetre. Pourtant elle est cense reste agrandi jusqu'au bout.

## maximalize

Lorsque j'ouvre la fenetre la touche pour maximiser n'est pas fonctionnel mais lorsque je minimalise lorsque je clique sur la fenetre dans la barre de tache elle s'agrandi.

## canFullscreen

J'ai mis a `false` mais je n'arrive pas a passer la fenetre.

## modal

Ici modal ne signifie pas "bouton modal". Cela définit le comportement de la fenêtre vis-à-vis des autres fenêtres. la fenêtre est modale : lorsqu'elle est active, elle est destinée à bloquer les interactions avec les autres fenêtres concernées.
la fenêtre devient non modale :

elle peut coexister avec d'autres fenêtres ;
l'utilisateur peut normalement interagir avec les autres fenêtres ;
elle ne doit pas imposer le blocage propre à une fenêtre modale.

**Mais elle impose le blocage propre a une fenetre modale**
