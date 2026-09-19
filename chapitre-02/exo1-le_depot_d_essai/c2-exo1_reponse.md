# Création d'un dépôt vide

Pour créer le dossier qui servira de dépôt d'essai, j'ai utilisé la commande :

```
mkdir depot-test
```

## Résultat obtenu

```
Répertoire : C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----        16/09/2026     12:06                depot-test
```

J'ai ensuite utilisé la commande :

```
cd depot-test
```

Cette commande permet d'entrer dans le dossier `depot-test`.

Ensuite, j'ai utilisé :

```
git init
```

Cette commande permet d'initialiser le dossier comme un dépôt Git en créant notamment le dossier `.git` qui contient les informations nécessaires au suivi de l'historique du dépôt.

# Ajouter les fichiers et faire les commits

Pour ajouter le premier fichier, j'ai utilisé les commandes :

```
"Fichier 1" > fichier1.txt
git add fichier1.txt
git commit -m "Ajout du fichier 1"
```

Les commandes ont les rôles suivants :

1. `"Fichier 1" > fichier1.txt` permet de créer le fichier `fichier1.txt` et d'y écrire le texte `Fichier 1`.
2. `git add fichier1.txt` ajoute le fichier à la zone de préparation (*staging*).
3. `git commit -m "Ajout du fichier 1"` enregistre cette modification dans l'historique du dépôt avec le message `Ajout du fichier 1`.

J'ai appliqué le même principe pour les fichiers 2 et 3 :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> "Fichier 2" > fichier2.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git add fichier2.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git commit -m "Ajout du fichier 2"

[master 0fea6f8] Ajout du fichier 2
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 fichier2.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> "Fichier 3" > fichier3.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git add fichier3.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git commit -m "Ajout du fichier 3"

[master d84e186] Ajout du fichier 3
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 fichier3.txt
```

Les trois fichiers ont donc été ajoutés dans trois commits distincts.

# Ajouter l'historique en une ligne par commit

Pour afficher l'historique avec une seule ligne par commit, j'ai utilisé la commande :

```
git log --oneline
```

J'ai obtenu :

```
d84e186 (HEAD -> master) Ajout du fichier 3
0fea6f8 Ajout du fichier 2
5b1cafc Ajout du fichier 1
```

Cette commande permet d'afficher les commits de manière condensée. Pour chaque commit, Git affiche notamment son identifiant abrégé et son message.

On voit ici que les trois commits sont bien présents dans l'ordre inverse de leur création : le commit le plus récent apparaît en premier.

# Affichage du graphe

Pour afficher l'historique sous forme de graphe, j'ai utilisé :

```
git log --oneline --graph
```

Le résultat obtenu était :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git log --oneline --graph
* d84e186 (HEAD -> master) Ajout du fichier 3
* 0fea6f8 Ajout du fichier 2
* 5b1cafc Ajout du fichier 1
```

Le caractère `*` représente chaque commit. Les trois commits sont reliés verticalement car ils appartiennent à la même branche `master` et ont été réalisés successivement.

# Ajout personnel

D'après mes recherches, il est également possible d'utiliser des options supplémentaires pour afficher un graphe avec toutes les références et toutes les branches :

```
git log --oneline --graph --all --decorate
```

J'ai testé cette commande dans mon dépôt d'essai.

Le résultat obtenu était :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git log --oneline --graph --all --decorate
* d84e186 (HEAD -> master) Ajout du fichier 3
* 0fea6f8 Ajout du fichier 2
* 5b1cafc Ajout du fichier 1
```

Le résultat est similaire à celui obtenu avec :

```
git log --oneline --graph
```

Dans mon dépôt d'essai, il n'y avait qu'une seule branche, `master`, et aucune autre référence à afficher. Les options `--all` et `--decorate` n'ont donc pas apporté de différence visible dans ce cas.

Ce test m'a permis de constater que ces options deviennent surtout intéressantes lorsqu'un dépôt contient plusieurs branches ou plusieurs références à afficher.
