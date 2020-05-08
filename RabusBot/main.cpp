//Token: 1122758262:AAFiM8n4f7m9-szeLjhvSF2yQJ9Rsilu6NI
//API Key 	LFGXA9Y4-GYCNXRWN-QNC70DCO-B5U1R092
//Secret 	cb0774508eb9779d6eb564a3eef165d6404fc937b07961a7c008afa1ebd6418415a90acc50933276d5129c35c988151f8fa273058c2f16e057c864de352ccf28

#include <iostream>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <sys/time.h>
#include <sstream>
#include <curl/curl.h>

//using namespace TgBot;


int main() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    const std::string returnTicker = "https://poloniex.com/tradingApi" ;
    std::vector<std::string> test;
    TgBot::Bot bot("1122758262:AAFiM8n4f7m9-szeLjhvSF2yQJ9Rsilu6NI"); //Communicating with the Telegram Bot

    CURL *curl = curl_easy_init();
    if(curl) {
      const char *data = "data to send";

      curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");

      /* size of the POST data */
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));

      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
      /* set up the read callback with CURLOPT_READFUNCTION */

      double ret = curl_easy_perform(curl);

      curl_easy_cleanup(curl);
    }


    // Thanks Pietro Falessi for code
    TgBot::InlineKeyboardMarkup::Ptr keyboard(new TgBot::InlineKeyboardMarkup);
    std::vector<TgBot::InlineKeyboardButton::Ptr> row0;
    TgBot::InlineKeyboardButton::Ptr checkButton(new TgBot::InlineKeyboardButton);
    checkButton->text = "btc";
    checkButton->callbackData = "btc";
    row0.push_back(checkButton);
    keyboard->inlineKeyboard.push_back(row0);



    bot.getEvents().onCommand("start", [&bot, &keyboard](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!", false, 0, keyboard);
    });
/*    bot.getEvents().onCommand("penis", [&bot, &keyboard](Message::Ptr message) {
        std::string response = "Das wird geschrieben beim asführen";
        bot.getApi().sendMessage(message->chat->id, response, false, 0, keyboard, "Markdown");
    });
    */
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr query) {
        if (StringTools::startsWith(query->data, "btc")) {
            double btcvalue = 3.0;

            std::string btcvaluestring = std::to_string(btcvalue);
            std::string response = "Der Aktuelle Kontostand beträgt: " ;
            response = response += btcvalue;
            bot.getApi().sendMessage(query->message->chat->id, response, false, 0, keyboard, "Markdown");
        }
    });

    signal(SIGINT, [](int s) {
        printf("SIGINT got\n");
        exit(0);
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        bot.getApi().deleteWebhook();

        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (std::exception& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}
