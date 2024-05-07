#include <stdio.h>
#include <string.h>

char* extract_words(char *sentence, int start, int end) {
    if (start > end) {
        return NULL; // Base case: invalid range
    }

    int word_start = start;
    int word_end = start;

    // Find the first word
    while (word_end <= end && sentence[word_end] != ' ') {
        word_end++;
    }

    // Check if any word found
    if (word_start == word_end) {
        return NULL; // No word found
    }

    // Allocate memory for the extracted sentence (including null terminator)
    int extracted_len = word_end - word_start + 1;
    char *extracted = (char*)malloc(extracted_len * sizeof(char));
    if (extracted == NULL) {
        return NULL; // Memory allocation error
    }

    // Copy the first word
    strncpy(extracted, sentence + word_start, extracted_len - 1);
    extracted[extracted_len - 1] = '\0'; // Add null terminator

    // Recursively extract remaining words (if any)
    char *next_word = extract_words(sentence, word_end + 1, end);
    if (next_word != NULL) {
        // Concatenate extracted words (append a space)
        strcat(extracted, " ");
        strcat(extracted, next_word);
        free(next_word); // Free memory from recursive call
    }

    return extracted;
}

int main() {
    char sentence[] = "This is a test sentence";
    int start = 5;
    int end = 10;

    char *extracted = extract_words(sentence, start, end);

    if (extracted == NULL) {
        printf("Error extracting words\n");
    } else {
        printf("Extracted sentence: %s\n", extracted);
        free(extracted); // Free memory allocated by extract_words
    }

    return 0;
}
