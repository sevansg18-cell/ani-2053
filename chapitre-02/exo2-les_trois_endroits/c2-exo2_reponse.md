# Modification d'un fichier

Pour effectuer ce travail, nous avons choisi le fichier `README.md`.

Nous avons utilisé la commande :

```
notepad README.md
```

Cette commande permet d'ouvrir le fichier `README.md` avec le Bloc-notes. Dans le fichier, j'ai ajouté le texte :

```
Bonjour a tous
```

Une fois la modification effectuée, j'ai utilisé la commande `git status` afin de vérifier l'état du fichier :

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

À ce moment, `README.md` est **modifié mais pas encore indexé**. Il apparaît donc dans la partie `Changes not staged for commit`. Le fichier n'est pas encore prêt à être inclus dans un commit.

# Ajout avec `git add`

Pour placer la modification de `README.md` dans la zone d'index, j'ai utilisé :

```
git add README.md
```

Puis j'ai vérifié l'état du dépôt avec `git status` :

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
  (use "git add <file>..." to include what will be committed)
        chapitre-02/exo2-les_trois_endroits/
```

La différence avec le premier `git status` est que `README.md` n'apparaît plus dans `Changes not staged for commit`. Il apparaît maintenant dans **`Changes to be committed`**.

Cela signifie que la modification a été **indexée** avec `git add` et qu'elle est maintenant prête à être enregistrée dans un commit.

# Création du commit

Pour enregistrer la modification dans l'historique Git, j'ai utilisé :

```
git commit -m "Modification du README"
```

J'ai obtenu :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Modification du README"
[main 34ce519] Modification du README
 1 file changed, 4 insertions(+), 1 deletion)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git status 
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/exo2-les_trois_endroits/

nothing added to commit but untracked files present (use "git add" to track)
```

Le commit a donc bien été créé. Git indique :

```
1 file changed, 4 insertions(+), 1 deletion(-)
```

Cela signifie que le commit contient **4 lignes ajoutées et 1 ligne supprimée** dans `README.md`.

# Comparaison des trois états

Les trois commandes `git status` permettent de suivre le déplacement de la modification dans les différentes zones de Git.

Dans le **premier état**, `README.md` est modifié dans le répertoire de travail mais n'est pas indexé :

```
Changes not staged for commit:
        modified:   README.md
```

Dans le **deuxième état**, après `git add README.md`, le fichier est placé dans la zone d'index :

```
Changes to be committed:
        modified:   README.md
```

Dans le **troisième état**, après le `git commit`, la modification de `README.md` n'apparaît plus comme une modification à valider. Elle fait maintenant partie de l'historique Git.

On peut donc résumer le fonctionnement ainsi :

```
Modification du fichier
        ↓
Répertoire de travail
        ↓ git add
Zone d'index
        ↓ git commit
Historique Git
```

Les trois états montrent donc concrètement le passage de la modification du **répertoire de travail**, vers la **zone d'index**, puis vers le **commit**.

Il faut également remarquer que le dossier :

```
chapitre-02/exo2-les_trois_endroits/
```

reste indiqué comme `Untracked files` dans les sorties. Il n'a pas été ajouté au commit, car l'objectif de cet exercice était uniquement de démontrer le parcours de la modification de `README.md`.

Enfin, j'ai utilisé la commande `git status` à chaque étape, comme le demandait l'énoncé, afin de vérifier l'état du fichier avant son indexation, après son indexation et après la création du commit.
