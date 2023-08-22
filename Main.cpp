#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Function to write compressed image data to a file
void writeCompressedImageToFile(const vector<uchar>& compressedImage, const string& outputPath) {
    ofstream outputFile(outputPath, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create the output file." << endl;
        return;
    }

    // Writing the compressed image data to the file
    outputFile.write(reinterpret_cast<const char*>(compressedImage.data()), compressedImage.size());
    outputFile.close();
    cout << "Compressed image data written to the file." << endl;
}
// Function to compress the input image to JPEG format
vector<uchar> jpegCompressImage(const string& inputImage) {
    vector<uchar> compressedData;

    // Load the input image
    Mat image = imread(inputImage, IMREAD_UNCHANGED);
    if (image.empty()) {
        cerr << "Error: Unable to load the image." << endl;
        return compressedData;
    }

    // Set JPEG compression quality level (0-100)
    vector<int> params = { IMWRITE_JPEG_QUALITY, 0 };

    // Compress the image to JPEG format and store the compressed data in compressedData vector
    imencode(".jpg", image, compressedData, params);

    return compressedData;
}
int main() {
    // Replace these paths with the appropriate input PNG image and desired output path
    string inputImage = "C:\\Users\\ASUS\\Downloads\\raoul-droog-yMSecCHsIBc-unsplash.jpg";
    string outputPath = "compressed_output.jpg";

    // Compress the PNG image and store the compressed data in compressedJpegData
    vector<uchar> compressedJpegData = jpegCompressImage(inputImage);
    if (!compressedJpegData.empty()) {
        // Write the compressed JPEG data to the output file
        writeCompressedImageToFile(compressedJpegData, outputPath);
    }
    return 0;
}