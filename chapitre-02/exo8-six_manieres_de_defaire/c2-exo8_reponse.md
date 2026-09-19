# Modification non voulue

J'ai commence par faire un `git status` dans le depot-test que j'ai fait pour au dernier exercice.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
nothing to commit, working tree clean
```
Ensuite utilise `"Modification temporaire non voulue" >> fichier.txt` pour faire une modification directement dans le terminal. Apres j'ai refait `git status` pour verifier.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> "Modification temporaire non voulue" >> fichier.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
```
J'ai fait `git add` pour ajouter la modification  et `git status` a nouveau.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add fichier.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier.txt
```

# add de trop

Apres les etapes ci dessus j'ai fait `git restore --staged fichier.txt` et `git status`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git restore --staged fichier.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
```
# commit de trop

J'ai fait une modification puis j'ai verifier. Je l'ai ajoute et j'ai refait une verification et J'ai provoqué un commit de trop avec le commit 64eaaf7 intitulé « Modification de trop ». Comme ce commit n'avait pas été poussé vers un dépôt distant, j'ai utilisé git reset --hard HEAD~1. Après cette commande, HEAD est revenu sur le commit 8422b45 et le commit 64eaaf7 n'apparaît plus dans l'historique de la branche master. La commande git status confirme également que le répertoire de travail est propre. Cette manipulation montre qu'un commit local peut être supprimé de l'historique avec git reset.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> "Modification temporaire non voulue" >> fichier.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add
Nothing specified, nothing added.
hint: Maybe you wanted to say 'git add .'?
hint: Disable this message with "git config set advice.addEmptyPathspec false"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add .
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Modification de trop" 
[master 64eaaf7] Modification de trop
 1 file changed, 0 insertions(+), 0 deletions(-)
```

# Annuler un commit déjà poussé

Cette situation est différente de la précédente car le commit avait déjà été envoyé sur le dépôt distant. Pour réaliser le test, un fichier spécifique a été créé : `test-revert.txt`. Son contenu était : `Commit pousse a annuler`. Le fichier a été ajouté avec: `git add "chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt"`.
Puis un commit a été créé. :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status --short -- "chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt"
?? chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add "chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status
On branch branche-mesure-2
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   chapitre-02/exo6-le_conflit_provoque/c2-exo6_reponse.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo5-la_branche_mesuree/
        chapitre-02/exo7-le_conflit_qui_n_en_est_pas_un/
        chapitre-02/exo8-six_manieres_de_defaire/c2-exo8_reponse.md
        depot-test/

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Commit a annuler"
[branche-mesure-2 d3865f6] Commit a annuler
 1 file changed, 1 insertion(+)
 create mode 100644 chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -3
d3865f6 (HEAD -> branche-mesure-2) Commit a annuler
b652c9e Troisième commit de mesure
d0348ed Deuxième commit de mesure

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git push origin branche-mesure-2
Enumerating objects: 50, done.
Counting objects: 100% (50/50), done.
Delta compression using up to 12 threads
Compressing objects: 100% (35/35), done.
Writing objects: 100% (50/50), 6.29 KiB | 189.00 KiB/s, done.
Total 50 (delta 9), reused 3 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (9/9), done.
remote: 
remote: Create a pull request for 'branche-mesure-2' on GitHub by visiting:
remote:      https://github.com/sevansg18-cell/ani-2053/pull/new/branche-mesure-2
remote: 
To https://github.com/sevansg18-cell/ani-2053.git
 * [new branch]      branche-mesure-2 -> branche-mesure-2
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git revert d3865f6
[branche-mesure-2 a9f66ac] Revert "Commit a annuler"
 1 file changed, 1 deletion(-)
 delete mode 100644 chapitre-02/exo8-six_manieres_de_defaire/test-revert.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
a9f66ac (HEAD -> branche-mesure-2) Revert "Commit a annuler"
d3865f6 (origin/branche-mesure-2) Commit a annuler
b652c9e Troisième commit de mesure
d0348ed Deuxième commit de mesure
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git push origin branche-mesure-2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 344 bytes | 344.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/sevansg18-cell/ani-2053.git
   d3865f6..a9f66ac  branche-mesure-2 -> branche-mesure-2
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
a9f66ac (HEAD -> branche-mesure-2, origin/branche-mesure-2) Revert "Commit a annuler"
d3865f6 Commit a annuler
b652c9e Troisième commit de mesure
d0348ed Deuxième commit de mesure
```

# Mettre un travail en cours de côté avec stash

J'ai cree un travail en  cours a mettre de cote avec `PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> "Travail en cours a mettre de cote" | Out-File -Encoding utf8 "chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt"`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> "Travail en cours a mettre de cote" | Out-File -Encoding utf8 "chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status --short -- "chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt"
?? chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt
```
`git stash -u` permet de mettre de côté les fichiers non suivis. PowerShell a affiché notamment : `Saved working directory and index state WIP on branche-mesure-2: a9f66ac Revert "Commit a annuler"`. J'ai fait une verification sur la branche mesure 2 .Et j'ai utilise la commande : `git stash list`. Pour le récupérer, la commande utilisée a été : `git stash pop`.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status --short -- "chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt"
?? chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git stash -u
Ignoring path depot-test/
Saved working directory and index state WIP on branche-mesure-2: a9f66ac Revert "Commit a annuler"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status
On branch branche-mesure-2
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        depot-test/

nothing added to commit but untracked files present (use "git add" to track)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git stash list
stash@{0}: WIP on branche-mesure-2: a9f66ac Revert "Commit a annuler"
stash@{1}: On branche-mesure: Modifications exercice branche mesure
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git stash pop
On branch branche-mesure-2
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   chapitre-02/exo6-le_conflit_provoque/c2-exo6_reponse.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo5-la_branche_mesuree/
        chapitre-02/exo7-le_conflit_qui_n_en_est_pas_un/
        chapitre-02/exo8-six_manieres_de_defaire/
        depot-test/

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (27c79244ff8465cd63f831e91b067a6fe87efdd6)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status --short
 M chapitre-02/exo6-le_conflit_provoque/c2-exo6_reponse.md
?? chapitre-02/exo5-la_branche_mesuree/
?? chapitre-02/exo7-le_conflit_qui_n_en_est_pas_un/
?? chapitre-02/exo8-six_manieres_de_defaire/
?? depot-test/
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git stash list
stash@{0}: On branche-mesure: Modifications exercice branche mesure
```

# Retrouver un commit « perdu » avec le reflog

Un fichier a d'abord été créé :`chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt`, avec le contenu :`Commit que je vais perdre`. Le fichier a été ajouté puis commité avec : `git add "chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt"`
`git commit -m "Commit temporairement perdu"`. Pour simuler sa perte, la commande suivante a été utilisée :`git reset --hard HEAD~1`. Après cette commande, le commit a3f574f ne figurait plus dans l'historique normal de branche-mesure-2.
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> "Commit que je vais perdre" | Out-File -Encoding utf8 "chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add "chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status
On branch branche-mesure-2
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   chapitre-02/exo6-le_conflit_provoque/c2-exo6_reponse.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo5-la_branche_mesuree/
        chapitre-02/exo7-le_conflit_qui_n_en_est_pas_un/
        chapitre-02/exo8-six_manieres_de_defaire/c2-exo8_reponse.md
        chapitre-02/exo8-six_manieres_de_defaire/travail-en-cours.txt
        depot-test/

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Commit temporairement perdu"
[branche-mesure-2 a3f574f] Commit temporairement perdu
 1 file changed, 1 insertion(+)
 create mode 100644 chapitre-02/exo8-six_manieres_de_defaire/commit-perdu.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
a3f574f (HEAD -> branche-mesure-2) Commit temporairement perdu
a9f66ac (origin/branche-mesure-2) Revert "Commit a annuler"
d3865f6 Commit a annuler
b652c9e Troisième commit de mesure
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git reset --hard HEAD~1
HEAD is now at a9f66ac Revert "Commit a annuler"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
a9f66ac (HEAD -> branche-mesure-2, origin/branche-mesure-2) Revert "Commit a annuler"
d3865f6 Commit a annuler
b652c9e Troisième commit de mesure
d0348ed Deuxième commit de mesure
```

Cependant, Git conserve les déplacements de HEAD dans le reflog. La commande :`git reflog` a permis de retrouver notamment :`a9f66ac HEAD@{0}: reset: moving to HEAD~1`
`a3f574f HEAD@{1}: commit: Commit temporairement perdu`

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git reflog
a9f66ac (HEAD -> branche-mesure-2, origin/branche-mesure-2) HEAD@{0}: reset: moving to HEAD~1
a3f574f HEAD@{1}: commit: Commit temporairement perdu
a9f66ac (HEAD -> branche-mesure-2, origin/branche-mesure-2) HEAD@{2}: reset: moving to HEAD
a9f66ac (HEAD -> branche-mesure-2, origin/branche-mesure-2) HEAD@{3}: revert: Revert "Commit a annuler"
d3865f6 HEAD@{4}: commit: Commit a annuler
b652c9e HEAD@{5}: commit: Troisième commit de mesure
d0348ed HEAD@{6}: commit: Deuxième commit de mesure
840dd48 HEAD@{7}: commit: Premier commit de mesure
3f4d956 (main) HEAD@{8}: checkout: moving from main to branche-mesure-2
3f4d956 (main) HEAD@{9}: checkout: moving from branche-mesure to main
de7635d (branche-mesure) HEAD@{10}: reset: moving to HEAD
de7635d (branche-mesure) HEAD@{11}: commit: Mise à jour des informations du 
README
2f1521b HEAD@{12}: commit: Correction du titre du README
83eaa44 HEAD@{13}: commit: Préparation du README
6b155ac HEAD@{14}: commit: Premier commit de mesure
ccfde1d HEAD@{15}: commit: Premier commit de mesure
3f4d956 (main) HEAD@{16}: checkout: moving from main to branche-mesure
3f4d956 (main) HEAD@{17}: commit: message
d491c05 HEAD@{18}: commit: Ajout d'une présentation de Git
a2f8d9c HEAD@{19}: commit: Ajout du fichier de réponse
a3de3bd HEAD@{20}: commit: Ajout de l'exercice 2
34ce519 HEAD@{21}: commit: Modification du README
db88553 HEAD@{22}: commit: Ajout de l'exercice1
2476454 (origin/main, origin/HEAD) HEAD@{23}: clone: from https://github.com
/sevansg18-cell/ani-2053.git
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git branch commit-retrouve a3f574f
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git switch commit-retrouve
Switched to branch 'commit-retrouve'
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
a3f574f (HEAD -> commit-retrouve) Commit temporairement perdu
a9f66ac (origin/branche-mesure-2, branche-mesure-2) Revert "Commit a annuler"
d3865f6 Commit a annuler
b652c9e Troisième commit de mesure.

```
### NB: J'ai effectue les 6 taches.
