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

## Stap 3: Update je `.ini` bestand voor de libraries (en de serial monitor snelheid)
- Voeg `monitor_speed = 115200` toe om de snelheid van de seriële monitor in te stellen.
- Voeg de juiste **lib_deps** toe zodat PlatformIO de benodigde libraries installeert. Voor dit project gebruiken we:
    ```ini
    lib_deps = 
    bblanchon/ArduinoJson@^6.19.4 
    https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot.git
    ```

## Stap 4: De code
- Open het bestand **main.cpp** in je projectmap.
- Vervang de huidige inhoud met de code die beschikbaar is in de "src" folder van deze repository, in het bestand genaamd `main.cpp`. Je kunt dit gewoon kopiëren en plakken in je eigen project (of je kunt deze repository overnemen).
  
> Vervang in de code de waarden `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD` en `YOUR_BOT_TOKEN` met je eigen Wi-Fi-inloggegevens en de **API bot token** die je eerder van BotFather hebt gekregen.

## Stap 5: Uploaden maar!
- Build en upload je code naar je ESP32 door op de **Upload** knop te drukken in Visual Studio Code.

## Stap 6: Test de bot
- Ga naar je Telegram bot via de link die je in het begin van BotFather hebt gekregen.
- Typ `/start` om te beginnen. De bot geeft je nu instructies over wat je kunt doen.
- Typ `/ledon` om de LED aan te zetten.
- Typ `/ledoff` om de LED weer uit te zetten.
