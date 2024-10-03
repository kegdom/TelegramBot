## Stap 1: Bot aanmaken
- Zoek de bot **@Botfather** op via Google. Je ziet deze bovenaan de resultaten. Voeg de bot toe aan je contacten in Telegram.
- Klik op de bot en stuur `/start`, de bot begint nu en toont meerdere opties.
- We willen een nieuwe bot, dus stuur `/newbot`.
- BotFather vraagt nu om een naam: geef je bot een naam.
- Vervolgens wil hij een gebruikersnaam (deze moet uniek zijn en eindigen op "bot", dus wees creatief!).
- Gefeliciteerd, je hebt nu een bot aangemaakt! BotFather geeft je nu een **API-token** terug. Bewaar deze goed, want we hebben deze later nodig.

## Stap 2: Maak een nieuw project aan (Visual Studio Code met PlatformIO)
- Klik op **+ New Project** in PlatformIO.
- Selecteer je ESP32 board, bijvoorbeeld **esp32dev module**.
- Druk op **Finish** om het project aan te maken.

## Stap 3: Update je `platformio.ini` bestand voor de libraries (en de serial monitor snelheid)
- Voeg `monitor_speed = 115200` toe om de snelheid van de seriële monitor in te stellen.
- Voeg de juiste **lib_deps** toe zodat PlatformIO de benodigde libraries installeert. Voor dit project gebruiken we:
    ```ini
    lib_deps = 
    bblanchon/ArduinoJson@^6.19.4 
    https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot.git
    ```
   Door dit bestand aan te passen weet PlatformIo precies wat het nodig heeft en installeert het de jusite libraries en andere benodigdheden. Als je      een foute library hebt toegevoegd, dan haal je dit uit je **lib_deps** en dan verwijderd PlatformIO dit ook weer automatisch bij de build.
  Na deze stap moet je `plaformio.ini` er zo uitzien:
  <img width="547" alt="Screenshot 2024-10-03 at 11 12 46" src="https://github.com/user-attachments/assets/f361f9a8-54b1-477b-9235-21a4c232220f">

  
## Stap 4: De code
- Open het bestand **main.cpp** in je projectmap. Deze vind je in je `src` folder
- Vervang de huidige inhoud met de code die beschikbaar is in de `src` folder van deze repository, in het bestand genaamd `main.cpp`. Je kunt dit gewoon kopiëren en plakken in je eigen project (of je kunt deze repository overnemen/clonen).
  
> Vervang in de code de waarden `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD` en `YOUR_BOT_TOKEN` met je eigen Wi-Fi-inloggegevens en de **API bot token** die je eerder van BotFather hebt gekregen.

## Stap 5: Uploaden maar!
- Build en upload je code naar je ESP32 door op de **Upload** knop te drukken in Visual Studio Code.
- Druk hiervoor eerst op het vinkje om je project te compileren, en daarna op het pijltje om het naar je ESP te sturen (zie de screenshot hieronder). Let erop dat als je serial monitor `connecting....` zegt dan moet je eventjes de **boot** knop van je esp ingedrukt houden zodat je ESP in de juiste boot stand staat om je code te kunenn ontvangen.
<img width="433" alt="Screenshot 2024-10-03 at 11 10 00" src="https://github.com/user-attachments/assets/65afddb0-e101-4d0e-a809-56a30a5e2bfa">

## Stap 6: Test de bot
- Ga naar je Telegram bot via de link die je in het begin van BotFather hebt gekregen.
- Typ `/start` om te beginnen. De bot geeft je nu instructies over wat je kunt doen.
- Typ `/ledon` om de LED aan te zetten.
- Typ `/ledoff` om de LED weer uit te zetten.

https://randomnerdtutorials.com/telegram-control-esp32-esp8266-nodemcu-outputs/
https://core.telegram.org/bots
https://www.instructables.com/Telegram-Bot-Arduino/
