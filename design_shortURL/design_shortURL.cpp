#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

class UrlShortener 
{
private:
    std::unordered_map<std::string, std::string> urlMap;

    std::string generateRandomShortUrl() {
        const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        const int length = 7;  // Adjust the length as needed

        std::string shortUrl;
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < length; ++i) {
            shortUrl += characters[rand() % characters.length()];
        }

        return shortUrl;
    }

public:
    // O(n) operation
    std::string shortenUrl(const std::string& longUrl) 
    {
        std::string shortUrl = generateRandomShortUrl();

        // Ensure the generated short URL is unique
        while (urlMap.find(shortUrl) != urlMap.end()) {
            shortUrl = generateRandomShortUrl();
        }
        // O(1) operation
        urlMap[shortUrl] = longUrl;
        return shortUrl;
    }
    std::string getLongUrl(const std::string& shortUrl) 
    {
        auto it = urlMap.find(shortUrl);
        if (it != urlMap.end()) {
            return it->second;
        } else {
            return "Short URL not found.";
        }
    }
};
int main()
{
    std::string URL_thats_too_long = "https://www.srsfusion.com/fusion-sensors-blah-blah-blah";
    UrlShortener* url_shortner = new UrlShortener();
    
    // Obtain the short URL
    std::string new_short_url = url_shortner->shortenUrl(URL_thats_too_long);
    std::cout << new_short_url << std::endl;

    // Go in reverse and retrieve the original long url
    std::string original_long_url = url_shortner->getLongUrl(new_short_url);
    std::cout << original_long_url << std::endl;

}