#include <iostream>
#include <fstream>
using namespace std;

struct FileHeader{ 
    char signature[2]; 
    uint32_t file_size; 
    uint32_t reserved; 
    uint32_t file_offset_to_pixel_array; 
};

struct Pixel{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct Bitmap{ 
    uint32_t dib_header_size; 
    uint32_t image_width;
    uint32_t image_height;
    uint16_t planes;
    uint16_t bits_per_pixel; 
   
    uint32_t compression;
    uint32_t image_size;
    uint32_t x_pixels_per_meter; 
    uint32_t colors_in_color_table;
    uint32_t important_color_count;
};

int main(void){

    const char* filePath = "test.bmp";
    FILE* bmp = fopen(filePath, "rb");
    FileHeader fh;
    Bitmap bih;
 
    fread(&fh.signature,2,1,bmp);
    fread(&fh.file_size,4,1,bmp);
    fread(&fh.reserved,4,1,bmp);
    fread(&fh.file_offset_to_pixel_array,4,1,bmp);
    fread(&bih, 40, 1, bmp); 
}
