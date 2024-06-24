#include <windows.h>
#include <string.h>
#include <stdio.h>

// Enum for text alignment options
enum Alignment {
    LEFT,
    CENTER,
    RIGHT
};

// Define a struct for text data
struct TextData {
    char text[100];
    int x;
    int y;
    int size;
    enum Alignment alignment;
};

// Function to generate HTML code based on array of TextData structs
void generateHTML(struct TextData data[], int num_texts) {
    // Open a file to write HTML code
    FILE *file = fopen("output.html", "w");

    if (file == NULL) {
        printf("Error opening file!");
        return;
    }

    // HTML code
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html>\n");
    fprintf(file, "<head>\n");
    fprintf(file, "<title>Text Placement</title>\n");
    // Set page size to A4
    fprintf(file, "<style>\n");
    fprintf(file, "html, body { height: 100%%; margin: 0; }\n");
    fprintf(file, "@page { size: A4; margin: 0; }\n");
    fprintf(file, "@media print { body { margin: 0; } header, footer, nav, aside, article, section, details, figcaption, figure, menu { display: none; } }\n");
    fprintf(file, ".page { width: 210mm; height: 297mm; margin: auto; position: relative; background-color: #fff; border: 1px solid #000; }\n");
    fprintf(file, ".content { position: absolute; left: 0; top: 0; overflow: hidden; }\n");
    fprintf(file, "</style>\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "<div class=\"page\">\n");

    // Loop through each TextData struct and place text at specified location
    for (int i = 0; i < num_texts; i++) {
        int text_width = strlen(data[i].text) * data[i].size / 2; // Assuming average character width is half of font size
        int adjusted_x = data[i].x;
        // Adjust X coordinate based on alignment
        if (data[i].alignment == CENTER)
            adjusted_x -= text_width/2;
        else if (data[i].alignment == RIGHT)
            adjusted_x -= text_width;

        // Placing the text at the specified location with specified size
        fprintf(file, "<div class=\"content\" style=\"left:%dpx; top:%dpx; font-size:%dpx;\">%s</div>\n",
                adjusted_x, data[i].y, data[i].size, data[i].text);
    }

    fprintf(file, "</div>\n");
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");

    // Close the file
    fclose(file);

    printf("HTML file generated successfully!\n");
}

int main() {
    // Define array of TextData structs
    struct TextData texts[] = {
        {"Hello, World!", 300, 100, 20, CENTER},
        {"This is a test.", 780, 200, 16, LEFT}
    };

    // Calculate number of texts
    int num_texts = sizeof(texts) / sizeof(texts[0]);

    // Generate HTML based on the array of TextData structs
    generateHTML(texts, num_texts);

    return 0;
}
