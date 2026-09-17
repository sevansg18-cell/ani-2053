# Creation d'une branche

J'ai cree une nouvelle branche et effectue avec:
`git switch -c branche-mesure` et j'ai verifie avec `git branch`

Le resultat que j'ai obtenue est:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053>git switch -c branche-mesure

Switched to a new branch 'branche-mesure'

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git branch 

* branche-mesure
  main
```  

# Creation des trois commits 

J'ai cree les trois commits avec les commandes `git add .`, `git commit -m "..."`.

J'ai obtenu les resultats suivant:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Premier commit de mesure"

[branche-mesure ccfde1d] Premier commit de mesure
 3 files changed, 38 insertions(+), 14 deletions(-)
 create mode 100644 chapitre-02/exo3-le_message_qui_sert/c2-exo3_reponse.md
 create mode 100644 chapitre-02/exo5-la_branche_mesuree/c2-exo5_reponse.md

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Deuxième commit de mesure"

On branch branche-mesure
nothing to commit, working tree clean

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git add .

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git commit -m "Troisième commit de mesure"

On branch branche-mesure
nothing to commit, working tree clean
```

J'ai fait une verification des trois commits avec la commande `git log --oneline -3`. J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> git log --oneline -3
ccfde1d (HEAD -> branche-mesure) Premier commit de mesure
3f4d956 (main) message
d491c05 Ajout d'une présentation de Git
```

# Mesurage

J'ai mesure la taille du depot avec `(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum` et j'ai obtenu 40858.

J'ai converti en Mo avec `"{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB)`
J'ai obtenu:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum
40858
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> "{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB)
0,04 Mo
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> "{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB)
0,04 Mo
```
## NB: J'ai mesure avant et apres la creation des commits

Le resultat est le meme : `0,04Mo`.

0,04 - 0,04 = 0,00Mo.
Il n'y a donc pas de difference.

## Justification

La taille mesurée du dépôt n'a pas changé après les trois commits. Cela ne signifie pas que les commits n'ont rien ajouté.
Git enregistre les commits sous forme d'objets et optimise le stockage des données.
Les modifications réalisées étaient très petites et leur impact sur la taille totale du dépôt est négligeable ou inférieur à la précision de la mesure utilisée.
Il faut également distinguer la taille du projet de celle du dossier .git, qui contient les données internes de Git.
