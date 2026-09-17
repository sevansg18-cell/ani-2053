# Etude des differents des trois derniers commits

Pour faire une recuperation des differents commits j'ai utilise la commande `git log --oneline -20` dans le dossier du moteur:
```
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> git log --oneline -20

0d50a971 (HEAD -> main, origin/main, origin/HEAD) NKCode 0.1.

0-beta.6 : version bumpee avant publication

7c3e84a0 Merge remote-tracking branch 'origin/main'

4c7d66b5 Distribution : refuser de livrer un exe dont une DLL importee manque

ad0779cb NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur

cc41ca45 GemCrush : le jeu complet -- menu, aventure 30 niveaux, 3 modes, audio synthetise (#84)

5fc605de Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux

56b0ed67 wiki : les mesures Vulkan sont CONFIRMEES par contre-ve
rification -- et un 5e piege, celui qui a permis le desaccord

ecfb57cb wiki maintenabilite : quelle garde rougirait AUJOURD HU
I -- reponse mesuree, et c est << aucune ici >>

b4cdf3cc wiki pieges : l avertissement sur CreateWithFallback es
t MAINTENU -- mesure a l appui -- et gagne le corollaire sur les
 bancs

92cf625a wiki : je retire << 18 shaders casses >> -- c etait mon
 cache, pas le depot ; + les 4 pieges d instrument et la validat
ion de G1

7ddd10ce NKRenderer : garde G1 -- l ordre de frame devient bruya
nt au lieu d etre silencieux

5e2d56ab wiki NKRenderer/NKRHI : le contrat de frame mesure, la 
surface publique, la divergence des backends -- et deux correcti
ons datees de mes propres chiffres

3b79729b NKRenderer : Present() avant EndFrame() sur les 3 sites
 inverses, et le commentaire qui enseignait l inverse

d45a78d4 Merge branch 'feat/design-nodal'

ab2ba781 verifie_planches : deux controles sur la TABLE du 13, e
t un \b qui n en etait pas un

20648f12 Planche 08 : le panneau 3 ne dit plus  CE QUE LE MODELE
 NE PERMET PAS AUJOURD HUI  -- c est code, et date

70f78561 NKGraph specification : le 19.3 est FAUX par la mesure,
 le 19.9 gagne une quatrieme raison, et le 20 cesse de decrire u
n code d hier

d266cd56 NKGraph specification : les trois contradictions signal
ees par le chantier voisin, et une famille de defaut nommee

0b918850 Kernel : sortir les SORTIES de bancs du suivi, retirer 
les residus

4ec71d47 NKGraph : le fichier Lunacy de Rodolf rejoint la branch
e design, et il est ENFIN suivi

```
Comme mon resultat le montre j'ai bien 20 commits.

J'ai choisi les commits: `4c7d66b5`(Distribution : refuser de livrer un exe dont une DLL importee manque), `ad0779cb`(NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur), `5fc605de`(Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux).

## Dire ce qu'ils font

`4c7d66b5 — Distribution : refuser de livrer un exe dont une DLL importee manque`: Oui Le message indique clairement que la distribution doit refuser de livrer un exécutable lorsqu’une DLL importée est manquante.

`ad0779cb — NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur`: Oui. Le message indique que le runtime MinGW est lié statiquement afin que l’exécutable ne dépende plus du MSYS2/MinGW installé sur la machine du testeur.

`5fc605de — Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux`: Oui. Le message indique qu’une protection pour le mode headless existait uniquement sous Windows et qu’un segfault se produisait sur les trois backends Linux.


## Pourquoi?

`4c7d66b5 — Distribution : refuser de livrer un exe dont une DLL importee manque`:  Parce que Le corps du commit explique que la liste des DLL copiées était maintenue manuellement et qu’elle était incomplète. La nouvelle vérification compare la table d’imports réelle du binaire avec les fichiers livrés afin de détecter les DLL manquantes.


`ad0779cb — NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur`: parce que le corps du commit explique que NKCode.exe dépendait auparavant de certaines DLL MinGW trouvées grâce au PATH. Une différence de version de MSYS2 pouvait donc provoquer une erreur au lancement.

`5fc605de — Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux`: Parce que Le commit explique que, sous Linux, la surface Vulkan était créée sans vérifier si une fenêtre existait. Cela pouvait conduire à appeler vkCreateXlibSurfaceKHR avec dpy = nullptr.


## Un seul sujet?

Les trois commits parlent tous d'un seul sujet.

## Le message le plus faible

Parmi les trois, le message que je trouve le plus faible est :

`5fc605de — Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux`

Il donne déjà beaucoup d’informations, notamment le problème rencontré. Cependant, il décrit surtout le constat et la cause, sans formuler directement l’action réalisée sous la forme d’un sujet court à l’impératif.
