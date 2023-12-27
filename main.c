#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define true 1
#define false 0

#define MAX_ROW 10
#define MAX_COL 10

typedef struct {

} model_t;

typedef struct {
    int8_t r, g, b;
} pixel_t;

typedef struct {
    pixel_t image[MAX_ROW][MAX_COL];
} image_t;

void sum_rgb(image_t* img) {
    int sum = 0;
    int sum_row = 0;
    int sum_all = 0;
    for(int i = 0; i < MAX_ROW; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            sum = img->image[i][j].r + img->image[i][j].g + img->image[i][j].b;
            printf("[%d] ", sum);
            sum_row += sum;
        }
        printf("%d\n", sum_row);
        sum_all += sum_row;
        sum_row = 0;
    }
    printf("%d\n", sum_all);
}

void display_image(image_t* img) {
    for(int i = 0; i < MAX_ROW; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("[%d %d %d] ", img->image[i][j].r, img->image[i][j].g, img->image[i][j].b);
        }
        printf("\n");
    }
}

image_t random_image() {
    image_t temp;
    for(int i = 0; i < MAX_ROW; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            temp.image[i][j].r = rand() % 8;
            temp.image[i][j].g = rand() % 8;
            temp.image[i][j].b = rand() % 8;
        }
    }
    return temp;
};

unsigned chisq(image_t* img) {
    // Sum (O - E)^2 / E
    // Expected is 50%
    double E = 0.5;
    double O = 0.0;
    double X = pow((O-E),2) / E;
    printf("Chi-Squared Value: %.2f", X);
    return false;
}

int main() {
    srand(1);
    image_t img = random_image();
    sum_rgb(&img);
    return 0;
}