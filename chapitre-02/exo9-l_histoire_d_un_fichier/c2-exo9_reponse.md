# Reconstitution de l'historique d'un fichier du moteur Nkentseu

Pour cet exercice j'ai choisi `NkAngle.cpp`. J'ai utilise `git log --follow --stat --oneline -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"` pour reconstituer l'historique complet du fichier Git en suivant aussi ses eventuels deplacemnets.

```
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> git log --follow --stat --oneline -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"
f0456467 Licence : uniformiser les en-tetes sur « All Rights Reserved »
 Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
 Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp | 4 +---
 1 file changed, 1 insertion(+), 3 deletions(-)
d557314e update
 {Modules => Kernel}/Foundation/NKMath/src/NKMath/NkAngle.cpp | 0
 1 file changed, 0 insertions(+), 0 deletions(-)
1d4f072b refactor 002
 Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp | 97 +--------------------
---
 1 file changed, 2 insertions(+), 95 deletions(-)
f1e536a5 refactor 001
 Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp | 119 ++++++++++++++++++++
+--
 1 file changed, 110 insertions(+), 9 deletions(-)
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
 Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp | 14 ++++++++++++++
 1 file changed, 14 insertions(+)
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"
```
Par la suite j'ai utilise `git log --follow --format=fuller -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"` pour voir l'historique detaille des commits d'un fichier (qui l'a modifie et a quelles date).

```
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> git log --follow --format=fuller -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"
commit f04564676e2e30ead592baec70fa75e471e72d94
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Thu Aug 6 20:15:13 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Thu Aug 6 20:15:13 2026 +0100

    Licence : uniformiser les en-tetes sur « All Rights Reserved »
    
    189 fichiers portaient encore « Free to use and modify », ce qui CONTREDISAIT
    le fichier LICENSE a la racine. Une contradiction dans les en-tetes n'es
t pas
    un detail cosmetique : c'est elle qui fait foi pour qui lit un fichier i
sole,
    et deux textes opposes rendent la licence inopposable.
    
    Aucun changement de code : ces fichiers n'ont qu'une ligne modifiee. Iso
les
    dans leur propre commit pour que le travail reel des commits suivants re
ste
    lisible.

commit bdda350a054705f217f0daf5a54ab02bcb9c56ef
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Thu Jul 9 16:53:52 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Thu Jul 9 16:53:52 2026 +0100

    style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
    
    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    
    1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderde
mo 28/28 buildent OK apres reformatage.

commit d557314e707baf17e53029b9d9cae2c5164dd417
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Tue May 5 20:04:22 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Tue May 5 20:04:22 2026 +0100

    update

commit 1d4f072b3ca1af774f191889211cc51fc224e24e
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Thu Apr 30 08:44:44 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Thu Apr 30 08:44:44 2026 +0100

    refactor 002

commit f1e536a58890ac267b12ab7df1004d0a43270c48
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Wed Apr 29 10:39:16 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Wed Apr 29 10:39:16 2026 +0100

    refactor 001

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author:     LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Sat Mar 21 03:25:48 2026 +0100
Commit:     LeTeguis <teuguiasederis@gmail.com>
CommitDate: Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> 
```
J'ai maintenant utilise `git log --follow -p -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"` pour voir tout ce qui a ete modifie dans le fichier au cours de son histoire.

```
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> git log --follow -p -- "Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp"
commit f04564676e2e30ead592baec70fa75e471e72d94
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Aug 6 20:15:13 2026 +0100

    Licence : uniformiser les en-tetes sur « All Rights Reserved »
    
    189 fichiers portaient encore « Free to use and modify », ce qui CONTREDISAIT
    le fichier LICENSE a la racine. Une contradiction dans les en-tetes n'est pas
    un detail cosmetique : c'est elle qui fait foi pour qui lit un fichier i
sole,
    et deux textes opposes rendent la licence inopposable.
    
    Aucun changement de code : ces fichiers n'ont qu'une ligne modifiee. Iso
les
    dans leur propre commit pour que le travail reel des commits suivants re
ste
    lisible.

diff --git a/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Kernel/Founda
tion/NKMath/src/NKMath/NkAngle.cpp
index c32d99ea..6450ff02 100644
--- a/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp
+++ b/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp
@@ -4,7 +4,7 @@
 // AUTEUR: Rihen
 // DATE: 2026-04-26
 // VERSION: 2.0.0
-// LICENCE: Proprietary - Free to use and modify
+// LICENCE: Proprietary - All Rights Reserved (see LICENSE)
 // ------------------------------------------------------------------------
-----
 
 #include "pch.h"

commit bdda350a054705f217f0daf5a54ab02bcb9c56ef
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Jul 9 16:53:52 2026 +0100

    style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
    
    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    
    1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderde
mo 28/28 buildent OK apres reformatage.

diff --git a/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Kernel/Founda
tion/NKMath/src/NKMath/NkAngle.cpp
index f03cc78a..c32d99ea 100644
--- a/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp
+++ b/Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp
@@ -13,9 +13,7 @@
 #include "NKContainers/String/NkFormat.h"
 #include <ostream>
 
-namespace nkentseu {
-
-} // namespace nkentseu
+namespace nkentseu {} // namespace nkentseu
 
 // ============================================================
 // Copyright © 2024-2026 Rihen. All rights reserved.

commit d557314e707baf17e53029b9d9cae2c5164dd417
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Tue May 5 20:04:22 2026 +0100

    update

diff --git a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Kernel/Found
ation/NKMath/src/NKMath/NkAngle.cpp
similarity index 100%
rename from Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
rename to Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp

commit 1d4f072b3ca1af774f191889211cc51fc224e24e
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Apr 30 08:44:44 2026 +0100

    refactor 002

diff --git a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Modules/Foun
dation/NKMath/src/NKMath/NkAngle.cpp
index bab2bd00..f03cc78a 100644
--- a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
+++ b/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
@@ -7,109 +7,16 @@
 // LICENCE: Proprietary - Free to use and modify
 // ------------------------------------------------------------------------
-----
 
-// ------------------------------------------------------------------------
-
-// PRECOMPILED HEADER (requis pour tous les fichiers .cpp du projet)
-// ------------------------------------------------------------------------
-
 #include "pch.h"
 
-// ------------------------------------------------------------------------
-
-// EN-TÊTES DU MODULE
-// ------------------------------------------------------------------------
-
 #include "NKMath/NkAngle.h"
-#include "NKCore/NkString.h"
+#include "NKContainers/String/NkFormat.h"
 #include <ostream>
 
-// ------------------------------------------------------------------------
-
-// ESPACE DE NOMS PRINCIPAL
-// ------------------------------------------------------------------------
-
-
 namespace nkentseu {
 
-    // ====================================================================
-    // NAMESPACE : MATH (IMPLÉMENTATIONS NON-INLINE TEMPLATE)
-    // ====================================================================
-
-    namespace math {
-
-        // ================================================================
====
-        // INSTANCIATIONS EXPLICITES POUR PRÉCISIONS SUPPORTÉES
-        // ================================================================
====
-        // Note : Les méthodes template non-inline doivent être instanciées
-        // explicitement pour chaque type de précision supporté.
-
-        // ----------------------------------------------------------------
---------
-        // MÉTHODES DE REPRÉSENTATION TEXTE - FLOAT32
-        // ----------------------------------------------------------------
---------
-
-        NKENTSEU_MATH_API
-        NkString NkAngleT<float32>::ToString() const
-        {
-            return NkFormat("{0}_deg", mDeg);
-        }
-
-        NKENTSEU_MATH_API
-        NkString ToString(const NkAngleT<float32>& a)
-        {
-            return a.ToString();
-        }
-
-        NKENTSEU_MATH_API
-        std::ostream& operator<<(std::ostream& os, const NkAngleT<float32>&
 a)
-        {
-            return os << a.ToString().CStr();
-        }
-
-        // ----------------------------------------------------------------
---------
-        // MÉTHODES DE REPRÉSENTATION TEXTE - FLOAT64
-        // ----------------------------------------------------------------
---------
-
-        NKENTSEU_MATH_API
-        NkString NkAngleT<float64>::ToString() const
-        {
-            return NkFormat("{0}_deg", mDeg);
-        }
-
-        NKENTSEU_MATH_API
-        NkString ToString(const NkAngleT<float64>& a)
-        {
-            return a.ToString();
-        }
-
-        NKENTSEU_MATH_API
-        std::ostream& operator<<(std::ostream& os, const NkAngleT<float64>&
 a)
-        {
-            return os << a.ToString().CStr();
-        }
-
-    } // namespace math
-
-    // ====================================================================
========
-    // SPÉCIALISATION : NKTOSTRING<NKANGLET> (ESPACE DE NOMS GLOBAL)
-    // ====================================================================
========
-
-    // --------------------------------------------------------------------
-----
-    // INSTANCIATION FLOAT32
-    // --------------------------------------------------------------------
-----
-    template<>
-    NKENTSEU_MATH_API
-    NkString NkToString(const math::NkAngleT<float32>& a, const NkFormatPro
ps& props)
-    {
-        return NkApplyFormatProps(a.ToString(), props);
-    }
-
-    // --------------------------------------------------------------------
-----
-    // INSTANCIATION FLOAT64
-    // --------------------------------------------------------------------
-----
-    template<>
-    NKENTSEU_MATH_API
-    NkString NkToString(const math::NkAngleT<float64>& a, const NkFormatPro
ps& props)
-    {
-        return NkApplyFormatProps(a.ToString(), props);
-    }
-
 } // namespace nkentseu
 
 // ============================================================
 // Copyright © 2024-2026 Rihen. All rights reserved.
-// Proprietary License - Free to use and modify
-// ============================================================
\ No newline at end of file
+// ============================================================

commit f1e536a58890ac267b12ab7df1004d0a43270c48
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Wed Apr 29 10:39:16 2026 +0100

    refactor 001

diff --git a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Modules/Foun
dation/NKMath/src/NKMath/NkAngle.cpp
index 325b3ca8..bab2bd00 100644
--- a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
+++ b/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
@@ -1,14 +1,115 @@
-//
-// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 4/11/2024 at 10:11:58 AM.
-// Copyright (c) 2024 Rihen. All rights reserved.
-//
+// ------------------------------------------------------------------------
-----
+// FICHIER: NKMath\NkAngle.cpp
+// DESCRIPTION: Implémentation des fonctions non-inline de NkAngleT
+// AUTEUR: Rihen
+// DATE: 2026-04-26
+// VERSION: 2.0.0
+// LICENCE: Proprietary - Free to use and modify
+// ------------------------------------------------------------------------
-----
 
+// ------------------------------------------------------------------------
-
+// PRECOMPILED HEADER (requis pour tous les fichiers .cpp du projet)
+// ------------------------------------------------------------------------
-
+#include "pch.h"
 
-#include "NkAngle.h"
-#include "NKMath/NkFunctions.h"
+// ------------------------------------------------------------------------
-
+// EN-TÊTES DU MODULE
+// ------------------------------------------------------------------------
-
+#include "NKMath/NkAngle.h"
+#include "NKCore/NkString.h"
+#include <ostream>
+
+// ------------------------------------------------------------------------
-
+// ESPACE DE NOMS PRINCIPAL
+// ------------------------------------------------------------------------
-
 
 namespace nkentseu {
 
-       namespace math {
-       }
-}    // namespace nkentseu
\ No newline at end of file
+    // ====================================================================
+    // NAMESPACE : MATH (IMPLÉMENTATIONS NON-INLINE TEMPLATE)
+    // ====================================================================
+
+    namespace math {
+
+        // ================================================================
====
+        // INSTANCIATIONS EXPLICITES POUR PRÉCISIONS SUPPORTÉES
+        // ================================================================
====
+        // Note : Les méthodes template non-inline doivent être instanciées
+        // explicitement pour chaque type de précision supporté.
+
+        // ----------------------------------------------------------------
---------
+        // MÉTHODES DE REPRÉSENTATION TEXTE - FLOAT32
+        // ----------------------------------------------------------------
---------
+
+        NKENTSEU_MATH_API
+        NkString NkAngleT<float32>::ToString() const
+        {
+            return NkFormat("{0}_deg", mDeg);
+        }
+
+        NKENTSEU_MATH_API
+        NkString ToString(const NkAngleT<float32>& a)
+        {
+            return a.ToString();
+        }
+
+        NKENTSEU_MATH_API
+        std::ostream& operator<<(std::ostream& os, const NkAngleT<float32>&
 a)
+        {
+            return os << a.ToString().CStr();
+        }
+
+        // ----------------------------------------------------------------
---------
+        // MÉTHODES DE REPRÉSENTATION TEXTE - FLOAT64
+        // ----------------------------------------------------------------
---------
+
+        NKENTSEU_MATH_API
+        NkString NkAngleT<float64>::ToString() const
+        {
+            return NkFormat("{0}_deg", mDeg);
+        }
+
+        NKENTSEU_MATH_API
+        NkString ToString(const NkAngleT<float64>& a)
+        {
+            return a.ToString();
+        }
+
+        NKENTSEU_MATH_API
+        std::ostream& operator<<(std::ostream& os, const NkAngleT<float64>&
 a)
+        {
+            return os << a.ToString().CStr();
+        }
+
+    } // namespace math
+
+    // ====================================================================
========
+    // SPÉCIALISATION : NKTOSTRING<NKANGLET> (ESPACE DE NOMS GLOBAL)
+    // ====================================================================
========
+
+    // --------------------------------------------------------------------
-----
+    // INSTANCIATION FLOAT32
+    // --------------------------------------------------------------------
-----
+    template<>
+    NKENTSEU_MATH_API
+    NkString NkToString(const math::NkAngleT<float32>& a, const NkFormatPro
ps& props)
+    {
+        return NkApplyFormatProps(a.ToString(), props);
+    }
+
+    // --------------------------------------------------------------------
-----
+    // INSTANCIATION FLOAT64
+    // --------------------------------------------------------------------
-----
+    template<>
+    NKENTSEU_MATH_API
+    NkString NkToString(const math::NkAngleT<float64>& a, const NkFormatPro
ps& props)
+    {
+        return NkApplyFormatProps(a.ToString(), props);
+    }
+
+} // namespace nkentseu
+
+// ============================================================
+// Copyright © 2024-2026 Rihen. All rights reserved.
+// Proprietary License - Free to use and modify
+// ============================================================
\ No newline at end of file

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

diff --git a/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp b/Modules/Foun
dation/NKMath/src/NKMath/NkAngle.cpp
new file mode 100644
index 00000000..325b3ca8
--- /dev/null
+++ b/Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp
@@ -0,0 +1,14 @@
+//
+// Created by TEUGUIA TADJUIDJE Rodolf Séderis on 4/11/2024 at 10:11:58 AM.
+// Copyright (c) 2024 Rihen. All rights reserved.
+//
+
+
+#include "NkAngle.h"
+#include "NKMath/NkFunctions.h"
+
+namespace nkentseu {
+
+       namespace math {
+       }
+}    // namespace nkentseu
\ No newline at end of file
```
De tout ce que j'ai fait, l'historique de `NkAngle.cpp` est donc la suivante:
```
# Histoire du fichier `NkAngle.cpp`

Pour cette étude, j’ai choisi le fichier `Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp` du moteur **Nkentseu**. L’historique Git a été reconstitué avec la commande `git log --follow`, ce qui permet également de suivre le fichier lorsqu’il a changé de répertoire. L’historique montre que le fichier était initialement situé dans `Modules/Foundation/NKMath/src/NKMath/NkAngle.cpp`, avant d’être déplacé vers `Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp` le 5 mai 2026.

La **création du fichier** apparaît dans le commit `9c49f79f`, daté du **21 mars 2026**, intitulé « bug fix vulkan opengl dx11 current bug software and dx12 ». Git indique alors un nouveau fichier de 14 lignes. Le fichier contenait seulement les inclusions de `NkAngle.h` et de `NKMath/NkFunctions.h`, ainsi qu'un espace de noms `nkentseu::math` encore vide. Le message du commit indique que cette création s'inscrivait dans une correction concernant plusieurs environnements graphiques : Vulkan, OpenGL, DX11, le mode software et DX12.

Le **premier changement majeur** intervient le **29 avril 2026**, avec le commit `f1e536a5`, intitulé **« refactor 001 »**. C'est le plus gros changement de l'histoire du fichier : **110 lignes sont ajoutées et 9 supprimées**. Le fichier passe alors d'un simple squelette à une véritable implémentation. Un en-tête décrivant le fichier est ajouté, ainsi que le précompilé `pch.h`, les inclusions nécessaires et plusieurs implémentations de `NkAngleT`. Le code ajoute notamment les fonctions `ToString()` pour les précisions `float32` et `float64`, les opérateurs d'affichage et les spécialisations de `NkToString`. Le changement correspond donc à une réorganisation et surtout à une mise en place de l'implémentation complète des fonctions non-inline de `NkAngleT`.

Le **deuxième changement majeur** arrive dès le lendemain, le **30 avril 2026**, avec le commit `1d4f072b`, intitulé **« refactor 002 »**. Cette fois, **95 lignes sont supprimées et seulement 2 sont ajoutées**. Une grande partie du code ajouté la veille est retirée : les commentaires détaillés, les instanciations explicites de `float32` et `float64`, les fonctions `ToString`, l'opérateur `<<` et les spécialisations `NkToString` disparaissent du fichier. L'inclusion `NKCore/NkString.h` est remplacée par `NKContainers/String/NkFormat.h`. Le message « refactor 002 » ne donne pas de justification détaillée, mais le diff montre clairement une simplification importante du fichier.

Le **troisième changement important** est donc le commit initial `9c49f79f`, avec ses **14 lignes ajoutées**, même s'il est beaucoup plus petit que les deux refactorisations. Il est important parce qu'il correspond à la création du fichier et est directement associé, par son message, à une correction de compatibilité concernant plusieurs systèmes graphiques.

Après ces trois étapes fonctionnelles, le fichier connaît surtout des modifications de maintenance. Le **5 mai 2026**, le commit `d557314e` le déplace de `Modules/Foundation/NKMath` vers `Kernel/Foundation/NKMath`, avec une similarité de 100 %, ce qui signifie que son contenu n'est pas modifié. Le **9 juillet 2026**, le commit `bdda350a` applique le `clang-format` à 1748 fichiers du dépôt ; pour `NkAngle.cpp`, cela transforme notamment le namespace vide en une écriture sur une seule ligne. Le but annoncé est uniquement l'harmonisation du formatage du code. Enfin, le **6 août 2026**, le commit `f0456467` modifie uniquement l'en-tête de licence, en remplaçant « Free to use and modify » par « All Rights Reserved (see LICENSE) », afin d'éviter une contradiction avec le fichier `LICENSE` situé à la racine du dépôt. Le commit précise explicitement qu'il ne s'agit d'aucun changement de code.

Ainsi, l'histoire de `NkAngle.cpp` montre une évolution en plusieurs phases : **création liée à un correctif graphique, développement de son implémentation avec `refactor 001`, simplification avec `refactor 002`, puis déplacement et opérations de maintenance** concernant le formatage et la licence.
```
