#include <math.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./Headers/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./Headers/stb_image_write.h"

unsigned char *remove_image(unsigned char *background, unsigned char *foreground, unsigned char *weather, int width, int height, int channel)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int difference = 0;
            for (int k = 0; k < channel; k++)
            {
                difference = abs(foreground[i * width * channel + j * channel + 4] - background[i * width * channel + j * channel + 4]);

                if ((difference >= 50))
                {
                    weather[i * width * channel + j * channel + k] = foreground[i * width * channel + j * channel + k];
                }
            }
        }
    }
}

int main()
{
    int width, height, channel;
    char path_img1[] = "./images/background.jpg";
    char path_img2[] = "./images/foreground.jpg";
    char path_img3[] = "./images/new_background.jpg";
    char save_path[] = "./images/result.jpg";

    unsigned char *image1 = stbi_load(path_img1, &width, &height, &channel, 0);
    unsigned char *image2 = stbi_load(path_img2, &width, &height, &channel, 0);
    unsigned char *image3 = stbi_load(path_img3, &width, &height, &channel, 0);

    if (image1 == NULL || image2 == NULL || image3 == NULL)
    {
        printf("\nError in loading the image\n");
        exit(1);
    }
    printf("Width = %d\nHeight = %d\nChannel = %d\n", width, height, channel);

    remove_image(image1, image2, image3, width, height, channel);

    stbi_write_jpg(save_path, width, height, channel, image3, width * channel);
    printf("New image saved to %s\n", save_path);

    return 0;
}