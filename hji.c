#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- STRUCTURE BLUEPRINTS ---

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

// --- 1. FETCHING FUNCTIONS (Converts 1-based index to 0-based index) ---

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

// --- 2. DOCUMENT PARSING FACTORY ---

struct document get_document(char* text) {
    struct document doc;
    doc.data = NULL;
    doc.paragraph_count = 0;

    int p_idx = -1, s_idx = -1, w_idx = -1;
    int char_count = 0;
    
    // Allocate buffer for staging a single word
    char* current_word = malloc(sizeof(char) * 1025); 

    // Helper macro to initialize/reallocate paragraphs on demand
    #define INITIALIZE_PARAGRAPH if (s_idx == -1) { \
        doc.paragraph_count++; \
        doc.data = realloc(doc.data, doc.paragraph_count * sizeof(struct paragraph)); \
        p_idx = doc.paragraph_count - 1; \
        doc.data[p_idx].data = NULL; \
        doc.data[p_idx].sentence_count = 0; \
        s_idx = 0; \
    }

    // Helper macro to initialize/reallocate sentences on demand
    #define INITIALIZE_SENTENCE if (w_idx == -1) { \
        doc.data[p_idx].sentence_count++; \
        doc.data[p_idx].data = realloc(doc.data[p_idx].data, doc.data[p_idx].sentence_count * sizeof(struct sentence)); \
        s_idx = doc.data[p_idx].sentence_count - 1; \
        doc.data[p_idx].data[s_idx].data = NULL; \
        doc.data[p_idx].data[s_idx].word_count = 0; \
        w_idx = 0; \
    }

    // Character-by-character scan loop
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c == ' ' || c == '.' || c == '\n') {
            if (char_count > 0) {
                current_word[char_count] = '\0'; // Cap off string
                
                INITIALIZE_PARAGRAPH;
                INITIALIZE_SENTENCE;

                struct sentence* s = &doc.data[p_idx].data[s_idx];
                s->word_count++;
                s->data = realloc(s->data, s->word_count * sizeof(struct word));
                w_idx = s->word_count - 1;
                
                s->data[w_idx].data = malloc((char_count + 1) * sizeof(char));
                strcpy(s->data[w_idx].data, current_word);
                
                char_count = 0; 
            }

            if (c == '.') {
                w_idx = -1; 
            } else if (c == '\n') {
                w_idx = -1;
                s_idx = -1; 
            }
        } else {
            current_word[char_count++] = c;
        }
    }

    // Capture trailing words without a delimiter at the absolute end
    if (char_count > 0) {
        current_word[char_count] = '\0';
        INITIALIZE_PARAGRAPH;
        INITIALIZE_SENTENCE;
        struct sentence* s = &doc.data[p_idx].data[s_idx];
        s->word_count++;
        s->data = realloc(s->data, s->word_count * sizeof(struct word));
        w_idx = s->word_count - 1;
        s->data[w_idx].data = malloc((char_count + 1) * sizeof(char));
        strcpy(s->data[w_idx].data, current_word);
    }

    free(current_word);
    return doc;
}

// --- 3. THE MISSING COMPILER ENTRY POINT ---

int main() {
    // Sample raw string matching the format constraints
    char text[] = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";

    printf("--- Running Document Parser ---\n\n");

    // Build the dynamic structural object
    struct document my_doc = get_document(text);

    // Query 1: Get the first word of the first sentence of the first paragraph (1, 1, 1)
    struct word w = kth_word_in_mth_sentence_of_nth_paragraph(my_doc, 1, 1, 1);
    printf("Query [Word 1, Sentence 1, Paragraph 1]: %s\n", w.data);

    // Query 2: Get the second word of the first sentence of the first paragraph (2, 1, 1)
    struct word w2 = kth_word_in_mth_sentence_of_nth_paragraph(my_doc, 2, 1, 1);
    printf("Query [Word 2, Sentence 1, Paragraph 1]: %s\n", w2.data);

    // Query 3: Get the first word of the second sentence of the second paragraph (1, 2, 2)
    struct word w3 = kth_word_in_mth_sentence_of_nth_paragraph(my_doc, 1, 2, 2);
    printf("Query