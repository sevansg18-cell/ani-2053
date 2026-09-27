# Exercice — Afficher l'état du programme dans le titre

## 1. Objectif

L'objectif est d'afficher dans le titre de la fenêtre :

* le nom du document ;
* `*` lorsque le document est modifié ;
* la taille courante de la fenêtre.

Le titre doit être mis à jour uniquement lorsque l'une de ces informations change, et non à chaque image.

Exemple :

```
MaFenetre - 1278 x 720
MaFenetre* - 1278 x 720
```

## 2. Implémentation

J'ai utilisé une variable pour conserver l'état du document :

```
bool documentModifie = false;
```

Une fonction lambda permet de construire et d'appliquer le titre :

```
auto mettreAJourTitre = [&]() {
    auto taille = window.GetSize();

    NkString titre = cfg.title;

    if (documentModifie)
        titre += "*";

    titre += " - ";
    titre += NkString::Fmtf("%u x %u", taille.x, taille.y);

    window.SetTitle(titre);
};
```

La taille est récupérée avec :

```
window.GetSize();
```

Cela permet d'afficher la taille réelle de la fenêtre plutôt que seulement la taille configurée initialement.


## 3. Mise à jour du titre

La fonction est appelée une première fois au démarrage :

```
mettreAJourTitre();
```

Elle est ensuite appelée uniquement lorsqu'un événement nécessite une modification du titre.

### Redimensionnement

```
if (e->Is<NkWindowResizeEvent>())
{
    mettreAJourTitre();
}
```

La nouvelle largeur et la nouvelle hauteur sont donc immédiatement affichées.

### Modification du document

Pour tester l'état modifié, une pression sur une touche est utilisée :

```
if (e->Is<NkKeyPressEvent>())
{
    documentModifie = true;
    mettreAJourTitre();
}
```

Le `*` apparaît alors dans le titre.


## 4. Difficultés rencontrées

### Taille réelle

La taille configurée était :

```
cfg.width = 1280;
cfg.height = 720;
```

mais `GetSize()` a retourné lors d'un test :

```text
1278 x 720
```

J'ai donc utilisé `window.GetSize()` afin d'afficher la taille réellement obtenue par la fenêtre.


## 5. Tests

### Démarrage

Le titre affiché était :

```
MaFenetre - 1278 x 720
```

### Modification

Après une pression sur une touche :

```
MaFenetre* - 1278 x 720
```

Le `*` apparaît correctement.

### Redimensionnement

Après avoir redimensionné la fenêtre, la taille affichée dans le titre change également.

Par exemple :

```text
MaFenetre* - 800 x 600
```

Ces tests montrent que le titre est bien actualisé lors des événements concernés.



## 6. Conclusion

L'exercice est fonctionnel.

Le titre affiche correctement le nom du document, l'état de modification avec `*` et la taille actuelle de la fenêtre. Les mises à jour sont déclenchées par les événements concernés plutôt qu'à chaque image.

Les principales difficultés rencontrées concernaient la conservation de l'état de `documentModifie`, le placement de `return 0` et l'utilisation de la taille réelle retournée par `GetSize()`.
