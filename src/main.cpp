#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

// Vervang deze met je Wi-Fi gegevens
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Telegram Bot Token (van BotFather)
String botToken = "YOUR_BOT_TOKEN";

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
  digitalWrite(ledPin, LOW);  // Zet de LED uit bij het opstarten, voor de zekerheid

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
