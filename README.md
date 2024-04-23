# Proiect sincretic / Github / Dockerhub

https://hub.docker.com/r/nagygabrielrazvan/proiect-sah


## Nagy Gabriel-Razvan

Circuitul calului: Se dă o tablă de șah de N x N elemente pe care se află un cal la coordonatele
(i,j). Se cere să se scrie un program care determină mutările calului (respectând săritura calului
din jocul de șah) astfel încât toate pozițiile tablei să fie acoperite.


Cum incep sa gandesc programul: voi incepe prin a imi declara o variabila globala N care va determina dimensiunea tablei de sah.

Voi avea nevoie de o functie care va verifica daca pozitiile i si j pe care va merge 
calul se afla in tabla de sah de dimensiunea N x N pe care o da utilizatorul.

Voi aborda o metoda folosind backtracking, prin care voi genera toate 
tururile calului unul cate unul, urmand sa fie verificate daca acestea respecta conditiile impuse.
In momentul in care gasim un tur al calului care va acoperii toate solutiile si pozitiile tablei de sah 
de dimensiunea N x N, vom afisa acel traseu. MAI EXACT:
Acest algloritm va arata in modul urmator ( inspiratia mea pentru aceasta functie/problema a fost de pe geeksforgeeks, codul a fost implementat de mine dar m-am uitat la algoritm pentru a intelege mai bine.
Fara aceasta inspiratie recunosc faptul ca nu puteam rezolva problema in totalitate).
Acesta functioneaza in felul urmator:

Verificam daca toate pozitiile matricei au fost vizitate
Daca acest lucru se intampla, afisam solutia.
Else
1. Adaugam una dintre urmatoarele miscari ale calului la vectorul solutie si verificam recursiv daca aceasta miscare duce la  solutie ( un cal poate face maxim 8 miscari).
Alegem una dintre cele 8 miscari din acest pas.
2. Daca mutarea aleasa in pasul de mai sus nu duce la o solutie, atunci elminam aceasta miscarer din vectorul de solutii si incercam alte miscari alternative.
3. Daca niciuna dintre aceste alternative nu functioneaza, atunci returnam false.
Observam ca daca returnam false, vom elimina elementul adaugat anterior in recursivitate.
Daca false este returnat de apelul initial al recursiunii, atunci
inseamna ca nu exista nici-o solutie.

# Nelamuriri
Nu am inteles exact din cerinta daca calul poate pleca mereu de la o pozitie anume sau daca pozitia de la care
pleaca trebuie data de utilizator de la tastatura, asa ca am ales sa plece de la i=0,j=0 fiind cea mai usoara metoda de abordat. Am incercat sa gandesc algoritmul si pentru a 
da o valoarea random, folosind rand()%N, dar pentru o dimensiune a tablei mai mare, compilarea si gasirea unei solutii ar dura mult datorita algoritmului folosit.



Avem nevoie de 2 vectori (unul pentru x altul pentru y) care sa reprezinte toate posibilele deplasari ale calului intr-un joc de sah.
calul poate face deplasari astfel:
dreapta cu 2 si sus cu 1
dreapta cu 1 si sus cu 2
stanga cu 1 si sus cu 2
stanga cu 2 si sus cu 1
stanga cu 2 si jos cu 1
stanga cu 1 si jos cu 2
dreapta cu 1 si jos cu 2
dreapta cu 2 si jos cu 1


# Cateva informatii despre GitHub, am realizat cat de important, usor de folosit si esential este pentru un programator.

In primul rand, fiecare proiect de pe GitHub/GitLab, are un depozit repository care contine istoricul complet al modificariilor. Pe langa acest aspect, dezvoltatorii pot reveni la versiuni anterioare ale proiectului oricand doresc ei. 
Colaborarea cu altii programatori in orice parte a lumii, se face cu usurinta datorita platformei Git.
Se pot creea mai multe Branche-uri, in cazul in care mai multe persoane doresc sa lucreze la acelasi proiect, insa in cazul meu, fiind singur, imi pot repara erorile, stiu exact ce se intampla in codul meu si nu a intervenit nimeni, asa ca nu am avut nevoie sa imi creez mai multe branch-uri, insa intr-un proiect de echipa acesta poate fi foarte folositor. 

# Ce am invatat in detaliu despre Git?

Un depozit este locul in care este stocat codul sursa al unui proiect.
Utilizatorii pot folosii functia de clonare pentru a obtine o copie locala a codului.
Modificarile sunt adaugate pe platforma Git cu ajutorul commit-urilor, ficare commit fiind dat in cadrul unei salvari a proiectului. Codurile pe care le scrii, toate fisierele pe care le editezi vorfi conectate cu repository-ul tau, deci cu fiecaare editare pe care o faci asupra unui fisier, ai posibilitatea prin GitHub Desktop sa dai un commit. Aplicatia vede orice modificare pe care ai facut-o, pastrand si o varianta veche a codului/fisierelor tale, avand posibilitatea de a revenii la acestea oricand doresti.
Cum am spus si mai sus, se pot creea brench-uri separate.
Pull request, care permit integrarea modificarilor dintr-un branch in altul (nu m am folosit de aceasta functionalitate).

Se pot creea politici de securitate pentru a proteja un proiect, al tau.
Se poate adauga o licenta la proiect, pentru a specifica modul in care codul poate fi utilizat de alte persoane ( desigur daca acesta este pus pe modul public, si poate fii accesat de alti utilizatori).


# Cateva informatii importante despre Docker/Docker Hub
Docker ofera un mediu izolat pentru aplicatii, acestea ruleaza fara interferente pe orice sistem care suporta Docker.

Containerele Docker pot fi rulate pe ofice masina, fara sa conteze sistemul de operare, fara a avea nevoie de un program de tipul: visual studio code, eliminand erorile dintre diferitele versiuni de compilatoare.

## De ce sa folosim Docker?

Din punctul meu de vedere principalul motiv ar fi pentru a ne scapa de vorba: "functioneaza pe masina mea, e ceva gresit la masina ta!".
Docker asigura ca aplicatiile ruleaza in acelasi mod in timpul dezvoltarii si testarii.
Dezvoltatorii pot crea containere identice pe toate etapele ciclului de viata al unei aplicatii.
Scade riscul de erori cauzate de diferentele de versiuni.
Se pot rula mai multa containere simultan.

Containerele pot fi create, distribuite si rulate rapid.
Docker contine un ecosistem bogat de imagini si instrumente pentru diferite aplicatii.
Din punctul meu de vedere, aceasta aplicatie, a revolutionat modul in care aplicatiile sunt dezvoltate, livrate si rulate, oferind o solutie eficienta si portabila pentru o aplicatie, si sunt foarte bucuros ca am invatat destul de multe despre ea.


## Cum functioneaza Docker?

Docker utilizeaza containere pentru a impacheta aplicatiile si toate dependetele lor.
Un container include tot ce este necesar pentru a rula o aplicatie: codul sursa, limbajul de programare, bibliotecile, diferite setari.

O imagine Docker este un sablon care defineste continutul unui container.

Imaginile sunt utlizate pentru a crea containere si pot fi partajate si descarcate de pe Docker Hub.

Pentru a putea incarca un proiect, avem nevoie de un Dockerfile

Un dockerfile este un fisier de econfigurare text, care descrie pasii pentru contruirea unei imagini docker.

Dockerfile are comenzi specifice pentru a creea imaginea.

FROM gcc:latest ->Primele linii sunt pentru baza imaginii cu care lucram, pe baza imaginii gcc, proiectul fiind in limbajul C.

WORKDIR /usr/src/myapp ->Aceasta comanda specifica directorul in care ne aflam, si unde se afla codul sursa, etc.

COPY main.c . ->Copiem codul sursa, (pentru mine main.c),din directorul local unde se afla si DockerFile-ul, in directorul curent al sistemului de fisiere din container. 

RUN gcc -o main main.c->Comanda aceasta are rolul de a compila fisierul main.c folosinduse de compilatorul GCC si de a creea un executabil main.exe.

CMD ["./main"] -> Prin ultima comanda, executabilul functioneaza si afiseaza rezultatul pe ecran.


# Imaginile Docker sunt stocate prin intermediul unui registry, Docker Hub.

Docker Hub este un serviciu de registrator de imagini care permite dezvoltatorilor sa partajeze si sa descarce imagini Docker gata de utilizare.

Urmatoarele comenzi folosite de mine: 

docker build -t nagygabrielrazvan/proiect-sincretic:sah .
->construim imaginea in Docker desktop.

docker run -d -p 8080:80 nagygabrielrazvan/proiect-sincretic:sah
->rulam imaginea in terminal, si totodata in Docker Desktop.

docker login -> o folosim pentru a ne autentifica pentru a putea da push sau pull unei imagine, in special pentru a incarca o imagine pe Docker Hub.

docker push nagygabrielrazvan/proiect-sincretic:sah
->incarcam o imagine catre un registry Docker.

docker pull nagygabrielrazvan/proiect-sah:sincretic - pentru a da pull imaginii de pe Docker Hub pe orice masina. (pentru proiectul meu se foloseste aceasta comanda).

Link-uri de care m-am folosit si m-au ajutat pentru realizarea proiectului:

## Bibliografie 
1. In principal de informatiile profesorului de la seminar, demonstratiile live si instructiuniile pe care ni le-a oferit.

2. https://www.geeksforgeeks.org/the-knights-tour-problem/

3. https://docs.docker.com/engine/reference/commandline/info/

4. https://github.com/topics/info-website

## Mediu de dezvoltare
Limbaj: C

IDE: Visual Studio Code

