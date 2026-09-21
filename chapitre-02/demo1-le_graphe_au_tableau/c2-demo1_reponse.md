# Graphe des commits d'un dépôt réel

## 1. Chemin d'accès au dépôt

J'ai travaillé dans le dépôt `ani-2053`, situé dans :

```
C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia\ani-2053
```

Je me suis placé dans ce dossier avec PowerShell :

```
PS C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia> cd ani-2053
```

J'ai vérifié l'état du dépôt :

```
PS C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia\ani-2053> git status
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/demo1-le_graphe_au_tableau/
        chapitre-02/exo12-la_regle_du_depot/

nothing added to commit but untracked files present (use "git add" to track)
```

Le dépôt est bien sur la branche `main`.

## 2. Graphe réalisé avant la vérification avec Git

Avant d'afficher le graphe avec Git, j'ai observé l'historique connu du travail réalisé avec les deux clones.

J'ai donc dessiné au tableau le graphe que je pensais obtenir :

```
b778ee1
   |
   +---- 3b8b0a2 ----\
   |                  \
   +---- cd2f54b ------ f1a104f
```

J'ai interprété ce dessin de la manière suivante :

* `b778ee1` est le point commun de départ ;
* `3b8b0a2` représente une modification réalisée depuis `clone1` ;
* `cd2f54b` représente une modification réalisée depuis `clone2` ;
* `f1a104f` doit réunir les deux lignes lors de la fusion.

Ce dessin constitue donc mon hypothèse avant la vérification avec Git.

## 3. Vérification avec Git

Pour vérifier si le dessin correspondait réellement à l'historique du dépôt, j'ai utilisé :

```
git log --oneline --graph --all
```

J'ai obtenu :

```
* 7b54462 (HEAD -> main, origin/main, origin/HEAD) exo11
* 0c8acfb exo11
* 6376378 exo11
* b55ddb3 exo1
* 2cda76b exo10
* fc43caa exo2
* 8b89ab5 exo6
* f79c996 exo9
* 8624631 exo8
* af708d7 exo3
* a442fd exo4
* dae2e54 exo7
* b61bf94 exo 6
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
* b778ee1 exo5
```

## 4. Comparaison entre mon dessin et le graphe de Git

La sortie de Git confirme le dessin réalisé au préalable.

On retrouve bien :

```
                 f1a104f
                    |
                  /   \
           3b8b0a2   cd2f54b
               \       /
                 b778ee1
```

Les trois éléments principaux correspondent :

```
b778ee1  → point commun
3b8b0a2  → développement depuis clone1
cd2f54b  → développement depuis clone2
f1a104f  → fusion des deux historiques
```

Les caractères `|\` montrent la séparation des deux lignes et `|/` leur réunion.

## 5. Conclusion

Le dessin réalisé avant l'utilisation de `git log --graph` correspond à l'historique réel du dépôt. La vérification avec Git montre donc que le raisonnement effectué à partir des commits était correct.

Cet exemple permet de visualiser une situation de **divergence puis de fusion** : à partir du commit commun `b778ee1`, deux développements différents sont réalisés dans `clone1` et `clone2`, puis ils sont réunis par le commit `f1a104f`, intitulé `Résolution du conflit dans README`.

Le graphe de Git permet ainsi de vérifier visuellement l'organisation réelle des commits et de comparer cette organisation avec le graphe que j'avais prévu avant la vérification.
