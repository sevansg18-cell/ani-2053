# Creation d'un depot vide

Pour creer le depot vide j'ai utilise la commande: 'mkdir depot-test

## Resultat obtenu:

```
 Répertoire : C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia


Mode                 LastWriteTime         Length Name                                                                                                                          
----                 -------------         ------ ----                                                                                                                          
d-----        16/09/2026     12:06                depot-test                                    

```
J'ai utilise la commande:
```
cd depot-test
```
Pour entrer dans le dossier d'essai.
Ensuite:
```
git init 
```
Pour transformer un dossier simple en depot github.


# Ajouter les fichiers et faire les commits

Pour ajouter le premier fichier j'ai utilise:
```
"Fichier 1" > fichier1.txt
git add fichier1.txt
git commit -m "Ajout du fichier 1"
```
1. "Fichier 1" > fichier1.txt: pour creer un fichier texte appele "fichier1.txt
2. git add fichier1.txt: pour ajouter le fichier1.
3. git commit -m "Ajout du fichier 1": pour envoyer un message d'ajout. 

J'ai applique le meme principe avec lesfichiers 2 et 3
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

# Ajouter l'historique en une ligne par commit

Pour ajouter l'historique en une ligne par commit, j'ai utilise:
```
git log --oneline
``` 
J'ai obtenu:
```
d84e186 (HEAD -> master) Ajout du fichier 3
0fea6f8 Ajout du fichier 2
5b1cafc Ajout du fichier 1
```

# Affichage du graphe

Pour afficher le graphe j'ai utilise:
```
git log --oneline --graph
```
Le resultat etait:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git log --oneline --graph
* d84e186 (HEAD -> master) Ajout du fichier 3
* 0fea6f8 Ajout du fichier 2
* 5b1cafc Ajout du fichier 1
```

## Ajout personnel 

D'apres mes recherche il etait possible d'avoir un graphe encore plus detaille et plus complet c'est a dire avec les branches et les references 
```
git log --oneline --graph --all --decorate
```
Mais lorsque j'ai tape le resultat etait similaire a celui de l'affichage du graphe

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\depot-test> git log --oneline --graph --all --decorate
* d84e186 (HEAD -> master) Ajout du fichier 3
* 0fea6f8 Ajout du fichier 2
* 5b1cafc Ajout du fichier 1
```