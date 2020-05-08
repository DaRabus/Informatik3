#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("1122758262:AAFiM8n4f7m9-szeLjhvSF2yQJ9Rsilu6NI");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}

//API Key 	LFGXA9Y4-GYCNXRWN-QNC70DCO-B5U1R092
//Secret 	cb0774508eb9779d6eb564a3eef165d6404fc937b07961a7c008afa1ebd6418415a90acc50933276d5129c35c988151f8fa273058c2f16e057c864de352ccf28
