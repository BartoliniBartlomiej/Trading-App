//
// Created by Bartłomiej Kuś on 20/09/2025.
//

#include "item.h"
#include <iostream>

using json = nlohmann::json;

// static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
//     size_t realSize = size * nmemb;
//     std::string* mem = static_cast<std::string*>(userp);
//     mem->append(static_cast<char*>(contents), realSize);
//     return realSize;
// }
//
// bool Item::update(const std::string& symbol)
// {
//     const std::string& apiKey = "7KMAWA4CQR1NLGDI";
//     std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol="
//                       + symbol + "&interval=5min&apikey=" + apiKey;
//
//     CURL* curl = curl_easy_init();
//     if (!curl) {
//         std::cerr << "curl init failed\n";
//         return false;
//     }
//
//     std::string response;
//     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//     CURLcode res = curl_easy_perform(curl);
//     curl_easy_cleanup(curl);
//
//     if (res != CURLE_OK) {
//         std::cerr << "curl error: " << curl_easy_strerror(res) << "\n";
//         return false;
//     }
//
//     try {
//         auto j = json::parse(response);
//
//         // 🔎 Obsługa limitów / błędów
//         if (j.contains("Note")) {
//             std::cerr << "API limit exceeded: " << j["Note"] << "\n";
//             return false;
//         }
//         if (j.contains("Error Message")) {
//             std::cerr << "API error: " << j["Error Message"] << "\n";
//             return false;
//         }
//
//         // 🔎 Standardowa odpowiedź
//         if (j.contains("Meta Data") && j["Meta Data"].contains("3. Last Refreshed")) {
//             std::string lastRefreshed = j["Meta Data"]["3. Last Refreshed"];
//             auto ts = j["Time Series (5min)"][lastRefreshed];
//             std::string priceStr = ts["4. close"];
//             double newPrice = std::stod(priceStr);
//
//             price = newPrice;  // aktualizacja ceny
//             std::cout << "Zaktualizowano " << name
//                       << " -> " << price
//                       << " (czas: " << lastRefreshed << ")\n";
//             return true;
//         } else {
//             std::cerr << "Brak timestampu w odpowiedzi API. Odpowiedź: " << response << "\n";
//             return false;
//         }
//     } catch (std::exception &e) {
//         std::cerr << "JSON parse error: " << e.what()
//                   << "\nOdpowiedź API: " << response << "\n";
//         return false;
//     }
// }
