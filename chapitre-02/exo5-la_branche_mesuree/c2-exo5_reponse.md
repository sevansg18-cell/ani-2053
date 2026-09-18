# Creation d'une branche

J'ai temporairement mis mes modifications de côté avec `git stash git stash push -m "Modifications exercice branche mesure"`. Et switcher sur la branche principale avec `git switch main`.

Le resultat que j'ai obtenue est:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git stash push -m "Modifications exercice branche mesure"
Saved working directory and index state On branche-mesure: Modifications exercice branche mesure
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git switch main
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 6 commits.
  (use "git push" to publish your local commits)
```  
J'ai effectue une mesure avant de faire mes modifications et mes commits avec `$avant = (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum`
J'ai obtenu: `51577`.

J'ai ensuite switche sur une nouvelle branche pour bien refaire l'exercice avec `git switch -c branche-mesure-2 `.

# Creation des trois commits 

J'ai cree les trois commits avec les commandes `git add .`, `git commit -m "..."`.

J'ai obtenu les resultats suivant:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Premier commit de mesure"

[branche-mesure-2 840dd48] Premier commit de mesure
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 chapitre-02/exo6-le_conflit_provoque/c2-exo6_reponse.md

 PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Deuxième commit de mesure"

[branche-mesure-2 d0348ed] Deuxième commit de mesure
 1 file changed, 1 insertion(+)

 PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Troisième commit de mesure"

[branche-mesure-2 b652c9e] Troisième commit de mesure
 1 file changed, 2 insertions(+), 1 deletion(-)
```

J'ai fait une verification des trois commits et de mon switch sur "main" avec la commande `git log --oneline -4`. J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -4
b652c9e (HEAD -> branche-mesure-2) Troisième commit de mesure
d0348ed Deuxième commit de mesure
840dd48 Premier commit de mesure
3f4d956 (main) message
```

# Mesurage

J'ai mesure la taille du depot avec `(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum` apres les commits et j'ai obtenu `54982`.

### Gain

C'est la difference entre les deux mesures:

54982 - 51577 = 3405 octets.
Lorsqu'on converti 3405 en Mo on obtient: `0,003405 Mo`

## NB: J'ai mesure avant et apres la creation des commits


## Justification

La taille mesurée du dépôt a  changé après les trois commits parce que la branche elle-même est une simple référence vers un commit, tandis que les nouveaux commits et les objets nécessaires à leur stockage font augmenter la taille de .git.
