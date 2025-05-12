#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

struct URLParams {
    char author[256];
    char publisher[256];
    char publish_year[256];
    char title[256];
};

void build_url(char *url, struct URLParams *params) {
    // base url
    strcpy(url, "https://openlibrary.org/search.json?");

    // Append to params: Auhor
    if (strlen(params->author) > 0 ) {
        strcat(url, "author=");
        strcat(url, params->author);
    }
    // Append to params: Publisher
    if (strlen(params->publisher) > 0) {
        strcat(url, "&publisher=");
        strcat(url, params->publisher);
    }
    // Append to params: Publish Year
    if (strlen(params->publish_year) > 0) {
        strcat(url, "&publish_year=");
        strcat(url, params->publish_year);
    }
    // Append to params: Auhor
    if (strlen(params->title) > 0) {
        strcat(url, "&title=");
        strcat(url, params->title);
    }
} 

    
    

int main() {
    struct URLParams params;
    char url[300];
    
    printf("Author: ");
    fgets(params.author, sizeof(params.author), stdin);
    params.author[strcspn(params.author, "\n")] = 0;
    printf("Publisher: ");
    fgets(params.publisher, sizeof(params.publisher), stdin);
    params.publisher[strcspn(params.publisher, "\n")] = 0;
    printf("Published Year:");
    fgets(params.publish_year, sizeof(params.publish_year), stdin);
    params.publish_year[strcspn(params.publish_year, "\n")] = 0;
    printf("Title: "); 
    fgets(params.title, sizeof(params.title), stdin);
    params.title[strcspn(params.title, "\n")] = 0;

    build_url(url, &params);

    CURL *curl;
    FILE *fp;

    fp = fopen("data.json", "wb");

    int result;

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    result = curl_easy_perform(curl);

    if (result == CURLE_OK) { printf("Download Successful!\n"); }
    else { printf("ERROR: %s\n", curl_easy_strerror(result)); }
    
    fclose(fp);

    curl_easy_cleanup(curl);
}
