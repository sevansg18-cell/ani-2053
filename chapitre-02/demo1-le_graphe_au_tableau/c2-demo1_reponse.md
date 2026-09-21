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

J'ai ensuite vérifié l'état du dépôt :

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

## 2. Affichage du graphe avec Git

J'ai utilisé la commande :

```
git log --oneline --graph --all
```

Le résultat obtenu est :

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
* 170e687 exo4
* eba6675 exo3
* 9d291a8 exo4
* 29eee28 exo5
* ba51e55 exo3
* 472b0c5 exo2
* febe87b exo1
| * a9f66ac (origin/branche-mesure-2) Revert "Commit a annuler"
| * d3865f6 Commit a annuler
| * b652c9e Troisième commit de mesure
| * d0348ed Deuxième commit de mesure
| * 840dd48 Premier commit de mesure
| * 3f4d956 message
| * d491c05 Ajout d'une présentation de Git
| * a2f8d9c Ajout du fichier de réponse
| * a3de3bd Ajout de l'exercice 2
| * 34ce519 Modification du README
| * db88553 Ajout de l'exercice1
|/
* 2476454 Initial commit
```

## 3. Partie du graphe étudiée

Pour montrer clairement une divergence puis une fusion, je retiens cette partie :

```
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
* b778ee1 exo5
```

On voit ici deux lignes de développement qui partent de `b778ee1`, puis qui sont réunies par le commit de fusion `f1a104f`.

## 4. Graphe à dessiner au tableau

Le dessin peut être représenté simplement comme ceci :

```
                 f1a104f
                    |
              Fusion / Réunion
                /       \
        3b8b0a2         cd2f54b
        clone1           clone2
            \             /
             \           /
               b778ee1
              Point commun
```

Une autre manière de le dessiner, en suivant l'ordre des commits, est :

```
b778ee1
   |
   +---- 3b8b0a2 ----\
   |                  \
   +---- cd2f54b ------ f1a104f
```

## 5. Correspondance avec `git log --graph`

Le commit `b778ee1` dans le dessin correspond à :

```
* b778ee1 exo5
```

C'est le point commun avant la séparation des deux lignes de développement.

Le commit `3b8b0a2` correspond à :

```
| * 3b8b0a2 Modification depuis clone1
```

Il représente une des deux lignes de développement.

Le commit `cd2f54b` correspond à :

```
* | cd2f54b Modification depuis clone2
```

Il représente l'autre ligne de développement.

Le commit `f1a104f` correspond à :

```
*   f1a104f Résolution du conflit dans README
```

C'est le commit de fusion qui réunit les deux historiques.

Les caractères :

```
|\
```

montrent la séparation des deux historiques au niveau de la fusion.

Les caractères :

```
|/
```

montrent que les deux lignes sont ensuite réunies dans l'historique commun.

## 6. Conclusion

Le graphe dessiné au tableau correspond donc directement au graphe obtenu avec :

```
git log --oneline --graph --all
```

Le dépôt réel montre bien
