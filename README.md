## Stap 1: Bot aanmaken
- Zoek de bot @Botfather op op google. Je krijgt hier bovenaan de bot te zien. Voeg deze toe aan je contacten in Telegram.
- Klik op de bot en stuur “/start”, de bot start nu en geeft meerdere opties
- Wij willen een nieuwe bot dus stuur “/newbot”
- Hij wil nu een naam: geef je bot een naam
- Nu wilt hij een username (deze moet uniek zijn en eindigen op “bot” dus succes)
- Gefeliciteerd je hebt nu een bot aangemaakt! BotFather geeft nu een API-token terug, bewaar deze goed deze hebben we later nodig.

## Stap 2: Maak een nieuw project aan (ik gebruik hiervoor Visual Studio Code met PlatformIO)
- Klik op “+ new project” in platformIO
- Selecteer je ESP32 board, in mijn geval esp32dev module
- Druk op finish om een project aan te maken

##Stap 3: Update je .ini bestand voor de libraries (en je serial monitor speed)
- Voeg hiervoor `monitor_speed = 115200` toe
- En voeg de lib_deps toe zodat PlatformIO weet welke libraries het nodig heeb voor je project, in dit geval: 
`
lib_deps = 
bblanchon/ArduinoJson@^6.19.4 
https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot.git
`
 
## Stap 5: De code
- Open de main.cpp in je project folder
- Vervang de inhoud die er nu staat met de code die in deze repo staat in de "src" folder genaamd `main.cpp` dit kan je gewoon copieeren en plakken in je eigenproject. (of neem deze repo over)

> Vervang hierin de YOUR_SSID, YOUR_PASSWORD en YOUR_BOT_TOKEN met je eigen wifi inlog gegevens en de API bot token die we eerder hebben gekregen van BotFather.

## Stap 6: Uploaden maar!
- Build en upload je code naar je esp32 door op de upload knop te drukken in je Visual Studio Code

## Stap 7: Test de bot
- Ga naar je telegram bot via de link die je hebt gekregen in het begin van BotFather.
- Typ /start om te beginnen. De bot zegt al wat je kunt doen
- Typ /ledon om de led aan te zetten
- Typ /ledoff om hem weer uit te zetten
