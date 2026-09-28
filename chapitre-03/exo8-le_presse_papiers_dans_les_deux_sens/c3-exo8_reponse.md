# Test pratique : presse-papiers avec NKWindow

## 1. Objectif

Dans cet exercice, j'ai réalisé deux tests pratiques avec `NKWindow` :

* lire un texte présent dans le presse-papiers, le transformer en majuscules et remettre le résultat dans le presse-papiers ;
* lire une image présente dans le presse-papiers, inverser ses couleurs sans modifier son canal alpha, puis remettre l'image modifiée dans le presse-papiers.

J'ai utilisé les fonctions fournies par `NKWindow` et je n'ai pas appelé directement l'API Win32.


# 2. Test pratique du texte

Pour commencer, j'ai placé le texte suivant dans mon presse-papiers :

```
Bonjour Gabriel
```

Dans mon programme, j'ai récupéré ce texte avec :

```
NkString texte = window.GetClipboardText();
```

J'ai ensuite affiché le contenu récupéré :

```
logger.Info("Texte du presse-papiers avant : {}", texte);
```

Le programme a donc lu :

```
Texte du presse-papiers avant : Bonjour
```

## Conversion en majuscules

Pour transformer le texte, j'ai utilisé la fonction `ToUpper()` de `NkString` :

```
texte = texte.ToUpper();
```

Le texte :

```
Bonjour Gabriel
```

est devenu :

```
BONJOUR GABRIEL
```

J'ai ensuite remis le texte transformé dans le presse-papiers avec :

```
window.SetClipboardText(texte);
```

Puis j'ai affiché le résultat :

```
logger.Info("Texte remis dans le presse-papiers : {}", texte);
```

Le résultat obtenu était :

```
Texte remis dans le presse-papiers : BONJOUR
```

### Résultat du test texte

```
Texte initial : Bonjour Gabriel
Texte après traitement : BONJOUR GABRIEL
```

Le test demandé pour le presse-papiers texte fonctionne donc : j'ai lu `Bonjour`, je l'ai transformé en `BONJOUR`, puis j'ai remis le résultat dans le presse-papiers.


# 3. Test pratique de l'image

Après le test du texte, j'ai testé la partie image.

J'ai d'abord vérifié si une image était disponible dans le presse-papiers avec :

```
logger.Info("Image présente : {}", window.HasClipboardImage());
```

J'ai ensuite créé une structure `NkClipboardImage` pour recevoir l'image :

```
NkClipboardImage image;
```

Puis j'ai demandé à `NKWindow` de lire l'image :

```
bool imageLue = window.GetClipboardImage(image);
```

J'ai affiché le résultat de cette lecture :

```
logger.Info("Image lue : {}", imageLue);
```

## Dimensions et format

Après la lecture, j'ai récupéré les dimensions avec :

```
image.width
image.height
```

J'ai affiché les informations avec :

```
logger.Info(
    "Image : {} x {} | 32 bits par pixel",
    image.width,
    image.height
);
```

Dans mon test, l'image était au format **RGBA8**.

Cela signifie que chaque pixel contient quatre composantes de 8 bits :

```
R = rouge
G = vert
B = bleu
A = alpha
```

Soit :

```
8 + 8 + 8 + 8 = 32 bits par pixel
```

## Inversion des couleurs

J'ai ensuite parcouru les pixels quatre par quatre :

```
for (usize i = 0; i + 3 < image.pixels.Size(); i += 4)
{
    image.pixels[i] = 255 - image.pixels[i];
    image.pixels[i + 1] = 255 - image.pixels[i + 1];
    image.pixels[i + 2] = 255 - image.pixels[i + 2];
}
```

Pour chaque pixel :

```
image.pixels[i]     → rouge
image.pixels[i + 1] → vert
image.pixels[i + 2] → bleu
image.pixels[i + 3] → alpha
```

J'ai donc inversé uniquement les trois couleurs RGB.

Je n'ai pas modifié :

```
image.pixels[i + 3]
```

Ainsi, le canal alpha reste inchangé comme demandé dans l'exercice.

## Remise de l'image

Après l'inversion, j'ai remis l'image dans le presse-papiers avec :

```
bool imageRemise = window.SetClipboardImage(image);
```

J'ai ensuite vérifié que l'image pouvait être relue :

```
NkClipboardImage imageFinale;
bool imageFinaleLue = window.GetClipboardImage(imageFinale);
```

Cela m'a permis de vérifier que l'image modifiée avait bien été remise dans le presse-papiers.



# 4. Fonctions de NKWindow utilisées

Pour réaliser cet exercice, j'ai principalement utilisé les fonctions suivantes.

Pour le texte :

```
window.GetClipboardText();
window.SetClipboardText(texte);
```

Pour l'image :

```
window.HasClipboardImage();
window.GetClipboardImage(image);
window.SetClipboardImage(image);
```

J'ai donc effectué toutes les opérations du presse-papiers à travers `NKWindow`.

Je n'ai pas utilisé directement les fonctions du presse-papiers de Windows.


# 5. Résultat du test pratique

Le premier test demandé par l'exercice a été réalisé avec :

```
Bonjour gabriel
```

J'ai obtenu :

```
Avant : Bonjour gabriel
Après : BONJOUR GABRIEL
```

La transformation du texte en majuscules fonctionne.

Pour l'image, j'ai récupéré une image avec `GetClipboardImage()`, obtenu ses dimensions et ses pixels RGBA8, puis inversé les composantes rouge, verte et bleue.

Le canal alpha n'a pas été modifié.

Enfin, j'ai utilisé `SetClipboardImage()` pour remettre l'image transformée dans le presse-papiers.


# 6. Conclusion

Dans ce test pratique, j'ai réalisé les deux opérations demandées par l'exercice.

Pour le texte, j'ai utilisé le presse-papiers avec `NKWindow` pour lire `Bonjour`, le convertir en `BONJOUR`, puis remettre le résultat dans le presse-papiers.

Pour l'image, j'ai récupéré les pixels avec `GetClipboardImage()`, inversé les composantes RGB et conservé l'alpha, puis remis l'image modifiée avec `SetClipboardImage()`.

Le programme fonctionne avec les fonctions publiques de `NKWindow` et ne dépend donc pas directement des fonctions Win32 du presse-papiers.
