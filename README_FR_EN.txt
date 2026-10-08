LEKAK — PREMIER ESSAI IPHONE
==========================

STATUT
Ce dossier prépare une application de diagnostic iOS. CE N'EST PAS LE JEU.
Le projet n'a pas encore été compilé avec Xcode ni testé sur un iPhone.
La compilation en ligne reste à lancer depuis un compte GitHub.
Le contrôle local du projet est distinct d'une compilation iOS réussie.

POURQUOI CE TEST
Le moteur Android actuel utilise des pointeurs stockés sur 32 bits, de la
mémoire à des adresses précises et des modifications du code en mémoire.
Le test vérifie le compilateur iOS, les adresses mémoire demandées et
l'adresse d'une fonction native. Il ne modifie pas de code exécutable.
Même si le test réussit, il restera à porter le moteur, les contrôles tactiles,
le lecteur de BIN, les sauvegardes et les mécanismes du mod.
Un mapping demandé mais non obtenu ne prouve pas que toutes les autres
stratégies de mapping sont impossibles.

ETAPE 1 — COMPILER DEPUIS WINDOWS
1. Dézipper Lekak_iPhone_Premier_Essai.zip.
2. Sur https://github.com, créer un compte si nécessaire, puis un nouveau
   dépôt nommé lekak-iphone-test. Un dépôt public permet d'utiliser les
   runners macOS standard gratuitement. Ce projet de test n'inclut aucun
   fichier du jeu, portrait, musique ou BIN.
3. Dans le dépôt : Add file > Upload files.
4. Déposer le CONTENU du dossier extrait à la racine du dépôt :
   .github/, App/, tools/, README_FR_EN.txt et engine-audit.json.
   Ne pas téléverser seulement le ZIP : GitHub ne l'exécuterait pas.
   Ne pas mettre ces fichiers dans un sous-dossier supplémentaire.
5. Cliquer Commit changes.
6. Ouvrir Actions > iPhone diagnostic > Run workflow > Run workflow.
7. Attendre le résultat. Si le statut est vert, ouvrir cette exécution et,
   dans Artifacts, télécharger Lekak-iPhone-Diagnostic.
8. Extraire l'archive téléchargée pour obtenir
   Lekak_iPhone_Diagnostic.ipa.
9. Si le statut est rouge, télécharger Compiler-results si disponible et
   transmettre le résultat pour corriger le portage. Ne pas transmettre
   de mot de passe ni de code de connexion.

ETAPE 2 — INSTALLER LE TEST DEPUIS WINDOWS
Suivre le guide officiel AltStore Classic pour Windows :
https://faq.altstore.io/altstore-classic/how-to-install-altstore-windows
AltServer sur Windows installe AltStore sur l'iPhone connecté.
Puis ouvrir AltStore sur l'iPhone, My Apps > +, et sélectionner l'IPA.
L'IPA est volontairement non signée ; l'outil d'installation doit la signer
pour ton compte et ton appareil. Aucun compte Apple n'est intégré au projet.
Avec un compte gratuit, les apps doivent être renouvelées tous les 7 jours.
Ce processus ne publie rien sur l'App Store.

ETAPE 3 — RESULTAT
Ouvrir « Lekak — essai iOS », toucher Partager et envoyer le fichier
Lekak_iOS_Report.json dans cette conversation.
Le rapport ne contient ni nom de compte ni identifiant unique de téléphone.
Il permettra de choisir la bonne adaptation du moteur.

REFERENCES
Runners macOS : https://docs.github.com/en/actions/reference/runners/github-hosted-runners
Moteur : https://github.com/Unchiga/Yu-Gi-Oh-Forbidden-Memories-Recompiled
Base étudiée : 0d78202729967a5bbdbc886aa128e48e82bef7ac.

ENGLISH
=======
This is an iPhone compatibility probe, NOT the game. It has not yet been
built with Xcode or tested on an iPhone. The local project checks do not
constitute an iOS compilation test.

On Windows, extract this project and upload its CONTENTS to the root of a
GitHub repository, including .github/workflows/ios-probe.yml. Do not upload
only the ZIP and do not add an extra enclosing folder. A public repository
can use standard macOS GitHub-hosted runners for free.
Open Actions > iPhone diagnostic > Run workflow. If successful, download
the Lekak-iPhone-Diagnostic artifact and extract the unsigned IPA.
Install it using AltStore Classic and AltServer for Windows, following the
official guide above. The sideloading tool signs the IPA for your Apple
account and device; no credentials are stored in this project. Free-account
apps need refreshing every seven days.
Open the probe and use Share to export Lekak_iOS_Report.json.
If the build fails, provide the compiler logs instead.

The probe checks G32 stored-pointer compilation, safe low-address memory
requests, and whether a native function fits in a 32-bit slot. It does not
patch executable code or overwrite existing mappings. A rejected memory
hint does not prove every other strategy impossible. The full game still
needs a native iOS build, static mod dispatch, input, BIN import and save
integration even if all diagnostic checks pass.
