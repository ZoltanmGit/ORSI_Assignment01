# ORSI_Assigmnet01
2020 // First assignment for ORSI in c++  
Created by: Márton Zoltán

## The Story
Az emberiség újabb kihívás elé néz. A titokzatos tiara-baktérium főleg a fiatalokat célozza; a jövő generációjának szervezetében olyan mértékben megnöveli a gumicukor fogyasztására vonatkozó vágyat; melyet sem a boltok, sem az orvosok nem tudnak követni. A fiatalok egymást ütik a békás Hariboért, harcok alakulnak ki a Tesco polcainál a gumimacikért is.

Néhányan közülük felismerve a probléma súlyát, arra jutottak, hogy meg kell állítani a kórokozót. A magyar kutatást az ELTE IK és TTK hallgatói vezetik. Az eddigi tudás alapján a baktériumok minden ember szervezetében más és más formát vesznek fel, figyelembe véve az egyén ízlését a gumicukor terén. Ezt felhasználva tovább tud osztódni, hogy még nagyobb fogyasztásra bírja a gazdatestet.

A megoldást az alapján próbálják az ifjú kutatók megtalálni, hogy egyezést keresnek a baktérium és a gumicukrok fehérje-szerkezeti felépítésében. Ennek eredményét felhasználva lehetőség nyílna egy olyan ízesétésű chips gyártására, mely a szerkezeti felépítést kihasználva elpusztítja a baktériumot.

A TTKs hallgatók feladata a fiatalok szervezetében lévő baktérium, és a különböző gumicukrok fehérje-szerkezetének megállapítása volt. Ezt az információt az IK-soknak kellett feldolgozni; minden azonosított baktérium-típushoz tarotozó felépítést össze kell vetni a különböző édességek fehérjéivel, és megállapítani a lehető legnagyobb közös láncot a kettőben.

Az így kapott információkat felhasználva már lehetőség nyílt a közös törzsek feltárására, és az ellenchips gyártásának megkezdésére.

P. S: a kutatások során nem végeztetek állatkísérleteket gumimacikon vagy békákon.

## The Task
A feladat két sorozat leghosszabb közös részsorozatának (LKR) megállapítása. A sorozatokat stringként értelmezzük (minden string legalább 1 karakter hosszú), melyben az angol ábécé kis- és nagybetűi fordulhatnak elő, egyéb karakterek (számok, írásjelek, speciális karakterek, whitespacek) nem. A megoldást nem brute-force, hanem a dinamikus programozás alapján kell megoldani (algoritmusokat lásd lejjebb).
### Main()
A main() feladata beolvasni az input.txt tartalmát, elindítani N szálat, ahol minden szál LKR-t számol az eredeti minta és az input egy sora között. A főprogram ezután az összes, így indított száltól fogadja az eredményt (a LKR-t, mint stringet) és ezeket az adatokat az output.txt -be írja - soronként egyet. Ha üres sorozatot kap, mint LKR, akkor egy üres string kerül a fájlba az adott sorba (azaz lesz üres sor), ez nem jelent hibát az algoritmus szempontjából.
### Threads
Az egyes szálak ugyanazt a feladatot oldják meg, csupán más adatokkal. Az első, algoritmusban X -el jelölt sorozat minden szálnál ugyanaz - az eredeti minta. Az Y értéke fog változni a szálak között.

Lentebb olvasható az LKR algoritmusa, a szálaknak ezt az algoritmust - illetve az olvasható eredmény előállítását kell megvalósítani. Az adatok case-sensitivek, így ne módosíts a casingen! A kiírási algoritmusban található print xi sort kell majd úgy módosítani, hogy ne a konzolra / output fájlba írja az eredményt, hanem valamilyen módon eltárolja, hogy amikor a rekurzív algoritmus végetért, az így kapott eredményt tudjuk visszaadni a main() felé.

A két algoritmust paraméterezésben módosíthatod, kaphatnak plusz paramétereket (vagy kevesebbet), kihasználva a C++ által biztosított dolgokat.(Pl.az STL konténerekről lekérdezhető azok mérete, így az n és m explicit átadása az LKR-nek nem is feltétlenül szükséges).

A két algoritmust nem is feltétlenül szükséges külön függvénybe megírni, történhet egyben is a számítás, ha meg tudod oldani.

Előfordulhat, hogy nincs közös részsorozat (pl.az ABCD és a gefh sorozatoknak nincs közös eleme). Ilyenkor az LKR egy üres sorozatot ad eredményül, nem száll el.
### Input File
Az input fájl felépítése az alábbi:

Az első sorban egy N szám található, összesen ennyi stringgel kell összevetni az eredeti mintát. Ugyanebben a sorban, szóközzel elválasztva az N -től egy stringet olvasható, az eredeti minta, amihez a többit majd hasonlítani kell. A következő N sorban egy-egy string található, mely mindegyike megfelel a fentieknek (csak az angol ábécé kis- és nagybetűi). A stringek nem egyenlő hosszúak.

Egy példa bemenet ( input.txt ):
>4 vWjxvfUBMmRDAVV  
>dlKBILGZWJAqXzAGFRHZMitzLyOax  
>tcZfEPRIETXGEtsHcKwZ  
ZzUzRqpVkElpuPuaIsCFXGLeVDYWVOtKcmjRmpjuWUQre  
GFRHZMitzLyOaxtcZfWhfQEaktRmE  
### Output File
A fenti input alapján kapott output.txt tartalma:
>Wx  
fR  
URDV  
Wfm 
### You can assume that
- The input file exists  
- The input file is formated correctly  
- The input file has no strings longer than 50 chars  
