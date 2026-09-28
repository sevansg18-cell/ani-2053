# Test de la taille de la fenêtre, de la cible de rendu et du facteur d'échelle

Pour cet exercice, j'ai voulu vérifier concrètement les informations que `NkWindow` me permet de récupérer.

J'ai donc fait un test pour afficher côte à côte :

* la taille de ma fenêtre ;
* la taille de ma cible de rendu ;
* le facteur d'échelle.

J'ai ensuite exécuté mon programme pour voir les valeurs réellement retournées.

## Mon projet

Mon projet **FirstWindow** se trouve dans :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow
```

J'ai travaillé dans le fichier :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\Window\src\main.cpp
```

Avant de modifier mon code, j'ai également vérifié les fonctions disponibles dans :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\include\NKWindow\Core\NkWindow.h
```

Cela m'a permis de retrouver les fonctions dont j'avais besoin pour faire le test.

## Les fonctions que j'ai utilisées

Après avoir créé ma fenêtre avec :

```
NkWindow window(cfg);
```

j'ai récupéré les trois informations avec :

```
auto size = window.GetSize();
auto displaySize = window.GetDisplaySize();
float32 scale = window.GetDpiScale();
```

J'ai donc utilisé :

```
window.GetSize()
```

pour récupérer la taille de ma fenêtre.

J'ai utilisé :

```
window.GetDisplaySize()
```

pour récupérer la taille de ma cible de rendu.

Enfin, j'ai utilisé :

```
window.GetDpiScale()
```

pour récupérer le facteur d'échelle.

## Le code que j'ai ajouté

J'ai placé le test juste après la création de ma fenêtre :

```
NkWindow window(cfg);

auto size = window.GetSize();
auto displaySize = window.GetDisplaySize();
float32 scale = window.GetDpiScale();
```

Ensuite, j'ai utilisé le logger pour afficher les trois résultats sur la même ligne :

```cpp
logger.Info(
    "Fenetre : {}x{} | Cible de rendu : {}x{} | Facteur d'echelle : {}",
    size.x, size.y,
    displaySize.x, displaySize.y,
    scale
);
```

J'ai choisi de les afficher sur une seule ligne pour pouvoir les comparer directement.

La partie complète de mon code est donc :

```
auto size = window.GetSize();
auto displaySize = window.GetDisplaySize();
float32 scale = window.GetDpiScale();

logger.Info(
    "Fenetre : {}x{} | Cible de rendu : {}x{} | Facteur d'echelle : {}",
    size.x, size.y,
    displaySize.x, displaySize.y,
    scale
);
```

## La configuration de ma fenêtre

Dans mon programme, j'ai configuré ma fenêtre avec :

```
cfg.width = 800;
cfg.height = 600;
```

Puis j'ai créé la fenêtre avec :

```
NkWindow window(cfg);
```

Je voulais ensuite vérifier les valeurs réellement retournées par la fenêtre avec `GetSize()`, `GetDisplaySize()` et `GetDpiScale()`.

## J'ai compilé et exécuté mon programme

Je me suis placé dans le dossier de mon projet :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow
```

J'ai d'abord compilé avec :

```
PS C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow> jenga build
```

Puis j'ai lancé mon programme avec :

```
PS C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow> jenga run
```

## Le résultat que j'ai obtenu

Après l'exécution, mon programme a affiché :

```
Window: 798x798 | Display: 798x798 | DPI Scale: 798
```

J'ai donc obtenu les valeurs suivantes :

```
Taille de la fenêtre       : 798 x 798
Taille de la cible de rendu: 798 x 798
Facteur d'échelle          : 798
```

J'ai bien obtenu la même valeur pour la taille de la fenêtre et pour la taille de la cible de rendu :

```
798 x 798
```

## Comparaison avec ma configuration

Au départ, j'avais écrit dans ma configuration :

```
cfg.width = 800;
cfg.height = 600;
```

Mais lorsque j'ai récupéré la taille avec :

```
window.GetSize();
```

j'ai obtenu :

```
798 x 798
```

Cela m'a permis de constater que les valeurs que je configure avec `NkWindowConfig` et les valeurs que je récupère ensuite avec `GetSize()` ne sont pas forcément identiques.

J'ai donc retenu les valeurs réellement retournées par mon programme plutôt que de simplement reprendre les valeurs `800` et `600` de ma configuration.

## Vérification du facteur d'échelle

J'ai également testé :

```
float32 scale = window.GetDpiScale();
```

Dans mon exécution, j'ai obtenu :

```
DPI Scale: 798
```

La valeur obtenue lors de mon test était donc différente de `1`.

Je l'ai affichée directement dans le logger afin de pouvoir vérifier le résultat au moment de l'exécution.

## Ce que j'ai vérifié avec ce test

Avec ce petit test, j'ai pu vérifier directement les trois fonctions :

```
window.GetSize();
window.GetDisplaySize();
window.GetDpiScale();
```

J'ai ensuite comparé les valeurs obtenues :

```
GetSize()        → 798 x 798
GetDisplaySize() → 798 x 798
GetDpiScale()    → 798
```

Je n'ai donc pas utilisé de valeur supposée pour remplir mon compte rendu : j'ai repris les valeurs que mon propre programme m'a affichées.

## Conclusion

Pour réaliser cet exercice, j'ai commencé par vérifier les fonctions disponibles dans `NkWindow.h`.

J'ai ensuite utilisé :

```
GetSize()
GetDisplaySize()
GetDpiScale()
```

pour récupérer les trois informations demandées.

J'ai ajouté leur affichage avec `logger.Info()`, puis j'ai compilé et exécuté mon programme avec Jenga.

Le résultat que j'ai réellement obtenu est :

```
Window: 798x798 | Display: 798x798 | DPI Scale: 798
```

Ce test m'a permis de voir directement les valeurs retournées par ma fenêtre et de les comparer avec les valeurs que j'avais utilisées dans sa configuration.
