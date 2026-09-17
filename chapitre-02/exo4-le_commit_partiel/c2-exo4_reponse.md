# Modifications dans un fichiers

Pour effectuer les modifications j'ai pris le `fichier1` du `depot-test` de l'exercice1.

A l'interieur de ce fichier j'ai ecrit deux phrases.

1. Phrase1: Bonjour monsieur.

2. Phrase2: Au-revoir

Pour verifier l'etat actuel j'ai tape `git status`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier1.txt

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> 
```
Ensuite j'ai utilise `git diff` pour verifier le fichier en question.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git diff
diff --git a/fichier1.txt b/fichier1.txt
index 8c8682b..8e8abb6 100644
--- a/fichier1.txt
+++ b/fichier1.txt
@@ -1,2 +1,14 @@
 bonjour monsieur
-Au-revoir git
+Bienvenue dans le dépôt Git
+ligne 1
+ligne 2
+ligne 3
+ligne 4
+ligne 5
+ligne 6
+ligne 7
+ligne 8
+ligne 9
+ligne 10
+Au-revoir git
+Merci pour votre attention^M
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> 
```

Ensuite j'ai utilise `git add -p` pour selectioner chaque modifications separement donc chaque commits contient son propre sujet.
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git add -p
diff --git a/fichier1.txt b/fichier1.txt
index 8c8682b..8e8abb6 100644
--- a/fichier1.txt
+++ b/fichier1.txt
@@ -1,2 +1,14 @@
 bonjour monsieur
-Au-revoir git
+Bienvenue dans le dépôt Git
+ligne 1
+ligne 2
+ligne 3
+ligne 4
+ligne 5
+ligne 6
+ligne 7
+ligne 8
+ligne 9
+ligne 10
+Au-revoir git
+Merci pour votre attention
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? s
Sorry, cannot split this hunk
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? n
```

Ensuite j'ai utilise `git commit -m ""` pour afficher et enregistrer le message. J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test>  git commit -m "Correction de la réponse"
[master 811f535] Correction de la réponse
 1 file changed, 13 insertions(+), 1 deletion(-)
```

J'ai effectue un deuxieme commit :
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git commit -m "Ajout d'une précision"
On branch master
nothing to commit, working tree clean
```

# Verification de l'historique 

Pour verifier l'historique j'ai utilise `git log -2 --oneline`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git log -2 --oneline
811f535 (HEAD -> master) Correction de la réponse
1fc7cc9 Conversion de fichier1 en UTF-8
```
Pour voir precisement les modifications j'ai fait `git show --stat --oneline HEAD`

J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git show --stat --oneline HEAD
811f535 (HEAD -> master) Correction de la réponse
 fichier1.txt | 14 +++++++++++++-
 1 file changed, 13 insertions(+), 1 deletion(-)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git show --stat --oneline HEAD~1
1fc7cc9 Conversion de fichier1 en UTF-8
 fichier1.txt | Bin 24 -> 35 bytes
 1 file changed, 0 insertions(+), 0 deletions(-)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git show HEAD~1
commit 1fc7cc91f42d6efca4cca3ba60113ede71881434
Author: Gabriel2016-dev <clothairesadif@gmail.com>
Date:   Thu Sep 17 13:33:24 2026 +0100

    Conversion de fichier1 en UTF-8

diff --git a/fichier1.txt b/fichier1.txt
index cc9267e..8c8682b 100644
Binary files a/fichier1.txt and b/fichier1.txt differ
```

## NB: Le compte GitHub qui a servi d'apres 
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git show HEAD~1
commit 1fc7cc91f42d6efca4cca3ba60113ede71881434
Author: Gabriel2016-dev <clothairesadif@gmail.com>
Date:   Thu Sep 17 13:33:24 2026 +0100

    Conversion de fichier1 en UTF-8

diff --git a/fichier1.txt b/fichier1.txt
index cc9267e..8c8682b 100644
Binary files a/fichier1.txt and b/fichier1.txt differ
```
Est un cmpte m'appartenant 

## Chacun parle de son sujet sauf que un commit porte sur la conversion de mon fichier UTF-8 en UTF-16. Et non du contenu du fichier.
