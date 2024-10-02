#Stap 1: Bot aanmaken
-Zoek de bot @Botfather op op google. Je krijgt hier bovenaan de bot te zien. Voeg deze toe aan je contacten in Telegram.
-Klik op de bot en stuur “/start”, de bot start nu en geeft meerdere opties
-Wij willen een nieuwe bot dus stuur “/newbot”
-Hij wil nu een naam: geef je bot een naam
-Nu wilt hij een username (deze moet uniek zijn en eindigen op “bot” dus succes)
-Gefeliciteerd je hebt nu een bot aangemaakt! BotFather geeft nu een API-token terug, bewaar deze goed deze hebben we later nodig.

#Stap 2: Maak een nieuw project aan (ik gebruik hiervoor Visual Studio Code met PlatformIO)
-Klik op “+ new project” in platformIO
-Selecteer je ESP32 board, in mijn geval esp32dev module
-Druk op finish om een project aan te maken

#Stap 3: Update je .ini bestand voor de libraries (en je serial monitor speed)
-Voeg hiervoor `monitor_speed = 115200` toe
-En voeg de lib_deps toe zodat PlatformIO weet welke libraries het nodig heeb voor je project, in dit geval: 
`
lib_deps = 
bblanchon/ArduinoJson@^6.19.4 
https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot.git
`
 
#Stap 5: De code
Open de main.cpp in je project folder
Vervang de inhoud die er nu staat met de volgende code (zie comments voor uitleg over de code):
`
#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

// Vervang deze met je Wi-Fi gegevens
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Telegram Bot Token (van BotFather)
String botToken = "your_BOT_TOKEN";

// WiFi client voor Telegram
WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

// Pin van de ingebouwde LED
const int ledPin = 2;

// Timer instellingen
unsigned long lastTimeBotRan;
const long botRequestDelay = 1000;

void setup() {
  // Instellen van de LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Zet de LED uit bij het opstarten

  // Start de seriële monitor
  Serial.begin(115200);

  // Verbinding maken met Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbinden met Wi-Fi...");
  }
  Serial.println("Verbonden met Wi-Fi");

  // Stel de tijd in voor een veilige verbinding (dit is nodig voor Telegram Bot API)
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
}

void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;
    
    Serial.println("Nieuw bericht ontvangen: " + text);

    if (text == "/ledon") {
      digitalWrite(ledPin, HIGH);  // Zet de LED aan
      bot.sendMessage(chat_id, "LED is AAN", "");
    } else if (text == "/ledoff") {
      digitalWrite(ledPin, LOW);  // Zet de LED uit
      bot.sendMessage(chat_id, "LED is UIT", "");
    } else {
      bot.sendMessage(chat_id, "Stuur /ledon om de LED aan te zetten of /ledoff om de LED uit te zetten", "");
    }
  }
}
`
void loop() {
  if (millis() - lastTimeBotRan > botRequestDelay) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}

Vervang hierin de YOUR_SSID, YOUR_PASSWORD en YOUR_BOT_TOKEN met je eigen wifi inlog gegevens en de API bot token die we eerder hebben gekregen van BotFather.

#Stap 6: Uploaden maar!
Build en upload je code naar je esp32

#Stap 7: Test de bot
Ga naar je telegram bot via de link die je hebt gekregen in het begin van BotFather.
Typ /start om te beginnen. De bot zegt al wat je kunt doen
Typ /ledon om de led aan te zetten
Typ /ledoff om hem weer uit te zetten
