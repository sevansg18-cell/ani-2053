# Modifications dans un fichiers

Pour effectuer les modifications j'ai pris le `README.md`.

Mon README.md avait du texte c'est a dire les restes des modifications que j'avais essaye sans succes pour l'exercice.

Pour verifier l'etat actuel j'ai tape `git status` et rien n'avait bouge.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status
On branch branche-mesure
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   chapitre-02/exo3-le_message_qui_sert/c2-exo3_reponse.md
        modified:   chapitre-02/exo4-le_commit_partiel/c2-exo4_reponse.md
        modified:   chapitre-02/exo5-la_branche_mesuree/c2-exo5_reponse.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo6-le_conflit_provoque/

no changes added to commit (use "git add" and/or "git commit -a")
```
Comme on peut le voir le README.md n'a pas subit de modification.

Ensuite j'ai utilise `git diff README.md` pour verifier le fichier en question. Et il n'a recu aucune modification.

J'ai effectue deux modifications :
1. Ajouter le point d'exclamation a bonjour monsieur

2. Ecrire chapitre 2 a la fin.

Ensuite j'ai utilise `git diff -- README.md` pour voir les modifications .
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git diff -- README.md
diff --git a/README.md b/README.md
index 1ed53ff..c543774 100644
--- a/README.md
+++ b/README.md
@@ -1,8 +1,8 @@
-# Bonjour a tous
+# Bonjour à tous !
 # ani-2053
 ## Chapitre 1
 Contenu du chapitre 1.
 ## Chapitre 2
 Contenu du chapitre 2.
 ## Informations
-Dépôt de travaux pratiques Git.
+Dépôt de travaux pratiques Git - Chapitre 2.
```

Ensuite j'ai utilise `git -c diff.context=1 add -p README.md` pour forcer la separeration de mes changements en deux staged.
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git -c diff.context=1 add -p README.md
diff --git a/README.md b/README.md
index 1ed53ff..c543774 100644
--- a/README.md
+++ b/README.md
@@ -1,2 +1,2 @@
-# Bonjour a tous
+# Bonjour à tous !
 # ani-2053
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
@@ -7,2 +7,2 @@ Contenu du chapitre 2.
 ## Informations
-Dépôt de travaux pratiques Git.
+Dépôt de travaux pratiques Git - Chapitre 2.
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n

```

J'ai effectue un `git diff --cached` pour avoir une confirmation claire que la premiere modification est preparee pour le commit :
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git diff --cached -- README.md 
diff --git a/README.md b/README.md
index 1ed53ff..e56e949 100644
--- a/README.md
+++ b/README.md
@@ -1,4 +1,4 @@
-# Bonjour a tous
+# Bonjour à tous !
 # ani-2053
 ## Chapitre 1
 Contenu du chapitre 1.
```
Apres j'ai fait un `git commit -m "Correction du titre du README"`:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Correction du titre du README"
[branche-mesure 2f1521b] Correction du titre du README
 1 file changed, 1 insertion(+), 1 deletion(-)
 ```
 `git status` pour verifier.

 ```
 PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status
On branch branche-mesure
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md
        modified:   chapitre-02/exo3-le_message_qui_sert/c2-exo3_reponse.md
        modified:   chapitre-02/exo4-le_commit_partiel/c2-exo4_reponse.md
        modified:   chapitre-02/exo5-la_branche_mesuree/c2-exo5_reponse.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo6-le_conflit_provoque/

no changes added to commit (use "git add" and/or "git commit -a")
```
J'ai refait `git diff --cached` pour la confirmation de la deuxieme modification.
Et `git commit -m "Mise à jour des informations du README"` pour le commit:

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add README.md
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git diff --cached -- README.md 
diff --git a/README.md b/README.md
index e56e949..c543774 100644
--- a/README.md
+++ b/README.md
@@ -5,4 +5,4 @@ Contenu du chapitre 1.
 ## Chapitre 2
 Contenu du chapitre 2.
 ## Informations
-Dépôt de travaux pratiques Git.
+Dépôt de travaux pratiques Git - Chapitre 2.
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Mise à jour des informations du README"
[branche-mesure de7635d] Mise à jour des informations du README
 1 file changed, 1 insertion(+), 1 deletion(-)
```
# Verification de l'historique 

Pour verifier l'historique j'ai utilise `git log -2 --oneline --stat`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log -2 --oneline --stat
de7635d (HEAD -> branche-mesure) Mise à jour des informations du README
 README.md | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
2f1521b Correction du titre du README
 README.md | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
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

## Chacun parle de son sujet 

Après avoir corrigé le problème d'encodage de `fichier1.txt`, j'ai effectué deux modifications différentes et éloignées dans le même fichier.

J'ai utilisé :

```
git diff -- fichier1.txt
```

pour vérifier que les deux modifications étaient bien présentes.

Ensuite, j'ai utilisé :

```
git add -p fichier1.txt
```

Git a séparé les modifications en deux blocs :

```
(1/2) Stage this hunk [...]? y
(2/2) Stage this hunk [...]? n
```

J'ai donc sélectionné la première modification pour le premier commit et laissé la deuxième dans le répertoire de travail.

J'ai créé le premier commit :

```
git commit -m "Première modification de fichier1"
```

Puis j'ai ajouté la deuxième modification et créé le second commit :

```
git add fichier1.txt
git commit -m "Deuxième modification de fichier1"
```

Enfin, j'ai utilisé `git show` sur chacun des commits afin de vérifier leur contenu.

Ainsi, chaque commit contient uniquement sa propre modification : **chacun parle de son sujet**.

