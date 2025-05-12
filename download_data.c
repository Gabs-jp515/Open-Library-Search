#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

struct URLParams {
    char author[256]
    char publisher[256];
    char publish_year[256];
    char title[256];
};

void build_url(char *url, struct URLParams *params) {
    // base url
    strcpy(url, "https://openlibrary.org/search.json?");

    // Append to params: Auhor
    if (&params.author != NULL) {
        strcat(url, "author=");
        strcat(url, params->author);
    }
    // Append to params: Publisher
    if (&params.publisher != NULL) {
        strcat(url, "&publisher=");
        strcat(url, params->publisher);
    }
    // Append to params: Publish Year
    if (&params.publish_year != NULL) {
        strcat(url, "&publish_year=");
        strcat(url, params->publish_year);
    }
    // Append to params: Auhor
    if (&params.title != NULL) {
        strcat(url, "&title=");
        strcat(url, params->title);
    }
    

    
    

int main() {
    struct URLParams params;
    char url[300];
    
    printf("Author: ");
    fgets(params.author, sizeof(params.author), stdin);
    scanf("Publisher %s (Press Enter for no specifcation)\n", publisher);
    fgets(params.publisher, sizeof(params.publisher), stdin);
    scanf("Published Year: %d (Press Enter for no specification)\n", publish_year);
    fgets(params.publish_year, sizeof(params.publish_year), stdin);
    scanf("Title: %s\n", title); 
    fgets(params.title, sizeof(params.title), stdin);

    build_url(url, &params);

    CURL *curl;
    FILE *fp;

    fp = fopen("data.json", "wb");

    int result;

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easysetopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    result = curl_easy_perform(curl);

    if (result == CURLE_OK) { printf("Download Successful!\n"); }
    else { printf("ERROR: %s\n", curl_easy_strerror(result)); }
    
    fclose(fp);

    curl_easy_cleanup(curl);
}
