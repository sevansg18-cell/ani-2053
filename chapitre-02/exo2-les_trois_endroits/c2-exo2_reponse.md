# Modification d'un fichier

Pour effectuer ce travail nous avons choisi README.md

Nous avons utilise la commande:
```
notepad README.md
```
Pour ouvrir notepad. Dans notepad j'ai ecrit ` Bonjour a tous`

Une fois la commande tape et la modification effectue j'ai tape `git status` et j'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status 
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo2-les_trois_endroits/

no changes added to commit (use "git add" and/or "git commit -a")
```

# Ajout avec git add

J'ai utilise `git add README.md` et j'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add README.md
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status 
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo2-les_trois_endroits/
```

# Envoie du commit

Pour envoyer mon commit j'ai utilise `git commit`. J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Modification du README"
[main 34ce519] Modification du README
 1 file changed, 4 insertions(+), 1 deletion(-)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status 
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo2-les_trois_endroits/

nothing added to commit but untracked files present (use "git add" to track)
```
## NB: J'ai utilise git status a chaque fois comme voulait l'enonce.
